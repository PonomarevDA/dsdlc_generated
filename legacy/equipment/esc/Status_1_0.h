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
// Source file:   /home/nex/PX4-Autopilot/src/drivers/cyphal/legacy_data_types/legacy/equipment/esc/Status.1.0.uavcan
// Generated at:  2024-11-12 20:17:27.328925 UTC
// Is deprecated: no
// Fixed port-ID: None
// Full name:     legacy.equipment.esc.Status
// Version:       1.0
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

#ifndef LEGACY_EQUIPMENT_ESC_STATUS_1_0_INCLUDED_
#define LEGACY_EQUIPMENT_ESC_STATUS_1_0_INCLUDED_

#include <nunavut/support/serialization.h>
#include <stdint.h>
#include <stdlib.h>

static_assert( NUNAVUT_SUPPORT_LANGUAGE_OPTION_TARGET_ENDIANNESS == 1693710260,
              "/home/nex/PX4-Autopilot/src/drivers/cyphal/legacy_data_types/legacy/equipment/esc/Status.1.0.uavcan is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not allowed." );
static_assert( NUNAVUT_SUPPORT_LANGUAGE_OPTION_OMIT_FLOAT_SERIALIZATION_SUPPORT == 0,
              "/home/nex/PX4-Autopilot/src/drivers/cyphal/legacy_data_types/legacy/equipment/esc/Status.1.0.uavcan is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not allowed." );
static_assert( NUNAVUT_SUPPORT_LANGUAGE_OPTION_ENABLE_SERIALIZATION_ASSERTS == 0,
              "/home/nex/PX4-Autopilot/src/drivers/cyphal/legacy_data_types/legacy/equipment/esc/Status.1.0.uavcan is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not allowed." );
static_assert( NUNAVUT_SUPPORT_LANGUAGE_OPTION_ENABLE_OVERRIDE_VARIABLE_ARRAY_CAPACITY == 0,
              "/home/nex/PX4-Autopilot/src/drivers/cyphal/legacy_data_types/legacy/equipment/esc/Status.1.0.uavcan is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not allowed." );
static_assert( NUNAVUT_SUPPORT_LANGUAGE_OPTION_CAST_FORMAT == 2368206204,
              "/home/nex/PX4-Autopilot/src/drivers/cyphal/legacy_data_types/legacy/equipment/esc/Status.1.0.uavcan is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not allowed." );

