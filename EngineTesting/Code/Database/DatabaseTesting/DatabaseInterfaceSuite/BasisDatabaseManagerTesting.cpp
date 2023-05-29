///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.10 (2023/05/26 15:37)

#include "BasisDatabaseManagerTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Database/Configuration/ConfigurationStrategy.h"
#include "Database/DatabaseInterface/BasisDatabase.h"
#include "Database/DatabaseInterface/BasisDatabaseContainer.h"
#include "Database/DatabaseInterface/BasisDatabaseManagerDetail.h"

Database::BasisDatabaseManagerTesting::BasisDatabaseManagerTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    DATABASE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Database, BasisDatabaseManagerTesting)

void Database::BasisDatabaseManagerTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Database::BasisDatabaseManagerTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(BasisTest);
    ASSERT_NOT_THROW_EXCEPTION_0(GetAnyValueTest);
}

void Database::BasisDatabaseManagerTesting::BasisTest()
{
    const BasisDatabaseContainer key{ BasisDatabase{ "key", 1 } };
    const BasisDatabaseManager basisDatabaseManager{ WrappersStrategy::Mongo, "basis", ChangeType::Insert, key };

    ASSERT_ENUM_EQUAL(basisDatabaseManager.GetChangeType(), ChangeType::Insert);
    ASSERT_ENUM_EQUAL(basisDatabaseManager.GetWrappersStrategy(), WrappersStrategy::Mongo);
    ASSERT_EQUAL(basisDatabaseManager.GetDatabaseName(), "basis");

    const auto database = basisDatabaseManager.GetDatabase();
    ASSERT_EQUAL(database.GetSize(), 0);
    ASSERT_FALSE(basisDatabaseManager.IsModify());

    const auto keyResult = basisDatabaseManager.GetKey();
    ASSERT_EQUAL(keyResult.GetSize(), 1);
    ASSERT_EQUAL(keyResult.GetContainer().size(), 1u);
    ASSERT_EQUAL(std::any_cast<int32_t>(keyResult.GetAnyValue("key")), 1);
}

void Database::BasisDatabaseManagerTesting::GetAnyValueTest()
{
    const BasisDatabaseContainer key{ BasisDatabaseContainer::ObjectContainer{ BasisDatabase{ "key0", 1 }, BasisDatabase{ "key1", 2 } } };
    const BasisDatabaseContainer database{ BasisDatabaseContainer::ObjectContainer{ BasisDatabase{ "database0", 2 }, BasisDatabase{ "database1", 3 }, BasisDatabase{ "database2", 4 } } };
    BasisDatabaseManager basisDatabaseManager{ WrappersStrategy::Mongo, "basis", ChangeType::Insert, key, database };

    const auto databaseResult0 = basisDatabaseManager.GetDatabase();
    ASSERT_EQUAL(databaseResult0.GetSize(), 3);
    ASSERT_EQUAL(std::any_cast<int32_t>(databaseResult0.GetAnyValue("database0")), 2);
    ASSERT_TRUE(basisDatabaseManager.IsModify());

    ASSERT_EQUAL(basisDatabaseManager.GetValue<DataType::Int32>("database0"), 2);

    const auto keyResult = basisDatabaseManager.GetKey();
    ASSERT_EQUAL(keyResult.GetSize(), 2);

    basisDatabaseManager.Modify(BasisDatabase{ "database0", 3 });

    const auto databaseResult1 = basisDatabaseManager.GetDatabase();
    ASSERT_EQUAL(databaseResult1.GetSize(), 3);
    ASSERT_EQUAL(std::any_cast<int32_t>(databaseResult1.GetAnyValue("database0")), 3);
    ASSERT_EQUAL(std::any_cast<int32_t>(databaseResult0.GetAnyValue("database0")), 2);

    ASSERT_EQUAL(basisDatabaseManager.GetValue<DataType::Int32>("database0"), 3);

    basisDatabaseManager.Modify(BasisDatabase{ "database3", 31 });

    const auto databaseResult2 = basisDatabaseManager.GetDatabase();
    ASSERT_EQUAL(databaseResult2.GetSize(), 4);
    ASSERT_EQUAL(std::any_cast<int32_t>(databaseResult2.GetAnyValue("database3")), 31);

    ASSERT_EQUAL(basisDatabaseManager.GetValue<DataType::Int32>("database3"), 31);

    basisDatabaseManager.Set(BasisDatabaseContainer{ BasisDatabaseContainer::ObjectContainer{ BasisDatabase{ "database0", 21 }, BasisDatabase{ "database1", 3 } } });

    const auto databaseResult3 = basisDatabaseManager.GetDatabase();
    ASSERT_EQUAL(databaseResult3.GetSize(), 2);
    ASSERT_EQUAL(std::any_cast<int32_t>(databaseResult3.GetAnyValue("database0")), 21);

    ASSERT_EQUAL(basisDatabaseManager.GetValue<DataType::Int32>("database0"), 21);

    ASSERT_EQUAL(basisDatabaseManager.GetValue<DataType::Int32>("database3"), 0);
    ASSERT_EQUAL(basisDatabaseManager.GetValue<DataType::Int32>("database3", 7), 7);

    basisDatabaseManager.Clear();
    const auto databaseResult4 = basisDatabaseManager.GetDatabase();
    ASSERT_EQUAL(databaseResult4.GetSize(), 0);

    ASSERT_EQUAL(databaseResult3.GetSize(), 2);
    ASSERT_EQUAL(databaseResult2.GetSize(), 4);
    ASSERT_EQUAL(databaseResult1.GetSize(), 3);
    ASSERT_EQUAL(databaseResult0.GetSize(), 3);

    ASSERT_FALSE(basisDatabaseManager.IsModify());
}
