///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.10 (2023/05/26 13:41)

#include "DatabaseManagerTesting.h"
#include "System/Windows/Engineering.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Database/Configuration/ConfigurationStrategy.h"
#include "Database/DatabaseInterface/BasisDatabaseManager.h"
#include "Database/DatabaseInterface/DatabaseEnvironment.h"
#include "Database/DatabaseInterface/DatabaseManager.h"
#include "Toolset/Database/DatabaseEntity/DatabaseEntity/Chapter.h"

Database::DatabaseManagerTesting::DatabaseManagerTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    DATABASE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Database, DatabaseManagerTesting)

void Database::DatabaseManagerTesting::DoRunUnitTest()
{
    DatabaseEnvironment::Create();

    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);

    DatabaseEnvironment::Destroy();
}

void Database::DatabaseManagerTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(SelectOneTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DeleteTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SelectAllTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DeleteAllTest);
}

void Database::DatabaseManagerTesting::SelectOneTest()
{
    DatabaseManager databaseManager{ "Configuration/DatabaseTest.json" };

    constexpr auto userId = 5LL + System::GetEngineeringOffsetValue();

    const auto basisDatabaseManager = databaseManager.SelectOne(SYSTEM_TEXT("GameServerDB"),
                                                                ::DatabaseEntity::Chapter::GetSelect(WrappersStrategy::MysqlConnector, userId),
                                                                ::DatabaseEntity::Chapter::GetDatabaseFieldContainer());

    ASSERT_FALSE(basisDatabaseManager.IsModify());

    ::DatabaseEntity::Chapter chapter{ WrappersStrategy::MysqlConnector, userId };
    chapter.SetChapterId(1100000000);
    chapter.SetChapterName("ChapterName");
    chapter.SetChanceWinning(12.0);
    chapter.SetWinning(true);
    chapter.SetCurrency(2000000);
    chapter.SetCount(300000000);

    databaseManager.ChangeDatabase(SYSTEM_TEXT("GameServerDB"), chapter.GetUserId(), chapter.GetModify());
}

void Database::DatabaseManagerTesting::DeleteTest()
{
    DatabaseManager databaseManager{ "Configuration/DatabaseTest.json" };

    constexpr auto userId = 5LL + System::GetEngineeringOffsetValue();

    const auto basisDatabaseManager = databaseManager.SelectOne(SYSTEM_TEXT("GameServerDB"),
                                                                ::DatabaseEntity::Chapter::GetSelect(WrappersStrategy::MysqlConnector, userId),
                                                                ::DatabaseEntity::Chapter::GetDatabaseFieldContainer());

    ASSERT_TRUE(basisDatabaseManager.IsModify());

    const ::DatabaseEntity::Chapter chapter{ basisDatabaseManager };

    ASSERT_EQUAL(chapter.GetUserId(), userId);
    ASSERT_EQUAL(chapter.GetChapterId(), 1100000000);
    ASSERT_EQUAL(chapter.GetChapterName(), "ChapterName");
    ASSERT_EQUAL(chapter.GetChanceWinning(), 12.0);
    ASSERT_TRUE(chapter.IsWinning());
    ASSERT_EQUAL(chapter.GetCurrency(), 2000000);
    ASSERT_EQUAL(chapter.GetCount(), 300000000);

    databaseManager.ChangeDatabase(SYSTEM_TEXT("GameServerDB"), chapter.GetUserId(), chapter.GetDelete());
}

void Database::DatabaseManagerTesting::SelectAllTest()
{
    DatabaseManager databaseManager{ "Configuration/DatabaseTest.json" };

    constexpr auto userId = 5LL + System::GetEngineeringOffsetValue();

    const auto basisDatabaseManager = databaseManager.SelectAll(SYSTEM_TEXT("GameServerDB"),
                                                                ::DatabaseEntity::Chapter::GetSelect(WrappersStrategy::MysqlConnector, userId),
                                                                ::DatabaseEntity::Chapter::GetDatabaseFieldContainer());

    ASSERT_TRUE(basisDatabaseManager.empty());

    ::DatabaseEntity::Chapter chapter{ WrappersStrategy::MysqlConnector, userId };
    chapter.SetChapterId(1100000000);
    chapter.SetChapterName("ChapterName");
    chapter.SetChanceWinning(12.0);
    chapter.SetWinning(true);
    chapter.SetCurrency(2000000);
    chapter.SetCount(300000000);

    databaseManager.ChangeDatabase(SYSTEM_TEXT("GameServerDB"), chapter.GetUserId(), chapter.GetModify());
}

void Database::DatabaseManagerTesting::DeleteAllTest()
{
    DatabaseManager databaseManager{ "Configuration/DatabaseTest.json" };

    constexpr auto userId = 5LL + System::GetEngineeringOffsetValue();

    const auto basisDatabaseManager = databaseManager.SelectAll(SYSTEM_TEXT("GameServerDB"),
                                                                ::DatabaseEntity::Chapter::GetSelect(WrappersStrategy::MysqlConnector, userId),
                                                                ::DatabaseEntity::Chapter::GetDatabaseFieldContainer());

    ASSERT_FALSE(basisDatabaseManager.empty());

    const ::DatabaseEntity::Chapter chapter{ basisDatabaseManager.at(0) };

    ASSERT_EQUAL(chapter.GetUserId(), userId);
    ASSERT_EQUAL(chapter.GetChapterId(), 1100000000);
    ASSERT_EQUAL(chapter.GetChapterName(), "ChapterName");
    ASSERT_EQUAL(chapter.GetChanceWinning(), 12.0);
    ASSERT_TRUE(chapter.IsWinning());
    ASSERT_EQUAL(chapter.GetCurrency(), 2000000);
    ASSERT_EQUAL(chapter.GetCount(), 300000000);

    databaseManager.ChangeDatabase(SYSTEM_TEXT("GameServerDB"), chapter.GetUserId(), chapter.GetDelete());
}
