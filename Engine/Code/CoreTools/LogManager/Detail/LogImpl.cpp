///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/07 22:38)

#include "CoreTools/CoreToolsExport.h"

#include "AnalysisAppenderManager.h"
#include "LogImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/LogMacro.h"
#include "CoreTools/LogManager/Appender.h"
#include "CoreTools/LogManager/LogFilterManager.h"
#include "CoreTools/LogManager/Logger.h"

using System::operator++;

using boost::property_tree::ptree_error;
using std::make_shared;
using std::string;

CoreTools::LogImpl::LogImpl(MAYBE_UNUSED DisableNotThrow disableNotThrow)
    : appenderManager{ AppenderManager::Create() }, logAppenderIOManagerContainer{}, errorLogAppenderIOManager{ LogAppenderIOManager::Create() }
{
    InitIOManager();

    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

// private
void CoreTools::LogImpl::InitIOManager()
{
    for (auto logLevelType = LogLevel::Trace; logLevelType < LogLevel::MaxLogLevels; ++logLevelType)
    {
        logAppenderIOManagerContainer.insert({ logLevelType, LogAppenderIOManager::CreateSharedPtr(logLevelType, appenderManager) });
    }
}

void CoreTools::LogImpl::ResetIOManager() noexcept
{
    for (auto& value : logAppenderIOManagerContainer)
    {
        value.second->SetAppenderManager(appenderManager);
    }
}

#ifdef OPEN_CLASS_INVARIANT

bool CoreTools::LogImpl::IsValid() const noexcept
{
    try
    {
        if (appenderManager != nullptr && DisabledIsNotExist())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    catch (...)
    {
        return false;
    }
}

bool CoreTools::LogImpl::DisabledIsNotExist() const
{
    return logAppenderIOManagerContainer.find(LogLevel::Disabled) == logAppenderIOManagerContainer.cend();
}

#endif  // OPEN_CLASS_INVARIANT

void CoreTools::LogImpl::InsertAppender(const String& name, const Appender& appender)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    if (!appenderManager->InsertAppender(name, appender))
    {
        System::OutputDebugStringWithTChar(SYSTEM_TEXT("InsertAppender失败。"));
    }
}

void CoreTools::LogImpl::RemoveAppender(const String& name)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    if (!appenderManager->RemoveAppender(name))
    {
        System::OutputDebugStringWithTChar(SYSTEM_TEXT("RemoveAppender失败。"));
    }
}

void CoreTools::LogImpl::LoadConfiguration(const string& fileName)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    try
    {
        const AnalysisAppenderManager analysis{ fileName };

        appenderManager = analysis.GetAppenderManager();

        ResetIOManager();
    }
    catch (const ptree_error& error)
    {
        LOG_SINGLETON_ENGINE_APPENDER(Warn, CoreTools)
            << error.what()
            << LOG_SINGLETON_TRIGGER_ASSERT;
    }
}

CoreTools::LogAppenderIOManager& CoreTools::LogImpl::OutTrace() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    return Find(LogLevel::Trace);
}

CoreTools::LogAppenderIOManager& CoreTools::LogImpl::OutDebug() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    return Find(LogLevel::Debug);
}

CoreTools::LogAppenderIOManager& CoreTools::LogImpl::OutInfo() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    return Find(LogLevel::Info);
}

CoreTools::LogAppenderIOManager& CoreTools::LogImpl::OutWarn() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    return Find(LogLevel::Warn);
}

CoreTools::LogAppenderIOManager& CoreTools::LogImpl::OutError() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    return Find(LogLevel::Error);
}

CoreTools::LogAppenderIOManager& CoreTools::LogImpl::OutFatal() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    return Find(LogLevel::Fatal);
}

// private
CoreTools::LogAppenderIOManager& CoreTools::LogImpl::Find(LogLevel type) noexcept
{
    try
    {
        const auto iter = logAppenderIOManagerContainer.find(type);

        if (iter != logAppenderIOManagerContainer.cend())
        {
            return *iter->second;
        }
        else
        {
            CORE_TOOLS_ASSERTION_2(false, "日志库出现了错误,找不到对应的Appender。");
        }
    }
    catch (...)
    {
        System::OutputDebugStringWithTChar(SYSTEM_TEXT("Find LogAppenderIOManager失败。"));
    }

    return errorLogAppenderIOManager;
}

void CoreTools::LogImpl::ReloadAppenderFile()
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    appenderManager->ReloadAppenderFile();
}
