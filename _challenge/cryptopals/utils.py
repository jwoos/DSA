import base64


def hex_string_to_bytes(s):
    return bytearray.fromhex(s)

def hex_string_to_b64_byte_string(s):
    b_array = hex_string_to_bytes(s)

    return base64.b64encode(s)

def xor_fixed_length(a_string, b_string):
    a = hex_string_to_bytes(a_string)
    b = hex_string_to_bytes(b_string)

    result = bytearray()

    for i in range(len(a)):
        result.append(a[i] ^ b[i])

    return result
