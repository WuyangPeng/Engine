///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/14 16:29)

#include "UserMacroTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Database/Helper/UserMacro.h"

Database::UserMacroTesting::UserMacroTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    DATABASE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Database, UserMacroTesting)

void Database::UserMacroTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Database::UserMacroTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CloseDatabaseMaxTest);
    ASSERT_NOT_THROW_EXCEPTION_0(MacroExistTest);
}

void Database::UserMacroTesting::CloseDatabaseMaxTest()
{
    ASSERT_EQUAL(CLOSE_USE_MYSQL | CLOSE_USE_MYSQL_C_API | CLOSE_USE_MYSQL_CPP_CONNECTOR | CLOSE_USE_SQL_SERVER | CLOSE_USE_SQLITE | CLOSE_USE_POSTGRE | CLOSE_USE_ORACLE | CLOSE_USE_MARIA_DB | CLOSE_USE_MONGO | CLOSE_USE_REDIS, CLOSE_DATABASE_MAX);
}

void Database::UserMacroTesting::MacroExistTest() noexcept
{
#ifdef DATABASE_USE_MYSQL_CPP_CONNECTOR

    DATABASE_USE_MYSQL;

#endif  // DATABASE_USE_MYSQL_CPP_CONNECTOR

#ifdef DATABASE_USE_MYSQL_CPP_CONNECTOR

    DATABASE_USE_MYSQL;

#endif  // DATABASE_USE_MYSQL_CPP_CONNECTOR

#ifdef BUILDING_DATABASE_STATIC

    BUILDING_STATIC;

#endif  // BUILDING_DATABASE_STATIC
}
