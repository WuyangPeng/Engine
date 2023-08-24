///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.3 (2023/08/14 16:31)

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
