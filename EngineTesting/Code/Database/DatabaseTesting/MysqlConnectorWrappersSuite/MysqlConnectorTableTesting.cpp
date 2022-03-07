// Copyright (c) 2011-2020
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
//
// ÒýÇæ²âÊÔ°æ±¾£º0.0.2.5 (2020/03/16 18:57)

#include "MysqlConnectorTableTesting.h"
#include "System/Windows/Engineering.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Database/Configuration/ConfigurationStrategy.h"
#include "Database/SqlInterface/Session.h"
#include "Database/SqlInterface/Table.h"

using std::string;
using std::to_string;
using std::vector;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Database, MysqlConnectorTableTesting)

void Database::MysqlConnectorTableTesting ::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(TableTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SelectTest);
}

void Database::MysqlConnectorTableTesting ::TableTest()
{
    ConfigurationStrategy::FlagsOption flagsOption;
    ConfigurationStrategy::StringOption stringOption;
    ConfigurationStrategy::BooleanOption booleanOption;
    ConfigurationStrategy::IntOption intOption;
    ConfigurationStrategy::SSLOption sslOption;
    ConfigurationStrategy::DBMapping dbMapping;

    dbMapping.insert({ 1, "dbtest" });

    ConfigurationStrategy configurationStrategy{ WrappersStrategy::MysqlConnector, "127.0.0.1", 33060, "tcretest", "root", "TCRE", false, 10, 100, 1000,
                                                 flagsOption, stringOption, booleanOption, intOption, sslOption, dbMapping };

    Session session{ configurationStrategy };

    Schema schema{ session };

    string dbName{ "test" };
    constexpr auto engineeringOffsetValue = System::GetEngineeringOffsetValue();

    dbName += to_string(engineeringOffsetValue);

    auto quotedName = string("`") + configurationStrategy.GetDBHostName() + "`.`" + dbName + "`";
    session.Execute(string("DROP TABLE IF EXISTS") + quotedName);

    string create = "CREATE TABLE ";
    create += quotedName;
    create += "(id INT NOT NULL PRIMARY KEY AUTO_INCREMENT)";

    session.Execute(create);

    Table table{ schema, "test" };
}

void Database::MysqlConnectorTableTesting ::SelectTest()
{
    ConfigurationStrategy configurationStrategy{ WrappersStrategy::MysqlConnector, "127.0.0.1", 33060, "tcretest", "root", "TCRE" };

    Session session{ configurationStrategy };

    Schema schema{ session };

    Table employees{ schema, "employee" };
    Table::BindStatementType bindStatementType{ { "param", "m%" } };

    auto res = employees.Select({ "name", "age" }, "name like :param", "name", bindStatementType);

    auto one = res->FetchOne();

    ASSERT_EQUAL(one->GetColCount(), 2);

    ASSERT_EQUAL(one->GetStringValue(0), "m1");
    ASSERT_EQUAL(one->GetIntValue(1), 2);

    auto result = session.ExecuteResult(
        "SELECT name, age "
        "FROM employee "
        "WHERE name like ? "
        "ORDER BY name",
        "m%");

    one = result->FetchOne();

    ASSERT_EQUAL(one->GetColCount(), 2);

    ASSERT_EQUAL(one->GetStringValue(0), "m1");
    ASSERT_EQUAL(one->GetIntValue(1), 2);
}
