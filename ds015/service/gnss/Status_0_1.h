// This is an AUTO-GENERATED UAVCAN DSDL data type implementation. Curious? See https://opencyphal.org.
// You shouldn't attempt to edit this file.
//
// Checking this file under version control is not recommended unless it is used as part of a high-SIL
// safety-critical codebase. The typical usage scenario is to generate it as part of the build process.
//
// To avoid conflicts with definitions given in the source DSDL file, all entities created by the code generator
// are named with an underscore at the end, like foo_bar_().
//
// Generator:     nunavut-1.8.0 (serialization was enabled)
// Source file:   /home/nex/PX4-Autopilot/src/drivers/cyphal/ds015/service/gnss/Status.0.1.dsdl
// Generated at:  2024-11-12 20:17:26.669749 UTC
// Is deprecated: no
// Fixed port-ID: None
// Full name:     ds015.service.gnss.Status
// Version:       0.1
//
// Platform
//     python_implementation:  CPython
//     python_version:  3.10.12
//     python_release_level:  final
//     python_build:  ('main', 'Sep 11 2024 15:47:36')
//     python_compiler:  GCC 11.4.0
//     python_revision:
//     python_xoptions:  {}
//     runtime_platform:  Linux-6.8.0-48-generic-x86_64-with-glibc2.35
//
// Language Options
//     target_endianness:  any
//     omit_float_serialization_support:  False
//     enable_serialization_asserts:  False
//     enable_override_variable_array_capacity:  False
//     cast_format:  (({type}) {value})

#ifndef DS015_SERVICE_GNSS_STATUS_0_1_INCLUDED_
#define DS015_SERVICE_GNSS_STATUS_0_1_INCLUDED_

#include <nunavut/support/serialization.h>
#include <stdint.h>
#include <stdlib.h>

static_assert( NUNAVUT_SUPPORT_LANGUAGE_OPTION_TARGET_ENDIANNESS == 1693710260,
              "/home/nex/PX4-Autopilot/src/drivers/cyphal/ds015/service/gnss/Status.0.1.dsdl is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not allowed." );
static_assert( NUNAVUT_SUPPORT_LANGUAGE_OPTION_OMIT_FLOAT_SERIALIZATION_SUPPORT == 0,
              "/home/nex/PX4-Autopilot/src/drivers/cyphal/ds015/service/gnss/Status.0.1.dsdl is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not allowed." );
static_assert( NUNAVUT_SUPPORT_LANGUAGE_OPTION_ENABLE_SERIALIZATION_ASSERTS == 0,
              "/home/nex/PX4-Autopilot/src/drivers/cyphal/ds015/service/gnss/Status.0.1.dsdl is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not allowed." );
static_assert( NUNAVUT_SUPPORT_LANGUAGE_OPTION_ENABLE_OVERRIDE_VARIABLE_ARRAY_CAPACITY == 0,
              "/home/nex/PX4-Autopilot/src/drivers/cyphal/ds015/service/gnss/Status.0.1.dsdl is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not allowed." );
static_assert( NUNAVUT_SUPPORT_LANGUAGE_OPTION_CAST_FORMAT == 2368206204,
              "/home/nex/PX4-Autopilot/src/drivers/cyphal/ds015/service/gnss/Status.0.1.dsdl is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not allowed." );

