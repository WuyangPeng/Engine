///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.3 (2022/10/05 21:23)

#ifndef SYSTEM_SYSTEM_OUTPUT_OUTPUT_DEBUG_STRING_H
#define SYSTEM_SYSTEM_OUTPUT_OUTPUT_DEBUG_STRING_H

#include "System/SystemDll.h"

#include "System/Helper/UnicodeUsing.h"

namespace System
{
    // 消息输出到调试窗口。

    void SYSTEM_DEFAULT_DECLARE OutputDebugStringWithChar(const char* outputString) noexcept;
    void SYSTEM_DEFAULT_DECLARE OutputDebugStringWithWChar(const wchar_t* outputString) noexcept;
    void SYSTEM_DEFAULT_DECLARE OutputDebugStringWithTChar(const TChar* outputString) noexcept;
}

#endif  // SYSTEM_SYSTEM_OUTPUT_OUTPUT_DEBUG_STRING_H