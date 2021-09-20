///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.1.1 (2021/03/15 15:59)

#ifndef SYSTEM_HELPER_GL_UTILITY_MACRO_H
#define SYSTEM_HELPER_GL_UTILITY_MACRO_H

#include "GLPluginMacro.h"
#include "System/OpenGL/Detail/GetOpenGLFunction.h"

#ifdef SYSTEM_PLATFORM_WIN32
    // Microsoft Windows
    #define OPENGL_STDCALL __stdcall
    #define OPENGL_EXTERN __declspec(dllimport)
#else  // !SYSTEM_PLATFORM_WIN32
    // Macintosh, Linux
    #define OPENGL_STDCALL
    #define OPENGL_EXTERN extern
#endif  // SYSTEM_PLATFORM_WIN32

namespace System
{
    constexpr auto g_SystemOpenGLVersionNone = 0;
    constexpr auto g_SystemOpenGLVersion10 = 10;
    constexpr auto g_SystemOpenGLVersion11 = 11;
    constexpr auto g_SystemOpenGLVersion12 = 12;
    constexpr auto g_SystemOpenGLVersion13 = 13;
    constexpr auto g_SystemOpenGLVersion14 = 14;
    constexpr auto g_SystemOpenGLVersion15 = 15;
    constexpr auto g_SystemOpenGLVersion20 = 20;
    constexpr auto g_SystemOpenGLVersion21 = 21;
    constexpr auto g_SystemOpenGLVersion30 = 30;
    constexpr auto g_SystemOpenGLVersion31 = 31;
    constexpr auto g_SystemOpenGLVersion32 = 32;
    constexpr auto g_SystemOpenGLVersion33 = 33;
    constexpr auto g_SystemOpenGLVersion40 = 40;
    constexpr auto g_SystemOpenGLVersion41 = 41;
    constexpr auto g_SystemOpenGLVersion42 = 42;
    constexpr auto g_SystemOpenGLVersion43 = 43;
    constexpr auto g_SystemOpenGLVersion44 = 44;
    constexpr auto g_SystemOpenGLVersion45 = 45;
    constexpr auto g_SystemOpenGLVersion46 = 46;
    constexpr auto g_SystemOpenGLVersionMax = 100;
}

#define SYSTEM_GET_FUNCTION(glFunction) \
    System::GetFunction(SYSTEM_STRINGIZE(glFunction), glFunction)

// 宏对于函数没有返回值。

#define SYSTEM_BODY_0(function)            \
    SYSTEM_ENTER_FUNCTION(function);       \
    if (function != nullptr)               \
    {                                      \
        SYSTEM_NONNULL_FUNCTION(function); \
        function();                        \
    }                                      \
    else                                   \
    {                                      \
        SYSTEM_NULL_FUNCTION(function);    \
    }                                      \
    SYSTEM_EXIT_FUNCTION(function)

#define SYSTEM_BODY_1(function, a0)        \
    SYSTEM_ENTER_FUNCTION(function);       \
    if (function != nullptr)               \
    {                                      \
        SYSTEM_NONNULL_FUNCTION(function); \
        function(a0);                      \
    }                                      \
    else                                   \
    {                                      \
        SYSTEM_NULL_FUNCTION(function);    \
    }                                      \
    SYSTEM_EXIT_FUNCTION(function)

#define SYSTEM_BODY_2(function, a0, a1)    \
    SYSTEM_ENTER_FUNCTION(function);       \
    if (function != nullptr)               \
    {                                      \
        SYSTEM_NONNULL_FUNCTION(function); \
        function(a0, a1);                  \
    }                                      \
    else                                   \
    {                                      \
        SYSTEM_NULL_FUNCTION(function);    \
    }                                      \
    SYSTEM_EXIT_FUNCTION(function)

#define SYSTEM_BODY_3(function, a0, a1, a2) \
    SYSTEM_ENTER_FUNCTION(function);        \
    if (function != nullptr)                \
    {                                       \
        SYSTEM_NONNULL_FUNCTION(function);  \
        function(a0, a1, a2);               \
    }                                       \
    else                                    \
    {                                       \
        SYSTEM_NULL_FUNCTION(function);     \
    }                                       \
    SYSTEM_EXIT_FUNCTION(function)

