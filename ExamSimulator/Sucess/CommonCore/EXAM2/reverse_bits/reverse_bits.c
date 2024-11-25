unsigned char	reverse_bits(unsigned char octet){
	unsigned char c = 0;
	int bits = 7;
	
	while(bits >= 0){
		if (octet & 128)
			c = c | 128 >> bits;
		octet <<= 1;
		bits--;
	}
	return (c);
}
