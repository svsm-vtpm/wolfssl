#ifndef WOLFSSL_USER_SETTINGS_H
#define WOLFSSL_USER_SETTINGS_H

#ifdef __cplusplus
extern "C" {
#endif

/* If TARGET_EMBEDDED is defined then small target settings are used */
//#if !(defined(__MACH__) || defined(__FreeBSD__) || defined(__linux__) || defined(_WIN32))
    //#error "Enabling target embedded"
    #define TARGET_EMBEDDED
//#endif

/* ------------------------------------------------------------------------- */
/* Platform */
/* ------------------------------------------------------------------------- */
#define WOLFSSL_GENERAL_ALIGNMENT 4
#define SIZEOF_LONG_LONG 8

#ifdef TARGET_EMBEDDED
    /* disable mutex locking */
    #define SINGLE_THREADED

    /* reduce stack use. For variables over 100 bytes allocate from heap */
    //#define WOLFSSL_SMALL_STACK
#endif

/* ------------------------------------------------------------------------- */
/* Math Configuration */
/* ------------------------------------------------------------------------- */
#define USE_FAST_MATH
#define TFM_TIMING_RESISTANT
#define ECC_TIMING_RESISTANT

/* ------------------------------------------------------------------------- */
/* Crypto */
/* ------------------------------------------------------------------------- */
/* RSA */
#undef NO_RSA
#if 1
    #ifdef USE_FAST_MATH
        /* Maximum math bits (Max RSA key bits * 2) */
        #define FP_MAX_BITS 4096
    #endif

    /* half as much memory but twice as slow */
    //#define RSA_LOW_MEM

    /* Enables blinding mode, to prevent timing attacks */
    #define WC_RSA_BLINDING

    /* RSA PSS Support */
    #define WC_RSA_PSS
#else
    #define NO_RSA
#endif

/* ------------------------------------------------------------------------- */
/* Benchmark / Test */
/* ------------------------------------------------------------------------- */
#ifdef TARGET_EMBEDDED
    /* Use reduced benchmark / test sizes */
    #define BENCH_EMBEDDED
#endif


/* ------------------------------------------------------------------------- */
/* Debugging */
/* ------------------------------------------------------------------------- */
#undef DEBUG_WOLFSSL
#undef NO_ERROR_STRINGS
#if 0
    #define DEBUG_WOLFSSL
#else
    #if 0
        #define NO_ERROR_STRINGS
    #endif
#endif

/* ------------------------------------------------------------------------- */
/* Memory */
/* ------------------------------------------------------------------------- */

#if 1
    /* Static memory requires fast math */
    #define WOLFSSL_STATIC_MEMORY

    /* Disable fallback malloc/free */
    //#define WOLFSSL_NO_MALLOC
    #if 1
        #define WOLFSSL_MALLOC_CHECK /* trap malloc failure */
    #endif
#endif

/* ------------------------------------------------------------------------- */
/* RNG */
/* ------------------------------------------------------------------------- */
#define WOLFSSL_AMD_SVSM
#define HAVE_CPUID
#define HAVE_CPUID_INTEL
#define HAVE_AMD_RDSEED
#define HAVE_INTEL_RDRAND

/* ASN */
//#define NO_ASN_TIME

//#define WC_NO_HARDEN

/* ------------------------------------------------------------------------- */
/* Disable Features */
/* ------------------------------------------------------------------------- */
/* Disable all TLS support, only wolfCrypt features */
//#define WOLFCRYPT_ONLY
#define NO_OLD_SHA_NAMES
//#define NO_WOLFSSL_SERVER
#define NO_WOLFSSL_CLIENT
#define NO_OLD_TLS
#define NO_FILESYSTEM
#undef HAVE_HTTP_CLIENT
#undef USE_WOLFSSL_IO
#define NO_BIO
#define WOLFSSL_NO_SOCK
#define NO_WRITEV

// Enable features
#define WOLFSSL_SHA384
#define WOLFSSL_SHA512
#define OPENSSL_EXTRA
#define WOLFSSL_AES_DIRECT
#define BUILD_SHA
#define BUILD_SHA3
#define BUILD_SHA512
#define HAVE_ECC
#define ECC_SHAMIR
#define WOLFSSL_DES_ECB
#define WOLFSSL_CERT_REQ
#define WOLFSSL_CERT_GEN
#define WOLFSSL_CERT_EXT
#define WOLFSSL_KEY_GEN
#define HAVE_AESGCM

/* Use test buffers from array (not filesystem) */
#ifdef NO_FILESYSTEM
#define USE_CERT_BUFFERS_256
#define USE_CERT_BUFFERS_2048
#endif

#ifdef __cplusplus
}
#endif

#endif /* WOLFSSL_USER_SETTINGS_H */