#define SYSTEM_BODY_4(function, a0, a1, a2, a3) \
    SYSTEM_ENTER_FUNCTION(function);            \
    if (function != nullptr)                    \
    {                                           \
        SYSTEM_NONNULL_FUNCTION(function);      \
        function(a0, a1, a2, a3);               \
    }                                           \
    else                                        \
    {                                           \
        SYSTEM_NULL_FUNCTION(function);         \
    }                                           \
    SYSTEM_EXIT_FUNCTION(function)

#define SYSTEM_BODY_5(function, a0, a1, a2, a3, a4) \
    SYSTEM_ENTER_FUNCTION(function);                \
    if (function != nullptr)                        \
    {                                               \
        SYSTEM_NONNULL_FUNCTION(function);          \
        function(a0, a1, a2, a3, a4);               \
    }                                               \
    else                                            \
    {                                               \
        SYSTEM_NULL_FUNCTION(function);             \
    }                                               \
    SYSTEM_EXIT_FUNCTION(function)

#define SYSTEM_BODY_6(function, a0, a1, a2, a3, a4, a5) \
    SYSTEM_ENTER_FUNCTION(function);                    \
    if (function != nullptr)                            \
    {                                                   \
        SYSTEM_NONNULL_FUNCTION(function);              \
        function(a0, a1, a2, a3, a4, a5);               \
    }                                                   \
    else                                                \
    {                                                   \
        SYSTEM_NULL_FUNCTION(function);                 \
    }                                                   \
    SYSTEM_EXIT_FUNCTION(function)

#define SYSTEM_BODY_7(function, a0, a1, a2, a3, a4, a5, a6) \
    SYSTEM_ENTER_FUNCTION(function);                        \
    if (function != nullptr)                                \
    {                                                       \
        SYSTEM_NONNULL_FUNCTION(function);                  \
        function(a0, a1, a2, a3, a4, a5, a6);               \
    }                                                       \
    else                                                    \
    {                                                       \
        SYSTEM_NULL_FUNCTION(function);                     \
    }                                                       \
    SYSTEM_EXIT_FUNCTION(function)

#define SYSTEM_BODY_8(function, a0, a1, a2, a3, a4, a5, a6, a7) \
    SYSTEM_ENTER_FUNCTION(function);                            \
    if (function != nullptr)                                    \
    {                                                           \
        SYSTEM_NONNULL_FUNCTION(function);                      \
        function(a0, a1, a2, a3, a4, a5, a6, a7);               \
    }                                                           \
    else                                                        \
    {                                                           \
        SYSTEM_NULL_FUNCTION(function);                         \
    }                                                           \
    SYSTEM_EXIT_FUNCTION(function)

#define SYSTEM_BODY_9(function, a0, a1, a2, a3, a4, a5, a6, a7, a8) \
    SYSTEM_ENTER_FUNCTION(function);                                \
    if (function != nullptr)                                        \
    {                                                               \
        SYSTEM_NONNULL_FUNCTION(function);                          \
        function(a0, a1, a2, a3, a4, a5, a6, a7, a8);               \
    }                                                               \
    else                                                            \
    {                                                               \
        SYSTEM_NULL_FUNCTION(function);                             \
    }                                                               \
    SYSTEM_EXIT_FUNCTION(function)

#define SYSTEM_BODY_10(function, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9) \
    SYSTEM_ENTER_FUNCTION(function);                                     \
    if (function != nullptr)                                             \
    {                                                                    \
        SYSTEM_NONNULL_FUNCTION(function);                               \
        function(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9);                \
    }                                                                    \
    else                                                                 \
    {                                                                    \
        SYSTEM_NULL_FUNCTION(function);                                  \
    }                                                                    \
    SYSTEM_EXIT_FUNCTION(function)

#define SYSTEM_BODY_11(function, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10) \
    SYSTEM_ENTER_FUNCTION(function);                                          \
    if (function != nullptr)                                                  \
    {                                                                         \
        SYSTEM_NONNULL_FUNCTION(function);                                    \
        function(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10);                \
    }                                                                         \
    else                                                                      \
    {                                                                         \
        SYSTEM_NULL_FUNCTION(function);                                       \
    }                                                                         \
    SYSTEM_EXIT_FUNCTION(function)

#define SYSTEM_BODY_12(function, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11) \
    SYSTEM_ENTER_FUNCTION(function);                                               \
    if (function != nullptr)                                                       \
    {                                                                              \
        SYSTEM_NONNULL_FUNCTION(function);                                         \
        function(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11);                \
    }                                                                              \
    else                                                                           \
    {                                                                              \
        SYSTEM_NULL_FUNCTION(function);                                            \
    }                                                                              \
    SYSTEM_EXIT_FUNCTION(function)

