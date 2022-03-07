///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/07 22:50)

#include "CoreTools/CoreToolsExport.h"

#include "LogAppenderIOManager.h"
#include "Detail/LogAppenderIOManagerImplDetail.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Threading/ScopedMutex.h"

using std::make_shared;
using std::string;
using std::wstring;

CoreTools::LogAppenderIOManager::LogAppenderIOManagerSharedPtr CoreTools::LogAppenderIOManager::CreateSharedPtr(LogLevel logLevel, const AppenderManagerSharedPtr& appenderManager)
{
    return std::make_shared<LogAppenderIOManager>(logLevel, appenderManager);
}

CoreTools::LogAppenderIOManager CoreTools::LogAppenderIOManager::Create()
{
    return LogAppenderIOManager{ DisableNotThrow::Disable };
}

CoreTools::LogAppenderIOManager CoreTools::LogAppenderIOManager::Create(LogLevel logLevel, const AppenderManagerSharedPtr& appenderManager)
{
    return LogAppenderIOManager{ logLevel, appenderManager };
}

CoreTools::LogAppenderIOManager::LogAppenderIOManager(LogLevel logLevel, const AppenderManagerSharedPtr& appenderManager)
    : impl{ logLevel, appenderManager }, logAppenderIOManagerMutex{ MutexCreate::UseCriticalSection }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CoreTools::LogAppenderIOManager::LogAppenderIOManager(MAYBE_UNUSED DisableNotThrow disableNotThrow)
    : impl{ CoreTools::ImplCreateUseDefaultConstruction::Default }, logAppenderIOManagerMutex{ MutexCreate::UseCriticalSection }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CoreTools::LogAppenderIOManager::LogAppenderIOManager(LogAppenderIOManager&& rhs) noexcept
    : impl{ std::move(rhs.impl) }, logAppenderIOManagerMutex{ std::move(rhs.logAppenderIOManagerMutex) }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CoreTools::LogAppenderIOManager& CoreTools::LogAppenderIOManager::operator=(LogAppenderIOManager&& rhs) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    if (this != &rhs)
    {
        impl = std::move(rhs.impl);
        logAppenderIOManagerMutex = std::move(rhs.logAppenderIOManagerMutex);
    }

    return *this;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, LogAppenderIOManager)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR_NOEXCEPT(CoreTools, LogAppenderIOManager, SetAppenderManager, AppenderManagerSharedPtr, void)

CoreTools::LogAppenderIOManager& CoreTools::LogAppenderIOManager::operator<<(int32_t value) noexcept
{
    try
    {
        ScopedMutex scopedMutex{ logAppenderIOManagerMutex };

        *impl << value;
    }
    catch (...)
    {
        System::OutputDebugStringWithTChar(SYSTEM_TEXT("LogAppenderIOManager operator<<抛出异常"));
    }

    return *this;
}

CoreTools::LogAppenderIOManager& CoreTools::LogAppenderIOManager::operator<<(uint32_t value) noexcept
{
    try
    {
        ScopedMutex scopedMutex{ logAppenderIOManagerMutex };

        *impl << value;
    }
    catch (...)
    {
        System::OutputDebugStringWithTChar(SYSTEM_TEXT("LogAppenderIOManager operator<<抛出异常"));
    }

    return *this;
}

CoreTools::LogAppenderIOManager& CoreTools::LogAppenderIOManager::operator<<(int64_t value) noexcept
{
    try
    {
        ScopedMutex scopedMutex{ logAppenderIOManagerMutex };

        *impl << value;
    }
    catch (...)
    {
        System::OutputDebugStringWithTChar(SYSTEM_TEXT("LogAppenderIOManager operator<<抛出异常"));
    }

    return *this;
}

CoreTools::LogAppenderIOManager& CoreTools::LogAppenderIOManager::operator<<(uint64_t value) noexcept
{
    try
    {
        ScopedMutex scopedMutex{ logAppenderIOManagerMutex };

        *impl << value;
    }
    catch (...)
    {
        System::OutputDebugStringWithTChar(SYSTEM_TEXT("LogAppenderIOManager operator<<抛出异常"));
    }

    return *this;
}

CoreTools::LogAppenderIOManager& CoreTools::LogAppenderIOManager::operator<<(float value) noexcept
{
    try
    {
        ScopedMutex scopedMutex{ logAppenderIOManagerMutex };

        *impl << value;
    }
    catch (...)
    {
        System::OutputDebugStringWithTChar(SYSTEM_TEXT("LogAppenderIOManager operator<<抛出异常"));
    }

    return *this;
}

CoreTools::LogAppenderIOManager& CoreTools::LogAppenderIOManager::operator<<(double value) noexcept
{
    try
    {
        ScopedMutex scopedMutex{ logAppenderIOManagerMutex };

        *impl << value;
    }
    catch (...)
    {
        System::OutputDebugStringWithTChar(SYSTEM_TEXT("LogAppenderIOManager operator<<抛出异常"));
    }

    return *this;
}

