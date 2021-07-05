#ifndef MBEDTLS_SHA256_H_
#define MBEDTLS_SHA256_H_
#include "third_party/mbedtls/config.h"
COSMOPOLITAN_C_START_
/* clang-format off */

#define MBEDTLS_ERR_SHA256_HW_ACCEL_FAILED                -0x0037  /**< SHA-256 hardware accelerator failed */
#define MBEDTLS_ERR_SHA256_BAD_INPUT_DATA                 -0x0074  /**< SHA-256 input data was malformed. */

/**
 * \brief          The SHA-256 context structure.
 *
 *                 The structure is used both for SHA-256 and for SHA-224
 *                 checksum calculations. The choice between these two is
 *                 made in the call to mbedtls_sha256_starts_ret().
 */
typedef struct mbedtls_sha256_context
{
    uint32_t state[8];          /*!< The intermediate digest state.  */
    uint32_t total[2];          /*!< The number of Bytes processed.  */
    unsigned char buffer[64];   /*!< The data block being processed. */
    int is224;                  /*!< Determines which function to use:
                                     0: Use SHA-256, or 1: Use SHA-224. */
}
mbedtls_sha256_context;

void mbedtls_sha256_init( mbedtls_sha256_context * );
void mbedtls_sha256_free( mbedtls_sha256_context * );
void mbedtls_sha256_clone( mbedtls_sha256_context *, const mbedtls_sha256_context * );
int mbedtls_sha256_starts_ret( mbedtls_sha256_context *, int );
int mbedtls_sha256_update_ret( mbedtls_sha256_context *, const unsigned char *, size_t );
int mbedtls_sha256_finish_ret( mbedtls_sha256_context *, unsigned char[32] );
int mbedtls_internal_sha256_process( mbedtls_sha256_context *, const unsigned char[64] );
int mbedtls_sha256_ret( const void *, size_t, unsigned char[32], int );
int mbedtls_sha256_self_test( int );

COSMOPOLITAN_C_END_
#endif /* MBEDTLS_SHA256_H_ */