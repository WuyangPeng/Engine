///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.10 (2023/05/26 09:17)

#include "DatabaseEntityTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Database/Configuration/ConfigurationStrategy.h"
#include "Database/DatabaseInterface/BasisDatabase.h"
#include "Database/DatabaseInterface/BasisDatabaseManager.h"
#include "Toolset/Database/DatabaseEntity/DatabaseEntity/Chapter.h"

Database::DatabaseEntityTesting::DatabaseEntityTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    DATABASE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Database, DatabaseEntityTesting)

void Database::DatabaseEntityTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Database::DatabaseEntityTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(FieldNameContainerTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SelectTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DeleteTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ChangeTypeTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ModifyTest);
}

void Database::DatabaseEntityTesting::FieldNameContainerTest()
{
    const auto& fieldNameContainer = ::DatabaseEntity::Chapter::GetDatabaseFieldContainer();

    ASSERT_FALSE(fieldNameContainer.empty());

    ASSERT_EQUAL(fieldNameContainer.at(0).GetFieldName(), "_id");
    ASSERT_EQUAL(fieldNameContainer.at(0).GetDataType(), DataType::Int64);
    ASSERT_EQUAL(fieldNameContainer.at(0).GetIndexType(), IndexType::Key);
}

void Database::DatabaseEntityTesting::SelectTest()
{
    const auto basisDatabaseManager = ::DatabaseEntity::Chapter::GetSelect(WrappersStrategy::Mongo, 5);

    ASSERT_EQUAL(basisDatabaseManager.GetWrappersStrategy(), WrappersStrategy::Mongo);
    ASSERT_EQUAL(basisDatabaseManager.GetDatabaseName(), ::DatabaseEntity::Chapter::GetDatabaseName());
    ASSERT_EQUAL(basisDatabaseManager.GetChangeType(), ChangeType::Select);

    const auto userId = basisDatabaseManager.GetKey().GetAnyValue("_id");

    ASSERT_EQUAL(std::any_cast<int64_t>(userId), 5);
}

void Database::DatabaseEntityTesting::DeleteTest()
{
    const BasisDatabaseManager basisDatabaseManager{ WrappersStrategy::Mongo,
                                                     "UserChapter",
                                                     ChangeType::Select,
                                                     BasisDatabaseContainer{ BasisDatabaseContainer::ObjectContainer{ Database::BasisDatabase{ "_id", 5LL } } },
                                                     BasisDatabaseContainer{ BasisDatabaseContainer::ObjectContainer{ Database::BasisDatabase{ "_id", 5LL },
                                                                                                                      BasisDatabase{ "chapterId", 3 } } } };

    const ::DatabaseEntity::Chapter chapter{ basisDatabaseManager };

    const auto deleteDatabase = chapter.GetDelete();

    ASSERT_EQUAL(deleteDatabase.GetChangeType(), ChangeType::Delete);

    const auto key = deleteDatabase.GetKey();
    ASSERT_EQUAL(key.GetSize(), 1);
    ASSERT_EQUAL(std::any_cast<int64_t>(key.GetAnyValue("_id")), 5);
}

void Database::DatabaseEntityTesting::ChangeTypeTest()
{
    ::DatabaseEntity::Chapter chapter{ WrappersStrategy::Mongo, 3 };

    const auto modify0 = chapter.GetModify();
    ASSERT_EQUAL(modify0.GetChangeType(), ChangeType::Insert);
    ASSERT_TRUE(chapter.IsModify());

    chapter.ClearModify();

    const auto modify1 = chapter.GetModify();
    ASSERT_EQUAL(modify1.GetChangeType(), ChangeType::Update);

    ASSERT_EQUAL(modify0.GetDatabase().GetSize(), 1);
    ASSERT_EQUAL(modify1.GetDatabase().GetSize(), 0);

    ASSERT_FALSE(chapter.IsModify());
}

void Database::DatabaseEntityTesting::ModifyTest()
{
    ::DatabaseEntity::Chapter chapter{ WrappersStrategy::Mongo, 3 };

    const auto modify0 = chapter.GetModify();

    ASSERT_EQUAL(modify0.GetValue<DataType::Int64>("_id"), 3);

    ASSERT_EQUAL(chapter.GetChapterId(), 0);
    chapter.SetChapterId(1);
    ASSERT_EQUAL(chapter.GetChapterId(), 1);

    const auto modify1 = chapter.GetModify();

    ASSERT_EQUAL(modify1.GetValue<DataType::Int32>("chapterId"), 1);

    ASSERT_FALSE(chapter.IsWinning());
    chapter.SetWinning(true);
    ASSERT_TRUE(chapter.IsWinning());

    const auto modify2 = chapter.GetModify();

    ASSERT_TRUE(modify2.GetValue<DataType::Bool>("winning"));
}
