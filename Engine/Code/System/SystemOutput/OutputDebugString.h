///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/08/30 18:08)

#ifndef SYSTEM_SYSTEM_OUTPUT_OUTPUT_DEBUG_STRING_H
#define SYSTEM_SYSTEM_OUTPUT_OUTPUT_DEBUG_STRING_H

#include "System/SystemDll.h"

#include "System/Helper/UnicodeUsing.h"

// ��Ϣ��������Դ��ڡ�
namespace System
{
    void SYSTEM_DEFAULT_DECLARE OutputDebugStringWithChar(const char* outputString) noexcept;
    void SYSTEM_DEFAULT_DECLARE OutputDebugStringWithWChar(const wchar_t* outputString) noexcept;
    void SYSTEM_DEFAULT_DECLARE OutputDebugStringWithTChar(const TChar* outputString) noexcept;
}

#endif  // SYSTEM_SYSTEM_OUTPUT_OUTPUT_DEBUG_STRING_H