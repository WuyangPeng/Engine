///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.10 (2023/05/29 09:19)

#include "MysqlConnectorDatabaseFlushTesting.h"
#include "System/Windows/Engineering.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Database/Configuration/ConfigurationStrategy.h"
#include "Database/DatabaseInterface/BasisDatabaseManager.h"
#include "Database/DatabaseInterface/DatabaseFlush.h"
#include "Toolset/Database/DatabaseEntity/DatabaseEntity/Chapter.h"

Database::MysqlConnectorDatabaseFlushTesting::MysqlConnectorDatabaseFlushTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    DATABASE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Database, MysqlConnectorDatabaseFlushTesting)

void Database::MysqlConnectorDatabaseFlushTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Database::MysqlConnectorDatabaseFlushTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ChangeDatabaseTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SelectOneTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SelectAllTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DeleteDatabaseTest);
}

void Database::MysqlConnectorDatabaseFlushTesting::ChangeDatabaseTest()
{
    const ConfigurationStrategy::FlagsOption flagsOption{};
    const ConfigurationStrategy::StringOption stringOption{};
    const ConfigurationStrategy::BooleanOption booleanOption{};
    const ConfigurationStrategy::IntOption intOption{};
    const ConfigurationStrategy::SSLOption sslOption{};
    const ConfigurationStrategy::DBMapping dbMapping{};

    const ConfigurationStrategy configurationStrategy{ WrappersStrategy::MysqlConnector, "43.139.123.106", 33060, "tcretest", "root", "TCRE", true, 10, 1000, 500, 1, flagsOption, stringOption, booleanOption, intOption, sslOption, dbMapping };

    DatabaseFlush mysqlConnectorDatabaseFlush{ configurationStrategy };

    constexpr auto userId = 5LL + System::GetEngineeringOffsetValue();

    ::DatabaseEntity::Chapter chapter{ WrappersStrategy::MysqlConnector, userId };
    chapter.SetChapterId(1100000000);
    chapter.SetChapterName("ChapterName");
    chapter.SetChanceWinning(12.0);
    chapter.SetWinning(true);
    chapter.SetCurrency(2000000);
    chapter.SetCount(300000000);

    mysqlConnectorDatabaseFlush.ChangeDatabase(userId, chapter.GetModify());
}

void Database::MysqlConnectorDatabaseFlushTesting::DeleteDatabaseTest()
{
    const ConfigurationStrategy::FlagsOption flagsOption{};
    const ConfigurationStrategy::StringOption stringOption{};
    const ConfigurationStrategy::BooleanOption booleanOption{};
    const ConfigurationStrategy::IntOption intOption{};
    const ConfigurationStrategy::SSLOption sslOption{};
    const ConfigurationStrategy::DBMapping dbMapping{};

    const ConfigurationStrategy configurationStrategy{ WrappersStrategy::MysqlConnector, "43.139.123.106", 33060, "tcretest", "root", "TCRE", true, 10, 1000, 500, 1, flagsOption, stringOption, booleanOption, intOption, sslOption, dbMapping };

    DatabaseFlush mysqlConnectorDatabaseFlush{ configurationStrategy };

    constexpr auto userId = 5LL + System::GetEngineeringOffsetValue();

    const ::DatabaseEntity::Chapter chapter{ WrappersStrategy::MysqlConnector, userId };

    mysqlConnectorDatabaseFlush.ChangeDatabase(userId, chapter.GetDelete());
}

void Database::MysqlConnectorDatabaseFlushTesting::SelectOneTest()
{
    const ConfigurationStrategy::FlagsOption flagsOption{};
    const ConfigurationStrategy::StringOption stringOption{};
    const ConfigurationStrategy::BooleanOption booleanOption{};
    const ConfigurationStrategy::IntOption intOption{};
    const ConfigurationStrategy::SSLOption sslOption{};
    const ConfigurationStrategy::DBMapping dbMapping{};

    const ConfigurationStrategy configurationStrategy{ WrappersStrategy::MysqlConnector, "43.139.123.106", 33060, "tcretest", "root", "TCRE", true, 10, 1000, 500, 1, flagsOption, stringOption, booleanOption, intOption, sslOption, dbMapping };

    const DatabaseFlush mysqlConnectorDatabaseFlush{ configurationStrategy };

    constexpr auto userId = 5LL + System::GetEngineeringOffsetValue();

    const auto database = mysqlConnectorDatabaseFlush.SelectOne(::DatabaseEntity::Chapter::GetSelect(WrappersStrategy::MysqlConnector, userId),
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

void Database::MysqlConnectorDatabaseFlushTesting::SelectAllTest()
{
    const ConfigurationStrategy::FlagsOption flagsOption{};
    const ConfigurationStrategy::StringOption stringOption{};
    const ConfigurationStrategy::BooleanOption booleanOption{};
    const ConfigurationStrategy::IntOption intOption{};
    const ConfigurationStrategy::SSLOption sslOption{};
    const ConfigurationStrategy::DBMapping dbMapping{};

    const ConfigurationStrategy configurationStrategy{ WrappersStrategy::MysqlConnector, "43.139.123.106", 33060, "tcretest", "root", "TCRE", true, 10, 1000, 500, 1, flagsOption, stringOption, booleanOption, intOption, sslOption, dbMapping };

    const DatabaseFlush mysqlConnectorDatabaseFlush{ configurationStrategy };

    constexpr auto userId = 5LL + System::GetEngineeringOffsetValue();

    const auto database = mysqlConnectorDatabaseFlush.SelectAll(::DatabaseEntity::Chapter::GetSelect(WrappersStrategy::MysqlConnector, userId),
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
