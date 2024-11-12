// UAVCAN common serialization support routines.                                                             +-+ +-+
// This file is based on canard_dsdl.h, which is part of Libcanard.                                          | | | |
//                                                                                                           \  -  /
// AUTOGENERATED, DO NOT EDIT.                                                                                 ---
//                                                                                                              o
//---------------------------------------------------------------------------------------------------------------------
// Language Options
//     target_endianness:  any
//     omit_float_serialization_support:  False
//     enable_serialization_asserts:  False
//     enable_override_variable_array_capacity:  False
//     cast_format:  (({type}) {value})

#ifndef NUNAVUT_SUPPORT_SERIALIZATION_H_INCLUDED
#define NUNAVUT_SUPPORT_SERIALIZATION_H_INCLUDED

#ifdef __cplusplus
#   if (__cplusplus < 201100L)
#       error "Unsupported language: ISO C11, C++11, or a newer version of either is required."
#   endif
extern "C"
{
#else
#   if !defined(__STDC_VERSION__) || (__STDC_VERSION__ < 201112L)
#       error "Unsupported language: ISO C11 or a newer version is required."
#   endif
#endif

#include <string.h>

#include <float.h>
#include <math.h>  // For isfinite().
#include <stdbool.h>
#include <stdint.h>
#include <assert.h>  // For static_assert (C11) and assert() if NUNAVUT_ASSERT is used.

static_assert(sizeof(size_t) >= sizeof(size_t),
    "The bit-length type used by Nunavut, size_t, "
    "is smaller than this platform's size_t type. "
    "Nunavut serialization relies on size_t to size_t conversions "
    "that do not lose data. You will need to regenerate Nunavut serialization support with a larger "
    "unsigned_bit_length type specified.");

#define NUNAVUT_SUPPORT_LANGUAGE_OPTION_TARGET_ENDIANNESS 1693710260
#define NUNAVUT_SUPPORT_LANGUAGE_OPTION_OMIT_FLOAT_SERIALIZATION_SUPPORT 0
#define NUNAVUT_SUPPORT_LANGUAGE_OPTION_ENABLE_SERIALIZATION_ASSERTS 0
#define NUNAVUT_SUPPORT_LANGUAGE_OPTION_ENABLE_OVERRIDE_VARIABLE_ARRAY_CAPACITY 0
#define NUNAVUT_SUPPORT_LANGUAGE_OPTION_CAST_FORMAT 2368206204

/// Nunavut returns 0 for success and < 0 for any failure. It is always adequate to check that error_value < 0
/// to detect errors or error_value == 0 for success.
///
/// Nunavut serialization will never define more than 127 errors and the reserved error numbers are [-1,-127]
/// (-128 is not used). Error code 1 is currently also not used to avoid conflicts with 3rd-party software.
///
/// Return values > 0 for Nunavut serialization are undefined.
#define NUNAVUT_SUCCESS 0
// API usage errors:
#define NUNAVUT_ERROR_INVALID_ARGUMENT                  2
#define NUNAVUT_ERROR_SERIALIZATION_BUFFER_TOO_SMALL    3
// Invalid representation (caused by bad input data, not API misuse):
#define NUNAVUT_ERROR_REPRESENTATION_BAD_ARRAY_LENGTH        10
#define NUNAVUT_ERROR_REPRESENTATION_BAD_UNION_TAG           11
#define NUNAVUT_ERROR_REPRESENTATION_BAD_DELIMITER_HEADER    12

/// Detect whether the target platform is compatible with IEEE 754.
#define NUNAVUT_PLATFORM_IEEE754_FLOAT \
    ((FLT_RADIX == 2) && (FLT_MANT_DIG == 24) && (FLT_MIN_EXP == -125) && (FLT_MAX_EXP == 128))
#define NUNAVUT_PLATFORM_IEEE754_DOUBLE \
    ((FLT_RADIX == 2) && (DBL_MANT_DIG == 53) && (DBL_MIN_EXP == -1021) && (DBL_MAX_EXP == 1024))

// This code is endianness-invariant. Use target_endianness='little' to generate little-endian-optimized code.

// ---------------------------------------------------- HELPERS ----------------------------------------------------

/// Returns the smallest value.
static inline size_t nunavutChooseMin(const size_t a, const size_t b)
{
    return (a < b) ? a : b;
}

/// Calculate the number of bits to safely copy from/to a serialized buffer.
/// Mind the units! By convention, buffer size is specified in bytes, but fragment length and offset are in bits.
///
///      buffer                                                                buffer
///      origin                                                                 end
///         [------------------------- buffer_size_bytes ------------------------]
///         [--------------- fragment_offset_bits ---------------][--- fragment_length_bits ---]
///                                                               [-- out bits --]
///
static inline size_t nunavutSaturateBufferFragmentBitLength(
    const size_t buffer_size_bytes, const size_t fragment_offset_bits, const size_t fragment_length_bits)
{
    const size_t size_bits = (size_t)buffer_size_bytes * 8U;
    const size_t tail_bits = size_bits - nunavutChooseMin(size_bits, fragment_offset_bits);
    return nunavutChooseMin(fragment_length_bits, tail_bits);
}

// ---------------------------------------------------- BIT ARRAY ----------------------------------------------------

/// Copy the specified number of bits from the source buffer into the destination buffer in accordance with the
/// DSDL bit-level serialization specification. The offsets may be arbitrary (may exceed 8 bits).
/// If both offsets are byte-aligned, the function invokes memmove() and possibly adjusts the last byte separately.
/// If the source and the destination overlap AND the offsets are not byte-aligned, the behavior is undefined.
/// If either source or destination pointers are NULL, the behavior is undefined.
/// Arguments:
///     dst             Destination buffer. Shall be at least ceil(length_bits/8) bytes large.
///     dst_offset_bits Offset in bits from the destination pointer. May exceed 8.
///     length_bits     The number of bits to copy. Both source and destination shall be large enough.
///     src             Source buffer. Shall be at least ceil(length_bits/8) bytes large.
///     src_offset_bits Offset in bits from the source pointer. May exceed 8.
static inline void nunavutCopyBits(void* const dst,
                                   const size_t dst_offset_bits,
                                   const size_t length_bits,
                                   const void* const src,
                                   const size_t src_offset_bits)
{



    if ((0U == (src_offset_bits % 8U)) && (0U == (dst_offset_bits % 8U)))  // Aligned copy, optimized, most common case.
    {
        const size_t length_bytes = (size_t)(length_bits / 8U);
        // Intentional violation of MISRA: Pointer arithmetics. This is done to remove the API constraint that
        // offsets be under 8 bits. Fewer constraints reduce the chance of API misuse.
        const uint8_t* const psrc = (src_offset_bits / 8U) + (const uint8_t*) src;  // NOSONAR NOLINT
        uint8_t*       const pdst = (dst_offset_bits / 8U) +       (uint8_t*) dst;  // NOSONAR NOLINT
        (void) memmove(pdst, psrc, length_bytes);
        const uint8_t length_mod = (uint8_t)(length_bits % 8U);
        if (0U != length_mod)  // If the length is unaligned, the last byte requires special treatment.
        {
            // Intentional violation of MISRA: Pointer arithmetics. It is unavoidable in this context.
            const uint8_t* const last_src = psrc + length_bytes;  // NOLINT NOSONAR
            uint8_t* const last_dst       = pdst + length_bytes;  // NOLINT NOSONAR

            const uint8_t mask = (uint8_t)((1U << length_mod) - 1U);
            *last_dst = (*last_dst & (uint8_t)~mask) | (*last_src & mask);
        }
    }
    else
    {
        // The algorithm was originally designed by Ben Dyer for Libuavcan v0:
        // https://github.com/OpenCyphal/libuavcan/blob/legacy-v0/libuavcan/src/marshal/uc_bit_array_copy.cpp
        // This version is modified for v1 where the bit order is the opposite.
        const uint8_t* const psrc = (const uint8_t*) src;
        uint8_t*       const pdst =       (uint8_t*) dst;
        size_t       src_off  = src_offset_bits;
        size_t       dst_off  = dst_offset_bits;
        const size_t last_bit = src_off + length_bits;


        while (last_bit > src_off)
        {
            const uint8_t src_mod = (uint8_t)(src_off % 8U);
            const uint8_t dst_mod = (uint8_t)(dst_off % 8U);
            const uint8_t max_mod = (src_mod > dst_mod) ? src_mod : dst_mod;
            const uint8_t size = (uint8_t) nunavutChooseMin(8U - max_mod, last_bit - src_off);


            // Suppress a false warning from Clang-Tidy & Sonar that size is being over-shifted. It's not.
            const uint8_t mask = (uint8_t)((((1U << size) - 1U) << dst_mod) & 0xFFU);  // NOLINT NOSONAR

            // Intentional violation of MISRA: indexing on a pointer.
            // This simplifies the implementation greatly and avoids pointer arithmetics.
            const uint8_t in = (uint8_t)((uint8_t)(psrc[src_off / 8U] >> src_mod) << dst_mod) & 0xFFU;  // NOSONAR
            // Intentional violation of MISRA: indexing on a pointer.
            // This simplifies the implementation greatly and avoids pointer arithmetics.
            const uint8_t a = pdst[dst_off / 8U] & ((uint8_t) ~mask);  // NOSONAR
            const uint8_t b = in & mask;
            // Intentional violation of MISRA: indexing on a pointer.
            // This simplifies the implementation greatly and avoids pointer arithmetics.
            pdst[dst_off / 8U] = a | b;  // NOSONAR
            src_off += size;
            dst_off += size;
        }

    }
}

/// This function is intended for deserialization of contiguous sequences of zero-cost primitives.
/// It extracts (len_bits) bits that are offset by (off_bits) from the origin of (buf) whose size is (buf_size_bytes).
/// If the requested (len_bits+off_bits) overruns the buffer, the missing bits are implicitly zero-extended.
/// If (len_bits % 8 != 0), the output buffer is right-zero-padded up to the next byte boundary.
/// If (off_bits % 8 == 0), the operation is delegated to memmove(); otherwise, a much slower unaligned bit copy
/// algorithm is employed. See @ref nunavutCopyBits() for further details.
static inline void nunavutGetBits(void* const output,
                                  const void* const buf,
                                  const size_t buf_size_bytes,
                                  const size_t off_bits,
                                  const size_t len_bits)
{


    const size_t sat_bits = nunavutSaturateBufferFragmentBitLength(buf_size_bytes, off_bits, len_bits);
    // Apply implicit zero extension. Normally, this is a no-op unless (len_bits > sat_bits) or (len_bits % 8 != 0).
    // The former case ensures that if we're copying <8 bits, the MSB in the destination will be zeroed out.
    (void) memset(((uint8_t*)output) + (sat_bits / 8U), 0, ((len_bits + 7U) / 8U) - (sat_bits / 8U));
    nunavutCopyBits(output, 0U, sat_bits, buf, off_bits);
}

// ---------------------------------------------------- INTEGER ----------------------------------------------------

/// Serialize a DSDL field value at the specified bit offset from the beginning of the destination buffer.
/// The behavior is undefined if the input pointer is NULL. The time complexity is linear of the bit length.
/// One-bit-wide signed integers are processed without raising an error but the result is unspecified.
///
/// Arguments:
///     buf             Destination buffer where the result will be stored.
///     buf_size_bytes  Size of the above, in bytes.
///     off_bits        Offset, in bits, from the beginning of the buffer. May exceed one byte.
///     value           The value itself (in case of integers it is promoted to 64-bit for unification).
///     len_bits        Length of the serialized representation, in bits. Zero has no effect. Values >64 bit saturated.

static inline int8_t nunavutSetBit(
    uint8_t* const buf,
    const size_t buf_size_bytes,
    const size_t off_bits,
    const bool value)
{

    if ((buf_size_bytes * 8) <= off_bits)
    {
        return -NUNAVUT_ERROR_SERIALIZATION_BUFFER_TOO_SMALL;
    }
    const uint8_t val = value ? 1U : 0U;
    nunavutCopyBits(buf, off_bits, 1U, &val, 0U);
    return NUNAVUT_SUCCESS;
}

static inline int8_t nunavutSetUxx(
    uint8_t* const buf,
    const size_t buf_size_bytes,
    const size_t off_bits,
    const uint64_t value,
    const uint8_t len_bits)
{
    static_assert(64U == (sizeof(uint64_t) * 8U), "Unexpected size of uint64_t");

    if ((buf_size_bytes * 8) < (off_bits + len_bits))
    {
        return -NUNAVUT_ERROR_SERIALIZATION_BUFFER_TOO_SMALL;
    }
    const size_t saturated_len_bits = nunavutChooseMin(len_bits, 64U);
    const uint8_t tmp[sizeof(uint64_t)] = {
        (uint8_t)((value >> 0U) & 0xFFU),
        (uint8_t)((value >> 8U) & 0xFFU),
        (uint8_t)((value >> 16U) & 0xFFU),
        (uint8_t)((value >> 24U) & 0xFFU),
        (uint8_t)((value >> 32U) & 0xFFU),
        (uint8_t)((value >> 40U) & 0xFFU),
        (uint8_t)((value >> 48U) & 0xFFU),
        (uint8_t)((value >> 56U) & 0xFFU),
    };
    nunavutCopyBits(buf, off_bits, saturated_len_bits, &tmp[0], 0U);
    return NUNAVUT_SUCCESS;
}

static inline int8_t nunavutSetIxx(
    uint8_t* const buf,
    const size_t buf_size_bytes,
    const size_t off_bits,
    const int64_t value,
    const uint8_t len_bits)
{
    // The naive sign conversion is safe and portable according to the C standard:
    // 6.3.1.3.3: if the new type is unsigned, the value is converted by repeatedly adding or subtracting one more
    // than the maximum value that can be represented in the new type until the value is in the range of the new type.
    return nunavutSetUxx(buf, buf_size_bytes, off_bits, (uint64_t) value, len_bits);
}

/// Deserialize a DSDL field value located at the specified bit offset from the beginning of the source buffer.
/// If the deserialized value extends beyond the end of the buffer, the missing bits are taken as zero, as required
/// by the DSDL specification (see Implicit Zero Extension Rule, IZER).
///
/// If len_bits is greater than the return type, extra bits will be truncated per standard narrowing conversion rules.
/// If len_bits is shorter than the return type, missing bits will be zero per standard integer promotion rules.
/// Essentially, for integers, it would be enough to have 64-bit versions only; narrower variants exist only to avoid
/// narrowing type conversions of the result and for some performance gains.
///
/// The behavior is undefined if the input pointer is NULL. The time complexity is linear of the bit length.
/// One-bit-wide signed integers are processed without raising an error but the result is unspecified.
///
/// Arguments:
///     buf             Source buffer where the serialized representation will be read from.
///     buf_size_bytes  The size of the source buffer, in bytes. Reads past this limit will return zero bits.
///     off_bits        Offset, in bits, from the beginning of the buffer. May exceed one byte.
///     len_bits        Length of the serialized representation, in bits. Zero returns 0. Out-of-range values saturated.

static inline uint8_t nunavutGetU8(const uint8_t* const buf,
                                   const size_t buf_size_bytes,
                                   const size_t off_bits,
                                   const uint8_t len_bits);

static inline bool nunavutGetBit(const uint8_t* const buf,
                                 const size_t buf_size_bytes,
                                 const size_t off_bits)
{
    return 1U == nunavutGetU8(buf, buf_size_bytes, off_bits, 1U);
}

static inline uint8_t nunavutGetU8(const uint8_t* const buf,
                                   const size_t buf_size_bytes,
                                   const size_t off_bits,
                                   const uint8_t len_bits)
{

    const size_t bits = nunavutSaturateBufferFragmentBitLength(buf_size_bytes, off_bits, nunavutChooseMin(len_bits, 8U));

    uint8_t val = 0;
    nunavutCopyBits(&val, 0U, bits, buf, off_bits);
    return val;
}

static inline uint16_t nunavutGetU16(const uint8_t* const buf,
                                     const size_t buf_size_bytes,
                                     const size_t off_bits,
                                     const uint8_t len_bits)
{

    const size_t bits = nunavutSaturateBufferFragmentBitLength(buf_size_bytes, off_bits, nunavutChooseMin(len_bits, 16U));

    uint8_t tmp[sizeof(uint16_t)] = {0};
    nunavutCopyBits(&tmp[0], 0U, bits, buf, off_bits);
    return (uint16_t)(tmp[0] | (uint16_t)(((uint16_t) tmp[1]) << 8U));
}

static inline uint32_t nunavutGetU32(const uint8_t* const buf,
                                     const size_t buf_size_bytes,
                                     const size_t off_bits,
                                     const uint8_t len_bits)
{

    const size_t bits = nunavutSaturateBufferFragmentBitLength(buf_size_bytes, off_bits, nunavutChooseMin(len_bits, 32U));

    uint8_t tmp[sizeof(uint32_t)] = {0};
    nunavutCopyBits(&tmp[0], 0U, bits, buf, off_bits);
    return (uint32_t)(tmp[0] | ((uint32_t) tmp[1] << 8U) | ((uint32_t) tmp[2] << 16U) | ((uint32_t) tmp[3] << 24U));
}

static inline uint64_t nunavutGetU64(const uint8_t* const buf,
                                     const size_t buf_size_bytes,
                                     const size_t off_bits,
                                     const uint8_t len_bits)
{

    const size_t bits = nunavutSaturateBufferFragmentBitLength(buf_size_bytes, off_bits, nunavutChooseMin(len_bits, 64U));

    uint8_t tmp[sizeof(uint64_t)] = {0};
    nunavutCopyBits(&tmp[0], 0U, bits, buf, off_bits);
    return (uint64_t)(tmp[0] |
                      ((uint64_t) tmp[1] << 8U) |
                      ((uint64_t) tmp[2] << 16U) |
                      ((uint64_t) tmp[3] << 24U) |
                      ((uint64_t) tmp[4] << 32U) |
                      ((uint64_t) tmp[5] << 40U) |
                      ((uint64_t) tmp[6] << 48U) |
                      ((uint64_t) tmp[7] << 56U));
}

static inline int8_t nunavutGetI8(const uint8_t* const buf,
                                  const size_t buf_size_bytes,
                                  const size_t off_bits,
                                  const uint8_t len_bits)
{
    const uint8_t sat = (uint8_t) nunavutChooseMin(len_bits, 8U);
    uint8_t       val = nunavutGetU8(buf, buf_size_bytes, off_bits, sat);
    const bool    neg = (sat > 0U) && ((val & (1ULL << (sat - 1U))) != 0U);
    val = ((sat < 8U) && neg) ? (uint8_t)(val | ~((1U << sat) - 1U)) : val;  // Sign extension
    return neg ? (int8_t)((-(int8_t)(uint8_t) ~val) - 1) : (int8_t) val;
}

static inline int16_t nunavutGetI16(const uint8_t* const buf,
                                    const size_t buf_size_bytes,
                                    const size_t off_bits,
                                    const uint8_t len_bits)
{
    const uint8_t sat = (uint8_t) nunavutChooseMin(len_bits, 16U);
    uint16_t      val = nunavutGetU16(buf, buf_size_bytes, off_bits, sat);
    const bool    neg = (sat > 0U) && ((val & (1ULL << (sat - 1U))) != 0U);
    val = ((sat < 16U) && neg) ? (uint16_t)(val | ~((1U << sat) - 1U)) : val;  // Sign extension
    return neg ? (int16_t)((-(int16_t)(uint16_t) ~val) - 1) : (int16_t) val;
}

static inline int32_t nunavutGetI32(const uint8_t* const buf,
                                    const size_t buf_size_bytes,
                                    const size_t off_bits,
                                    const uint8_t len_bits)
{
    const uint8_t sat = (uint8_t) nunavutChooseMin(len_bits, 32U);
    uint32_t      val = nunavutGetU32(buf, buf_size_bytes, off_bits, sat);
    const bool    neg = (sat > 0U) && ((val & (1ULL << (sat - 1U))) != 0U);
    val = ((sat < 32U) && neg) ? (uint32_t)(val | ~((1UL << sat) - 1U)) : val;  // Sign extension
    return neg ? (int32_t)((-(int32_t) ~val) - 1) : (int32_t) val;
}

static inline int64_t nunavutGetI64(const uint8_t* const buf,
                                    const size_t buf_size_bytes,
                                    const size_t off_bits,
                                    const uint8_t len_bits)
{
    const uint8_t sat = (uint8_t) nunavutChooseMin(len_bits, 64U);
    uint64_t      val = nunavutGetU64(buf, buf_size_bytes, off_bits, sat);
    const bool    neg = (sat > 0U) && ((val & (1ULL << (sat - 1U))) != 0U);
    val = ((sat < 64U) && neg) ? (uint64_t)(val | ~((1ULL << sat) - 1U)) : val;  // Sign extension
    return neg ? (int64_t)((-(int64_t) ~val) - 1) : (int64_t) val;
}

// ---------------------------------------------------- FLOAT16 ----------------------------------------------------

static_assert(NUNAVUT_PLATFORM_IEEE754_FLOAT,
              "The target platform does not support IEEE754 floating point operations.");
static_assert(32U == (sizeof(float) * 8U), "Unsupported floating point model");

/// Converts a single-precision float into the binary representation of the value as a half-precision IEEE754 value.
static inline uint16_t nunavutFloat16Pack(const float value)
{
    typedef union  // NOSONAR
    {
        uint32_t bits;
        float real;
    } Float32Bits;

    // The no-lint statements suppress the warning about the use of union. This is required for low-level bit access.
    const uint32_t round_mask = ~(uint32_t) 0x0FFFU;
    Float32Bits    f32inf;  // NOSONAR
    Float32Bits    f16inf;  // NOSONAR
    Float32Bits    magic;   // NOSONAR
    Float32Bits    in;      // NOSONAR
    f32inf.bits = ((uint32_t) 255U) << 23U;
    f16inf.bits = ((uint32_t) 31U) << 23U;
    magic.bits = ((uint32_t) 15U) << 23U;
    in.real = value;
    const uint32_t sign = in.bits & (((uint32_t) 1U) << 31U);
    in.bits ^= sign;
    uint16_t out = 0;
    if (in.bits >= f32inf.bits)
    {
        if ((in.bits & 0x7FFFFFUL) != 0)
        {
            out = 0x7E00U;
        }
        else
        {
            out = (in.bits > f32inf.bits) ? (uint16_t) 0x7FFFU : (uint16_t) 0x7C00U;
        }
    }
    else
    {
        in.bits &= round_mask;
        in.real *= magic.real;
        in.bits -= round_mask;
        if (in.bits > f16inf.bits)
        {
            in.bits = f16inf.bits;
        }
        out = (uint16_t)(in.bits >> 13U);
    }
    out |= (uint16_t)(sign >> 16U);
    return out;
}

static inline float nunavutFloat16Unpack(const uint16_t value)
{
    typedef union  // NOSONAR
    {
        uint32_t bits;
        float real;
    } Float32Bits;

    // The no-lint statements suppress the warning about the use of union. This is required for low-level bit access.
    Float32Bits magic;    // NOSONAR
    Float32Bits inf_nan;  // NOSONAR
    Float32Bits out;      // NOSONAR
    magic.bits = ((uint32_t) 0xEFU) << 23U;
    inf_nan.bits = ((uint32_t) 0x8FU) << 23U;
    out.bits = ((uint32_t)(value & 0x7FFFU)) << 13U;
    out.real *= magic.real;
    if (out.real >= inf_nan.real)
    {
        out.bits |= ((uint32_t) 0xFFU) << 23U;
    }
    out.bits |= ((uint32_t)(value & 0x8000U)) << 16U;
    return out.real;
}

static inline int8_t nunavutSetF16(
    uint8_t* const buf,
    const size_t buf_size_bytes,
    const size_t off_bits,
    const float value)
{
    return nunavutSetUxx(buf, buf_size_bytes, off_bits, nunavutFloat16Pack(value), 16U);
}

static inline float nunavutGetF16(
    const uint8_t* const buf,
    const size_t buf_size_bytes,
    const size_t off_bits)
{
    return nunavutFloat16Unpack(nunavutGetU16(buf, buf_size_bytes, off_bits, 16U));
}

// ---------------------------------------------------- FLOAT32 ----------------------------------------------------

static_assert(NUNAVUT_PLATFORM_IEEE754_FLOAT,
              "The target platform does not support IEEE754 floating point operations.");
static_assert(32U == (sizeof(float) * 8U), "Unsupported floating point model");

static inline int8_t nunavutSetF32(
    uint8_t* const buf,
    const size_t buf_size_bytes,
    const size_t off_bits,
    const float value)
{
    // Intentional violation of MISRA: use union to perform fast conversion from an IEEE 754-compatible native
    // representation into a serializable integer. The assumptions about the target platform properties are made
    // clear. In the future we may add a more generic conversion that is platform-invariant.
    union  // NOSONAR
    {
        float fl;
        uint32_t in;
    } const tmp = {value};  // NOSONAR
    return nunavutSetUxx(buf, buf_size_bytes, off_bits, tmp.in, sizeof(tmp) * 8U);
}

static inline float nunavutGetF32(
    const uint8_t* const buf,
    const size_t buf_size_bytes,
    const size_t off_bits)
{
    // Intentional violation of MISRA: use union to perform fast conversion to an IEEE 754-compatible native
    // representation into a serializable integer. The assumptions about the target platform properties are made
    // clear. In the future we may add a more generic conversion that is platform-invariant.
    union  // NOSONAR
    {
        uint32_t in;
        float fl;
    } const tmp = {nunavutGetU32(buf, buf_size_bytes, off_bits, 32U)};
    return tmp.fl;
}

// ---------------------------------------------------- FLOAT64 ----------------------------------------------------

static_assert(NUNAVUT_PLATFORM_IEEE754_DOUBLE,
              "The target platform does not support IEEE754 double-precision floating point operations.");
static_assert(64U == (sizeof(double) * 8U), "Unsupported floating point model");

static inline int8_t nunavutSetF64(
    uint8_t* const buf,
    const size_t buf_size_bytes,
    const size_t off_bits,
    const double value)
{
    // Intentional violation of MISRA: use union to perform fast conversion from an IEEE 754-compatible native
    // representation into a serializable integer. The assumptions about the target platform properties are made
    // clear. In the future we may add a more generic conversion that is platform-invariant.
    union  // NOSONAR
    {
        double fl;
        uint64_t in;
    } const tmp = {value};  // NOSONAR
    return nunavutSetUxx(buf, buf_size_bytes, off_bits, tmp.in, sizeof(tmp) * 8U);
}

static inline double nunavutGetF64(
    const uint8_t* const buf,
    const size_t buf_size_bytes,
    const size_t off_bits)
{
    // Intentional violation of MISRA: use union to perform fast conversion to an IEEE 754-compatible native
    // representation into a serializable integer. The assumptions about the target platform properties are made
    // clear. In the future we may add a more generic conversion that is platform-invariant.
    union  // NOSONAR
    {
        uint64_t in;
        double fl;
    } const tmp = {nunavutGetU64(buf, buf_size_bytes, off_bits, 64U)};
    return tmp.fl;
}

#ifdef __cplusplus
}
#endif

#endif // NUNAVUT_SUPPORT_SERIALIZATION_H_INCLUDED
