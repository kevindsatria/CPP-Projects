#include <stdio.h>
#include <openssl/bn.h>

#define NBITS 256

void printBN(char *msg, BIGNUM * a)
{
	/* Use BN_bn2hex(a) for hex string
	 * Use BN_bn2dec(a) for decimal string */
	char * number_str = BN_bn2hex(a);
	char * dec_str = BN_bn2dec(a);
	printf("%s %s\n", msg, number_str);
	printf("%s %s\n", "In Decimal:", dec_str);
	OPENSSL_free(number_str);
	OPENSSL_free(dec_str);
}

int main ()
{

	return 0;
}
