/**
* \copyright
* MIT License
*
* Copyright (c) 2021 Infineon Technologies AG
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in all
* copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE
*
* \endcopyright
*
* \author Infineon Technologies AG
*
* \file rsa_key_object_confidentiality.h
*
* \brief   This file provides the data set for protected update of rsa key object with confidentiality.
*
* \ingroup grOptigaExamples
*
* @{
*/

#include <stdint.h>

/**
 * Manifest for RSA key update with integrity and confidentiality
 */
const uint8_t manifest_rsa_key[] =
{
    // COSE Sign1 Trust
    0x84,
        // Protected signed header trust
        0x43,
            // Trust Sign Algorithm
            0xA1, 
            // ECDSA
            0x01, 0x26, 
        // Unprotected signed header trust
        0xA1, 
            // Root of trust
            0x04, 0x42, 
            // Trust Anchor OID
            0xE0, 0xE3, 
        // Payload info Byte string of single byte length
        0x58, 
            // Byte string length of manifest            
            0x9E, 
            // Trust manifest, array of 6 entries
            0x86, 
            // Version(Major Type 0)
            0x01,
            // NULL
            0xF6,
            // NULL
            0xF6,
            // Resources, array of 4 entries
            0x84, 
                // Trust Payload Type
                0x22,
                // Payload Length 
                0x19, 0x01, 0x0D,
                // Trust Payload version
                0x03, 
                // Trust Add info data 
                0x82, 
                    // key algorithm
                    0x18,
                    // key usage
                    0x41, 0x12, 
                // Trust Processors, array of 2 entries 
                0x82, 
                    // Processing step integrity, array of 2 entries
                    0x82, 
                        // Process( Major Type 1)
                        0x20, 
                        // Parameters, byte string with single byte length
                        0x58, 
                            // Byte string length 
                            0x25, 
                            // IFX Digest info, array of 2 entries
                            0x82, 
                                // Digest Algorithm
                                0x18,
                                    // SHA-256
                                    0x29, 
                                // Digest
                                0x58, 
                                    // Byte string length
                                    0x20, 
                                        // Digest data
                                        0x07, 0x68, 0xD2, 0xF6, 0x8F, 0x3E, 0x27, 0x64,
                                        0x49, 0x1C, 0x02, 0xC1, 0x82, 0xE5, 0xB0, 0x60,
                                        0x7D, 0xCF, 0x84, 0xD1, 0x40, 0x7C, 0x01, 0xCD,
                                        0x73, 0x30, 0x51, 0xE1, 0x61, 0xB6, 0x35, 0x5D,
                    // Processing step decrypt, array of 2 entries
                    0x82,
                        // Process( Major Type 0)
                        0x01,
                        // COSE_Encrypt_Trust array of 3 entries
                        0x83,
                            // protected-encrypt-header-Trust
                            0x43,
                                // Map 
                                0xA1,
                                    // Key 
                                    0x01,
                                    // AES-CCM-16-64-128, 128-bit key, 64-bit Authentication(MAC) tag, 13-byte nonce
                                    0x0A,
                            // recipients array of 1
                            0x81,
                                // COSE_Recipient_Trust array of 2
                                0x82,
                                    // protected-recipient-header-Trust
                                    0x58,
                                        // byte str
                                        0x54,
                                            // Map of 3
                                            0xA3,
                                                // Key
                                                0x04,
                                                // Value
                                                0x42,
                                                    // Shared secret OID
                                                    0xF1, 0xD1,
                                                // Key
                                                0x01,
                                                // Value (KeyDerivationAlgorithms)
                                                0x3A, 0x00, 0x01, 0x00, 0xB7,
                                                // Key
                                                0x05,
                                                // Value array of 2
                                                0x82,
                                                    0x44,
                                                        // label(4)
                                                        0x74, 0x65, 0x73, 0x74,
                                                    0x58,
                                                        0x40,
                                                        // seed(64)
                                                        0x9F, 0xAE, 0x2A, 0xBF, 0xC9, 0xC0, 0x0F, 0x94,
                                                        0xD9, 0x6F, 0x27, 0xD5, 0x9A, 0x0B, 0xE9, 0xF9,
                                                        0x1B, 0x93, 0xA7, 0xE3, 0x6E, 0x98, 0x5F, 0x48,
                                                        0x82, 0x1D, 0x44, 0x4D, 0xB0, 0x1B, 0x18, 0x63,
                                                        0x45, 0x52, 0xF3, 0x65, 0x1D, 0x9E, 0xDD, 0x83,
                                                        0xC7, 0xE9, 0xBF, 0xC7, 0xF8, 0xC4, 0x89, 0x70,
                                                        0x88, 0xFF, 0xBA, 0x7A, 0x44, 0x82, 0x24, 0x4A,
                                                        0x26, 0x92, 0xDF, 0x52, 0xE2, 0x43, 0xE6, 0xF7,
                                    // ciphertext-recipient-header-Trust
                                    0xF6,
                            // AdditionalInfo
                            0xF6,
                // Trust Target
                0x82, 
                    // Component identifier(0)
                    0x40,
                    // Storage identifier
                    0x42, 
                    // Optiga target OID
                    0xE0, 0xFC, 
        // Signature info, byte string of single byte length
        0x58, 
            // Byte string length for ECC 256
            0x40, 
            // Signature data
            0xDA, 0x82, 0xDF, 0x8F, 0xE1, 0x53, 0x87, 0x3B, 0x7C, 0x6E, 0x70, 0x1A, 0x13, 0xDA, 0x44, 0x0B,
            0xDC, 0xAD, 0x2C, 0x80, 0x78, 0x72, 0xB1, 0x1E, 0x10, 0xD4, 0xCA, 0xC5, 0xF5, 0xF0, 0x13, 0x91,
            0xAF, 0x4D, 0x54, 0x3F, 0x6B, 0xAB, 0xA0, 0x0B, 0xA3, 0x1E, 0x12, 0x07, 0xD8, 0xE8, 0x83, 0x52,
            0x5A, 0xED, 0xBE, 0x0E, 0xDA, 0x30, 0x59, 0xC3, 0x12, 0x7C, 0xD4, 0xD7, 0x42, 0xA5, 0x03, 0x93,
};


