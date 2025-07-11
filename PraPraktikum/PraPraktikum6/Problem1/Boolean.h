#ifndef BOOLEAN_H

    #define BOOLEAN_H

    // Untuk konteks C
    #ifndef __cplusplus

        // Jika menggunakan C23 atau lebih baru (yang memiliki bool, true, false built-in)
        #if defined __STDC_VERSION__ && __STDC_VERSION__ >= 202311L

            // C23 sudah memiliki bool, true, false secara native
            // Tidak perlu mendefinisikan ulang

        // Jika menggunakan C99 ke atas (yang mendukung _Bool)
        #elif defined __STDC_VERSION__ && __STDC_VERSION__ >= 199901L

            // Gunakan _Bool yang tersedia di C99+
            #define bool _Bool
            #define true 1
            #define false 0

        #else

            // Untuk versi C yang lebih lama (C90/C89)
            // Gunakan unsigned char sebagai fallback
            #define bool unsigned char
            #define true ((unsigned char)1)
            #define false ((unsigned char)0)

        #endif // __STDC_VERSION__

    // Untuk konteks C++
    #else

        // C++ sudah memiliki bool, true, false sebagai built-in
        // Tidak perlu mendefinisikan apa-apa

    #endif // __cplusplus

    // Makro untuk menandai bahwa bool, true, false sudah tersedia
    #ifndef __bool_true_false_are_defined

        #define __bool_true_false_are_defined 1

    #endif // __bool_true_false_are_defined

#endif // BOOLEAN_H