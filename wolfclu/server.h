#define NO_MAIN_DRIVER

#ifndef WOLFCLU_NO_FILESYSTEM
THREAD_RETURN WOLFSSL_THREAD server_test(word16 port, const char* ourKey,
                const char* ourCert);
#endif