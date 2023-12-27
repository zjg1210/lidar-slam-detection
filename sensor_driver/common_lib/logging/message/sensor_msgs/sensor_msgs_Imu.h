// THIS IS AN AUTOMATICALLY GENERATED FILE.
// DO NOT MODIFY BY HAND!!
//
// Generated by zcm-gen

#include <stdint.h>
#include <stdlib.h>
#include <zcm/zcm_coretypes.h>
#include <zcm/zcm.h>

#ifndef _sensor_msgs_Imu_h
#define _sensor_msgs_Imu_h

#ifdef __cplusplus
extern "C" {
#endif

#include "std_msgs/std_msgs_Header.h"
#include "geometry_msgs/geometry_msgs_Quaternion.h"
#include "geometry_msgs/geometry_msgs_Vector3.h"
#include "geometry_msgs/geometry_msgs_Vector3.h"
#define SENSOR_MSGS_IMU_IS_LITTLE_ENDIAN 0
typedef struct _sensor_msgs_Imu sensor_msgs_Imu;
struct _sensor_msgs_Imu
{
    std_msgs_Header header;
    geometry_msgs_Quaternion orientation;
    geometry_msgs_Vector3 angular_velocity;
    geometry_msgs_Vector3 linear_acceleration;
};

/**
 * Create a deep copy of a sensor_msgs_Imu.
 * When no longer needed, destroy it with sensor_msgs_Imu_destroy()
 */
sensor_msgs_Imu* sensor_msgs_Imu_copy(const sensor_msgs_Imu* to_copy);

/**
 * Destroy an instance of sensor_msgs_Imu created by sensor_msgs_Imu_copy()
 */
void sensor_msgs_Imu_destroy(sensor_msgs_Imu* to_destroy);

/**
 * Identifies a single subscription.  This is an opaque data type.
 */
typedef struct _sensor_msgs_Imu_subscription_t sensor_msgs_Imu_subscription_t;

/**
 * Prototype for a callback function invoked when a message of type
 * sensor_msgs_Imu is received.
 */
typedef void(*sensor_msgs_Imu_handler_t)(const zcm_recv_buf_t* rbuf,
             const char* channel, const sensor_msgs_Imu* msg, void* userdata);

/**
 * Publish a message of type sensor_msgs_Imu using ZCM.
 *
 * @param zcm The ZCM instance to publish with.
 * @param channel The channel to publish on.
 * @param msg The message to publish.
 * @return 0 on success, <0 on error.  Success means ZCM has transferred
 * responsibility of the message data to the OS.
 */
int sensor_msgs_Imu_publish(zcm_t* zcm, const char* channel, const sensor_msgs_Imu* msg);

/**
 * Subscribe to messages of type sensor_msgs_Imu using ZCM.
 *
 * @param zcm The ZCM instance to subscribe with.
 * @param channel The channel to subscribe to.
 * @param handler The callback function invoked by ZCM when a message is received.
 *                This function is invoked by ZCM during calls to zcm_handle() and
 *                zcm_handle_timeout().
 * @param userdata An opaque pointer passed to @p handler when it is invoked.
 * @return pointer to subscription type, NULL if failure. Must clean up
 *         dynamic memory by passing the pointer to sensor_msgs_Imu_unsubscribe.
 */
sensor_msgs_Imu_subscription_t* sensor_msgs_Imu_subscribe(zcm_t* zcm, const char* channel, sensor_msgs_Imu_handler_t handler, void* userdata);

/**
 * Removes and destroys a subscription created by sensor_msgs_Imu_subscribe()
 */
int sensor_msgs_Imu_unsubscribe(zcm_t* zcm, sensor_msgs_Imu_subscription_t* hid);
/**
 * Encode a message of type sensor_msgs_Imu into binary form.
 *
 * @param buf The output buffer.
 * @param offset Encoding starts at this byte offset into @p buf.
 * @param maxlen Maximum number of bytes to write.  This should generally
 *               be equal to sensor_msgs_Imu_encoded_size().
 * @param msg The message to encode.
 * @return The number of bytes encoded, or <0 if an error occured.
 */
int sensor_msgs_Imu_encode(void* buf, uint32_t offset, uint32_t maxlen, const sensor_msgs_Imu* p);

/**
 * Decode a message of type sensor_msgs_Imu from binary form.
 * When decoding messages containing strings or variable-length arrays, this
 * function may allocate memory.  When finished with the decoded message,
 * release allocated resources with sensor_msgs_Imu_decode_cleanup().
 *
 * @param buf The buffer containing the encoded message
 * @param offset The byte offset into @p buf where the encoded message starts.
 * @param maxlen The maximum number of bytes to read while decoding.
 * @param msg Output parameter where the decoded message is stored
 * @return The number of bytes decoded, or <0 if an error occured.
 */
int sensor_msgs_Imu_decode(const void* buf, uint32_t offset, uint32_t maxlen, sensor_msgs_Imu* msg);

/**
 * Release resources allocated by sensor_msgs_Imu_decode()
 * @return 0
 */
int sensor_msgs_Imu_decode_cleanup(sensor_msgs_Imu* p);

/**
 * Check how many bytes are required to encode a message of type sensor_msgs_Imu
 */
uint32_t sensor_msgs_Imu_encoded_size(const sensor_msgs_Imu* p);
uint32_t sensor_msgs_Imu_struct_size(void);
uint32_t sensor_msgs_Imu_num_fields(void);
int      sensor_msgs_Imu_get_field(const sensor_msgs_Imu* p, uint32_t i, zcm_field_t* f);
const zcm_type_info_t* sensor_msgs_Imu_get_type_info(void);

// ZCM support functions. Users should not call these
int64_t  __sensor_msgs_Imu_get_hash(void);
uint64_t __sensor_msgs_Imu_hash_recursive(const __zcm_hash_ptr* p);
int      __sensor_msgs_Imu_encode_array(void* buf, uint32_t offset, uint32_t maxlen, const sensor_msgs_Imu* p, uint32_t elements);
int      __sensor_msgs_Imu_decode_array(const void* buf, uint32_t offset, uint32_t maxlen, sensor_msgs_Imu* p, uint32_t elements);
int      __sensor_msgs_Imu_decode_array_cleanup(sensor_msgs_Imu* p, uint32_t elements);
uint32_t __sensor_msgs_Imu_encoded_array_size(const sensor_msgs_Imu* p, uint32_t elements);
uint32_t __sensor_msgs_Imu_clone_array(const sensor_msgs_Imu* p, sensor_msgs_Imu* q, uint32_t elements);

#ifdef __cplusplus
}
#endif

#endif
