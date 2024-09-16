#include <iostream>
#include <openssl/ssl.h>
#include <openssl/err.h>

int main() {
    SSL_load_error_strings();
    OpenSSL_add_ssl_algorithms();

    const SSL_METHOD *method = SSLv23_client_method(); // Deprecated and vulnerable in older versions of OpenSSL
    SSL_CTX *ctx = SSL_CTX_new(method);

    if (!ctx) {
        std::cerr << "Failed to create SSL context" << std::endl;
        ERR_print_errors_fp(stderr);
        return EXIT_FAILURE;
    }

    std::cout << "Successfully created SSL context using vulnerable OpenSSL version" << std::endl;

    SSL_CTX_free(ctx);
    EVP_cleanup();
    return 0;
}
