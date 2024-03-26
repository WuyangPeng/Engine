/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/08 19:39)

#ifndef SYSTEM_TESTING_HELPER_SUITE_GL_UTILITY_MACRO_HELPER_H
#define SYSTEM_TESTING_HELPER_SUITE_GL_UTILITY_MACRO_HELPER_H

#include "System/Helper/Detail/OpenGL/GLUtilityMacro.h"

namespace ExportTest
{
#ifdef BUILDING_SYSTEM_STATIC

    void ExportFunction() noexcept;

#else  // !BUILDING_SYSTEM_STATIC

    void OPENGL_EXTERN ExportFunction() noexcept;

#endif  // BUILDING_SYSTEM_STATIC
}

namespace System
{
    using GLGetFunction = void (*)() noexcept;

    void GLFunction() noexcept;

    int Function0() noexcept;
    int Function1(int a0) noexcept;
    int Function2(int a0, int a1) noexcept;
    int Function3(int a0, int a1, int a2) noexcept;
    int Function4(int a0, int a1, int a2, int a3) noexcept;
    int Function5(int a0, int a1, int a2, int a3, int a4) noexcept;
    int Function6(int a0, int a1, int a2, int a3, int a4, int a5) noexcept;
    int Function7(int a0, int a1, int a2, int a3, int a4, int a5, int a6) noexcept;
    int Function8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) noexcept;
    int Function9(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8) noexcept;
    int Function10(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9) noexcept;
    int Function11(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10) noexcept;
    int Function12(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) noexcept;
    int Function15(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13, int a14) noexcept;
    int Function17(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13, int a14, int a15, int a16) noexcept;
}

#endif  // SYSTEM_TESTING_HELPER_SUITE_GL_UTILITY_MACRO_HELPER_H
