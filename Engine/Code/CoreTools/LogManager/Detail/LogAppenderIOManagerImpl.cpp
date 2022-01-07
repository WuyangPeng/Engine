//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.2 (2020/10/15 18:32)

#include "CoreTools/CoreToolsExport.h"

#include "LogAppenderIOManagerImpl.h"
#include "System/Helper/PragmaWarning/Format.h"
#include "System/SystemOutput/OutputDebugString.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/LogManager/AppenderManager.h"
#include "CoreTools/LogManager/LogFileName.h"
#include "CoreTools/LogManager/LogMessage.h"

using std::make_shared;
using std::string;
using std::wstring;
using namespace std::literals;

CoreTools::LogAppenderIOManagerImpl::LogAppenderIOManagerImpl(LogLevel logLevel, const AppenderManagerPtr& appenderManager) noexcept
    : m_logLevel{ logLevel }, m_AppenderManager{ appenderManager }, m_FilterTypePtr{}, m_FunctionDescribedPtr{},
      m_LogFileNamePtr{}, m_Message{}, m_TriggerAssert{ false }, m_AlwaysConsole{ false }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CoreTools::LogAppenderIOManagerImpl::LogAppenderIOManagerImpl(MAYBE_UNUSED int count) noexcept
    : m_logLevel{ LogLevel::Disabled }, m_AppenderManager{}, m_FilterTypePtr{}, m_FunctionDescribedPtr{},
      m_LogFileNamePtr{}, m_Message{}, m_TriggerAssert{ false }, m_AlwaysConsole{ false }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CoreTools::LogAppenderIOManagerImpl::~LogAppenderIOManagerImpl() noexcept
{
    try
    {
        Refresh();
    }
    catch (...)
    {
        // 略过异常
        System::OutputDebugStringWithTChar(SYSTEM_TEXT("LogAppenderIOManagerImpl 析构抛出异常"));
    }

    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
bool CoreTools::LogAppenderIOManagerImpl::IsValid() const noexcept
{
    if (m_logLevel != LogLevel::MaxLogLevels)
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

CoreTools::LogAppenderIOManagerImpl& CoreTools::LogAppenderIOManagerImpl::operator<<(const string& message) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    try
    {
        m_Message += StringConversion::MultiByteConversionStandard(message);
    }
    catch (...)
    {
        // 略过异常
        System::OutputDebugStringWithTChar(SYSTEM_TEXT("LogAppenderIOManagerImpl operator<<(const string&) 抛出异常"));
    }

    return *this;
}

CoreTools::LogAppenderIOManagerImpl& CoreTools::LogAppenderIOManagerImpl::operator<<(const std::string_view& message) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    try
    {
        m_Message += StringConversion::MultiByteConversionStandard(message.data());
    }
    catch (...)
    {
        // 略过异常
        System::OutputDebugStringWithTChar(SYSTEM_TEXT("LogAppenderIOManagerImpl operator<<(const wstring&) 抛出异常"));
    }

    return *this;
}

CoreTools::LogAppenderIOManagerImpl& CoreTools::LogAppenderIOManagerImpl::operator<<(const wstring& message) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    try
    {
        m_Message += StringConversion::WideCharConversionStandard(message);
    }
    catch (...)
    {
        // 略过异常
        System::OutputDebugStringWithTChar(SYSTEM_TEXT("LogAppenderIOManagerImpl operator<<(const wstring&) 抛出异常"));
    }

    return *this;
}

CoreTools::LogAppenderIOManagerImpl& CoreTools::LogAppenderIOManagerImpl::operator<<(const Error& error) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    try
    {
        m_Message += SYSTEM_TEXT("异常："s) + error.GetError();
        m_FunctionDescribedPtr = make_shared<FunctionDescribed>(error.GetFunctionDescribed());
    }
    catch (...)
    {
        // 略过异常
        System::OutputDebugStringWithTChar(SYSTEM_TEXT("LogAppenderIOManagerImpl operator<<(const Error&) 抛出异常"));
    }

    return *this;
}

CoreTools::LogAppenderIOManagerImpl& CoreTools::LogAppenderIOManagerImpl::operator<<(const std::exception& error) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    try
    {
        m_Message += SYSTEM_TEXT("异常："s) + StringConversion::MultiByteConversionStandard(error.what());
    }
    catch (...)
    {
        // 略过异常
        System::OutputDebugStringWithTChar(SYSTEM_TEXT("LogAppenderIOManagerImpl operator<<(const Error&) 抛出异常"));
    }

    return *this;
}

CoreTools::LogAppenderIOManagerImpl& CoreTools::LogAppenderIOManagerImpl::operator<<(LogFilter filterType) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    try
    {
        if (m_FilterTypePtr != nullptr)
        {
            Refresh();
        }

        m_FilterTypePtr = make_shared<LogFilter>(filterType);
    }
    catch (...)
    {
        // 略过异常
        System::OutputDebugStringWithTChar(SYSTEM_TEXT("LogAppenderIOManagerImpl operator<<(LogFilter) 抛出异常"));
    }

    return *this;
}

