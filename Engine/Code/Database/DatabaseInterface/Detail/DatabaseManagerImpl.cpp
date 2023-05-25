///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.9 (2023/05/24 13:44)

#include "Database/DatabaseExport.h"

#include "DatabaseManagerImpl.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Database/Configuration/AnalysisDatabaseConfiguration.h"
#include "Database/DatabaseInterface/BasisDatabaseContainerDetail.h"
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
         const auto& value : analysisDatabaseConfiguration)
    {
        databaseFlush.emplace(value.first, std::make_shared<DatabaseFlush>(value.second));

        DATABASE_ENVIRONMENT_SINGLETON.InitEnvironment(value.second);
    }
}

CLASS_INVARIANT_STUB_DEFINE(Database, DatabaseManagerImpl)

void Database::DatabaseManagerImpl::ChangeDatabase(const String& databaseIndex, int64_t userId, const BasisDatabaseContainer& basisDatabaseContainer)
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

Database::BasisDatabaseContainer Database::DatabaseManagerImpl::SelectOne(const String& databaseIndex, const BasisDatabaseContainer& basisDatabaseContainer, const FieldNameContainer& fieldNameContainer) const
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

Database::DatabaseManagerImpl::ResultContainer Database::DatabaseManagerImpl::SelectAll(const String& databaseIndex, const BasisDatabaseContainer& basisDatabaseContainer, const FieldNameContainer& fieldNameContainer) const
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