#ifdef __cplusplus
extern "C" {
#endif

/// This type does not have a fixed port-ID. See https://forum.opencyphal.org/t/choosing-message-and-service-ids/889
#define legacy_equipment_esc_Status_1_0_HAS_FIXED_PORT_ID_ false

#define legacy_equipment_esc_Status_1_0_FULL_NAME_             "legacy.equipment.esc.Status"
#define legacy_equipment_esc_Status_1_0_FULL_NAME_AND_VERSION_ "legacy.equipment.esc.Status.1.0"

/// Extent is the minimum amount of memory required to hold any serialized representation of any compatible
/// version of the data type; or, on other words, it is the the maximum possible size of received objects of this type.
/// The size is specified in bytes (rather than bits) because by definition, extent is an integer number of bytes long.
/// When allocating a deserialization (RX) buffer for this data type, it should be at least extent bytes large.
/// When allocating a serialization (TX) buffer, it is safe to use the size of the largest serialized representation
/// instead of the extent because it provides a tighter bound of the object size; it is safe because the concrete type
/// is always known during serialization (unlike deserialization). If not sure, use extent everywhere.
#define legacy_equipment_esc_Status_1_0_EXTENT_BYTES_                    64UL
#define legacy_equipment_esc_Status_1_0_SERIALIZATION_BUFFER_SIZE_BYTES_ 14UL
static_assert(legacy_equipment_esc_Status_1_0_EXTENT_BYTES_ >= legacy_equipment_esc_Status_1_0_SERIALIZATION_BUFFER_SIZE_BYTES_,
              "Internal constraint violation");

typedef struct
{
    /// saturated uint32 error_count
    uint32_t error_count;

    /// saturated float16 voltage
    float voltage;

    /// saturated float16 current
    float current;

    /// saturated float16 temperature
    float temperature;

    /// saturated int18 rpm
    int32_t rpm;

    /// saturated uint7 power_rating_pct
    uint8_t power_rating_pct;

    /// saturated uint5 esc_index
    uint8_t esc_index;
} legacy_equipment_esc_Status_1_0;

/// Serialize an instance into the provided buffer.
/// The lifetime of the resulting serialized representation is independent of the original instance.
/// This method may be slow for large objects (e.g., images, point clouds, radar samples), so in a later revision
/// we may define a zero-copy alternative that keeps references to the original object where possible.
///
/// @param obj      The object to serialize.
///
/// @param buffer   The destination buffer. There are no alignment requirements.
///                 @see legacy_equipment_esc_Status_1_0_SERIALIZATION_BUFFER_SIZE_BYTES_
///
/// @param inout_buffer_size_bytes  When calling, this is a pointer to the size of the buffer in bytes.
///                                 Upon return this value will be updated with the size of the constructed serialized
///                                 representation (in bytes); this value is then to be passed over to the transport
///                                 layer. In case of error this value is undefined.
///
/// @returns Negative on error, zero on success.
static inline int8_t legacy_equipment_esc_Status_1_0_serialize_(
    const legacy_equipment_esc_Status_1_0* const obj, uint8_t* const buffer,  size_t* const inout_buffer_size_bytes)
{
    if ((obj == NULL) || (buffer == NULL) || (inout_buffer_size_bytes == NULL))
    {
        return -NUNAVUT_ERROR_INVALID_ARGUMENT;
    }


    const size_t capacity_bytes = *inout_buffer_size_bytes;
    if ((8U * (size_t) capacity_bytes) < 112UL)
    {
        return -NUNAVUT_ERROR_SERIALIZATION_BUFFER_TOO_SMALL;
    }
    // Notice that fields that are not an integer number of bytes long may overrun the space allocated for them
    // in the serialization buffer up to the next byte boundary. This is by design and is guaranteed to be safe.
    size_t offset_bits = 0U;





    {   // saturated uint32 error_count
        // Saturation code not emitted -- native representation matches the serialized representation.
        const int8_t _err0_ = nunavutSetUxx(&buffer[0], capacity_bytes, offset_bits, obj->error_count, 32U);
        if (_err0_ < 0)
        {
            return _err0_;
        }
        offset_bits += 32U;
    }




    {   // saturated float16 voltage
        float _sat0_ = obj->voltage;
        if (isfinite(_sat0_))
        {
            if (_sat0_ < ((float) -65504.0))
            {
                _sat0_ = ((float) -65504.0);
            }
            if (_sat0_ > ((float) 65504.0))
            {
                _sat0_ = ((float) 65504.0);
            }
        }
        const int8_t _err1_ = nunavutSetF16(&buffer[0], capacity_bytes, offset_bits, _sat0_);
        if (_err1_ < 0)
        {
            return _err1_;
        }
        offset_bits += 16U;
    }




    {   // saturated float16 current
        float _sat1_ = obj->current;
        if (isfinite(_sat1_))
        {
            if (_sat1_ < ((float) -65504.0))
            {
                _sat1_ = ((float) -65504.0);
            }
            if (_sat1_ > ((float) 65504.0))
            {
                _sat1_ = ((float) 65504.0);
            }
        }
        const int8_t _err2_ = nunavutSetF16(&buffer[0], capacity_bytes, offset_bits, _sat1_);
        if (_err2_ < 0)
        {
            return _err2_;
        }
        offset_bits += 16U;
    }




    {   // saturated float16 temperature
        float _sat2_ = obj->temperature;
        if (isfinite(_sat2_))
        {
            if (_sat2_ < ((float) -65504.0))
            {
                _sat2_ = ((float) -65504.0);
            }
            if (_sat2_ > ((float) 65504.0))
            {
                _sat2_ = ((float) 65504.0);
            }
        }
        const int8_t _err3_ = nunavutSetF16(&buffer[0], capacity_bytes, offset_bits, _sat2_);
        if (_err3_ < 0)
        {
            return _err3_;
        }
        offset_bits += 16U;
    }




    {   // saturated int18 rpm
        int32_t _sat3_ = obj->rpm;
        if (_sat3_ < -131072L)
        {
            _sat3_ = -131072L;
        }
        if (_sat3_ > 131071L)
        {
            _sat3_ = 131071L;
        }
        const int8_t _err4_ = nunavutSetIxx(&buffer[0], capacity_bytes, offset_bits, _sat3_, 18U);
        if (_err4_ < 0)
        {
            return _err4_;
        }
        offset_bits += 18U;
    }




    {   // saturated uint7 power_rating_pct
        uint8_t _sat4_ = obj->power_rating_pct;
        if (_sat4_ > 127U)
        {
            _sat4_ = 127U;
        }
        const int8_t _err5_ = nunavutSetUxx(&buffer[0], capacity_bytes, offset_bits, _sat4_, 7U);
        if (_err5_ < 0)
        {
            return _err5_;
        }
        offset_bits += 7U;
    }




    {   // saturated uint5 esc_index
        uint8_t _sat5_ = obj->esc_index;
        if (_sat5_ > 31U)
        {
            _sat5_ = 31U;
        }
        const int8_t _err6_ = nunavutSetUxx(&buffer[0], capacity_bytes, offset_bits, _sat5_, 5U);
        if (_err6_ < 0)
        {
            return _err6_;
        }
        offset_bits += 5U;
    }


    if (offset_bits % 8U != 0U)  // Pad to 8 bits. TODO: Eliminate redundant padding checks.
    {
        const uint8_t _pad0_ = (uint8_t)(8U - offset_bits % 8U);
        const int8_t _err7_ = nunavutSetUxx(&buffer[0], capacity_bytes, offset_bits, 0U, _pad0_);  // Optimize?
        if (_err7_ < 0)
        {
            return _err7_;
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
static inline int8_t legacy_equipment_esc_Status_1_0_deserialize_(
    legacy_equipment_esc_Status_1_0* const out_obj, const uint8_t* buffer, size_t* const inout_buffer_size_bytes)
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





    // saturated uint32 error_count
    out_obj->error_count = nunavutGetU32(&buffer[0], capacity_bytes, offset_bits, 32);
    offset_bits += 32U;




    // saturated float16 voltage
    out_obj->voltage = nunavutGetF16(&buffer[0], capacity_bytes, offset_bits);
    offset_bits += 16U;




    // saturated float16 current
    out_obj->current = nunavutGetF16(&buffer[0], capacity_bytes, offset_bits);
    offset_bits += 16U;




    // saturated float16 temperature
    out_obj->temperature = nunavutGetF16(&buffer[0], capacity_bytes, offset_bits);
    offset_bits += 16U;




    // saturated int18 rpm
    out_obj->rpm = nunavutGetI32(&buffer[0], capacity_bytes, offset_bits, 18);
    offset_bits += 18U;




    // saturated uint7 power_rating_pct
    out_obj->power_rating_pct = nunavutGetU8(&buffer[0], capacity_bytes, offset_bits, 7);
    offset_bits += 7U;




    // saturated uint5 esc_index
    out_obj->esc_index = nunavutGetU8(&buffer[0], capacity_bytes, offset_bits, 5);
    offset_bits += 5U;


    offset_bits = (offset_bits + 7U) & ~(size_t) 7U;  // Align on 8 bits.

    *inout_buffer_size_bytes = (size_t) (nunavutChooseMin(offset_bits, capacity_bits) / 8U);


    return NUNAVUT_SUCCESS;
}

/// Initialize an instance to default values. Does nothing if @param out_obj is NULL.
/// This function intentionally leaves inactive elements uninitialized; for example, members of a variable-length
/// array beyond its length are left uninitialized; aliased union memory that is not used by the first union field
/// is left uninitialized, etc. If full zero-initialization is desired, just use memset(&obj, 0, sizeof(obj)).
static inline void legacy_equipment_esc_Status_1_0_initialize_(legacy_equipment_esc_Status_1_0* const out_obj)
{
    if (out_obj != NULL)
    {
        size_t size_bytes = 0;
        const uint8_t buf = 0;
        const int8_t err = legacy_equipment_esc_Status_1_0_deserialize_(out_obj, &buf, &size_bytes);

        (void) err;
    }
}



#ifdef __cplusplus
}
#endif
#endif // LEGACY_EQUIPMENT_ESC_STATUS_1_0_INCLUDED_

