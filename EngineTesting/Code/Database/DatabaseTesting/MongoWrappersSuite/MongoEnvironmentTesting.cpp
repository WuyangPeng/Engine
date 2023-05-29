///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.10 (2023/05/26 11:39)

#include "MongoEnvironmentTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Database/Configuration/ConfigurationStrategy.h"
#include "Database/DatabaseInterface/DatabaseEnvironment.h"

Database::MongoEnvironmentTesting::MongoEnvironmentTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    DATABASE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Database, MongoEnvironmentTesting)

void Database::MongoEnvironmentTesting::DoRunUnitTest()
{
    DatabaseEnvironment::Create();

    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);

    DatabaseEnvironment::Destroy();
}

void Database::MongoEnvironmentTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(InitEnvironmentTest);
}

void Database::MongoEnvironmentTesting::InitEnvironmentTest()
{
    const ConfigurationStrategy configurationStrategy{ WrappersStrategy::Mongo, "127.0.0.1", 3306, "tcretest", "root", "123456" };

    DATABASE_ENVIRONMENT_SINGLETON.InitEnvironment(configurationStrategy);
}
