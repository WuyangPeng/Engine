///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/13 18:48)

#ifndef SYSTEM_FILE_MANAGE_ENVIRONMENT_VARIABLE_H
#define SYSTEM_FILE_MANAGE_ENVIRONMENT_VARIABLE_H

#include "System/SystemDll.h"

#include "System/Helper/UnicodeUsing.h"

#include <string>

namespace System
{
    // ���������Ļ�ȡ��

    NODISCARD bool SYSTEM_DEFAULT_DECLARE GetEnvironment(const String& variableName, TChar*& environmentVariable) noexcept;
    void SYSTEM_DEFAULT_DECLARE FreeEnvironment(TChar*& environmentVariable) noexcept;
}

#endif  // SYSTEM_FILE_MANAGE_ENVIRONMENT_VARIABLE_H