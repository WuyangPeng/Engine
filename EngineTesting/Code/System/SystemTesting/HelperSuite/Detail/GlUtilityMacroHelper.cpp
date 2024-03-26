/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/08 19:39)

#include "GlUtilityMacroHelper.h"
#include "System/Helper/Tools.h"

void System::GLFunction() noexcept
{
}

int System::Function0() noexcept
{
    return 0;
}

int System::Function1(int a0) noexcept
{
    return a0 + Function0();
}

int System::Function2(int a0, int a1) noexcept
{
    return a0 + a1 + Function0();
}

int System::Function3(int a0, int a1, int a2) noexcept
{
    return a0 + a1 + a2 + Function0();
}

int System::Function4(int a0, int a1, int a2, int a3) noexcept
{
    return a0 + a1 + a2 + a3 + Function0();
}

int System::Function5(int a0, int a1, int a2, int a3, int a4) noexcept
{
    return a0 + a1 + a2 + a3 + a4 + Function0();
}

int System::Function6(int a0, int a1, int a2, int a3, int a4, int a5) noexcept
{
    return a0 + a1 + a2 + a3 + a4 + a5 + Function0();
}

int System::Function7(int a0, int a1, int a2, int a3, int a4, int a5, int a6) noexcept
{
    return a0 + a1 + a2 + a3 + a4 + a5 + a6 + Function0();
}

int System::Function8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) noexcept
{
    return a0 + a1 + a2 + a3 + a4 + a5 + a6 + a7 + Function0();
}

int System::Function9(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8) noexcept
{
    return a0 + a1 + a2 + a3 + a4 + a5 + a6 + a7 + a8 + Function0();
}

int System::Function10(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9) noexcept
{
    return a0 + a1 + a2 + a3 + a4 + a5 + a6 + a7 + a8 + a9 + Function0();
}

int System::Function11(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10) noexcept
{
    return a0 + a1 + a2 + a3 + a4 + a5 + a6 + a7 + a8 + a9 + a10 + Function0();
}

int System::Function12(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) noexcept
{
    return a0 + a1 + a2 + a3 + a4 + a5 + a6 + a7 + a8 + a9 + a10 + a11 + Function0();
}

int System::Function15(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13, int a14) noexcept
{
    return a0 + a1 + a2 + a3 + a4 + a5 + a6 + a7 + a8 + a9 + a10 + a11 + a12 + a13 + a14 + Function0();
}

int System::Function17(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13, int a14, int a15, int a16) noexcept
{
    return a0 + a1 + a2 + a3 + a4 + a5 + a6 + a7 + a8 + a9 + a10 + a11 + a12 + a13 + a14 + a15 + a16 + Function0();
}

void* System::GetOpenGLFunctionPointer(const char* glFunction) noexcept
{
    UnusedFunction(glFunction);

    return &System::GLFunction;
}