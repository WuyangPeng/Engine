///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/12 21:07)

#ifndef SYSTEM_SYSTEM_OUTPUT_OUTPUT_DEBUG_STRING_H
#define SYSTEM_SYSTEM_OUTPUT_OUTPUT_DEBUG_STRING_H

#include "System/SystemDll.h"

#include "System/Helper/UnicodeUsing.h"

namespace System
{
    // ��Ϣ��������Դ��ڡ�

    void SYSTEM_DEFAULT_DECLARE OutputDebugStringWithChar(const char* outputString) noexcept;
    void SYSTEM_DEFAULT_DECLARE OutputDebugStringWithWChar(const wchar_t* outputString) noexcept;
    void SYSTEM_DEFAULT_DECLARE OutputDebugStringWithTChar(const TChar* outputString) noexcept;
}

#endif  // SYSTEM_SYSTEM_OUTPUT_OUTPUT_DEBUG_STRING_H