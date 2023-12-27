"""ZCM type definitions
This file automatically generated by zcm.
DO NOT MODIFY BY HAND!!!!
"""

try:
    import cStringIO.StringIO as BytesIO
except ImportError:
    from io import BytesIO
import struct

class Header(object):
    __slots__ = ["seq", "stamp", "frame_id"]

    IS_LITTLE_ENDIAN = False;
    def __init__(self):
        self.seq = 0
        self.stamp = 0
        self.frame_id = ""

    def encode(self):
        buf = BytesIO()
        buf.write(Header._get_packed_fingerprint())
        self._encode_one(buf)
        return buf.getvalue()

    def _encode_one(self, buf):
        buf.write(struct.pack(">qq", self.seq, self.stamp))
        __frame_id_encoded = self.frame_id.encode('utf-8')
        buf.write(struct.pack('>I', len(__frame_id_encoded)+1))
        buf.write(__frame_id_encoded)
        buf.write(b"\0")

    def decode(data):
        if hasattr(data, 'read'):
            buf = data
        else:
            buf = BytesIO(data)
        if buf.read(8) != Header._get_packed_fingerprint():
            raise ValueError("Decode error")
        return Header._decode_one(buf)
    decode = staticmethod(decode)

    def _decode_one(buf):
        self = Header()
        self.seq, self.stamp = struct.unpack(">qq", buf.read(16))
        __frame_id_len = struct.unpack('>I', buf.read(4))[0]
        self.frame_id = buf.read(__frame_id_len)[:-1].decode('utf-8', 'replace')
        return self
    _decode_one = staticmethod(_decode_one)

    _hash = None
    def _get_hash_recursive(parents):
        if Header in parents: return 0
        tmphash = (0xc86bbcf42728c594) & 0xffffffffffffffff
        tmphash  = (((tmphash<<1)&0xffffffffffffffff)  + ((tmphash>>63)&0x1)) & 0xffffffffffffffff
        return tmphash
    _get_hash_recursive = staticmethod(_get_hash_recursive)
    _packed_fingerprint = None

    def _get_packed_fingerprint():
        if Header._packed_fingerprint is None:
            Header._packed_fingerprint = struct.pack(">Q", Header._get_hash_recursive([]))
        return Header._packed_fingerprint
    _get_packed_fingerprint = staticmethod(_get_packed_fingerprint)