#define SYSTEM_BODY_15(function, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14) \
    SYSTEM_ENTER_FUNCTION(function);                                                              \
    if (function != nullptr)                                                                      \
    {                                                                                             \
        SYSTEM_NONNULL_FUNCTION(function);                                                        \
        function(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14);                \
    }                                                                                             \
    else                                                                                          \
    {                                                                                             \
        SYSTEM_NULL_FUNCTION(function);                                                           \
    }                                                                                             \
    SYSTEM_EXIT_FUNCTION(function)

// 宏对于函数有返回值。

#define SYSTEM_BODY_0_RESULT(function, nullReturnValue) \
    using Type = decltype(function());                  \
    Type result{ nullReturnValue };                     \
    SYSTEM_ENTER_FUNCTION(function);                    \
    if (function != nullptr)                            \
    {                                                   \
        SYSTEM_NONNULL_FUNCTION(function);              \
        result = function();                            \
    }                                                   \
    else                                                \
    {                                                   \
        SYSTEM_NULL_FUNCTION(function);                 \
    }                                                   \
    SYSTEM_EXIT_FUNCTION(function);                     \
    return result

#define SYSTEM_BODY_1_RESULT(function, a0, nullReturnValue) \
    using Type = decltype(function(a0));                    \
    Type result{ nullReturnValue };                         \
    SYSTEM_ENTER_FUNCTION(function);                        \
    if (function != nullptr)                                \
    {                                                       \
        SYSTEM_NONNULL_FUNCTION(function);                  \
        result = function(a0);                              \
    }                                                       \
    else                                                    \
    {                                                       \
        SYSTEM_NULL_FUNCTION(function);                     \
    }                                                       \
    SYSTEM_EXIT_FUNCTION(function);                         \
    return result

#define SYSTEM_BODY_2_RESULT(function, a0, a1, nullReturnValue) \
    using Type = decltype(function(a0, a1));                    \
    Type result{ nullReturnValue };                             \
    SYSTEM_ENTER_FUNCTION(function);                            \
    if (function != nullptr)                                    \
    {                                                           \
        SYSTEM_NONNULL_FUNCTION(function);                      \
        result = function(a0, a1);                              \
    }                                                           \
    else                                                        \
    {                                                           \
        SYSTEM_NULL_FUNCTION(function);                         \
    }                                                           \
    SYSTEM_EXIT_FUNCTION(function);                             \
    return result

#define SYSTEM_BODY_3_RESULT(function, a0, a1, a2, nullReturnValue) \
    using Type = decltype(function(a0, a1, a2));                    \
    Type result{ nullReturnValue };                                 \
    SYSTEM_ENTER_FUNCTION(function);                                \
    if (function != nullptr)                                        \
    {                                                               \
        SYSTEM_NONNULL_FUNCTION(function);                          \
        result = function(a0, a1, a2);                              \
    }                                                               \
    else                                                            \
    {                                                               \
        SYSTEM_NULL_FUNCTION(function);                             \
    }                                                               \
    SYSTEM_EXIT_FUNCTION(function);                                 \
    return result

#define SYSTEM_BODY_4_RESULT(function, a0, a1, a2, a3, nullReturnValue) \
    using Type = decltype(function(a0, a1, a2, a3));                    \
    Type result{ nullReturnValue };                                     \
    SYSTEM_ENTER_FUNCTION(function);                                    \
    if (function != nullptr)                                            \
    {                                                                   \
        SYSTEM_NONNULL_FUNCTION(function);                              \
        result = function(a0, a1, a2, a3);                              \
    }                                                                   \
    else                                                                \
    {                                                                   \
        SYSTEM_NULL_FUNCTION(function);                                 \
    }                                                                   \
    SYSTEM_EXIT_FUNCTION(function);                                     \
    return result

#define SYSTEM_BODY_5_RESULT(function, a0, a1, a2, a3, a4, nullReturnValue) \
    using Type = decltype(function(a0, a1, a2, a3, a4));                    \
    Type result{ nullReturnValue };                                         \
    SYSTEM_ENTER_FUNCTION(function);                                        \
    if (function != nullptr)                                                \
    {                                                                       \
        SYSTEM_NONNULL_FUNCTION(function);                                  \
        result = function(a0, a1, a2, a3, a4);                              \
    }                                                                       \
    else                                                                    \
    {                                                                       \
        SYSTEM_NULL_FUNCTION(function);                                     \
    }                                                                       \
    SYSTEM_EXIT_FUNCTION(function);                                         \
    return result

