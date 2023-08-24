///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/14 16:28)

#include "MysqlBoostDatabaseFlushTesting.h"
#include "System/Windows/Engineering.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Database/Configuration/ConfigurationStrategy.h"
#include "Database/DatabaseInterface/BasisDatabaseManager.h"
#include "Database/DatabaseInterface/DatabaseFlush.h"
#include "Toolset/Database/DatabaseEntity/DatabaseEntity/Chapter.h"

Database::MysqlBoostDatabaseFlushTesting::MysqlBoostDatabaseFlushTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    DATABASE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Database, MysqlBoostDatabaseFlushTesting)

void Database::MysqlBoostDatabaseFlushTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Database::MysqlBoostDatabaseFlushTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ChangeDatabaseTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SelectOneTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SelectAllTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DeleteDatabaseTest);
}

void Database::MysqlBoostDatabaseFlushTesting::ChangeDatabaseTest()
{
    const ConfigurationStrategy::FlagsOption flagsOption{};
    const ConfigurationStrategy::StringOption stringOption{};
    const ConfigurationStrategy::BooleanOption booleanOption{};
    const ConfigurationStrategy::IntOption intOption{};
    const ConfigurationStrategy::SSLOption sslOption{};
    const ConfigurationStrategy::DBMapping dbMapping{};

    const ConfigurationStrategy configurationStrategy{ WrappersStrategy::MysqlBoost, "43.139.123.106", 5000, "tcretest", "root", "TCRE", true, 10, 1000, 500, 1, flagsOption, stringOption, booleanOption, intOption, sslOption, dbMapping };

    DatabaseFlush mysqlConnectorDatabaseFlush{ configurationStrategy };

    constexpr auto userId = 5LL + System::GetEngineeringOffsetValue();

    ::DatabaseEntity::Chapter chapter{ WrappersStrategy::MysqlBoost, userId };
    chapter.SetChapterId(1100000000);
    chapter.SetChapterName("ChapterName");
    chapter.SetChanceWinning(12.0);
    chapter.SetWinning(true);
    chapter.SetCurrency(2000000);
    chapter.SetCount(300000000);

    mysqlConnectorDatabaseFlush.ChangeDatabase(userId, chapter.GetModify());
}

void Database::MysqlBoostDatabaseFlushTesting::DeleteDatabaseTest()
{
    const ConfigurationStrategy::FlagsOption flagsOption{};
    const ConfigurationStrategy::StringOption stringOption{};
    const ConfigurationStrategy::BooleanOption booleanOption{};
    const ConfigurationStrategy::IntOption intOption{};
    const ConfigurationStrategy::SSLOption sslOption{};
    const ConfigurationStrategy::DBMapping dbMapping{};

    const ConfigurationStrategy configurationStrategy{ WrappersStrategy::MysqlBoost, "43.139.123.106", 5000, "tcretest", "root", "TCRE", true, 10, 1000, 500, 1, flagsOption, stringOption, booleanOption, intOption, sslOption, dbMapping };

    DatabaseFlush mysqlConnectorDatabaseFlush{ configurationStrategy };

    constexpr auto userId = 5LL + System::GetEngineeringOffsetValue();

    const ::DatabaseEntity::Chapter chapter{ WrappersStrategy::MysqlBoost, userId };

    mysqlConnectorDatabaseFlush.ChangeDatabase(userId, chapter.GetDelete());
}

void Database::MysqlBoostDatabaseFlushTesting::SelectOneTest()
{
    const ConfigurationStrategy::FlagsOption flagsOption{};
    const ConfigurationStrategy::StringOption stringOption{};
    const ConfigurationStrategy::BooleanOption booleanOption{};
    const ConfigurationStrategy::IntOption intOption{};
    const ConfigurationStrategy::SSLOption sslOption{};
    const ConfigurationStrategy::DBMapping dbMapping{};

    const ConfigurationStrategy configurationStrategy{ WrappersStrategy::MysqlBoost, "43.139.123.106", 5000, "tcretest", "root", "TCRE", true, 10, 1000, 500, 1, flagsOption, stringOption, booleanOption, intOption, sslOption, dbMapping };

    const DatabaseFlush mysqlConnectorDatabaseFlush{ configurationStrategy };

    constexpr auto userId = 5LL + System::GetEngineeringOffsetValue();

    const auto database = mysqlConnectorDatabaseFlush.SelectOne(::DatabaseEntity::Chapter::GetSelect(WrappersStrategy::MysqlBoost, userId),
                                                                ::DatabaseEntity::Chapter::GetDatabaseFieldContainer());

    ASSERT_TRUE(database.IsModify());

    const ::DatabaseEntity::Chapter chapter{ database };

    ASSERT_EQUAL(chapter.GetUserId(), userId);
    ASSERT_EQUAL(chapter.GetChapterId(), 1100000000);
    ASSERT_EQUAL(chapter.GetChapterName(), "ChapterName");
    ASSERT_EQUAL(chapter.GetChanceWinning(), 12.0);
    ASSERT_TRUE(chapter.IsWinning());
    ASSERT_EQUAL(chapter.GetCurrency(), 2000000);
    ASSERT_EQUAL(chapter.GetCount(), 300000000);
}

void Database::MysqlBoostDatabaseFlushTesting::SelectAllTest()
{
    const ConfigurationStrategy::FlagsOption flagsOption{};
    const ConfigurationStrategy::StringOption stringOption{};
    const ConfigurationStrategy::BooleanOption booleanOption{};
    const ConfigurationStrategy::IntOption intOption{};
    const ConfigurationStrategy::SSLOption sslOption{};
    const ConfigurationStrategy::DBMapping dbMapping{};

    const ConfigurationStrategy configurationStrategy{ WrappersStrategy::MysqlBoost, "43.139.123.106", 5000, "tcretest", "root", "TCRE", true, 10, 1000, 500, 1, flagsOption, stringOption, booleanOption, intOption, sslOption, dbMapping };

    const DatabaseFlush mysqlConnectorDatabaseFlush{ configurationStrategy };

    constexpr auto userId = 5LL + System::GetEngineeringOffsetValue();

    const auto database = mysqlConnectorDatabaseFlush.SelectAll(::DatabaseEntity::Chapter::GetSelect(WrappersStrategy::MysqlBoost, userId),
                                                                ::DatabaseEntity::Chapter::GetDatabaseFieldContainer());

    ASSERT_FALSE(database.empty());

    const ::DatabaseEntity::Chapter chapter{ database.at(0) };

    ASSERT_EQUAL(chapter.GetUserId(), userId);
    ASSERT_EQUAL(chapter.GetChapterId(), 1100000000);
    ASSERT_EQUAL(chapter.GetChapterName(), "ChapterName");
    ASSERT_EQUAL(chapter.GetChanceWinning(), 12.0);
    ASSERT_TRUE(chapter.IsWinning());
    ASSERT_EQUAL(chapter.GetCurrency(), 2000000);
    ASSERT_EQUAL(chapter.GetCount(), 300000000);
}