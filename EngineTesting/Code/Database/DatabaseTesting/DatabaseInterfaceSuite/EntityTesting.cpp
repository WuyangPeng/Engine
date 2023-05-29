///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.10 (2023/05/26 10:55)

#include "EntityTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Database/Configuration/ConfigurationStrategy.h"
#include "Database/DatabaseInterface/EntityDetail.h"
#include "Database/DatabaseInterface/Flags/DataType.h"

Database::EntityTesting::EntityTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    DATABASE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Database, EntityTesting)

void Database::EntityTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Database::EntityTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(EntityTest);
}

void Database::EntityTesting::EntityTest()
{
    static constexpr std::string_view userIdDescribe{ "userId" };
    Entity<userIdDescribe, DataType::Int64, IndexType::Key> userId{ 1 };

    static_assert(DataType::Int64 == decltype(userId)::GetDataType());
    static_assert(IndexType::Key == decltype(userId)::GetIndexType());

    constexpr auto fieldName = decltype(userId)::GetFieldName();
    ASSERT_EQUAL(fieldName, userIdDescribe);

    const auto databaseField = decltype(userId)::GetDatabaseField();

    ASSERT_EQUAL(DataType::Int64, databaseField.GetDataType());
    ASSERT_EQUAL(IndexType::Key, databaseField.GetIndexType());

    ASSERT_EQUAL(databaseField.GetFieldName(), userIdDescribe);

    ASSERT_EQUAL(userId.GetValue(), 1);

    userId.SetValue(2);

    ASSERT_EQUAL(userId.GetValue(), 2);

    userId.ModifyValue(3);

    ASSERT_EQUAL(userId.GetValue(), 5);

    userId.ModifyValue(-13);

    ASSERT_EQUAL(userId.GetValue(), -8);
}
