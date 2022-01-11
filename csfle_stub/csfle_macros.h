#ifndef CSFLE_MACROS_H
#define CSFLE_MACROS_H

#ifdef _MSC_VER
/*
 * Microsoft Visual C
 */
#define MONGO_CSFLE_API __declspec(dllexport)
#define MONGO_API_CALL __cdecl

#elif defined(__GNUC__)
/*
 * GCC
 */
#define MONGO_CSFLE_API __attribute__ ((visibility ("default")))
#define MONGO_API_CALL

#else
/*
 * Other compilers
 */
#define MONGO_CSFLE_API
#define MONGO_API_CALL

#endif /* _MSC_VER */

#endif /* CSFLE_MACROS_H  */