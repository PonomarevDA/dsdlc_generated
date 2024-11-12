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
// Source file:   /home/nex/PX4-Autopilot/src/drivers/cyphal/legacy_data_types/legacy/equipment/indication/SingleLightCommand.1.0.uavcan
// Generated at:  2024-11-12 20:12:20.934698 UTC
// Is deprecated: no
// Fixed port-ID: None
// Full name:     legacy.equipment.indication.SingleLightCommand
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

#ifndef LEGACY_EQUIPMENT_INDICATION_SINGLE_LIGHT_COMMAND_1_0_INCLUDED_
#define LEGACY_EQUIPMENT_INDICATION_SINGLE_LIGHT_COMMAND_1_0_INCLUDED_

#include <legacy/equipment/indication/RGB565_1_0.h>
#include <nunavut/support/serialization.h>
#include <stdint.h>
#include <stdlib.h>

static_assert( NUNAVUT_SUPPORT_LANGUAGE_OPTION_TARGET_ENDIANNESS == 1693710260,
              "/home/nex/PX4-Autopilot/src/drivers/cyphal/legacy_data_types/legacy/equipment/indication/SingleLightCommand.1.0.uavcan is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not allowed." );
static_assert( NUNAVUT_SUPPORT_LANGUAGE_OPTION_OMIT_FLOAT_SERIALIZATION_SUPPORT == 0,
              "/home/nex/PX4-Autopilot/src/drivers/cyphal/legacy_data_types/legacy/equipment/indication/SingleLightCommand.1.0.uavcan is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not allowed." );
static_assert( NUNAVUT_SUPPORT_LANGUAGE_OPTION_ENABLE_SERIALIZATION_ASSERTS == 0,
              "/home/nex/PX4-Autopilot/src/drivers/cyphal/legacy_data_types/legacy/equipment/indication/SingleLightCommand.1.0.uavcan is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not allowed." );
static_assert( NUNAVUT_SUPPORT_LANGUAGE_OPTION_ENABLE_OVERRIDE_VARIABLE_ARRAY_CAPACITY == 0,
              "/home/nex/PX4-Autopilot/src/drivers/cyphal/legacy_data_types/legacy/equipment/indication/SingleLightCommand.1.0.uavcan is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not allowed." );
static_assert( NUNAVUT_SUPPORT_LANGUAGE_OPTION_CAST_FORMAT == 2368206204,
              "/home/nex/PX4-Autopilot/src/drivers/cyphal/legacy_data_types/legacy/equipment/indication/SingleLightCommand.1.0.uavcan is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not allowed." );

