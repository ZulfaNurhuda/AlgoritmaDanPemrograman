/**
 * --------------------------------------------------------------
 * | @file Boolean.h                                            |
 * --------------------------------------------------------------
 * | @details                                                   |
 * | Definisi tipe data boolean beserta nilai TRUE dan FALSE    |
 * | untuk digunakan dalam program C. Menyediakan kompatibilitas|
 * | dengan berbagai standar C. Versi ini menggunakan 'boolean' |
 * | dan TRUE/FALSE.                                            |
 * --------------------------------------------------------------
 */

#ifndef BOOLEAN_H
#define BOOLEAN_H

// Untuk konteks C
#ifndef __cplusplus

    // Jika menggunakan C23 atau lebih baru (yang memiliki bool, true, false built-in)
    #if defined __STDC_VERSION__ && __STDC_VERSION__ >= 202311L
        #include <stdbool.h> // C23 menyediakan bool, true, false melalui stdbool.h
        // Definisikan alias jika ingin tetap menggunakan 'boolean', TRUE, FALSE
        #define boolean bool
        #define TRUE true
        #define FALSE false

    // Jika menggunakan C99 ke atas (yang mendukung _Bool)
    #elif defined __STDC_VERSION__ && __STDC_VERSION__ >= 199901L
        #include <stdbool.h> // C99 menyediakan bool, true, false melalui stdbool.h
        // Definisikan alias jika ingin tetap menggunakan 'boolean', TRUE, FALSE
        #define boolean bool
        #define TRUE true
        #define FALSE false
    #else
        // Untuk versi C yang lebih lama (C90/C89)
        // Menggunakan definisi asli dari file.
        #define boolean unsigned char
        #define TRUE 1  // Sesuai file asli
        #define FALSE 0 // Sesuai file asli
    #endif // __STDC_VERSION__

// Untuk konteks C++
#else
    // C++ sudah memiliki bool, true, false sebagai built-in
    // Definisikan alias jika ingin menggunakan 'boolean', TRUE, FALSE dalam kode C++
    #define boolean bool
    #define TRUE true
    #define FALSE false
#endif // __cplusplus

// Makro untuk menandai bahwa tipe boolean dan konstanta terkait sudah tersedia.
#ifndef __boolean_true_false_are_defined // Menggunakan nama makro yang sedikit berbeda untuk menghindari konflik
    #define __boolean_true_false_are_defined 1
#endif

#endif // BOOLEAN_H