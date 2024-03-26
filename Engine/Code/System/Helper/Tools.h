/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/04 22:55)

#ifndef SYSTEM_HELPER_TOOLS_H
#define SYSTEM_HELPER_TOOLS_H

#include "UserMacro.h"

namespace System
{
    template <typename T, size_t N>
    NODISCARD constexpr size_t GetArraySize(T (&)[N]) noexcept
    {
        return N;
    }

    template <typename... T>
    constexpr void UnusedFunction(MAYBE_UNUSED T&&... value) noexcept
    {
    }

    /// 下面四个函数是用于消除编译器C26451警告。
    /// 定义GetDivide函数主要为了对称。
    NODISCARD static constexpr int GetPlus(int lhs, int rhs) noexcept
    {
        return lhs + rhs;
    }

    NODISCARD static constexpr int GetMinus(int lhs, int rhs) noexcept
    {
        return lhs - rhs;
    }

    NODISCARD static constexpr int GetProduct(int lhs, int rhs) noexcept
    {
        return lhs * rhs;
    }

    NODISCARD static constexpr int GetDivide(int lhs, int rhs) noexcept
    {
        return lhs / rhs;
    }

}

#if defined(_DEBUG) && !defined(NDEBUG)

constexpr auto isDebug = true;

#else  // !_DEBUG

constexpr auto isDebug = false;

#endif  // _DEBUG

constexpr auto isRelease = !isDebug;

#endif  // SYSTEM_HELPER_WINDOWS_MACRO_H