#define SYSTEM_BODY_6_RESULT(function, a0, a1, a2, a3, a4, a5, nullReturnValue) \
    using Type = decltype(function(a0, a1, a2, a3, a4, a5));                    \
    Type result{ nullReturnValue };                                             \
    SYSTEM_ENTER_FUNCTION(function);                                            \
    if (function != nullptr)                                                    \
    {                                                                           \
        SYSTEM_NONNULL_FUNCTION(function);                                      \
        result = function(a0, a1, a2, a3, a4, a5);                              \
    }                                                                           \
    else                                                                        \
    {                                                                           \
        SYSTEM_NULL_FUNCTION(function);                                         \
    }                                                                           \
    SYSTEM_EXIT_FUNCTION(function);                                             \
    return result

#define SYSTEM_BODY_7_RESULT(function, a0, a1, a2, a3, a4, a5, a6, nullReturnValue) \
    using Type = decltype(function(a0, a1, a2, a3, a4, a5, a6));                    \
    Type result{ nullReturnValue };                                                 \
    SYSTEM_ENTER_FUNCTION(function);                                                \
    if (function != nullptr)                                                        \
    {                                                                               \
        SYSTEM_NONNULL_FUNCTION(function);                                          \
        result = function(a0, a1, a2, a3, a4, a5, a6);                              \
    }                                                                               \
    else                                                                            \
    {                                                                               \
        SYSTEM_NULL_FUNCTION(function);                                             \
    }                                                                               \
    SYSTEM_EXIT_FUNCTION(function);                                                 \
    return result

#define SYSTEM_BODY_8_RESULT(function, a0, a1, a2, a3, a4, a5, a6, a7, nullReturnValue) \
    using Type = decltype(function(a0, a1, a2, a3, a4, a5, a6, a7));                    \
    Type result{ nullReturnValue };                                                     \
    SYSTEM_ENTER_FUNCTION(function);                                                    \
    if (function != nullptr)                                                            \
    {                                                                                   \
        SYSTEM_NONNULL_FUNCTION(function);                                              \
        result = function(a0, a1, a2, a3, a4, a5, a6, a7);                              \
    }                                                                                   \
    else                                                                                \
    {                                                                                   \
        SYSTEM_NULL_FUNCTION(function);                                                 \
    }                                                                                   \
    SYSTEM_EXIT_FUNCTION(function);                                                     \
    return result

#define SYSTEM_BODY_17_RESULT(function, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, nullReturnValue) \
    using Type = decltype(function(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16));                     \
    Type result{ nullReturnValue };                                                                                                 \
    SYSTEM_ENTER_FUNCTION(function);                                                                                                \
    if (function != nullptr)                                                                                                        \
    {                                                                                                                               \
        SYSTEM_NONNULL_FUNCTION(function);                                                                                          \
        result = function(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16);                               \
    }                                                                                                                               \
    else                                                                                                                            \
    {                                                                                                                               \
        SYSTEM_NULL_FUNCTION(function);                                                                                             \
    }                                                                                                                               \
    SYSTEM_EXIT_FUNCTION(function);                                                                                                 \
    return result

// 宏对于事先存在的函数没有返回值。

