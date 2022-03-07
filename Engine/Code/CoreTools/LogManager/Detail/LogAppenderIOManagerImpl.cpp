///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/07 22:34)

#include "CoreTools/CoreToolsExport.h"

#include "LogAppenderIOManagerImpl.h"
#include "System/Helper/PragmaWarning/Format.h"
#include "System/SystemOutput/OutputDebugString.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/LogManager/AppenderManager.h"
#include "CoreTools/LogManager/LogAsynchronous.h"
#include "CoreTools/LogManager/LogFileName.h"
#include "CoreTools/LogManager/LogMessage.h"

using std::make_shared;
using std::string;
using std::string_view;
using std::wstring;
using namespace std::literals;

CoreTools::LogAppenderIOManagerImpl::LogAppenderIOManagerImpl(LogLevel logLevel, const AppenderManagerSharedPtr& appenderManager) noexcept
    : logLevel{ logLevel },
      currentAppenderManager{ appenderManager },
      currentFilterType{},
      currentFunctionDescribed{},
      currentLogFileName{},
      logMessage{},
      triggerAssert{ false },
      alwaysConsole{ false }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CoreTools::LogAppenderIOManagerImpl::LogAppenderIOManagerImpl() noexcept
    : logLevel{ LogLevel::Disabled },
      currentAppenderManager{},
      currentFilterType{},
      currentFunctionDescribed{},
      currentLogFileName{},
      logMessage{},
      triggerAssert{ false },
      alwaysConsole{ false }
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
    if (logLevel != LogLevel::MaxLogLevels)
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
        if (!IsDisabled())
        {
            logMessage += StringConversion::MultiByteConversionStandard(message);
        }
    }
    catch (...)
    {
        // 略过异常
        System::OutputDebugStringWithTChar(SYSTEM_TEXT("LogAppenderIOManagerImpl operator<<(const string&) 抛出异常"));
    }

    return *this;
}

CoreTools::LogAppenderIOManagerImpl& CoreTools::LogAppenderIOManagerImpl::operator<<(const string_view& message) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    try
    {
        if (!IsDisabled())
        {
            logMessage += StringConversion::MultiByteConversionStandard(message.data());
        }
    }
    catch (...)
    {
        // 略过异常
        System::OutputDebugStringWithTChar(SYSTEM_TEXT("LogAppenderIOManagerImpl operator<<(const string_view&) 抛出异常"));
    }

    return *this;
}

CoreTools::LogAppenderIOManagerImpl& CoreTools::LogAppenderIOManagerImpl::operator<<(const wstring& message) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    try
    {
        if (!IsDisabled())
        {
            logMessage += StringConversion::WideCharConversionStandard(message);
        }
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
        if (!IsDisabled())
        {
            logMessage += SYSTEM_TEXT("异常："s) + error.GetError();
            currentFunctionDescribed = make_shared<FunctionDescribed>(error.GetFunctionDescribed());
        }
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
        if (!IsDisabled())
        {
            logMessage += SYSTEM_TEXT("异常："s) + StringConversion::MultiByteConversionStandard(error.what());
        }
    }
    catch (...)
    {
        // 略过异常
        System::OutputDebugStringWithTChar(SYSTEM_TEXT("LogAppenderIOManagerImpl operator<<(const exception&) 抛出异常"));
    }

    return *this;
}

CoreTools::LogAppenderIOManagerImpl& CoreTools::LogAppenderIOManagerImpl::operator<<(LogFilter filterType) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    try
    {
        if (currentFilterType != nullptr)
        {
            Refresh();
        }

        currentFilterType = make_shared<LogFilter>(filterType);
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
        if (currentFunctionDescribed != nullptr)
        {
            Refresh();
        }

        currentFunctionDescribed = make_shared<FunctionDescribed>(functionDescribed);
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
                logMessage += SYSTEM_TEXT(' ');
                break;
            }
            case LogAppenderIOManageSign::Newline:
            {
                logMessage += SYSTEM_TEXT('\n');
                break;
            }
            case LogAppenderIOManageSign::Refresh:
            {
                Refresh();
                break;
            }
            case LogAppenderIOManageSign::TriggerAssert:
            {
                triggerAssert = true;
                break;
            }
            case LogAppenderIOManageSign::AlwaysConsole:
            {
                alwaysConsole = true;
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
        if (currentLogFileName != nullptr)
        {
            Refresh();
        }

        currentLogFileName = make_shared<LogFileName>(logFileName);
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
        if (!IsDisabled())
        {
            logMessage += StringConversion::MultiByteConversionStandard(message);
        }
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
        if (!IsDisabled())
        {
            logMessage += StringConversion::WideCharConversionStandard(message);
        }
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
    if (logLevel != LogLevel::Disabled && currentFilterType != nullptr && currentAppenderManager != nullptr && currentFunctionDescribed != nullptr)
    {
        if (!logMessage.empty())
        {
            const LogMessage message{ logLevel, *currentFilterType, logMessage, *currentFunctionDescribed };

            if (currentLogFileName != nullptr)
            {
                LOG_ASYNCHRONOUS_SINGLETON.Registered(currentLogFileName->GetFileName(), message, currentAppenderManager);

                if (alwaysConsole && currentLogFileName->GetFileName() != currentAppenderManager->GetConsoleAppenderName())
                {
                    LOG_ASYNCHRONOUS_SINGLETON.Registered(currentAppenderManager->GetConsoleAppenderName(), message, currentAppenderManager);
                }
            }
            else
            {
                LOG_ASYNCHRONOUS_SINGLETON.Registered(message, currentAppenderManager);
            }
        }

        return true;
    }

    return false;
}

// private
void CoreTools::LogAppenderIOManagerImpl::TriggerAssert()
{
    if (triggerAssert)
    {
        const auto assertMessage = StringConversion::StandardConversionMultiByte(logMessage);

        if (currentFunctionDescribed != nullptr)
        {
            CORE_TOOLS_ASSERTION_USE_FUNCTION_DESCRIBED_2(false, *currentFunctionDescribed, assertMessage.c_str());
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
    logMessage.clear();
    currentFilterType.reset();
    currentFunctionDescribed.reset();
    currentLogFileName.reset();
    triggerAssert = false;
    alwaysConsole = false;
}

bool CoreTools::LogAppenderIOManagerImpl::IsDisabled() const
{
    if (logLevel == LogLevel::Disabled)
    {
        return true;
    }

    if (currentFilterType != nullptr)
    {
        const auto minLogLevel = currentAppenderManager->GetMinLogLevelType(*currentFilterType);

        if (minLogLevel == LogLevel::Disabled || logLevel < minLogLevel)
        {
            return true;
        }
    }

    return false;
}

void CoreTools::LogAppenderIOManagerImpl::SetAppenderManager(const AppenderManagerSharedPtr& appenderManager) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    currentAppenderManager = appenderManager;
}
