/**
 * --------------------------------------------------------------
 * | @file boolean.h                                            |
 * --------------------------------------------------------------
 * | @details                                                   |
 * | Definisi tipe data boolean beserta nilai true dan false    |
 * | untuk digunakan dalam program C. Menyediakan kompatibilitas|
 * | dengan berbagai standar C.                                 |
 * --------------------------------------------------------------
 */

#ifndef BOOLEAN_H
#define BOOLEAN_H

// Untuk konteks C
#ifndef __cplusplus

    // Jika menggunakan C23 atau lebih baru (yang memiliki bool, true, false built-in)
    #if defined __STDC_VERSION__ && __STDC_VERSION__ >= 202311L

        // C23 sudah memiliki bool, true, false secara native
        // Tidak perlu mendefinisikan ulang
        // #include <stdbool.h> // Bisa di-include jika ingin eksplisit

    // Jika menggunakan C99 ke atas (yang mendukung _Bool)
    #elif defined __STDC_VERSION__ && __STDC_VERSION__ >= 199901L

        // Gunakan _Bool yang tersedia di C99+
        #define bool _Bool
        #define true 1
        #define false 0

    #else

        // Untuk versi C yang lebih lama (C90/C89)
        // Gunakan unsigned char sebagai fallback
        // Nama tipe 'boolean' digunakan di sini sesuai file asli,
        // namun 'bool' lebih umum untuk standar modern.
        // Jika ingin mengikuti standar PraPraktikum sepenuhnya, 'bool' lebih baik.
        // Untuk saat ini, kita pertahankan 'boolean' agar tidak mengubah terlalu banyak dari file asli.
        #define boolean unsigned char
        #define true ((unsigned char)1)  // Cast untuk menghindari warning potensial
        #define false ((unsigned char)0) // Cast untuk menghindari warning potensial

    #endif // __STDC_VERSION__

// Untuk konteks C++
#else

    // C++ sudah memiliki bool, true, false sebagai built-in
    // Tidak perlu mendefinisikan apa-apa

#endif // __cplusplus

// Makro untuk menandai bahwa bool, true, false sudah tersedia (jika menggunakan C99+ atau C23)
// atau bahwa 'boolean' telah didefinisikan (untuk C89).
#ifndef __bool_true_false_are_defined // Mengikuti pola PraPraktikum
    #if (defined __STDC_VERSION__ && __STDC_VERSION__ >= 199901L) || defined __cplusplus
        #define __bool_true_false_are_defined 1
    #endif
#endif

#endif // BOOLEAN_H