///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/08/28 17:46)

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
}

#if defined(_DEBUG) && !defined(NDEBUG)

constexpr auto isDebug = true;

#else  // !_DEBUG

constexpr auto isDebug = false;

#endif  // _DEBUG

constexpr auto isRelease = !isDebug;

#endif  // SYSTEM_HELPER_WINDOWS_MACRO_H
