/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.1 (2023/11/28 22:39)

#include "DatabaseGenerate/DatabaseGenerateMiddleLayer/DatabaseGenerateMiddleLayerExport.h"

#include "DatabaseGenerate/DatabaseGenerateCore/Convert/AncientBooksDatabaseSave.h"
#include "DatabaseGenerate/DatabaseGenerateMiddleLayer/Helper/DatabaseGenerateMiddleLayerClassInvariantMacro.h"
#include "SystemManagerImpl.h"
#include "CoreTools/Helper/LogMacro.h"
#include "Database/DatabaseInterface/DatabaseEnvironment.h"
#include "Database/DatabaseInterface/DatabaseFlush.h"

DatabaseGenerateMiddleLayer::SystemManagerImpl::SystemManagerImpl(const std::string& fileName)
    : isSave{ false },
      analysisDatabaseConfiguration{ fileName },
      thread{},
      mutex{},
      finishCount{ 0 }
{
    DATABASE_GENERATE_MIDDLE_LAYER_CLASS_IS_VALID_CONST_9;
}

CLASS_INVARIANT_STUB_DEFINE(DatabaseGenerateMiddleLayer, SystemManagerImpl)

bool DatabaseGenerateMiddleLayer::SystemManagerImpl::Idle(const AncientBooksContainer& ancientBooksContainer)
{
    DATABASE_GENERATE_MIDDLE_LAYER_CLASS_IS_VALID_9;

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

void DatabaseGenerateMiddleLayer::SystemManagerImpl::CreateSaveDatabaseThread(const AncientBooksContainer& ancientBooksContainer)
{
    isSave = true;

    for (const auto& element : analysisDatabaseConfiguration)
    {
        CreateSaveDatabaseThread(element.second, ancientBooksContainer);
    }
}

void DatabaseGenerateMiddleLayer::SystemManagerImpl::CreateSaveDatabaseThread(const ConfigurationStrategy& configurationStrategy, const AncientBooksContainer& ancientBooksContainer)
{
    DATABASE_ENVIRONMENT_SINGLETON.InitEnvironment(configurationStrategy);

    thread.emplace_back(&ClassType::SaveDatabase, this, configurationStrategy, ancientBooksContainer);
}

void DatabaseGenerateMiddleLayer::SystemManagerImpl::SaveDatabase(const ConfigurationStrategy& configurationStrategy, const AncientBooksContainer& ancientBooksContainer)
{
    const auto databaseFlush = std::make_shared<Database::DatabaseFlush>(configurationStrategy);

    DatabaseGenerateCore::AncientBooksDatabaseSave ancientBooksDatabaseSave{ databaseFlush };

    ancientBooksDatabaseSave.DatabaseSave(ancientBooksContainer);

    ++finishCount;
}

bool DatabaseGenerateMiddleLayer::SystemManagerImpl::Initialize()
{
    DATABASE_GENERATE_MIDDLE_LAYER_CLASS_IS_VALID_9;

    Database::DatabaseEnvironment::Create();

    return true;
}

bool DatabaseGenerateMiddleLayer::SystemManagerImpl::Destroy() noexcept
{
    DATABASE_GENERATE_MIDDLE_LAYER_CLASS_IS_VALID_9;

    thread.clear();

    Database::DatabaseEnvironment::Destroy();

    return true;
}
