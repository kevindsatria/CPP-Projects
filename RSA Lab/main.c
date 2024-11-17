#include <stdio.h>
#include <openssl/bn.h>
#include <string.h>

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

int task1() {
    BN_CTX *ctx = BN_CTX_new();

    // Our Given variables
    BIGNUM *p = BN_new();
    BIGNUM *q = BN_new();
    BIGNUM *e = BN_new();

    // To be calculated
    BIGNUM *n = BN_new();
    BIGNUM *phi_n = BN_new();
    BIGNUM *d = BN_new();

    BN_hex2bn(&p,"F7E75FDC469067FFDC4E847C51F452DF");
    BN_hex2bn(&q,"E85CED54AF57E53E092113E62F436F4F");
    BN_hex2bn(&e, "0D88C3");

    // Storing n = p*q
    BN_mul(n, p, q, ctx);

    // Calculating p-1 and q-1
    BN_sub(p, p, BN_value_one());
    BN_sub(q, q, BN_value_one());

    // Calculating phi(n) = (p-1)*(q-1)
    BN_mul(phi_n, p, q, ctx);

    // Calculating private key d
    if (!BN_mod_inverse(d, e, phi_n, ctx)) {
        printf("Error computing modular inverse\n");
        return 1;
    }
    printBN("private key d: ", d);

    // Clean up
    BN_free(p);
    BN_free(q);
    BN_free(e);
    BN_free(n);
    BN_free(phi_n);
    BN_free(d);
    BN_CTX_free(ctx);

    return 0;
}

int task2() {
    BN_CTX *ctx = BN_CTX_new();

    // The given variables, M being the hex of "A top secret!"
    BIGNUM *n = BN_new();
    BIGNUM *e = BN_new();
    BIGNUM *M = BN_new();

    // To be calculated for ciphertext
    BIGNUM *C = BN_new();

    // Assigning the variables
    BN_hex2bn(&n, "DCBFFE3E51F62E09CE7032E2677A78946A849DC4CDDE3A4D0CB81629242FB1A5");
    BN_hex2bn(&e, "010001");
    BN_hex2bn(&M, "4120746f702073656372657421");

    // Creating the ciphertext
    if (!BN_mod_exp(C, M, e, n, ctx)) {
        printf("Error performing modular exponentiation.\n");
        return 1;
    }

    // Print the ciphertext
    printBN("Ciphertext (in hex):", C);

    // Clean up
    BN_free(n);
    BN_free(e);
    BN_free(M);
    BN_free(C);
    BN_CTX_free(ctx);

    return 0;
}

int task3(){
    BN_CTX *ctx = BN_CTX_new();

    //given variables
    BIGNUM *n = BN_new();
    BIGNUM *d = BN_new();
    BIGNUM *C = BN_new();
    BIGNUM *M = BN_new();

    //assigning variables
    BN_hex2bn(&n, "DCBFFE3E51F62E09CE7032E2677A78946A849DC4CDDE3A4D0CB81629242FB1A5");
    BN_hex2bn(&d, "74D806F9F3A62BAE331FFE3F0A68AFE35B3D2E4794148AACBC26AA381CD7D30D");
    BN_hex2bn(&C, "8C0F971DF2F3672B28811407E2DABBE1DA0FEBBBDFC7DCB67396567EA1E2493F");

    //calculating M = C^d mod n
    if (!BN_mod_exp(M, C, d, n, ctx)) {
        printf("Error performing modular exponentiation.\n");
        return 1;
    }

    //print the hex form
    printBN("Decrypted Message in Hex:", M);

    //converting M to string
    char *decrypted_str = BN_bn2hex(M);
    printf("Decrypted Message in ASCII: ");

    // Convert hex to ASCII
    int len = strlen(decrypted_str);
    for (int i = 0; i < len; i += 2) {
        char hex[3] = {decrypted_str[i], decrypted_str[i+1], '\0'};
        printf("%c", (char) strtol(hex, NULL, 16));
    }
    printf("\n");

    //clean up
    OPENSSL_free(decrypted_str);
    BN_free(n);
    BN_free(d);
    BN_free(C);
    BN_free(M);
    BN_CTX_free(ctx);
    return 0;
}