CoreTools::LogAppenderIOManager& CoreTools::LogAppenderIOManager::operator<<(const string& message) noexcept
{
    try
    {
        ScopedMutex scopedMutex{ logAppenderIOManagerMutex };

        *impl << message;
    }
    catch (...)
    {
        System::OutputDebugStringWithTChar(SYSTEM_TEXT("LogAppenderIOManager operator<<抛出异常"));
    }
    return *this;
}

CoreTools::LogAppenderIOManager& CoreTools::LogAppenderIOManager::operator<<(const wstring& message) noexcept
{
    try
    {
        ScopedMutex scopedMutex{ logAppenderIOManagerMutex };

        *impl << message;
    }
    catch (...)
    {
        System::OutputDebugStringWithTChar(SYSTEM_TEXT("LogAppenderIOManager operator<<抛出异常"));
    }

    return *this;
}

CoreTools::LogAppenderIOManager& CoreTools::LogAppenderIOManager::operator<<(const FunctionDescribed& functionDescribed) noexcept
{
    try
    {
        ScopedMutex scopedMutex{ logAppenderIOManagerMutex };

        *impl << functionDescribed;
    }
    catch (...)
    {
        System::OutputDebugStringWithTChar(SYSTEM_TEXT("LogAppenderIOManager operator<<抛出异常"));
    }

    return *this;
}

CoreTools::LogAppenderIOManager& CoreTools::LogAppenderIOManager::operator<<(const Error& error) noexcept
{
    try
    {
        ScopedMutex scopedMutex{ logAppenderIOManagerMutex };

        *impl << error;
    }
    catch (...)
    {
        System::OutputDebugStringWithTChar(SYSTEM_TEXT("LogAppenderIOManager operator<<抛出异常"));
    }

    return *this;
}

CoreTools::LogAppenderIOManager& CoreTools::LogAppenderIOManager::operator<<(const std::exception& error) noexcept
{
    try
    {
        ScopedMutex scopedMutex{ logAppenderIOManagerMutex };

        *impl << error;
    }
    catch (...)
    {
        System::OutputDebugStringWithTChar(SYSTEM_TEXT("LogAppenderIOManager operator<<抛出异常"));
    }

    return *this;
}

CoreTools::LogAppenderIOManager& CoreTools::LogAppenderIOManager::operator<<(LogFilter filterType) noexcept
{
    try
    {
        ScopedMutex scopedMutex{ logAppenderIOManagerMutex };

        *impl << filterType;
    }
    catch (...)
    {
        System::OutputDebugStringWithTChar(SYSTEM_TEXT("LogAppenderIOManager operator<<抛出异常"));
    }

    return *this;
}

CoreTools::LogAppenderIOManager& CoreTools::LogAppenderIOManager::operator<<(LogAppenderIOManageSign sign) noexcept
{
    try
    {
        ScopedMutex scopedMutex{ logAppenderIOManagerMutex };

        *impl << sign;
    }
    catch (...)
    {
        System::OutputDebugStringWithTChar(SYSTEM_TEXT("LogAppenderIOManager operator<<抛出异常"));
    }

    return *this;
}

CoreTools::LogAppenderIOManager& CoreTools::LogAppenderIOManager::operator<<(const LogFileName& logFileName) noexcept
{
    try
    {
        ScopedMutex scopedMutex{ logAppenderIOManagerMutex };

        *impl << logFileName;
    }
    catch (...)
    {
        System::OutputDebugStringWithTChar(SYSTEM_TEXT("LogAppenderIOManager operator<<抛出异常"));
    }

    return *this;
}

CoreTools::LogAppenderIOManager& CoreTools::LogAppenderIOManager::operator<<(const char* message) noexcept
{
    try
    {
        ScopedMutex scopedMutex{ logAppenderIOManagerMutex };

        *impl << message;
    }
    catch (...)
    {
        System::OutputDebugStringWithTChar(SYSTEM_TEXT("LogAppenderIOManager operator<<抛出异常"));
    }

    return *this;
}

CoreTools::LogAppenderIOManager& CoreTools::LogAppenderIOManager::operator<<(const wchar_t* message) noexcept
{
    try
    {
        ScopedMutex scopedMutex{ logAppenderIOManagerMutex };

        *impl << message;
    }
    catch (...)
    {
        System::OutputDebugStringWithTChar(SYSTEM_TEXT("LogAppenderIOManager operator<<抛出异常"));
    }

    return *this;
}

CoreTools::LogAppenderIOManager& CoreTools::LogAppenderIOManager::operator<<(const std::string_view& message) noexcept
{
    try
    {
        ScopedMutex scopedMutex{ logAppenderIOManagerMutex };

        *impl << message;
    }
    catch (...)
    {
        System::OutputDebugStringWithTChar(SYSTEM_TEXT("LogAppenderIOManager operator<<抛出异常"));
    }

    return *this;
}
