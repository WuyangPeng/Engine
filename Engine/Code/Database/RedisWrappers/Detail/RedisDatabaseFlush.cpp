///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.9 (2023/05/24 21:13)

#include "Database/DatabaseExport.h"

#include "RedisDatabaseFlush.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Database/DatabaseInterface/BasisDatabaseContainer.h"

#ifdef DATABASE_USE_REDIS

Database::RedisDatabaseFlush::RedisDatabaseFlush(const ConfigurationStrategy& configurationStrategy)
    : ParentType{ configurationStrategy }, connection{}
{
    const auto threadCount = 0 < configurationStrategy.GetThreadCount() ? configurationStrategy.GetThreadCount() : 1;
    for (auto i = 0; i < threadCount; ++i)
    {
        connection.emplace_back(std::make_shared<RedisConnection>(configurationStrategy));
    }

    DATABASE_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Database, RedisDatabaseFlush)

void Database::RedisDatabaseFlush::ChangeDatabase(int64_t userId, const BasisDatabaseContainer& basisDatabaseContainer)
{
    DATABASE_CLASS_IS_VALID_9;

    CheckWrappersStrategy(basisDatabaseContainer);

    connection.at(userId % connection.size())->ChangeDatabase(basisDatabaseContainer);
}

Database::BasisDatabaseContainer Database::RedisDatabaseFlush::SelectOne(const BasisDatabaseContainer& basisDatabaseContainer, const FieldNameContainer& fieldNameContainer) const
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    CheckWrappersStrategy(basisDatabaseContainer);

    return connection.at(connection.size() - 1)->SelectOne(basisDatabaseContainer, fieldNameContainer);
}

Database::RedisDatabaseFlush::ResultContainer Database::RedisDatabaseFlush::SelectAll(const BasisDatabaseContainer& basisDatabaseContainer, const FieldNameContainer& fieldNameContainer) const
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    CheckWrappersStrategy(basisDatabaseContainer);

    return connection.at(connection.size() - 1)->SelectAll(basisDatabaseContainer, fieldNameContainer);
}

void Database::RedisDatabaseFlush::CheckWrappersStrategy(const BasisDatabaseContainer& basisDatabaseContainer) const
{
    using System::operator&;
    if ((basisDatabaseContainer.GetWrappersStrategy() & WrappersStrategy::Redis) == WrappersStrategy::Null)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("数据库不是使用Redis。"))
    }
}

#endif  // DATABASE_USE_REDIS