#ifdef SYSTEM_PLATFORM_WIN32

    #define SYSTEM_PREVIOUSLY_BODY_0(function) \
        SYSTEM_ENTER_FUNCTION(function);       \
        SYSTEM_NONNULL_FUNCTION(function);     \
        function();                            \
        SYSTEM_EXIT_FUNCTION(function)

    #define SYSTEM_PREVIOUSLY_BODY_1(function, a0) \
        SYSTEM_ENTER_FUNCTION(function);           \
        SYSTEM_NONNULL_FUNCTION(function);         \
        function(a0);                              \
        SYSTEM_EXIT_FUNCTION(function)

    #define SYSTEM_PREVIOUSLY_BODY_2(function, a0, a1) \
        SYSTEM_ENTER_FUNCTION(function);               \
        SYSTEM_NONNULL_FUNCTION(function);             \
        function(a0, a1);                              \
        SYSTEM_EXIT_FUNCTION(function)

    #define SYSTEM_PREVIOUSLY_BODY_3(function, a0, a1, a2) \
        SYSTEM_ENTER_FUNCTION(function);                   \
        SYSTEM_NONNULL_FUNCTION(function);                 \
        function(a0, a1, a2);                              \
        SYSTEM_EXIT_FUNCTION(function)

    #define SYSTEM_PREVIOUSLY_BODY_4(function, a0, a1, a2, a3) \
        SYSTEM_ENTER_FUNCTION(function);                       \
        SYSTEM_NONNULL_FUNCTION(function);                     \
        function(a0, a1, a2, a3);                              \
        SYSTEM_EXIT_FUNCTION(function)

    #define SYSTEM_PREVIOUSLY_BODY_5(function, a0, a1, a2, a3, a4) \
        SYSTEM_ENTER_FUNCTION(function);                           \
        SYSTEM_NONNULL_FUNCTION(function);                         \
        function(a0, a1, a2, a3, a4);                              \
        SYSTEM_EXIT_FUNCTION(function)

    #define SYSTEM_PREVIOUSLY_BODY_6(function, a0, a1, a2, a3, a4, a5) \
        SYSTEM_ENTER_FUNCTION(function);                               \
        SYSTEM_NONNULL_FUNCTION(function);                             \
        function(a0, a1, a2, a3, a4, a5);                              \
        SYSTEM_EXIT_FUNCTION(function)

    #define SYSTEM_PREVIOUSLY_BODY_7(function, a0, a1, a2, a3, a4, a5, a6) \
        SYSTEM_ENTER_FUNCTION(function);                                   \
        SYSTEM_NONNULL_FUNCTION(function);                                 \
        function(a0, a1, a2, a3, a4, a5, a6);                              \
        SYSTEM_EXIT_FUNCTION(function)

    #define SYSTEM_PREVIOUSLY_BODY_8(function, a0, a1, a2, a3, a4, a5, a6, a7) \
        SYSTEM_ENTER_FUNCTION(function);                                       \
        SYSTEM_NONNULL_FUNCTION(function);                                     \
        function(a0, a1, a2, a3, a4, a5, a6, a7);                              \
        SYSTEM_EXIT_FUNCTION(function)

    #define SYSTEM_PREVIOUSLY_BODY_9(function, a0, a1, a2, a3, a4, a5, a6, a7, a8) \
        SYSTEM_ENTER_FUNCTION(function);                                           \
        SYSTEM_NONNULL_FUNCTION(function);                                         \
        function(a0, a1, a2, a3, a4, a5, a6, a7, a8);                              \
        SYSTEM_EXIT_FUNCTION(function)

    #define SYSTEM_PREVIOUSLY_BODY_10(function, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9) \
        SYSTEM_ENTER_FUNCTION(function);                                                \
        SYSTEM_NONNULL_FUNCTION(function);                                              \
        function(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9);                               \
        SYSTEM_EXIT_FUNCTION(function)

    // 宏对于事先存在的函数有返回值。

    #define SYSTEM_PREVIOUSLY_BODY_0_RESULT(function, nullReturnValue) \
        SYSTEM_ENTER_FUNCTION(function);                               \
        SYSTEM_NONNULL_FUNCTION(function);                             \
        const auto result = function();                                \
        SYSTEM_EXIT_FUNCTION(function);                                \
        return result

    #define SYSTEM_PREVIOUSLY_BODY_1_RESULT(function, a0, nullReturnValue) \
        SYSTEM_ENTER_FUNCTION(function);                                   \
        SYSTEM_NONNULL_FUNCTION(function);                                 \
        const auto result = function(a0);                                  \
        SYSTEM_EXIT_FUNCTION(function);                                    \
        return result

    #define SYSTEM_PREVIOUSLY_BODY_2_RESULT(function, a0, a1, nullReturnValue) \
        SYSTEM_ENTER_FUNCTION(function);                                       \
        SYSTEM_NONNULL_FUNCTION(function);                                     \
        const auto result = function(a0, a1);                                  \
        SYSTEM_EXIT_FUNCTION(function);                                        \
        return result

    #define SYSTEM_PREVIOUSLY_BODY_3_RESULT(function, a0, a1, a2, nullReturnValue) \
        SYSTEM_ENTER_FUNCTION(function);                                           \
        SYSTEM_NONNULL_FUNCTION(function);                                         \
        const auto result = function(a0, a1, a2);                                  \
        SYSTEM_EXIT_FUNCTION(function);                                            \
        return result

    #define SYSTEM_PREVIOUSLY_BODY_4_RESULT(function, a0, a1, a2, a3, nullReturnValue) \
        SYSTEM_ENTER_FUNCTION(function);                                               \
        SYSTEM_NONNULL_FUNCTION(function);                                             \
        const auto result = function(a0, a1, a2, a3);                                  \
        SYSTEM_EXIT_FUNCTION(function);                                                \
        return result

    #define SYSTEM_PREVIOUSLY_BODY_5_RESULT(function, a0, a1, a2, a3, a4, nullReturnValue) \
        SYSTEM_ENTER_FUNCTION(function);                                                   \
        SYSTEM_NONNULL_FUNCTION(function);                                                 \
        const auto result = function(a0, a1, a2, a3, a4);                                  \
        SYSTEM_EXIT_FUNCTION(function);                                                    \
        return result

