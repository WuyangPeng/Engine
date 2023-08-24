///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/09 22:23)

#include "DatabaseGenerateServer/DatabaseGenerateServerMiddleLayer/DatabaseGenerateServerMiddleLayerExport.h"

#include "DatabaseGenerateServer/DatabaseGenerateServerCore/Convert/AncientBooksDatabaseSave.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerMiddleLayer/Helper/DatabaseGenerateServerMiddleLayerClassInvariantMacro.h"
#include "SystemManagerImpl.h"
#include "CoreTools/Helper/LogMacro.h"
#include "Database/DatabaseInterface/DatabaseEnvironment.h"
#include "Database/DatabaseInterface/DatabaseFlush.h"

DatabaseGenerateServerMiddleLayer::SystemManagerImpl::SystemManagerImpl(const std::string& fileName)
    : isSave{ false },
      analysisDatabaseConfiguration{ fileName },
      thread{},
      mutex{},
      finishCount{ 0 }
{
    DATABASE_GENERATE_SERVER_MIDDLE_LAYER_CLASS_IS_VALID_CONST_9;
}

CLASS_INVARIANT_STUB_DEFINE(DatabaseGenerateServerMiddleLayer, SystemManagerImpl)

bool DatabaseGenerateServerMiddleLayer::SystemManagerImpl::Idle(const AncientBooksContainer& ancientBooksContainer)
{
    DATABASE_GENERATE_SERVER_MIDDLE_LAYER_CLASS_IS_VALID_9;

    if (!isSave)
    {
        CreateSaveDatabaseThread(ancientBooksContainer);
    }

    if (finishCount == analysisDatabaseConfiguration.GetSize())
    {
        LOG_SINGLETON_ENGINE_APPENDER(Info, User, SYSTEM_TEXT("数据库写入完成。"));
    }

    return true;
}

void DatabaseGenerateServerMiddleLayer::SystemManagerImpl::CreateSaveDatabaseThread(const AncientBooksContainer& ancientBooksContainer)
{
    isSave = true;

    for (const auto& element : analysisDatabaseConfiguration)
    {
        CreateSaveDatabaseThread(element.second, ancientBooksContainer);
    }
}

void DatabaseGenerateServerMiddleLayer::SystemManagerImpl::CreateSaveDatabaseThread(const ConfigurationStrategy& configurationStrategy, const AncientBooksContainer& ancientBooksContainer)
{
    DATABASE_ENVIRONMENT_SINGLETON.InitEnvironment(configurationStrategy);

    thread.emplace_back(&ClassType::SaveDatabase, this, configurationStrategy, ancientBooksContainer);
}

void DatabaseGenerateServerMiddleLayer::SystemManagerImpl::SaveDatabase(const ConfigurationStrategy& configurationStrategy, const AncientBooksContainer& ancientBooksContainer)
{
    const auto databaseFlush = std::make_shared<Database::DatabaseFlush>(configurationStrategy);

    DatabaseGenerateServerCore::AncientBooksDatabaseSave ancientBooksDatabaseSave{ databaseFlush };

    ancientBooksDatabaseSave.DatabaseSave(ancientBooksContainer);

    ++finishCount;
}

bool DatabaseGenerateServerMiddleLayer::SystemManagerImpl::Initialize()
{
    DATABASE_GENERATE_SERVER_MIDDLE_LAYER_CLASS_IS_VALID_9;

    Database::DatabaseEnvironment::Create();

    return true;
}

bool DatabaseGenerateServerMiddleLayer::SystemManagerImpl::Destroy() noexcept
{
    DATABASE_GENERATE_SERVER_MIDDLE_LAYER_CLASS_IS_VALID_9;

    thread.clear();

    Database::DatabaseEnvironment::Destroy();

    return true;
}
