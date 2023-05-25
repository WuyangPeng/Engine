///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/25 16:20)

#include "MysqlConnectorDocResultTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h"
#include "Database/Configuration/ConfigurationStrategy.h" 
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
using std::string;
using std::vector;

Database::MysqlConnectorDocResultTesting::MysqlConnectorDocResultTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    DATABASE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Database, MysqlConnectorDocResultTesting)

void Database::MysqlConnectorDocResultTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Database::MysqlConnectorDocResultTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ResultTest);
}

void Database::MysqlConnectorDocResultTesting::ResultTest()
{
    ConfigurationStrategy configurationStrategy{ WrappersStrategy::MysqlConnector, "43.139.123.106", 33060, "tcretest", "root", "TCRE" };

    
}
