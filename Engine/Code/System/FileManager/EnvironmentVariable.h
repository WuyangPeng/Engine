/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/05 09:27)

#ifndef SYSTEM_FILE_MANAGER_ENVIRONMENT_VARIABLE_H
#define SYSTEM_FILE_MANAGER_ENVIRONMENT_VARIABLE_H

#include "System/SystemDll.h"

#include "System/Helper/UnicodeUsing.h"

/// 环境变量的获取。
namespace System
{
    NODISCARD bool SYSTEM_DEFAULT_DECLARE GetEnvironment(const String& variableName, TChar*& environmentVariable) noexcept;
    void SYSTEM_DEFAULT_DECLARE FreeEnvironment(TChar*& environmentVariable) noexcept;
}

#endif  // SYSTEM_FILE_MANAGER_ENVIRONMENT_VARIABLE_H