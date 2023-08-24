///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/14 16:31)

#include "DatabaseFlushTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Database/Configuration/ConfigurationStrategy.h"
#include "Database/DatabaseInterface/BasisDatabaseManager.h"
#include "Database/DatabaseInterface/DatabaseFlush.h"
#include "Toolset/Database/DatabaseEntity/DatabaseEntity/Chapter.h"

Database::DatabaseFlushTesting::DatabaseFlushTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    DATABASE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Database, DatabaseFlushTesting)

void Database::DatabaseFlushTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Database::DatabaseFlushTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(NullDatabaseFlushTest);
}

void Database::DatabaseFlushTesting::NullDatabaseFlushTest()
{
    const ConfigurationStrategy configurationStrategy{ WrappersStrategy::Null, "127.0.0.1", 3306, "tcretest", "root", "123456" };

    DatabaseFlush databaseFlush{ configurationStrategy };

    const ::DatabaseEntity::Chapter chapter{ WrappersStrategy::MysqlConnector, 5 };

    databaseFlush.ChangeDatabase(chapter.GetUserId(), chapter.GetModify());

    const auto basisDatabaseManager0 = databaseFlush.SelectOne(::DatabaseEntity::Chapter::GetSelect(WrappersStrategy::MysqlConnector, 5),
                                                               ::DatabaseEntity::Chapter::GetDatabaseFieldContainer());

    ASSERT_FALSE(basisDatabaseManager0.IsModify());

    const auto basisDatabaseManager1 = databaseFlush.SelectAll(::DatabaseEntity::Chapter::GetSelect(WrappersStrategy::MysqlConnector, 5),
                                                               ::DatabaseEntity::Chapter::GetDatabaseFieldContainer());

    ASSERT_TRUE(basisDatabaseManager1.empty());
}