#ifdef __cplusplus
extern "C" {
#endif

/// This type does not have a fixed port-ID. See https://forum.opencyphal.org/t/choosing-message-and-service-ids/889
#define ds015_service_gnss_Status_0_1_HAS_FIXED_PORT_ID_ false

#define ds015_service_gnss_Status_0_1_FULL_NAME_             "ds015.service.gnss.Status"
#define ds015_service_gnss_Status_0_1_FULL_NAME_AND_VERSION_ "ds015.service.gnss.Status.0.1"

/// Extent is the minimum amount of memory required to hold any serialized representation of any compatible
/// version of the data type; or, on other words, it is the the maximum possible size of received objects of this type.
/// The size is specified in bytes (rather than bits) because by definition, extent is an integer number of bytes long.
/// When allocating a deserialization (RX) buffer for this data type, it should be at least extent bytes large.
/// When allocating a serialization (TX) buffer, it is safe to use the size of the largest serialized representation
/// instead of the extent because it provides a tighter bound of the object size; it is safe because the concrete type
/// is always known during serialization (unlike deserialization). If not sure, use extent everywhere.
#define ds015_service_gnss_Status_0_1_EXTENT_BYTES_                    2UL
#define ds015_service_gnss_Status_0_1_SERIALIZATION_BUFFER_SIZE_BYTES_ 2UL
static_assert(ds015_service_gnss_Status_0_1_EXTENT_BYTES_ >= ds015_service_gnss_Status_0_1_SERIALIZATION_BUFFER_SIZE_BYTES_,
              "Internal constraint violation");

/// saturated uint2 STATUS_NO_FIX = 0
#define ds015_service_gnss_Status_0_1_STATUS_NO_FIX (0U)
/// saturated uint2 STATUS_TIME_ONLY = 1
#define ds015_service_gnss_Status_0_1_STATUS_TIME_ONLY (1U)
/// saturated uint2 STATUS_2D_FIX = 2
#define ds015_service_gnss_Status_0_1_STATUS_2D_FIX (2U)
/// saturated uint2 STATUS_3D_FIX = 3
#define ds015_service_gnss_Status_0_1_STATUS_3D_FIX (3U)
/// saturated uint2 MODE_SINGLE = 0
#define ds015_service_gnss_Status_0_1_MODE_SINGLE (0U)
/// saturated uint2 MODE_DGPS = 1
#define ds015_service_gnss_Status_0_1_MODE_DGPS (1U)
/// saturated uint2 MODE_RTK = 2
#define ds015_service_gnss_Status_0_1_MODE_RTK (2U)
/// saturated uint2 MODE_PPP = 3
#define ds015_service_gnss_Status_0_1_MODE_PPP (3U)
/// saturated uint2 SUB_MODE_DGPS_OTHER = 0
#define ds015_service_gnss_Status_0_1_SUB_MODE_DGPS_OTHER (0U)
/// saturated uint2 SUB_MODE_DGPS_SBAS = 1
#define ds015_service_gnss_Status_0_1_SUB_MODE_DGPS_SBAS (1U)
/// saturated uint2 SUB_MODE_RTK_FLOAT = 0
#define ds015_service_gnss_Status_0_1_SUB_MODE_RTK_FLOAT (0U)
/// saturated uint2 SUB_MODE_RTK_FIXED = 1
#define ds015_service_gnss_Status_0_1_SUB_MODE_RTK_FIXED (1U)
/// saturated uint2 JAMMING_STATE_UNKNOWN = 0
#define ds015_service_gnss_Status_0_1_JAMMING_STATE_UNKNOWN (0U)
/// saturated uint2 JAMMING_STATE_OK = 1
#define ds015_service_gnss_Status_0_1_JAMMING_STATE_OK (1U)
/// saturated uint2 JAMMING_STATE_WARNING = 2
#define ds015_service_gnss_Status_0_1_JAMMING_STATE_WARNING (2U)
/// saturated uint2 JAMMING_STATE_CRITICAL = 3
#define ds015_service_gnss_Status_0_1_JAMMING_STATE_CRITICAL (3U)
/// saturated uint2 SPOOFING_STATE_UNKNOWN = 0
#define ds015_service_gnss_Status_0_1_SPOOFING_STATE_UNKNOWN (0U)
/// saturated uint2 SPOOFING_STATE_NONE = 1
#define ds015_service_gnss_Status_0_1_SPOOFING_STATE_NONE (1U)
/// saturated uint2 SPOOFING_STATE_INDICATED = 2
#define ds015_service_gnss_Status_0_1_SPOOFING_STATE_INDICATED (2U)
/// saturated uint2 SPOOFING_STATE_MULTIPLE = 3
#define ds015_service_gnss_Status_0_1_SPOOFING_STATE_MULTIPLE (3U)

typedef struct
{
    /// truncated uint2 status
    uint8_t status;

    /// truncated uint2 mode
    uint8_t mode;

    /// truncated uint2 sub_mode
    uint8_t sub_mode;

    /// truncated uint2 jamming_state
    uint8_t jamming_state;

    /// truncated uint2 spoofing_state
    uint8_t spoofing_state;
} ds015_service_gnss_Status_0_1;

/// Serialize an instance into the provided buffer.
/// The lifetime of the resulting serialized representation is independent of the original instance.
/// This method may be slow for large objects (e.g., images, point clouds, radar samples), so in a later revision
/// we may define a zero-copy alternative that keeps references to the original object where possible.
///
/// @param obj      The object to serialize.
///
/// @param buffer   The destination buffer. There are no alignment requirements.
///                 @see ds015_service_gnss_Status_0_1_SERIALIZATION_BUFFER_SIZE_BYTES_
///
/// @param inout_buffer_size_bytes  When calling, this is a pointer to the size of the buffer in bytes.
///                                 Upon return this value will be updated with the size of the constructed serialized
///                                 representation (in bytes); this value is then to be passed over to the transport
///                                 layer. In case of error this value is undefined.
///
/// @returns Negative on error, zero on success.
static inline int8_t ds015_service_gnss_Status_0_1_serialize_(
    const ds015_service_gnss_Status_0_1* const obj, uint8_t* const buffer,  size_t* const inout_buffer_size_bytes)
{
    if ((obj == NULL) || (buffer == NULL) || (inout_buffer_size_bytes == NULL))
    {
        return -NUNAVUT_ERROR_INVALID_ARGUMENT;
    }


    const size_t capacity_bytes = *inout_buffer_size_bytes;
    if ((8U * (size_t) capacity_bytes) < 16UL)
    {
        return -NUNAVUT_ERROR_SERIALIZATION_BUFFER_TOO_SMALL;
    }
    // Notice that fields that are not an integer number of bytes long may overrun the space allocated for them
    // in the serialization buffer up to the next byte boundary. This is by design and is guaranteed to be safe.
    size_t offset_bits = 0U;





    {   // truncated uint2 status
        buffer[offset_bits / 8U] = (uint8_t)(obj->status);  // C std, 6.3.1.3 Signed and unsigned integers
        offset_bits += 2U;
    }




    {   // truncated uint2 mode
        const int8_t _err0_ = nunavutSetUxx(&buffer[0], capacity_bytes, offset_bits, obj->mode, 2U);
        if (_err0_ < 0)
        {
            return _err0_;
        }
        offset_bits += 2U;
    }




    {   // truncated uint2 sub_mode
        const int8_t _err1_ = nunavutSetUxx(&buffer[0], capacity_bytes, offset_bits, obj->sub_mode, 2U);
        if (_err1_ < 0)
        {
            return _err1_;
        }
        offset_bits += 2U;
    }




    {   // truncated uint2 jamming_state
        const int8_t _err2_ = nunavutSetUxx(&buffer[0], capacity_bytes, offset_bits, obj->jamming_state, 2U);
        if (_err2_ < 0)
        {
            return _err2_;
        }
        offset_bits += 2U;
    }




    {   // truncated uint2 spoofing_state
        buffer[offset_bits / 8U] = (uint8_t)(obj->spoofing_state);  // C std, 6.3.1.3 Signed and unsigned integers
        offset_bits += 2U;
    }


    if (offset_bits % 8U != 0U)  // Pad to 8 bits. TODO: Eliminate redundant padding checks.
    {
        const uint8_t _pad0_ = (uint8_t)(8U - offset_bits % 8U);
        const int8_t _err3_ = nunavutSetUxx(&buffer[0], capacity_bytes, offset_bits, 0U, _pad0_);  // Optimize?
        if (_err3_ < 0)
        {
            return _err3_;
        }
        offset_bits += _pad0_;
    }
    // It is assumed that we know the exact type of the serialized entity, hence we expect the size to match.




    *inout_buffer_size_bytes = (size_t) (offset_bits / 8U);

    return NUNAVUT_SUCCESS;
}

/// Deserialize an instance from the provided buffer.
/// The lifetime of the resulting object is independent of the original buffer.
/// This method may be slow for large objects (e.g., images, point clouds, radar samples), so in a later revision
/// we may define a zero-copy alternative that keeps references to the original buffer where possible.
///
/// @param obj      The object to update from the provided serialized representation.
///
/// @param buffer   The source buffer containing the serialized representation. There are no alignment requirements.
///                 If the buffer is shorter or longer than expected, it will be implicitly zero-extended or truncated,
///                 respectively; see Specification for "implicit zero extension" and "implicit truncation" rules.
///
/// @param inout_buffer_size_bytes  When calling, this is a pointer to the size of the supplied serialized
///                                 representation, in bytes. Upon return this value will be updated with the
///                                 size of the consumed fragment of the serialized representation (in bytes),
///                                 which may be smaller due to the implicit truncation rule, but it is guaranteed
///                                 to never exceed the original buffer size even if the implicit zero extension rule
///                                 was activated. In case of error this value is undefined.
///
/// @returns Negative on error, zero on success.
static inline int8_t ds015_service_gnss_Status_0_1_deserialize_(
    ds015_service_gnss_Status_0_1* const out_obj, const uint8_t* buffer, size_t* const inout_buffer_size_bytes)
{
    if ((out_obj == NULL) || (inout_buffer_size_bytes == NULL) || ((buffer == NULL) && (0 != *inout_buffer_size_bytes)))
    {
        return -NUNAVUT_ERROR_INVALID_ARGUMENT;
    }
    if (buffer == NULL)
    {
        buffer = (const uint8_t*)"";
    }


    const size_t capacity_bytes = *inout_buffer_size_bytes;
    const size_t capacity_bits = capacity_bytes * (size_t) 8U;
    size_t offset_bits = 0U;





    // truncated uint2 status
    if ((offset_bits + 2U) <= capacity_bits)
    {
        out_obj->status = buffer[offset_bits / 8U] & 3U;
    }
    else
    {
        out_obj->status = 0U;
    }
    offset_bits += 2U;




    // truncated uint2 mode
    out_obj->mode = nunavutGetU8(&buffer[0], capacity_bytes, offset_bits, 2);
    offset_bits += 2U;




    // truncated uint2 sub_mode
    out_obj->sub_mode = nunavutGetU8(&buffer[0], capacity_bytes, offset_bits, 2);
    offset_bits += 2U;




    // truncated uint2 jamming_state
    out_obj->jamming_state = nunavutGetU8(&buffer[0], capacity_bytes, offset_bits, 2);
    offset_bits += 2U;




    // truncated uint2 spoofing_state
    if ((offset_bits + 2U) <= capacity_bits)
    {
        out_obj->spoofing_state = buffer[offset_bits / 8U] & 3U;
    }
    else
    {
        out_obj->spoofing_state = 0U;
    }
    offset_bits += 2U;


    offset_bits = (offset_bits + 7U) & ~(size_t) 7U;  // Align on 8 bits.

    *inout_buffer_size_bytes = (size_t) (nunavutChooseMin(offset_bits, capacity_bits) / 8U);


    return NUNAVUT_SUCCESS;
}

/// Initialize an instance to default values. Does nothing if @param out_obj is NULL.
/// This function intentionally leaves inactive elements uninitialized; for example, members of a variable-length
/// array beyond its length are left uninitialized; aliased union memory that is not used by the first union field
/// is left uninitialized, etc. If full zero-initialization is desired, just use memset(&obj, 0, sizeof(obj)).
static inline void ds015_service_gnss_Status_0_1_initialize_(ds015_service_gnss_Status_0_1* const out_obj)
{
    if (out_obj != NULL)
    {
        size_t size_bytes = 0;
        const uint8_t buf = 0;
        const int8_t err = ds015_service_gnss_Status_0_1_deserialize_(out_obj, &buf, &size_bytes);

        (void) err;
    }
}



#ifdef __cplusplus
}
#endif
#endif // DS015_SERVICE_GNSS_STATUS_0_1_INCLUDED_