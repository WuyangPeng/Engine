///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/14 15:08)

#include "Database/DatabaseExport.h"

#include "MysqlBoostDatabaseFlush.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Database/DatabaseInterface/BasisDatabaseManager.h"

Database::MysqlBoostDatabaseFlush::MysqlBoostDatabaseFlush(const ConfigurationStrategy& configurationStrategy)
    : ParentType{ configurationStrategy }, connection{}
{
    const auto threadCount = 0 < configurationStrategy.GetThreadCount() ? configurationStrategy.GetThreadCount() : 1;
    for (auto i = 0; i < threadCount; ++i)
    {
        connection.emplace_back(std::make_shared<MysqlBoostConnection>(configurationStrategy));
    }

    DATABASE_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Database, MysqlBoostDatabaseFlush)

void Database::MysqlBoostDatabaseFlush::ChangeDatabase(int64_t userId, const BasisDatabaseManager& basisDatabaseContainer)
{
    DATABASE_CLASS_IS_VALID_9;

    CheckWrappersStrategy(basisDatabaseContainer);

    connection.at(userId % connection.size())->ChangeDatabase(basisDatabaseContainer);
}

Database::BasisDatabaseManager Database::MysqlBoostDatabaseFlush::SelectOne(const BasisDatabaseManager& basisDatabaseContainer, const FieldNameContainer& fieldNameContainer) const
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    CheckWrappersStrategy(basisDatabaseContainer);

    return connection.at(connection.size() - 1)->SelectOne(basisDatabaseContainer, fieldNameContainer);
}

Database::MysqlBoostDatabaseFlush::ResultContainer Database::MysqlBoostDatabaseFlush::SelectAll(const BasisDatabaseManager& basisDatabaseContainer, const FieldNameContainer& fieldNameContainer) const
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    CheckWrappersStrategy(basisDatabaseContainer);

    return connection.at(connection.size() - 1)->SelectAll(basisDatabaseContainer, fieldNameContainer);
}

void Database::MysqlBoostDatabaseFlush::CheckWrappersStrategy(const BasisDatabaseManager& basisDatabaseContainer) const
{
    using System::operator&;
    if ((basisDatabaseContainer.GetWrappersStrategy() & WrappersStrategy::MysqlBoost) == WrappersStrategy::Null)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("数据库不是使用mysql boost。"))
    }
}

void Database::MysqlBoostDatabaseFlush::Wait()
{
    DATABASE_CLASS_IS_VALID_9;

    for (const auto& element : connection)
    {
        element->Wait();
    }
}
