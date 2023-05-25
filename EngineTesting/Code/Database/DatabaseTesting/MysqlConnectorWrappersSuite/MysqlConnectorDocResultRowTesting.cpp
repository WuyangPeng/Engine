///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/25 16:19)

#include "MysqlConnectorDocResultRowTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h"
#include "Database/Configuration/ConfigurationStrategy.h" 
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
using std::cout;
using std::endl;
using std::string;
using std::vector;

Database::MysqlConnectorDocResultRowTesting::MysqlConnectorDocResultRowTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    DATABASE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Database, MysqlConnectorDocResultRowTesting)

void Database::MysqlConnectorDocResultRowTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Database::MysqlConnectorDocResultRowTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ResultRowTest);
}

void Database::MysqlConnectorDocResultRowTesting::ResultRowTest()
{
    ConfigurationStrategy configurationStrategy{ WrappersStrategy::MysqlConnector, "43.139.123.106", 33060, "tcretest", "root", "TCRE" };

   
}
