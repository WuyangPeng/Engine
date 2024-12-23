/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.1.2 (2024/10/26 17:26)

#ifndef SYSTEM_SYSTEM_OUTPUT_OUTPUT_DEBUG_STRING_H
#define SYSTEM_SYSTEM_OUTPUT_OUTPUT_DEBUG_STRING_H

#include "System/SystemDll.h"

#include "System/Helper/UnicodeUsing.h"

/// 消息输出到调试窗口。
namespace System
{
    void SYSTEM_DEFAULT_DECLARE OutputDebugStringWithChar(const char* outputString) noexcept;
    void SYSTEM_DEFAULT_DECLARE OutputDebugStringWithWChar(const wchar_t* outputString) noexcept;
    void SYSTEM_DEFAULT_DECLARE OutputDebugStringWithTChar(const TChar* outputString) noexcept;
}

#endif  // SYSTEM_SYSTEM_OUTPUT_OUTPUT_DEBUG_STRING_H