#ifdef __cplusplus
extern "C" {
#endif

/// This type does not have a fixed port-ID. See https://forum.opencyphal.org/t/choosing-message-and-service-ids/889
#define legacy_equipment_indication_SingleLightCommand_1_0_HAS_FIXED_PORT_ID_ false

#define legacy_equipment_indication_SingleLightCommand_1_0_FULL_NAME_             "legacy.equipment.indication.SingleLightCommand"
#define legacy_equipment_indication_SingleLightCommand_1_0_FULL_NAME_AND_VERSION_ "legacy.equipment.indication.SingleLightCommand.1.0"

/// Extent is the minimum amount of memory required to hold any serialized representation of any compatible
/// version of the data type; or, on other words, it is the the maximum possible size of received objects of this type.
/// The size is specified in bytes (rather than bits) because by definition, extent is an integer number of bytes long.
/// When allocating a deserialization (RX) buffer for this data type, it should be at least extent bytes large.
/// When allocating a serialization (TX) buffer, it is safe to use the size of the largest serialized representation
/// instead of the extent because it provides a tighter bound of the object size; it is safe because the concrete type
/// is always known during serialization (unlike deserialization). If not sure, use extent everywhere.
#define legacy_equipment_indication_SingleLightCommand_1_0_EXTENT_BYTES_                    138UL
#define legacy_equipment_indication_SingleLightCommand_1_0_SERIALIZATION_BUFFER_SIZE_BYTES_ 69UL
static_assert(legacy_equipment_indication_SingleLightCommand_1_0_EXTENT_BYTES_ >= legacy_equipment_indication_SingleLightCommand_1_0_SERIALIZATION_BUFFER_SIZE_BYTES_,
              "Internal constraint violation");

/// saturated uint8 LIGHT_ID_ANTI_COLLISION = 246
#define legacy_equipment_indication_SingleLightCommand_1_0_LIGHT_ID_ANTI_COLLISION (246U)
/// saturated uint8 LIGHT_ID_RIGHT_OF_WAY = 247
#define legacy_equipment_indication_SingleLightCommand_1_0_LIGHT_ID_RIGHT_OF_WAY (247U)
/// saturated uint8 LIGHT_ID_STROBE = 248
#define legacy_equipment_indication_SingleLightCommand_1_0_LIGHT_ID_STROBE (248U)
/// saturated uint8 LIGHT_ID_WING = 249
#define legacy_equipment_indication_SingleLightCommand_1_0_LIGHT_ID_WING (249U)
/// saturated uint8 LIGHT_ID_LOGO = 250
#define legacy_equipment_indication_SingleLightCommand_1_0_LIGHT_ID_LOGO (250U)
/// saturated uint8 LIGHT_ID_TAXI = 251
#define legacy_equipment_indication_SingleLightCommand_1_0_LIGHT_ID_TAXI (251U)
/// saturated uint8 LIGHT_ID_TURN_OFF = 252
#define legacy_equipment_indication_SingleLightCommand_1_0_LIGHT_ID_TURN_OFF (252U)
/// saturated uint8 LIGHT_ID_TAKE_OFF = 253
#define legacy_equipment_indication_SingleLightCommand_1_0_LIGHT_ID_TAKE_OFF (253U)
/// saturated uint8 LIGHT_ID_LANDING = 254
#define legacy_equipment_indication_SingleLightCommand_1_0_LIGHT_ID_LANDING (254U)
/// saturated uint8 LIGHT_ID_FORMATION = 255
#define legacy_equipment_indication_SingleLightCommand_1_0_LIGHT_ID_FORMATION (255U)

typedef struct
{
    /// saturated uint8 light_id
    uint8_t light_id;

    /// legacy.equipment.indication.RGB565.1.0 color
    legacy_equipment_indication_RGB565_1_0 color;
} legacy_equipment_indication_SingleLightCommand_1_0;

/// Serialize an instance into the provided buffer.
/// The lifetime of the resulting serialized representation is independent of the original instance.
/// This method may be slow for large objects (e.g., images, point clouds, radar samples), so in a later revision
/// we may define a zero-copy alternative that keeps references to the original object where possible.
///
/// @param obj      The object to serialize.
///
/// @param buffer   The destination buffer. There are no alignment requirements.
///                 @see legacy_equipment_indication_SingleLightCommand_1_0_SERIALIZATION_BUFFER_SIZE_BYTES_
///
/// @param inout_buffer_size_bytes  When calling, this is a pointer to the size of the buffer in bytes.
///                                 Upon return this value will be updated with the size of the constructed serialized
///                                 representation (in bytes); this value is then to be passed over to the transport
///                                 layer. In case of error this value is undefined.
///
/// @returns Negative on error, zero on success.
static inline int8_t legacy_equipment_indication_SingleLightCommand_1_0_serialize_(
    const legacy_equipment_indication_SingleLightCommand_1_0* const obj, uint8_t* const buffer,  size_t* const inout_buffer_size_bytes)
{
    if ((obj == NULL) || (buffer == NULL) || (inout_buffer_size_bytes == NULL))
    {
        return -NUNAVUT_ERROR_INVALID_ARGUMENT;
    }


    const size_t capacity_bytes = *inout_buffer_size_bytes;
    if ((8U * (size_t) capacity_bytes) < 552UL)
    {
        return -NUNAVUT_ERROR_SERIALIZATION_BUFFER_TOO_SMALL;
    }
    // Notice that fields that are not an integer number of bytes long may overrun the space allocated for them
    // in the serialization buffer up to the next byte boundary. This is by design and is guaranteed to be safe.
    size_t offset_bits = 0U;





    {   // saturated uint8 light_id
        // Saturation code not emitted -- native representation matches the serialized representation.
        buffer[offset_bits / 8U] = (uint8_t)(obj->light_id);  // C std, 6.3.1.3 Signed and unsigned integers
        offset_bits += 8U;
    }


    if (offset_bits % 8U != 0U)  // Pad to 8 bits. TODO: Eliminate redundant padding checks.
    {
        const uint8_t _pad0_ = (uint8_t)(8U - offset_bits % 8U);
        const int8_t _err0_ = nunavutSetUxx(&buffer[0], capacity_bytes, offset_bits, 0U, _pad0_);  // Optimize?
        if (_err0_ < 0)
        {
            return _err0_;
        }
        offset_bits += _pad0_;
    }

    {   // legacy.equipment.indication.RGB565.1.0 color
        size_t _size_bytes0_ = 2UL;  // Nested object (max) size, in bytes.
        // Constant delimiter header can be written ahead of the nested object.
        const int8_t _err2_ = nunavutSetUxx(&buffer[0], capacity_bytes, offset_bits, _size_bytes0_, 32U);
        if (_err2_ < 0)
        {
            return _err2_;
        }
        offset_bits += 32U;
        int8_t _err1_ = legacy_equipment_indication_RGB565_1_0_serialize_(
            &obj->color, &buffer[offset_bits / 8U], &_size_bytes0_);
        if (_err1_ < 0)
        {
            return _err1_;
        }
        // It is assumed that we know the exact type of the serialized entity, hence we expect the size to match.
        offset_bits += _size_bytes0_ * 8U;  // Advance by the size of the nested object.
    }


    if (offset_bits % 8U != 0U)  // Pad to 8 bits. TODO: Eliminate redundant padding checks.
    {
        const uint8_t _pad1_ = (uint8_t)(8U - offset_bits % 8U);
        const int8_t _err3_ = nunavutSetUxx(&buffer[0], capacity_bytes, offset_bits, 0U, _pad1_);  // Optimize?
        if (_err3_ < 0)
        {
            return _err3_;
        }
        offset_bits += _pad1_;
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
static inline int8_t legacy_equipment_indication_SingleLightCommand_1_0_deserialize_(
    legacy_equipment_indication_SingleLightCommand_1_0* const out_obj, const uint8_t* buffer, size_t* const inout_buffer_size_bytes)
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





    // saturated uint8 light_id
    if ((offset_bits + 8U) <= capacity_bits)
    {
        out_obj->light_id = buffer[offset_bits / 8U] & 255U;
    }
    else
    {
        out_obj->light_id = 0U;
    }
    offset_bits += 8U;


    offset_bits = (offset_bits + 7U) & ~(size_t) 7U;  // Align on 8 bits.

    // legacy.equipment.indication.RGB565.1.0 color
    {
        // Delimiter header: truncated uint32
        size_t _size_bytes1_ = 0U;
        _size_bytes1_ = nunavutGetU32(&buffer[0], capacity_bytes, offset_bits, 32);
        offset_bits += 32U;
        if (_size_bytes1_ > (capacity_bytes - nunavutChooseMin((offset_bits / 8U), capacity_bytes)))
        {
            return -NUNAVUT_ERROR_REPRESENTATION_BAD_DELIMITER_HEADER;
        }
        const size_t _dh0_ = _size_bytes1_;  // Store the original delimiter header value.
        const int8_t _err4_ = legacy_equipment_indication_RGB565_1_0_deserialize_(
            &out_obj->color, &buffer[offset_bits / 8U], &_size_bytes1_);
        if (_err4_ < 0)
        {
            return _err4_;
        }
        // Advance the offset by the size of the delimiter header, even if the nested deserialization routine
        // consumed fewer bytes of data. This behavior implements the implicit truncation rule for nested objects.
        offset_bits += _dh0_ * 8U;
    }


    offset_bits = (offset_bits + 7U) & ~(size_t) 7U;  // Align on 8 bits.

    *inout_buffer_size_bytes = (size_t) (nunavutChooseMin(offset_bits, capacity_bits) / 8U);


    return NUNAVUT_SUCCESS;
}

/// Initialize an instance to default values. Does nothing if @param out_obj is NULL.
/// This function intentionally leaves inactive elements uninitialized; for example, members of a variable-length
/// array beyond its length are left uninitialized; aliased union memory that is not used by the first union field
/// is left uninitialized, etc. If full zero-initialization is desired, just use memset(&obj, 0, sizeof(obj)).
static inline void legacy_equipment_indication_SingleLightCommand_1_0_initialize_(legacy_equipment_indication_SingleLightCommand_1_0* const out_obj)
{
    if (out_obj != NULL)
    {
        size_t size_bytes = 0;
        const uint8_t buf = 0;
        const int8_t err = legacy_equipment_indication_SingleLightCommand_1_0_deserialize_(out_obj, &buf, &size_bytes);

        (void) err;
    }
}



#ifdef __cplusplus
}
#endif
#endif // LEGACY_EQUIPMENT_INDICATION_SINGLE_LIGHT_COMMAND_1_0_INCLUDED_

