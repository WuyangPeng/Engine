///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/29 23:05)

#include "DatabaseEntityTesting.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerCore/Helper/DatabaseGenerateServerCoreClassInvariantMacro.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Database/Configuration/ConfigurationStrategy.h"
#include "Database/DatabaseInterface/DatabaseEnvironment.h"
#include "Database/DatabaseInterface/DatabaseFlush.h"

DatabaseGenerateServerBaseTesting::DatabaseEntityTesting::DatabaseEntityTesting(const OStreamShared& stream)
    : ParentType{ stream },
      analysisDatabaseConfiguration{ "Configuration/Database.json" }
{
    DATABASE_GENERATE_SERVER_CORE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(DatabaseGenerateServerBaseTesting, DatabaseEntityTesting)

void DatabaseGenerateServerBaseTesting::DatabaseEntityTesting::DoRunUnitTest()
{
    Database::DatabaseEnvironment::Create();

    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);

    Database::DatabaseEnvironment::Destroy();
}

Database::Traits::StringArray DatabaseGenerateServerBaseTesting::DatabaseEntityTesting::Convert(const StringContainerConstIter& begin, const StringContainerConstIter& end)
{
    Database::Traits::StringArray result{};
    for (auto iter = begin; iter != end; ++iter)
    {
        result.emplace_back(CoreTools::StringConversion::StandardConversionUtf8(*iter));
    }

    return result;
}

void DatabaseGenerateServerBaseTesting::DatabaseEntityTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(InitEnvironmentTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DatabaseFlushTest);
}

void DatabaseGenerateServerBaseTesting::DatabaseEntityTesting::InitEnvironmentTest()
{
    for (const auto& element : analysisDatabaseConfiguration)
    {
        DATABASE_ENVIRONMENT_SINGLETON.InitEnvironment(element.second);
    }
}

void DatabaseGenerateServerBaseTesting::DatabaseEntityTesting::DatabaseFlushTest()
{
    for (const auto& element : analysisDatabaseConfiguration)
    {
        ASSERT_NOT_THROW_EXCEPTION_1(DoDatabaseFlushTest, element.second);
    }
}

void DatabaseGenerateServerBaseTesting::DatabaseEntityTesting::DoDatabaseFlushTest(const ConfigurationStrategy& configurationStrategy)
{
    DatabaseFlush databaseFlush{ configurationStrategy };

    ASSERT_NOT_THROW_EXCEPTION_1(SelectOneTest, databaseFlush);
    ASSERT_NOT_THROW_EXCEPTION_1(SelectAllTest, databaseFlush);
    ASSERT_NOT_THROW_EXCEPTION_1(SelectAllSizeTest, databaseFlush);
}
