///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/14 15:23)

#include "Database/DatabaseExport.h"

#include "DatabaseManagerImpl.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Database/Configuration/AnalysisDatabaseConfiguration.h"
#include "Database/DatabaseInterface/BasisDatabaseManagerDetail.h"
#include "Database/DatabaseInterface/DatabaseEnvironment.h"
#include "Database/DatabaseInterface/DatabaseFlush.h"

Database::DatabaseManagerImpl::DatabaseManagerImpl(const std::string& fileName)
    : databaseFlush{}
{
    LoadFlush(fileName);

    DATABASE_SELF_CLASS_IS_VALID_9;
}

void Database::DatabaseManagerImpl::LoadFlush(const std::string& fileName)
{
    for (const AnalysisDatabaseConfiguration analysisDatabaseConfiguration{ fileName };
         const auto& element : analysisDatabaseConfiguration)
    {
        databaseFlush.emplace(element.first, std::make_shared<DatabaseFlush>(element.second));

        DATABASE_ENVIRONMENT_SINGLETON.InitEnvironment(element.second);
    }
}

CLASS_INVARIANT_STUB_DEFINE(Database, DatabaseManagerImpl)

void Database::DatabaseManagerImpl::ChangeDatabase(const String& databaseIndex, int64_t userId, const BasisDatabaseManager& basisDatabaseContainer)
{
    DATABASE_CLASS_IS_VALID_9;

    if (const auto iter = databaseFlush.find(databaseIndex);
        iter != databaseFlush.cend())
    {
        iter->second->ChangeDatabase(userId, basisDatabaseContainer);
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("数据库索引不存在。"))
    }
}

Database::BasisDatabaseManager Database::DatabaseManagerImpl::SelectOne(const String& databaseIndex, const BasisDatabaseManager& basisDatabaseContainer, const FieldNameContainer& fieldNameContainer) const
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    if (const auto iter = databaseFlush.find(databaseIndex);
        iter != databaseFlush.cend())
    {
        return iter->second->SelectOne(basisDatabaseContainer, fieldNameContainer);
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("数据库索引不存在。"))
    }
}

Database::DatabaseManagerImpl::ResultContainer Database::DatabaseManagerImpl::SelectAll(const String& databaseIndex, const BasisDatabaseManager& basisDatabaseContainer, const FieldNameContainer& fieldNameContainer) const
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    if (const auto iter = databaseFlush.find(databaseIndex);
        iter != databaseFlush.cend())
    {
        return iter->second->SelectAll(basisDatabaseContainer, fieldNameContainer);
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("数据库索引不存在。"))
    }
}
