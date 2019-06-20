unsigned char reverse_bits(unsigned char octet)
{
    return (octet >> 4 | octet << 4); //原来的byte左移四位octet << 4并上原来的byte右移四位octet >> 4
}