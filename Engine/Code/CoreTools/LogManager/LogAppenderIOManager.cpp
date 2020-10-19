//	Copyright (c) 2011-2020
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
    : m_Impl{ make_shared<ImplType>(logLevel, appenderManager) }, m_LogAppenderIOManagerMutex{}
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CoreTools::LogAppenderIOManager::LogAppenderIOManager([[maybe_unused]] DisableNotThrow disableNotThrow)
    : m_Impl{ make_shared<ImplType>() }, m_LogAppenderIOManagerMutex{}
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(CoreTools, LogAppenderIOManager)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR_NOEXCEPT(CoreTools, LogAppenderIOManager, SetAppenderManager, AppenderManagerPtr, void)

CoreTools::LogAppenderIOManager& CoreTools::LogAppenderIOManager::operator<<(int32_t value) noexcept
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    try
    {
        ScopedMutex scopedMutex{ m_LogAppenderIOManagerMutex };

        *m_Impl << value;
    }
    catch (...)
    {
        System::OutputDebugStringWithTChar(SYSTEM_TEXT("LogAppenderIOManager operator<<抛出异常"));
    }

    return *this;
}

CoreTools::LogAppenderIOManager& CoreTools::LogAppenderIOManager::operator<<(uint32_t value) noexcept
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    try
    {
        ScopedMutex scopedMutex{ m_LogAppenderIOManagerMutex };

        *m_Impl << value;
    }
    catch (...)
    {
        System::OutputDebugStringWithTChar(SYSTEM_TEXT("LogAppenderIOManager operator<<抛出异常"));
    }

    return *this;
}

CoreTools::LogAppenderIOManager& CoreTools::LogAppenderIOManager::operator<<(int64_t value) noexcept
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    try
    {
        ScopedMutex scopedMutex{ m_LogAppenderIOManagerMutex };

        *m_Impl << value;
    }
    catch (...)
    {
        System::OutputDebugStringWithTChar(SYSTEM_TEXT("LogAppenderIOManager operator<<抛出异常"));
    }

    return *this;
}

CoreTools::LogAppenderIOManager& CoreTools::LogAppenderIOManager::operator<<(uint64_t value) noexcept
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    try
    {
        ScopedMutex scopedMutex{ m_LogAppenderIOManagerMutex };

        *m_Impl << value;
    }
    catch (...)
    {
        System::OutputDebugStringWithTChar(SYSTEM_TEXT("LogAppenderIOManager operator<<抛出异常"));
    }

    return *this;
}

CoreTools::LogAppenderIOManager& CoreTools::LogAppenderIOManager::operator<<(float value) noexcept
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    try
    {
        ScopedMutex scopedMutex{ m_LogAppenderIOManagerMutex };

        *m_Impl << value;
    }
    catch (...)
    {
        System::OutputDebugStringWithTChar(SYSTEM_TEXT("LogAppenderIOManager operator<<抛出异常"));
    }

    return *this;
}

CoreTools::LogAppenderIOManager& CoreTools::LogAppenderIOManager::operator<<(double value) noexcept
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    try
    {
        ScopedMutex scopedMutex{ m_LogAppenderIOManagerMutex };

        *m_Impl << value;
    }
    catch (...)
    {
        System::OutputDebugStringWithTChar(SYSTEM_TEXT("LogAppenderIOManager operator<<抛出异常"));
    }

    return *this;
}

CoreTools::LogAppenderIOManager& CoreTools::LogAppenderIOManager::operator<<(const string& message) noexcept
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    try
    {
        ScopedMutex scopedMutex{ m_LogAppenderIOManagerMutex };

        *m_Impl << message;
    }
    catch (...)
    {
        System::OutputDebugStringWithTChar(SYSTEM_TEXT("LogAppenderIOManager operator<<抛出异常"));
    }
    return *this;
}

