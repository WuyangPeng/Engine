/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/25 22:19)

#include "DatabaseGenerate/DatabaseGenerateBase/AncientBooks/Year.h"
#include "DatabaseGenerate/DatabaseGenerateBase/AncientBooks/YearContainerDetail.h"
#include "DatabaseGenerate/DatabaseGenerateBase/DatabaseEntity/YearEntity.h"
#include "DatabaseGenerate/DatabaseGenerateCore/Convert/ConvertEntity.h"
#include "DatabaseGenerate/DatabaseGenerateCore/Helper/DatabaseGenerateCoreClassInvariantMacro.h"
#include "YearConvertTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

DatabaseGenerateCoreTesting::YearConvertTesting::YearConvertTesting(const OStreamShared& stream, YearContainer yearContainer)
    : ParentType{ stream }, yearContainer{ std::move(yearContainer) }
{
    DATABASE_GENERATE_CORE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(DatabaseGenerateCoreTesting, YearConvertTesting)

void DatabaseGenerateCoreTesting::YearConvertTesting::ConvertTest(const DatabaseFlushSharedPtr& databaseFlush)
{
    DatabaseGenerateCore::ConvertEntity convertEntity{ databaseFlush };

    for (const auto& year : yearContainer.GetContainer())
    {
        const auto yearEntity = convertEntity.Convert(*year);

        ASSERT_NOT_THROW_EXCEPTION_2(EqualTest, *year, yearEntity);
    }
}

void DatabaseGenerateCoreTesting::YearConvertTesting::EqualTest(const Year& year, const YearEntity& yearEntity)
{
    ASSERT_EQUAL(yearEntity.GetName(), CoreTools::StringConversion::StandardConversionUtf8(year.GetName()));
    ASSERT_EQUAL(yearEntity.GetSexagenaryCycle(), year.GetSexagenaryCycle());
    ASSERT_EQUAL(yearEntity.GetReignTitle(), year.GetReignTitle());
    ASSERT_EQUAL(yearEntity.GetYear(), year.GetYear());
    ASSERT_EQUAL(yearEntity.GetUnorthodoxReignTitle(), year.GetUnorthodoxReignTitle());
    ASSERT_EQUAL(yearEntity.GetUnorthodoxYear(), year.GetUnorthodoxYear());
}