/**
 * Fragment array for final payload for RSA key update
 */
const uint8_t rsa_key_final_fragment_array[] =
{
    0x20, 0x0B, 0x5E, 0x72, 0x5E, 0x80, 0x7F, 0x5C, 0xCD, 0xA0, 0x55, 0x2D, 0x1D, 0x62, 0xE0, 0x02,
    0xCB, 0x7A, 0xAF, 0x4B, 0x99, 0xFC, 0x88, 0x5B, 0x31, 0x96, 0x18, 0x41, 0x01, 0x6B, 0x8D, 0x43,
    0xC9, 0x9B, 0x1C, 0xCD, 0xAF, 0xFB, 0x44, 0x06, 0x38, 0x54, 0xB2, 0x64, 0xC4, 0x6E, 0x31, 0x20,
    0xE7, 0xB7, 0xEF, 0x5E, 0x10, 0xBD, 0xD3, 0x13, 0x9A, 0x90, 0xB0, 0x6C, 0x9C, 0x04, 0x9C, 0xB4,
    0x02, 0xAB, 0x45, 0x6B, 0x89, 0x53, 0xAE, 0x3C, 0x2B, 0x79, 0xBC, 0x83, 0xA5, 0xCC, 0x34, 0x56,
    0x13, 0x38, 0x84, 0x5C, 0x68, 0x31, 0x8C, 0xB6, 0x92, 0xA5, 0xC7, 0x8A, 0xB4, 0xD0, 0xBC, 0x00,
    0x01, 0x90, 0xD3, 0xBB, 0x4F, 0xFB, 0xF6, 0x87, 0xB3, 0x8B, 0x05, 0xCE, 0x81, 0x62, 0x35, 0x82,
    0x10, 0x3F, 0x7C, 0x81, 0xBA, 0x7C, 0x61, 0xCC, 0x95, 0x15, 0xA6, 0x5E, 0x5D, 0x42, 0x2A, 0x76,
    0xB4, 0xFE, 0x96, 0xE9, 0xE1, 0xCD, 0xEC, 0x5B, 0xA0, 0xB8, 0x17, 0x22, 0x2E, 0x8D, 0x79, 0xEE,
    0xE6, 0xCB, 0x7D, 0x77, 0x75, 0x4C, 0xD8, 0xA2, 0xDE, 0x4F, 0xAD, 0x10, 0x9C, 0x56, 0x2D, 0xBC,
    0xB8, 0x5F, 0xEE, 0x0F, 0xB8, 0xEF, 0xB4, 0xCD, 0xB3, 0x07, 0x00, 0x1D, 0x53, 0x73, 0xBB, 0xF3,
    0x4F, 0x0B, 0x1C, 0x81, 0x62, 0xB8, 0x34, 0x6B, 0x27, 0x4E, 0x4F, 0x96, 0x9C, 0x02, 0x3A, 0x92,
    0x82, 0x90, 0x11, 0x93, 0x14, 0x8B, 0x1F, 0x4B, 0x7C, 0xAF, 0x85, 0xCF, 0x8C, 0x54, 0xFD, 0x76,
    0xD9, 0x89, 0x21, 0xEF, 0xD5, 0x1F, 0xCE, 0x26, 0x78, 0xE2, 0x73, 0x16, 0x80, 0x58, 0x78, 0xAD,
    0x81, 0x7F, 0x29, 0x84, 0xCB, 0x27, 0x79, 0xFB, 0x85, 0xCC, 0xC9, 0xB6, 0xD1, 0x4B, 0x20, 0x03,
    0x7D, 0xC8, 0x0F, 0xFA, 0x96, 0x4D, 0x58, 0xDF, 0x8C, 0x29, 0x8B, 0xE5, 0x9E, 0x3A, 0x19, 0x4C,
    0xCB, 0x05, 0x4E, 0xF9, 0xCA, 0x16, 0xEF, 0x86, 0x00, 0x57, 0x4C, 0xA4, 0xE0, 0x87, 0x4E, 0xA1,
    0xDE, 0x2B, 0x4B, 0xD9, 0xE9,
};

/**
* @}
*/
