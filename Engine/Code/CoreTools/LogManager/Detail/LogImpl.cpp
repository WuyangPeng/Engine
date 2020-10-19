//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.2 (2020/10/15 18:37)

#include "CoreTools/CoreToolsExport.h"

#include "AnalysisAppenderManager.h"
#include "LogImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/LogMacro.h"
#include "CoreTools/LogManager/Appender.h"
#include "CoreTools/LogManager/LogFilterManager.h"
#include "CoreTools/LogManager/Logger.h"

using boost::property_tree::ptree_error;
using std::make_shared;
using std::string;

CoreTools::LogImpl::LogImpl(DisableNotThrow disableNotThrow)
    : m_AppenderManager{ make_shared<AppenderManager>(disableNotThrow) }, m_LogAppenderIOManagerContainer{}, m_ErrorLogAppenderIOManager{ disableNotThrow }
{
    InitIOManager();

    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

// private
void CoreTools::LogImpl::InitIOManager()
{
    for (auto logLevelType = LogLevel::Trace; logLevelType < LogLevel::MaxLogLevels; ++logLevelType)
    {
        m_LogAppenderIOManagerContainer.insert({ logLevelType, make_shared<LogAppenderIOManager>(logLevelType, m_AppenderManager) });
    }
}

void CoreTools::LogImpl::ResetIOManager()
{
    for (auto& value : m_LogAppenderIOManagerContainer)
    {
        value.second->SetAppenderManager(m_AppenderManager);
    }
}

#ifdef OPEN_CLASS_INVARIANT
bool CoreTools::LogImpl::IsValid() const noexcept
{
    try
    {
        if (m_AppenderManager != nullptr && DisabledIsNotExist())
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
    return m_LogAppenderIOManagerContainer.find(LogLevel::Disabled) == m_LogAppenderIOManagerContainer.cend();
}
#endif  // OPEN_CLASS_INVARIANT

void CoreTools::LogImpl::InsertAppender(const String& name, const Appender& appender)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    if (!m_AppenderManager->InsertAppender(name, appender))
    {
        System::OutputDebugStringWithTChar(SYSTEM_TEXT("InsertAppenderʧ�ܡ�"));
    }
}

void CoreTools::LogImpl::RemoveAppender(const String& name)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    if (!m_AppenderManager->RemoveAppender(name))
    {
        System::OutputDebugStringWithTChar(SYSTEM_TEXT("RemoveAppenderʧ�ܡ�"));
    }
}

void CoreTools::LogImpl::LoadConfiguration(const string& fileName)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    try
    {
        AnalysisAppenderManager analysis{ fileName };

        m_AppenderManager = analysis.GetAppenderManager();

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
        const auto iter = m_LogAppenderIOManagerContainer.find(type);

        if (iter != m_LogAppenderIOManagerContainer.cend())
        {
            return *iter->second;
        }
        else
        {
            CORE_TOOLS_ASSERTION_2(false, "��־������˴���,�Ҳ�����Ӧ��Appender��");
        }
    }
    catch (...)
    {
    }

    return m_ErrorLogAppenderIOManager;
}

void CoreTools::LogImpl::ReloadAppenderFile()
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    m_AppenderManager->ReloadAppenderFile();
}
