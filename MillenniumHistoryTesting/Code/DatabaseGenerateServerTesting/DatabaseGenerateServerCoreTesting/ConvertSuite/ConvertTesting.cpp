///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/01 21:51)

#include "ConvertTesting.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerCore/Helper/DatabaseGenerateServerCoreClassInvariantMacro.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Database/DatabaseInterface/BasisDatabaseManager.h"
#include "Database/DatabaseInterface/DatabaseEnvironment.h"
#include "Database/DatabaseInterface/DatabaseFlush.h"

DatabaseGenerateServerCoreTesting::ConvertTesting::ConvertTesting(const OStreamShared& stream)
    : ParentType{ stream },
      analysisDatabaseConfiguration{ "Configuration/Database.json" }
{
    DATABASE_GENERATE_SERVER_CORE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(DatabaseGenerateServerCoreTesting, ConvertTesting)

void DatabaseGenerateServerCoreTesting::ConvertTesting::DoRunUnitTest()
{
    Database::DatabaseEnvironment::Create();

    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);

    Database::DatabaseEnvironment::Destroy();
}

void DatabaseGenerateServerCoreTesting::ConvertTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(InitEnvironmentTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DatabaseFlushTest);
}

void DatabaseGenerateServerCoreTesting::ConvertTesting::InitEnvironmentTest()
{
    for (const auto& element : analysisDatabaseConfiguration)
    {
        DATABASE_ENVIRONMENT_SINGLETON.InitEnvironment(element.second);
    }
}

void DatabaseGenerateServerCoreTesting::ConvertTesting::DatabaseFlushTest()
{
    for (const auto& element : analysisDatabaseConfiguration)
    {
        ASSERT_NOT_THROW_EXCEPTION_1(DoDatabaseFlushTest, element.second);
    }
}

void DatabaseGenerateServerCoreTesting::ConvertTesting::DoDatabaseFlushTest(const ConfigurationStrategy& configurationStrategy)
{
    auto databaseFlush = std::make_shared<DatabaseFlush>(configurationStrategy);

    ASSERT_NOT_THROW_EXCEPTION_1(ConvertTest, databaseFlush);
}

Database::Traits::StringArray DatabaseGenerateServerCoreTesting::ConvertTesting::Convert(const StringContainerConstIter& begin, const StringContainerConstIter& end)
{
    Database::Traits::StringArray result{};
    for (auto iter = begin; iter != end; ++iter)
    {
        result.emplace_back(CoreTools::StringConversion::StandardConversionUtf8(*iter));
    }

    return result;
}
