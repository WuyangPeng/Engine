///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/14 16:26)

#include "RedisStatementTesting.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "CoreTools/Helper/UnitTest/AssertTestMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Database/Configuration/Flags/ConfigurationStrategyFlags.h"
#include "Database/DatabaseInterface/BasisDatabase.h"
#include "Database/DatabaseInterface/BasisDatabaseContainer.h"
#include "Database/DatabaseInterface/BasisDatabaseManager.h"
#include "Database/DatabaseInterface/Flags/DataType.h"
#include "Database/Statement/RedisStatement.h"
#include "Toolset/Database/DatabaseEntity/DatabaseEntity/Chapter.h"

using namespace std::literals;

Database::RedisStatementTesting::RedisStatementTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    DATABASE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Database, RedisStatementTesting)

void Database::RedisStatementTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Database::RedisStatementTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(InsertStatementTest);
    ASSERT_NOT_THROW_EXCEPTION_0(UpdateStatementTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DeleteStatementTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SelectStatementTest);
}

void Database::RedisStatementTesting::InsertStatementTest()
{
    const BasisDatabaseContainer key{ BasisDatabase{ "key", 1 } };
    BasisDatabaseManager basisDatabaseManager{ WrappersStrategy::Redis, "basis", ChangeType::Insert, key };

    basisDatabaseManager.Modify(BasisDatabase{ "chapterId", 2 });
    basisDatabaseManager.Modify(BasisDatabase{ "chapterName", "chapterNameValue"s });

    const auto statement = RedisStatement::GenerateStatement("tcretest", basisDatabaseManager);

    ASSERT_UNEQUAL(statement.find("basis"), std::string::npos);

    ASSERT_UNEQUAL(statement.find("hmset"), std::string::npos);
    ASSERT_UNEQUAL(statement.find("chapterId"), std::string::npos);
    ASSERT_UNEQUAL(statement.find("chapterName"), std::string::npos);
    ASSERT_UNEQUAL(statement.find("chapterNameValue"), std::string::npos);
    ASSERT_UNEQUAL(statement.find('1'), std::string::npos);
    ASSERT_UNEQUAL(statement.find('2'), std::string::npos);
}

void Database::RedisStatementTesting::UpdateStatementTest()
{
    const BasisDatabaseContainer key{ BasisDatabase{ "key", 1 } };
    BasisDatabaseManager basisDatabaseManager{ WrappersStrategy::Redis, "basis", ChangeType::Update, key };

    basisDatabaseManager.Modify(BasisDatabase{ "chapterId", 2 });
    basisDatabaseManager.Modify(BasisDatabase{ "chapterName", "chapterNameValue"s });

    const auto statement = RedisStatement::GenerateStatement("tcretest", basisDatabaseManager);

    ASSERT_UNEQUAL(statement.find("basis"), std::string::npos);

    ASSERT_UNEQUAL(statement.find("hmset"), std::string::npos);
    ASSERT_UNEQUAL(statement.find("chapterId"), std::string::npos);
    ASSERT_UNEQUAL(statement.find("chapterName"), std::string::npos);
    ASSERT_UNEQUAL(statement.find("chapterNameValue"), std::string::npos);
    ASSERT_UNEQUAL(statement.find('1'), std::string::npos);
    ASSERT_UNEQUAL(statement.find('2'), std::string::npos);
}

void Database::RedisStatementTesting::DeleteStatementTest()
{
    const BasisDatabaseContainer key{ BasisDatabase{ "key", 1 } };
    const BasisDatabaseManager basisDatabaseManager{ WrappersStrategy::Redis, "basis", ChangeType::Delete, key };

    const auto statement = RedisStatement::GenerateStatement("tcretest", basisDatabaseManager);

    ASSERT_UNEQUAL(statement.find("del"), std::string::npos);
    ASSERT_UNEQUAL(statement.find("basis"), std::string::npos);
    ASSERT_UNEQUAL(statement.find('1'), std::string::npos);
}

void Database::RedisStatementTesting::SelectStatementTest()
{
    const auto basisDatabaseManager = ::DatabaseEntity::Chapter::GetSelect(WrappersStrategy::Redis, 5);

    const auto statement = RedisStatement::GenerateSelectStatement("tcretest", ::DatabaseEntity::Chapter::GetDatabaseFieldContainer(), basisDatabaseManager);

    ASSERT_UNEQUAL(statement.find("hmget"), std::string::npos);
}
