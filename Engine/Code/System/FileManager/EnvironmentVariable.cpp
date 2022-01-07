///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/13 18:51)

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

    if (environmentVariable == nullptr)
        return false;
    else
        return true;

#else  // !TCRE_USE_GCC && !SYSTEM_PLATFORM_ANDROID

    size_t length{ 0 };

    const auto error = _tdupenv_s(&environmentVariable, &length, variableName.c_str());
    if (error != 0)
        return false;
    else
        return true;

#endif  // ANDROID
}

void System::FreeEnvironment(TChar*& environmentVariable) noexcept
{
#if defined(SYSTEM_PLATFORM_ANDROID)

    environmentVariable = nullptr;

#else  // !SYSTEM_PLATFORM_ANDROID

    #include STSTEM_WARNING_PUSH
    #include SYSTEM_WARNING_DISABLE(26408)

    ::free(environmentVariable);

    #include STSTEM_WARNING_POP

    environmentVariable = nullptr;

#endif  // SYSTEM_PLATFORM_ANDROID
}