#else  // !SYSTEM_PLATFORM_WIN32

    #define SYSTEM_PREVIOUSLY_BODY_0(function) \
        SYSTEM_BODY_0(function);

    #define SYSTEM_PREVIOUSLY_BODY_1(function, a0) \
        SYSTEM_BODY_1(function, a);

    #define SYSTEM_PREVIOUSLY_BODY_2(function, a0, a1) \
        SYSTEM_BODY_2(function, a0, a1);

    #define SYSTEM_PREVIOUSLY_BODY_3(function, a0, a1, a2) \
        SYSTEM_BODY_3(function, a0, a1, a2);

    #define SYSTEM_PREVIOUSLY_BODY_4(function, a0, a1, a2, a3) \
        SYSTEM_BODY_4(function, a0, a1, a2, a3);

    #define SYSTEM_PREVIOUSLY_BODY_5(function, a0, a1, a2, a3, a4) \
        SYSTEM_BODY_5(function, a0, a1, a2, a3, a4);

    #define SYSTEM_PREVIOUSLY_BODY_6(function, a0, a1, a2, a3, a4, a5) \
        SYSTEM_BODY_6(function, a0, a1, a2, a3, a4, a5);

    #define SYSTEM_PREVIOUSLY_BODY_7(function, a0, a1, a2, a3, a4, a5, a6) \
        SYSTEM_BODY_7(function, a0, a1, a2, a3, a4, a5, a6);

    #define SYSTEM_PREVIOUSLY_BODY_8(function, a0, a1, a2, a3, a4, a5, a6, a7) \
        SYSTEM_BODY_8(function, a0, a1, a2, a3, a4, a5, a6, a7);

    #define SYSTEM_PREVIOUSLY_BODY_9(function, a0, a1, a2, a3, a4, a5, a6, a7, a8) \
        SYSTEM_BODY_9(function, a0, a1, a2, a3, a4, a5, a6, a7, a8);

    #define SYSTEM_PREVIOUSLY_BODY_10(function, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9) \
        SYSTEM_BODY_10(function, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9);

    // 宏对于事先存在的函数有返回值。

    #define SYSTEM_PREVIOUSLY_BODY_0_RESULT(function, nullReturnValue) \
        SYSTEM_BODY_0_RESULT(function, nullReturnValue)

    #define SYSTEM_PREVIOUSLY_BODY_1_RESULT(function, a0, nullReturnValue) \
        SYSTEM_BODY_1_RESULT(function, a0, nullReturnValue)

    #define SYSTEM_PREVIOUSLY_BODY_2_RESULT(function, a0, a1, nullReturnValue) \
        SYSTEM_BODY_2_RESULT(function, a0, a1, nullReturnValue)

    #define SYSTEM_PREVIOUSLY_BODY_3_RESULT(function, a0, a1, a2, nullReturnValue) \
        SYSTEM_BODY_3_RESULT(function, a0, a1, a2, nullReturnValue)

    #define SYSTEM_PREVIOUSLY_BODY_4_RESULT(function, a0, a1, a2, a3, nullReturnValue) \
        SYSTEM_BODY_4_RESULT(function, a0, a1, a2, a3, nullReturnValue)

    #define SYSTEM_PREVIOUSLY_BODY_5_RESULT(function, a0, a1, a2, a3, a4, nullReturnValue) \
        SYSTEM_BODY_5_RESULT(function, a0, a1, a2, a3, a4, nullReturnValue)

#endif  // SYSTEM_PLATFORM_WIN32

#endif  // SYSTEM_HELPER_GL_UTILITY_MACRO_H