CoreTools::LogAppenderIOManager& CoreTools::LogAppenderIOManager::operator<<(const wstring& message) noexcept
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    try
    {
        ScopedMutex scopedMutex{ m_LogAppenderIOManagerMutex };

        *m_Impl << message;
    }
    catch (...)
    {
        System::OutputDebugStringWithTChar(SYSTEM_TEXT("LogAppenderIOManager operator<<抛出异常"));
    }

    return *this;
}

CoreTools::LogAppenderIOManager& CoreTools::LogAppenderIOManager::operator<<(const FunctionDescribed& functionDescribed) noexcept
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    try
    {
        ScopedMutex scopedMutex{ m_LogAppenderIOManagerMutex };

        *m_Impl << functionDescribed;
    }
    catch (...)
    {
        System::OutputDebugStringWithTChar(SYSTEM_TEXT("LogAppenderIOManager operator<<抛出异常"));
    }

    return *this;
}

CoreTools::LogAppenderIOManager& CoreTools::LogAppenderIOManager::operator<<(const Error& error) noexcept
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    try
    {
        ScopedMutex scopedMutex{ m_LogAppenderIOManagerMutex };

        *m_Impl << error;
    }
    catch (...)
    {
        System::OutputDebugStringWithTChar(SYSTEM_TEXT("LogAppenderIOManager operator<<抛出异常"));
    }

    return *this;
}

CoreTools::LogAppenderIOManager& CoreTools::LogAppenderIOManager::operator<<(const std::exception& error) noexcept
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    try
    {
        ScopedMutex scopedMutex{ m_LogAppenderIOManagerMutex };

        *m_Impl << error;
    }
    catch (...)
    {
        System::OutputDebugStringWithTChar(SYSTEM_TEXT("LogAppenderIOManager operator<<抛出异常"));
    }

    return *this;
}

CoreTools::LogAppenderIOManager& CoreTools::LogAppenderIOManager::operator<<(LogFilter filterType) noexcept
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    try
    {
        ScopedMutex scopedMutex{ m_LogAppenderIOManagerMutex };

        *m_Impl << filterType;
    }
    catch (...)
    {
        System::OutputDebugStringWithTChar(SYSTEM_TEXT("LogAppenderIOManager operator<<抛出异常"));
    }

    return *this;
}

CoreTools::LogAppenderIOManager& CoreTools::LogAppenderIOManager::operator<<(LogAppenderIOManageSign sign) noexcept
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    try
    {
        ScopedMutex scopedMutex{ m_LogAppenderIOManagerMutex };

        *m_Impl << sign;
    }
    catch (...)
    {
        System::OutputDebugStringWithTChar(SYSTEM_TEXT("LogAppenderIOManager operator<<抛出异常"));
    }

    return *this;
}

CoreTools::LogAppenderIOManager& CoreTools::LogAppenderIOManager::operator<<(const LogFileName& logFileName) noexcept
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    try
    {
        ScopedMutex scopedMutex{ m_LogAppenderIOManagerMutex };

        *m_Impl << logFileName;
    }
    catch (...)
    {
        System::OutputDebugStringWithTChar(SYSTEM_TEXT("LogAppenderIOManager operator<<抛出异常"));
    }

    return *this;
}

CoreTools::LogAppenderIOManager& CoreTools::LogAppenderIOManager::operator<<(const char* message) noexcept
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    try
    {
        ScopedMutex scopedMutex{ m_LogAppenderIOManagerMutex };

        *m_Impl << message;
    }
    catch (...)
    {
        System::OutputDebugStringWithTChar(SYSTEM_TEXT("LogAppenderIOManager operator<<抛出异常"));
    }

    return *this;
}

CoreTools::LogAppenderIOManager& CoreTools::LogAppenderIOManager::operator<<(const wchar_t* message) noexcept
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    try
    {
        ScopedMutex scopedMutex{ m_LogAppenderIOManagerMutex };

        *m_Impl << message;
    }
    catch (...)
    {
        System::OutputDebugStringWithTChar(SYSTEM_TEXT("LogAppenderIOManager operator<<抛出异常"));
    }

    return *this;
}