CoreTools::LogAppenderIOManagerImpl& CoreTools::LogAppenderIOManagerImpl::operator<<(const FunctionDescribed& functionDescribed) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    try
    {
        if (m_FunctionDescribedPtr != nullptr)
        {
            Refresh();
        }

        m_FunctionDescribedPtr = make_shared<FunctionDescribed>(functionDescribed);
    }
    catch (...)
    {
        // 略过异常
        System::OutputDebugStringWithTChar(SYSTEM_TEXT("LogAppenderIOManagerImpl operator<<(const FunctionDescribed&) 抛出异常"));
    }

    return *this;
}

CoreTools::LogAppenderIOManagerImpl& CoreTools::LogAppenderIOManagerImpl::operator<<(LogAppenderIOManageSign sign) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    try
    {
        switch (sign)
        {
            case LogAppenderIOManageSign::BlankSpace:
            {
                m_Message += SYSTEM_TEXT(' ');
                break;
            }
            case LogAppenderIOManageSign::Newline:
            {
                m_Message += SYSTEM_TEXT('\n');
                break;
            }
            case LogAppenderIOManageSign::Refresh:
            {
                Refresh();
                break;
            }
            case LogAppenderIOManageSign::TriggerAssert:
            {
                m_TriggerAssert = true;
                break;
            }
            case LogAppenderIOManageSign::AlwaysConsole:
            {
                m_AlwaysConsole = true;
                break;
            }
            default:
            {
                CORE_TOOLS_ASSERTION_2(false, "LogAppenderIOManageSign错误！");
                break;
            }
        }
    }
    catch (...)
    {
        // 略过异常
        System::OutputDebugStringWithTChar(SYSTEM_TEXT("LogAppenderIOManagerImpl operator<<(LogAppenderIOManageSign) 抛出异常"));
    }

    return *this;
}

CoreTools::LogAppenderIOManagerImpl& CoreTools::LogAppenderIOManagerImpl::operator<<(const LogFileName& logFileName) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    try
    {
        if (m_LogFileNamePtr != nullptr)
        {
            Refresh();
        }

        m_LogFileNamePtr = make_shared<LogFileName>(logFileName);
    }
    catch (...)
    {
        // 略过异常
        System::OutputDebugStringWithTChar(SYSTEM_TEXT("LogAppenderIOManagerImpl operator<<(const LogFileName&) 抛出异常"));
    }

    return *this;
}

CoreTools::LogAppenderIOManagerImpl& CoreTools::LogAppenderIOManagerImpl::operator<<(const char* message) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    try
    {
        m_Message += StringConversion::MultiByteConversionStandard(message);
    }
    catch (...)
    {
        // 略过异常
        System::OutputDebugStringWithTChar(SYSTEM_TEXT("LogAppenderIOManagerImpl operator<<(const char*) 抛出异常"));
    }

    return *this;
}

CoreTools::LogAppenderIOManagerImpl& CoreTools::LogAppenderIOManagerImpl::operator<<(const wchar_t* message) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    try
    {
        m_Message += StringConversion::WideCharConversionStandard(message);
    }
    catch (...)
    {
        // 略过异常
        System::OutputDebugStringWithTChar(SYSTEM_TEXT("LogAppenderIOManagerImpl operator<<(const wchar_t*) 抛出异常"));
    }

    return *this;
}

// private
void CoreTools::LogAppenderIOManagerImpl::Refresh()
{
    if (Write())
    {
        TriggerAssert();
        Reset();
    }
}

// private
bool CoreTools::LogAppenderIOManagerImpl::Write()
{
    if (m_logLevel != LogLevel::Disabled && m_FilterTypePtr != nullptr && m_AppenderManager != nullptr && m_FunctionDescribedPtr != nullptr)
    {
        LogMessage message{ m_logLevel, *m_FilterTypePtr, m_Message, *m_FunctionDescribedPtr };

        if (m_LogFileNamePtr != nullptr)
        {
            m_AppenderManager->Write(m_LogFileNamePtr->GetFileName(), message);
            if (m_AlwaysConsole && m_LogFileNamePtr->GetFileName() != m_AppenderManager->GetConsoleAppenderName())
            {
                m_AppenderManager->WriteToConsole(message);
            }
        }
        else
        {
            m_AppenderManager->Write(message);
        }

        return true;
    }

    return false;
}

// private
void CoreTools::LogAppenderIOManagerImpl::TriggerAssert()
{
    if (m_TriggerAssert)
    {
        auto assertMessage = StringConversion::StandardConversionMultiByte(m_Message);

        if (m_FunctionDescribedPtr != nullptr)
        {
            CORE_TOOLS_ASSERTION_USE_FUNCTION_DESCRIBED_2(false, *m_FunctionDescribedPtr, assertMessage.c_str());
        }
        else
        {
            CORE_TOOLS_ASSERTION_2(false, assertMessage.c_str());
        }
    }
}

// private
void CoreTools::LogAppenderIOManagerImpl::Reset() noexcept
{
    m_Message.clear();
    m_FilterTypePtr.reset();
    m_FunctionDescribedPtr.reset();
    m_LogFileNamePtr.reset();
    m_TriggerAssert = false;
    m_AlwaysConsole = false;
}

void CoreTools::LogAppenderIOManagerImpl::SetAppenderManager(const AppenderManagerPtr& appenderManager) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    m_AppenderManager = appenderManager;
}
