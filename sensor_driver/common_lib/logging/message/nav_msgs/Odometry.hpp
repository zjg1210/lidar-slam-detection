/** THIS IS AN AUTOMATICALLY GENERATED FILE.
 *  DO NOT MODIFY BY HAND!!
 *
 *  Generated by zcm-gen
 **/

#include <zcm/zcm_coretypes.h>

#ifndef __nav_msgs_Odometry_hpp__
#define __nav_msgs_Odometry_hpp__

#include <string>
#include "std_msgs/Header.hpp"
#include "geometry_msgs/PoseWithCovariance.hpp"
#include "geometry_msgs/TwistWithCovariance.hpp"


namespace nav_msgs {
class Odometry
{
    public:
        std_msgs::Header header;

        std::string child_frame_id;

        geometry_msgs::PoseWithCovariance pose;

        geometry_msgs::TwistWithCovariance twist;

    public:
        /**
         * Destructs a message properly if anything inherits from it
        */
        virtual ~Odometry() {}

        /**
         * Encode a message into binary form.
         *
         * @param buf The output buffer.
         * @param offset Encoding starts at thie byte offset into @p buf.
         * @param maxlen Maximum number of bytes to write.  This should generally be
         *  equal to getEncodedSize().
         * @return The number of bytes encoded, or <0 on error.
         */
        inline int encode(void* buf, uint32_t offset, uint32_t maxlen) const;

        /**
         * Check how many bytes are required to encode this message.
         */
        inline uint32_t getEncodedSize() const;

        /**
         * Decode a message from binary form into this instance.
         *
         * @param buf The buffer containing the encoded message.
         * @param offset The byte offset into @p buf where the encoded message starts.
         * @param maxlen The maximum number of bytes to read while decoding.
         * @return The number of bytes decoded, or <0 if an error occured.
         */
        inline int decode(const void* buf, uint32_t offset, uint32_t maxlen);

        /**
         * Retrieve the 64-bit fingerprint identifying the structure of the message.
         * Note that the fingerprint is the same for all instances of the same
         * message type, and is a fingerprint on the message type definition, not on
         * the message contents.
         */
        inline static int64_t getHash();

        /**
         * Returns "Odometry"
         */
        inline static const char* getTypeName();

        // ZCM support functions. Users should not call these
        inline int      _encodeNoHash(void* buf, uint32_t offset, uint32_t maxlen) const;
        inline uint32_t _getEncodedSizeNoHash() const;
        inline int      _decodeNoHash(const void* buf, uint32_t offset, uint32_t maxlen);
        inline static uint64_t _computeHash(const __zcm_hash_ptr* p);
};

int Odometry::encode(void* buf, uint32_t offset, uint32_t maxlen) const
{
    uint32_t pos = 0;
    int thislen;
    int64_t hash = (int64_t)getHash();

    thislen = __int64_t_encode_array(buf, offset + pos, maxlen - pos, &hash, 1);
    if(thislen < 0) return thislen; else pos += thislen;

    thislen = this->_encodeNoHash(buf, offset + pos, maxlen - pos);
    if (thislen < 0) return thislen; else pos += thislen;

    return pos;
}

int Odometry::decode(const void* buf, uint32_t offset, uint32_t maxlen)
{
    uint32_t pos = 0;
    int thislen;

    int64_t msg_hash;
    thislen = __int64_t_decode_array(buf, offset + pos, maxlen - pos, &msg_hash, 1);
    if (thislen < 0) return thislen; else pos += thislen;
    if (msg_hash != getHash()) return -1;

    thislen = this->_decodeNoHash(buf, offset + pos, maxlen - pos);
    if (thislen < 0) return thislen; else pos += thislen;

    return pos;
}

uint32_t Odometry::getEncodedSize() const
{
    return 8 + _getEncodedSizeNoHash();
}

int64_t Odometry::getHash()
{
    static int64_t hash = _computeHash(NULL);
    return hash;
}

const char* Odometry::getTypeName()
{
    return "Odometry";
}

int Odometry::_encodeNoHash(void* buf, uint32_t offset, uint32_t maxlen) const
{
    uint32_t pos_byte = 0;
    int thislen;

    thislen = this->header._encodeNoHash(buf, offset + pos_byte, maxlen - pos_byte);
    if(thislen < 0) return thislen; else pos_byte += thislen;

    char* child_frame_id_cstr = (char*) this->child_frame_id.c_str();
    thislen = __string_encode_array(buf, offset + pos_byte, maxlen - pos_byte, &child_frame_id_cstr, 1);
    if(thislen < 0) return thislen; else pos_byte += thislen;

    thislen = this->pose._encodeNoHash(buf, offset + pos_byte, maxlen - pos_byte);
    if(thislen < 0) return thislen; else pos_byte += thislen;

    thislen = this->twist._encodeNoHash(buf, offset + pos_byte, maxlen - pos_byte);
    if(thislen < 0) return thislen; else pos_byte += thislen;

    return pos_byte;
}

int Odometry::_decodeNoHash(const void* buf, uint32_t offset, uint32_t maxlen)
{
    uint32_t pos_byte = 0;
    int thislen;

    thislen = this->header._decodeNoHash(buf, offset + pos_byte, maxlen - pos_byte);
    if(thislen < 0) return thislen; else pos_byte += thislen;

    int32_t __child_frame_id_len__;
    thislen = __int32_t_decode_array(buf, offset + pos_byte, maxlen - pos_byte, &__child_frame_id_len__, 1);
    if(thislen < 0) return thislen; else pos_byte += thislen;
    if((uint32_t)__child_frame_id_len__ > maxlen - pos_byte) return -1;
    this->child_frame_id.assign(((const char*)buf) + offset + pos_byte, __child_frame_id_len__ - ZCM_CORETYPES_INT8_NUM_BYTES_ON_BUS);
    pos_byte += __child_frame_id_len__;

    thislen = this->pose._decodeNoHash(buf, offset + pos_byte, maxlen - pos_byte);
    if(thislen < 0) return thislen; else pos_byte += thislen;

    thislen = this->twist._decodeNoHash(buf, offset + pos_byte, maxlen - pos_byte);
    if(thislen < 0) return thislen; else pos_byte += thislen;

    return pos_byte;
}

uint32_t Odometry::_getEncodedSizeNoHash() const
{
    uint32_t enc_size = 0;
    enc_size += this->header._getEncodedSizeNoHash();
    enc_size += this->child_frame_id.size() + ZCM_CORETYPES_INT32_NUM_BYTES_ON_BUS + ZCM_CORETYPES_INT8_NUM_BYTES_ON_BUS;
    enc_size += this->pose._getEncodedSizeNoHash();
    enc_size += this->twist._getEncodedSizeNoHash();
    return enc_size;
}

uint64_t Odometry::_computeHash(const __zcm_hash_ptr* p)
{
    const __zcm_hash_ptr* fp;
    for(fp = p; fp != NULL; fp = fp->parent)
        if(fp->v == Odometry::getHash)
            return 0;
    const __zcm_hash_ptr cp = { p, (void*)Odometry::getHash };

    uint64_t hash = (uint64_t)0x682b2733853d9e5bLL +
         std_msgs::Header::_computeHash(&cp) +
         geometry_msgs::PoseWithCovariance::_computeHash(&cp) +
         geometry_msgs::TwistWithCovariance::_computeHash(&cp);

    return (hash<<1) + ((hash>>63)&1);
}

}

#endif
