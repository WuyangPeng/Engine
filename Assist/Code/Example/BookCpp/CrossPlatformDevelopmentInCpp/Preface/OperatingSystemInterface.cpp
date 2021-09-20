///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.1.1 (2021/03/12 21:17)

#include "Example/BookCpp/CrossPlatformDevelopmentInCpp/CrossPlatformDevelopmentInCppExport.h"

#include "OperatingSystemInterface.h"
#include "System/Helper/UnicodeUsing.h"
#include "Example/BookCpp/CrossPlatformDevelopmentInCpp/Helper/CrossPlatformDevelopmentInCppClassInvariantMacro.h"

#ifdef SYSTEM_PLATFORM_WIN32
    #include <windows.h>
#elif defined(SYSTEM_PLATFORM_LINUX)
    #include <sys/types.h>
    #include <unisted.h>
#endif  // SYSTEM_PLATFORM_WIN32

#include <array>

using std::array;

BookAdvanced::CrossPlatformDevelopmentInCpp::OperatingSystemInterface::OperatingSystemInterface() noexcept
{
    CROSS_PLATFORM_DEVELOPMENT_IN_CPP_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(BookAdvanced::CrossPlatformDevelopmentInCpp, OperatingSystemInterface)

int BookAdvanced::CrossPlatformDevelopmentInCpp::OperatingSystemInterface::Main() const
{
    CROSS_PLATFORM_DEVELOPMENT_IN_CPP_CLASS_IS_VALID_CONST_9;

#ifdef SYSTEM_PLATFORM_WIN32
    STARTUPINFO si{};
    PROCESS_INFORMATION pi{};

    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));

    // Start the child process
    constexpr auto buffSize = 256;
    System::String notepad{ SYSTEM_TEXT("notepad") };
    array<System::TChar, buffSize> commandLine{};
    copy(notepad.begin(), notepad.end(), commandLine.begin());

    if (!CreateProcess(nullptr, commandLine.data(), nullptr, nullptr, FALSE, 0, nullptr, nullptr, &si, &pi))
    {
        return E_FAIL;
    }
    else
    {
        CloseHandle(pi.hProcess);
        CloseHandle(pi.hThread);

        return S_OK;
    }
#elif defined(SYSTEM_PLATFORM_LINUX)
    pid_t pid = fork();

    if (pid == 0)
    {
        // child process
        execl("/bin/date", "date", nullptr);
    }

    return 0;
#endif  // SYSTEM_PLATFORM_WIN32
}
