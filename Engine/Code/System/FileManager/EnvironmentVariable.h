///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.1.5 (2022/12/11 20:37)

#ifndef SYSTEM_FILE_MANAGER_ENVIRONMENT_VARIABLE_H
#define SYSTEM_FILE_MANAGER_ENVIRONMENT_VARIABLE_H

#include "System/SystemDll.h"

#include "System/Helper/UnicodeUsing.h"

#include <string>

// ���������Ļ�ȡ��
namespace System
{
    NODISCARD bool SYSTEM_DEFAULT_DECLARE GetEnvironment(const String& variableName, TChar*& environmentVariable) noexcept;
    void SYSTEM_DEFAULT_DECLARE FreeEnvironment(TChar*& environmentVariable) noexcept; 
}

#endif  // SYSTEM_FILE_MANAGER_ENVIRONMENT_VARIABLE_H