///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/25 16:20)

#include "MysqlConnectorResultRowTesting.h"
#include "System/Windows/Engineering.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Database/Configuration/ConfigurationStrategy.h"
#include "Database/SqlInterface/Session.h"

using std::string;
using std::to_string;
using std::vector;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Database, MysqlConnectorResultRowTesting)

void Database::MysqlConnectorResultRowTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ResultRowTest);
}

void Database::MysqlConnectorResultRowTesting::ResultRowTest()
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

    auto one = result->FetchOne();

    ASSERT_EQUAL(11, one->GetInt64Value(0));
}
