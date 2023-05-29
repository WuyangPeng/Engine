///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.9 (2023/05/23 13:38)

#include "Database/DatabaseExport.h"

#include "MongoDatabaseFlush.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Database/DatabaseInterface/BasisDatabaseManager.h"

#ifdef DATABASE_USE_MONGO

Database::MongoDatabaseFlush::MongoDatabaseFlush(const ConfigurationStrategy& configurationStrategy)
    : ParentType{ configurationStrategy }, connection{}
{
    const auto threadCount = 0 < configurationStrategy.GetThreadCount() ? configurationStrategy.GetThreadCount() : 1;
    for (auto i = 0; i < threadCount; ++i)
    {
        connection.emplace_back(std::make_shared<MongoConnection>(configurationStrategy));
    }

    DATABASE_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Database, MongoDatabaseFlush)

void Database::MongoDatabaseFlush::ChangeDatabase(int64_t userId, const BasisDatabaseManager& basisDatabaseContainer)
{
    DATABASE_CLASS_IS_VALID_9;

    CheckWrappersStrategy(basisDatabaseContainer);

    connection.at(userId % connection.size())->ChangeDatabase(basisDatabaseContainer);
}

Database::BasisDatabaseManager Database::MongoDatabaseFlush::SelectOne(const BasisDatabaseManager& basisDatabaseContainer, const FieldNameContainer& fieldNameContainer) const
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    CheckWrappersStrategy(basisDatabaseContainer);

    return connection.at(connection.size() - 1)->SelectOne(basisDatabaseContainer, fieldNameContainer);
}

Database::MongoDatabaseFlush::ResultContainer Database::MongoDatabaseFlush::SelectAll(const BasisDatabaseManager& basisDatabaseContainer, const FieldNameContainer& fieldNameContainer) const
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    CheckWrappersStrategy(basisDatabaseContainer);

    return connection.at(connection.size() - 1)->SelectAll(basisDatabaseContainer, fieldNameContainer);
}

void Database::MongoDatabaseFlush::CheckWrappersStrategy(const BasisDatabaseManager& basisDatabaseContainer) const
{
    using System::operator&;
    if ((basisDatabaseContainer.GetWrappersStrategy() & WrappersStrategy::Mongo) == WrappersStrategy::Null)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("数据库不是使用mongo。"))
    }
}

#endif  // DATABASE_USE_MONGO