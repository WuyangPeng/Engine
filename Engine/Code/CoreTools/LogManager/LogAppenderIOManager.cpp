//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.2 (2020/10/15 18:52)

#include "CoreTools/CoreToolsExport.h"

#include "LogAppenderIOManager.h"
#include "Detail/LogAppenderIOManagerImplDetail.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Threading/ScopedMutex.h"

using std::make_shared;
using std::string;
using std::wstring;

CoreTools::LogAppenderIOManager::LogAppenderIOManager(LogLevel logLevel, const AppenderManagerPtr& appenderManager)
    : impl{ logLevel, appenderManager }, m_LogAppenderIOManagerMutex{ MutexCreate::UseCriticalSection }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CoreTools::LogAppenderIOManager::LogAppenderIOManager([[maybe_unused]] DisableNotThrow disableNotThrow)
    : impl{ 0 }, m_LogAppenderIOManagerMutex{ MutexCreate::UseCriticalSection }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, LogAppenderIOManager)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR_NOEXCEPT(CoreTools, LogAppenderIOManager, SetAppenderManager, AppenderManagerPtr, void)

CoreTools::LogAppenderIOManager& CoreTools::LogAppenderIOManager::operator<<(int32_t value) noexcept
{
    

    try
    {
        ScopedMutex scopedMutex{ m_LogAppenderIOManagerMutex };

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
        ScopedMutex scopedMutex{ m_LogAppenderIOManagerMutex };

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
        ScopedMutex scopedMutex{ m_LogAppenderIOManagerMutex };

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
        ScopedMutex scopedMutex{ m_LogAppenderIOManagerMutex };

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
        ScopedMutex scopedMutex{ m_LogAppenderIOManagerMutex };

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
        ScopedMutex scopedMutex{ m_LogAppenderIOManagerMutex };

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
        ScopedMutex scopedMutex{ m_LogAppenderIOManagerMutex };

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
        ScopedMutex scopedMutex{ m_LogAppenderIOManagerMutex };

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
        ScopedMutex scopedMutex{ m_LogAppenderIOManagerMutex };

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
        ScopedMutex scopedMutex{ m_LogAppenderIOManagerMutex };

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
        ScopedMutex scopedMutex{ m_LogAppenderIOManagerMutex };

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
        ScopedMutex scopedMutex{ m_LogAppenderIOManagerMutex };

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
        ScopedMutex scopedMutex{ m_LogAppenderIOManagerMutex };

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
        ScopedMutex scopedMutex{ m_LogAppenderIOManagerMutex };

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
        ScopedMutex scopedMutex{ m_LogAppenderIOManagerMutex };

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
        ScopedMutex scopedMutex{ m_LogAppenderIOManagerMutex };

        *impl << message;
    }
    catch (...)
    {
        System::OutputDebugStringWithTChar(SYSTEM_TEXT("LogAppenderIOManager operator<<抛出异常"));
    }

    return *this;
}
