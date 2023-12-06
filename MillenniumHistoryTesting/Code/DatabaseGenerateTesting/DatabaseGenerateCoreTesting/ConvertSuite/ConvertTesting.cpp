/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.1 (2023/11/30 22:50)

#include "ConvertTesting.h"
#include "DatabaseGenerate/DatabaseGenerateCore/Helper/DatabaseGenerateCoreClassInvariantMacro.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Database/DatabaseInterface/BasisDatabaseManager.h"
#include "Database/DatabaseInterface/DatabaseEnvironment.h"
#include "Database/DatabaseInterface/DatabaseFlush.h"

#include <ranges>

DatabaseGenerateCoreTesting::ConvertTesting::ConvertTesting(const OStreamShared& stream)
    : ParentType{ stream },
      analysisDatabaseConfiguration{ "Configuration/Database.json" }
{
    DATABASE_GENERATE_CORE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(DatabaseGenerateCoreTesting, ConvertTesting)

void DatabaseGenerateCoreTesting::ConvertTesting::DoRunUnitTest()
{
    Database::DatabaseEnvironment::Create();

    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);

    Database::DatabaseEnvironment::Destroy();
}

void DatabaseGenerateCoreTesting::ConvertTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(InitEnvironmentTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DatabaseFlushTest);
}

void DatabaseGenerateCoreTesting::ConvertTesting::InitEnvironmentTest()
{
    for (const auto& element : analysisDatabaseConfiguration | std::views::values)
    {
        DATABASE_ENVIRONMENT_SINGLETON.InitEnvironment(element);
    }
}

void DatabaseGenerateCoreTesting::ConvertTesting::DatabaseFlushTest()
{
    for (const auto& element : analysisDatabaseConfiguration | std::views::values)
    {
        ASSERT_NOT_THROW_EXCEPTION_1(DoDatabaseFlushTest, element);
    }
}

void DatabaseGenerateCoreTesting::ConvertTesting::DoDatabaseFlushTest(const ConfigurationStrategy& configurationStrategy)
{
    auto databaseFlush = std::make_shared<DatabaseFlush>(configurationStrategy);

    ASSERT_NOT_THROW_EXCEPTION_1(ConvertTest, databaseFlush);
}

Database::Traits::StringArray DatabaseGenerateCoreTesting::ConvertTesting::Convert(const StringContainerConstIter& begin, const StringContainerConstIter& end)
{
    Database::Traits::StringArray result{};
    for (auto iter = begin; iter != end; ++iter)
    {
        result.emplace_back(CoreTools::StringConversion::StandardConversionUtf8(*iter));
    }

    return result;
}
