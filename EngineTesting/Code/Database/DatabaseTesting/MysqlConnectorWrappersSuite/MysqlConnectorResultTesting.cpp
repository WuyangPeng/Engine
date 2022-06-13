///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/25 16:20)

#include "MysqlConnectorResultTesting.h"
#include "System/Windows/Engineering.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Database/Configuration/ConfigurationStrategy.h"
#include "Database/SqlInterface/Collection.h"
#include "Database/SqlInterface/Result.h"
#include "Database/SqlInterface/Session.h"

using std::string;
using std::to_string;
using std::vector;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Database, MysqlConnectorResultTesting)

void Database::MysqlConnectorResultTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ResultTest);
}

void Database::MysqlConnectorResultTesting::ResultTest()
{
    ConfigurationStrategy configurationStrategy{ WrappersStrategy::MysqlConnector, "127.0.0.1", 33060, "", "root", "TCRE" };

    Session session{ configurationStrategy };

    session.Execute("USE tcretest");

    constexpr auto engineeringOffsetValue = System::GetEngineeringOffsetValue();
    auto procedure = "my_add_one_procedure" + to_string(engineeringOffsetValue);

    session.Execute("CREATE PROCEDURE " +
                    procedure +
                    " "
                    " (INOUT incr_param INT) "
                    "BEGIN "
                    "  SET incr_param = incr_param + 1;"
                    "END;");
    session.Execute("SET @my_var = ?;", 10);
    session.Execute("CALL " + procedure + "(@my_var);");
    session.Execute("DROP PROCEDURE " + procedure + ";");

    auto result = session.ExecuteResult("SELECT @my_var");
}