//the function takes in a message
void signMessage(const char *message) {
    BN_CTX *ctx = BN_CTX_new();
    BIGNUM *n = BN_new();
    BIGNUM *d = BN_new();

    //keys already found from task 2
    BN_hex2bn(&n, "DCBFFE3E51F62E09CE7032E2677A78946A849DC4CDDE3A4D0CB81629242FB1A5");
    BN_hex2bn(&d, "74D806F9F3A62BAE331FFE3F0A68AFE35B3D2E4794148AACBC26AA381CD7D30D");

    //to be calculated
    BIGNUM *M = BN_new();
    BIGNUM *signature = BN_new();

    // Convert message to BIGNUM (hex encoding)
    char hex_message[strlen(message) * 2 + 1];  // To hold hex string
    for (int i = 0; i < strlen(message); i++) {
        sprintf(&hex_message[i*2], "%02x", message[i]);
    }

    // Convert the hex message to BIGNUM
    BN_hex2bn(&M, hex_message);

    // Sign the message: signature = M^d mod n
    if (!BN_mod_exp(signature, M, d, n, ctx)) {
        printf("Error signing the message.\n");
        return;
    }

    printBN("Signature (in hex):", signature);

    // Free resources
    BN_free(n);
    BN_free(d);
    BN_free(M);
    BN_free(signature);
    BN_CTX_free(ctx);
}

int task4(){
    //original message
    const char *message = "I owe you $2000.";

    //signing the message
    printf("Original Message Signature:\n");
    signMessage(message);

    //altered message
    const char *modified_message = "I owe you $3000.";

    //signing the altered message
    printf("\nModified Message Signature:\n");
    signMessage(modified_message);

    return 0;
}

int verifySignature(const char *message, const char *signature_hex, const char *e_hex, const char *n_hex)
{
    BN_CTX *ctx = BN_CTX_new();
    BIGNUM *e = BN_new();
    BIGNUM *n = BN_new();
    BIGNUM *S = BN_new();
    BIGNUM *M_calculated = BN_new();
    BIGNUM *M_original = BN_new();

    //assigning variables
    BN_hex2bn(&e, e_hex);
    BN_hex2bn(&n, n_hex);
    BN_hex2bn(&S, signature_hex);

    //calculating M_calculated = S^e mod n
    if (!BN_mod_exp(M_calculated, S, e, n, ctx)){
        printf("Error performing modular exponentiation.\n");
        return 1;
    }

    //converting to hex
    char hex_message[strlen(message) * 2 + 1];
    for (int i = 0; i < strlen(message); i++){
        sprintf(&hex_message[i * 2], "%02x", message[i]);
    }

    BN_hex2bn(&M_original, hex_message);

    // Compare the calculated message with the original message
    if (BN_cmp(M_calculated, M_original) == 0){
        printf("Signature is valid.\n");
    } else{
        printf("Signature is invalid.\n");
    }

    //free spaces
    BN_free(e);
    BN_free(n);
    BN_free(S);
    BN_free(M_calculated);
    BN_free(M_original);
    BN_CTX_free(ctx);

    return 0;
}

int task5(char* signature)
{
    // Original message, signature, and public key
    const char *message = "Launch a missile.";
    char *signature_hex = signature;
    const char *e_hex = "010001"; // Public exponent
    const char *n_hex = "AE1CD4DC432798D933779FBD46C6E1247F0CF1233595113AA51B450F18116115"; // Modulus

    //function will take the signature
    verifySignature(message, signature_hex, e_hex, n_hex);

    return 0;
}


int main() {

    printf("Task1:\n");
    task1();

    printf("\nTask2:\n");
    task2();

    printf("\nTask3:\n");
    task3();

    printf("\nTask4:\n");
    task4();

    printf("\nTask5:\n");
    task5("643D6F34902D9C7EC90CB0B2BCA36C47FA37165C0005CAB026C0542CBDB6802F");

    printf("\nTask5 w altered signature:\n");
    task5("643D6F34902D9C7EC90CB0B2BCA36C47FA37165C0005CAB026C0542CBDB6803F");

    return 0;
}
