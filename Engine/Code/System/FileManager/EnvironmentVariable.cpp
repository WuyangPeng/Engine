/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/05 09:30)

#include "System/SystemExport.h"

#include "EnvironmentVariable.h"
#include "System/Helper/PragmaWarning.h"

#ifdef SYSTEM_PLATFORM_WIN32

    #include <tchar.h>

#endif  // SYSTEM_PLATFORM_WIN32

bool System::GetEnvironment(const String& variableName, TChar*& environmentVariable) noexcept
{
#if defined(SYSTEM_PLATFORM_ANDROID)

    environmentVariable = nullptr;

    return false;

#elif defined(TCRE_USE_GCC)

    #ifdef UNICODE

    environmentVariable = ::_wgetenv(variableName.c_str());

    #else  // !UNICODE

    environmentVariable = ::getenv(variableName.c_str());

    #endif  // UNICODE

    return environmentVariable == nullptr;

#else  // !TCRE_USE_GCC && !SYSTEM_PLATFORM_ANDROID

    size_t length{ 0 };

    return _tdupenv_s(&environmentVariable, &length, variableName.c_str()) == 0;

#endif  // ANDROID
}

void System::FreeEnvironment(TChar*& environmentVariable) noexcept
{
#if defined(SYSTEM_PLATFORM_ANDROID)

    environmentVariable = nullptr;

#else  // !SYSTEM_PLATFORM_ANDROID

    #include SYSTEM_WARNING_PUSH
    #include SYSTEM_WARNING_DISABLE(26408)

    ::free(environmentVariable);

    #include SYSTEM_WARNING_POP

    environmentVariable = nullptr;

#endif  // SYSTEM_PLATFORM_ANDROID
}
