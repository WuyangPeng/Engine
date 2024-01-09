/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/23 22:22)

#include "DatabaseEntityTesting.h"
#include "DatabaseGenerate/DatabaseGenerateCore/Helper/DatabaseGenerateCoreClassInvariantMacro.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Database/Configuration/ConfigurationStrategy.h"
#include "Database/DatabaseInterface/DatabaseEnvironment.h"
#include "Database/DatabaseInterface/DatabaseFlush.h"

#include <ranges>

DatabaseGenerateBaseTesting::DatabaseEntityTesting::DatabaseEntityTesting(const OStreamShared& stream)
    : ParentType{ stream },
      analysisDatabaseConfiguration{ "Configuration/Database.json" }
{
    DATABASE_GENERATE_CORE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(DatabaseGenerateBaseTesting, DatabaseEntityTesting)

void DatabaseGenerateBaseTesting::DatabaseEntityTesting::DoRunUnitTest()
{
    Database::DatabaseEnvironment::Create();

    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);

    Database::DatabaseEnvironment::Destroy();
}

Database::Traits::StringArray DatabaseGenerateBaseTesting::DatabaseEntityTesting::Convert(const StringContainerConstIter& begin, const StringContainerConstIter& end)
{
    Database::Traits::StringArray result{};
    for (auto iter = begin; iter != end; ++iter)
    {
        result.emplace_back(CoreTools::StringConversion::StandardConversionUtf8(*iter));
    }

    return result;
}

void DatabaseGenerateBaseTesting::DatabaseEntityTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(InitEnvironmentTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DatabaseFlushTest);
}

void DatabaseGenerateBaseTesting::DatabaseEntityTesting::InitEnvironmentTest()
{
    for (const auto& element : analysisDatabaseConfiguration | std::views::values)
    {
        DATABASE_ENVIRONMENT_SINGLETON.InitEnvironment(element);
    }
}

void DatabaseGenerateBaseTesting::DatabaseEntityTesting::DatabaseFlushTest()
{
    for (const auto& element : analysisDatabaseConfiguration | std::views::values)
    {
        ASSERT_NOT_THROW_EXCEPTION_1(DoDatabaseFlushTest, element);
    }
}

void DatabaseGenerateBaseTesting::DatabaseEntityTesting::DoDatabaseFlushTest(const ConfigurationStrategy& configurationStrategy)
{
    DatabaseFlush databaseFlush{ configurationStrategy };

    ASSERT_NOT_THROW_EXCEPTION_1(SelectOneTest, databaseFlush);
    ASSERT_NOT_THROW_EXCEPTION_1(SelectAllTest, databaseFlush);
    ASSERT_NOT_THROW_EXCEPTION_1(SelectAllSizeTest, databaseFlush);
}
