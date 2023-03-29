///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.4 (2023/03/28 14:48)

#include "CoreTools/CoreToolsExport.h"

#include "AnalysisAppenderManager.h"
#include "LogImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/LogManager/Appender.h"
#include "CoreTools/LogManager/LogMessage.h"

using System::operator++;

CoreTools::LogImpl::LogImpl(DisableNotThrow disableNotThrow)
    : appenderManager{ AppenderManager::Create() }, logAppenderIOManagerContainer{}
{
    System::UnusedFunction(disableNotThrow);

    InitIOManager();

    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

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
    if (appenderManager != nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}

#endif  // OPEN_CLASS_INVARIANT

void CoreTools::LogImpl::LoadConfiguration(const AnalysisAppenderManager& analysis) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    appenderManager = analysis.GetAppenderManager();

    ResetIOManager();
}

CoreTools::LogAppenderIOManager& CoreTools::LogImpl::Find(LogLevel type)
{
    if (const auto iter = logAppenderIOManagerContainer.find(type); iter != logAppenderIOManagerContainer.cend())
    {
        return *iter->second;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("��־������˴���,�Ҳ�����Ӧ��Appender��"))
    }
}

CoreTools::LogLevel CoreTools::LogImpl::GetMinLogLevelType(LogFilter filter) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return appenderManager->GetMinLogLevelType(filter);
}

void CoreTools::LogImpl::Write(const LogMessage& logMessage)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    Find(logMessage.GetLogLevel()) << logMessage;
}