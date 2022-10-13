///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.2 (2022/09/18 14:41)

#ifndef SYSTEM_HELPER_EXPORT_MACRO_H
#define SYSTEM_HELPER_EXPORT_MACRO_H

#include "ConfigMacro.h"

#if defined(SYSTEM_PLATFORM_WIN32) || defined(SYSTEM_PLATFORM_CYGWIN)

    #ifdef TCRE_USE_GCC

        #define TCRE_SYMBOL_EXPORT __attribute__((dllexport))
        #define TCRE_SYMBOL_IMPORT __attribute__((dllimport))

    #else  // !TCRE_USE_GCC

        #define TCRE_SYMBOL_EXPORT __declspec(dllexport)
        #define TCRE_SYMBOL_IMPORT __declspec(dllimport)

    #endif  // TCRE_USE_GCC

    #define TCRE_SYMBOL_NO_EXPORT
    #define TCRE_SYMBOL_VISIBLE

#else  // !defined (SYSTEM_PLATFORM_WIN32) && !defined (SYSTEM_PLATFORM_CYGWIN)

    #ifdef TCRE_USE_GCC

        #if 4 <= TCRE_USE_GCC

            #if defined(TCRE_COMPILER_VERSION) && (TCRE_COMPILER_VERSION < 1500)

                #define TCRE_SYMBOL_EXPORT __attribute__((visibility("default")))
                #define TCRE_SYMBOL_IMPORT
                #define TCRE_SYMBOL_NO_EXPORT __attribute__((visibility("hidden")))
                #define TCRE_SYMBOL_VISIBLE __attribute__((visibility("default")))

            #else  // !TCRE_COMPILER_VERSION || 1500 <= TCRE_COMPILER_VERSION

                #define TCRE_SYMBOL_EXPORT __attribute__((__visibility__("default")))
                #define TCRE_SYMBOL_IMPORT
                #define TCRE_SYMBOL_NO_EXPORT __attribute__((__visibility__("hidden")))
                #define TCRE_SYMBOL_VISIBLE __attribute__((__visibility__("default")))

            #endif  // TCRE_COMPILER_VERSION

        #else  // TCRE_USE_GCC < 4

            #define TCRE_SYMBOL_EXPORT
            #define TCRE_SYMBOL_IMPORT
            #define TCRE_SYMBOL_NO_EXPORT
            #define TCRE_SYMBOL_VISIBLE

        #endif  // TCRE_USE_GCC

    #elif defined(TCRE_USE_SUNPRO_CC)

        #define TCRE_SYMBOL_EXPORT __global
        #define TCRE_SYMBOL_IMPORT __global
        #define TCRE_SYMBOL_NO_EXPORT __global
        #define TCRE_SYMBOL_VISIBLE __global

    #elif defined(TCRE_USE_CLANG) || defined(TCRE_USE_XLCPP)

        #define TCRE_SYMBOL_EXPORT __attribute__((__visibility__("default")))
        #define TCRE_SYMBOL_IMPORT
        #define TCRE_SYMBOL_NO_EXPORT __attribute__((__visibility__("hidden")))
        #define TCRE_SYMBOL_VISIBLE __attribute__((__visibility__("default")))

    #else  // !defined(TCRE_USE_GCC) && !defined(TCRE_USE_SUNPRO_CC) && !defined(TCRE_USE_CLANG) && !defined(TCRE_USE_XLCPP)

        #define TCRE_SYMBOL_EXPORT
        #define TCRE_SYMBOL_IMPORT
        #define TCRE_SYMBOL_NO_EXPORT
        #define TCRE_SYMBOL_VISIBLE

    #endif  // TCRE_USE_GCC && TCRE_USE_SUNPRO_CC

#endif  // defined (SYSTEM_PLATFORM_WIN32) || defined (SYSTEM_PLATFORM_CYGWIN)

#define ERROR_SYMBOL_IMPORT ErrorImportClass ErrorImportClass
#define TCRE_SYMBOL_NO_IMPORT ERROR_SYMBOL_IMPORT

#endif  // SYSTEM_HELPER_EXPORT_MACRO_H
