///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.10 (2023/05/26 11:24)

#include "DatabaseFieldTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Database/Configuration/ConfigurationStrategy.h"
#include "Database/DatabaseInterface/DatabaseField.h"

Database::DatabaseFieldTesting::DatabaseFieldTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    DATABASE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Database, DatabaseFieldTesting)

void Database::DatabaseFieldTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Database::DatabaseFieldTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(DatabaseFieldTest);
}

void Database::DatabaseFieldTesting::DatabaseFieldTest()
{
    constexpr DatabaseField databaseField{ "field", DataType::Bool, IndexType::Key };

    static_assert(databaseField.GetFieldName() == "field");
    static_assert(databaseField.GetDataType() == DataType::Bool);
    static_assert(databaseField.GetIndexType() == IndexType::Key);
}
