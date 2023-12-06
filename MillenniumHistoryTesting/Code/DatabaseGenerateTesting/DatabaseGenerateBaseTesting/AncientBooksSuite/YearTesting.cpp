/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.1 (2023/11/30 22:37)

#include "DatabaseGenerate/DatabaseGenerateBase/AncientBooks/Year.h"
#include "DatabaseGenerate/DatabaseGenerateBase/AncientBooks/YearContainerDetail.h"
#include "DatabaseGenerate/DatabaseGenerateCore/Helper/DatabaseGenerateCoreClassInvariantMacro.h"
#include "YearTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

DatabaseGenerateBaseTesting::YearTesting::YearTesting(const OStreamShared& stream, const AncientBooksContainer& ancientBooksContainer)
    : ParentType{ stream },
      ancientBooksContainer{ ancientBooksContainer },
      yearContainer{ ancientBooksContainer.GetYearContainer() }
{
    DATABASE_GENERATE_CORE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(DatabaseGenerateBaseTesting, YearTesting)

void DatabaseGenerateBaseTesting::YearTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void DatabaseGenerateBaseTesting::YearTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MappingTest);
}

void DatabaseGenerateBaseTesting::YearTesting::MappingTest()
{
    for (const auto& year : yearContainer->GetContainer())
    {
        ASSERT_NOT_THROW_EXCEPTION_1(SexagenaryCycleMappingTest, *year);
        ASSERT_NOT_THROW_EXCEPTION_1(ReignTitleMappingTest, *year);
        ASSERT_NOT_THROW_EXCEPTION_1(UnorthodoxReignTitleMappingTest, *year);
        ASSERT_NOT_THROW_EXCEPTION_1(UnorthodoxYearMappingTest, *year);
    }
}

void DatabaseGenerateBaseTesting::YearTesting::SexagenaryCycleMappingTest(const Year& year)
{
    ASSERT_GREATER(year.GetSexagenaryCycle(), 0);
    ASSERT_UNEQUAL_NULL_PTR(year.GetSexagenaryCycle(ancientBooksContainer));
}

void DatabaseGenerateBaseTesting::YearTesting::ReignTitleMappingTest(const Year& year)
{
    if (0 < year.GetReignTitle())
    {
        ASSERT_UNEQUAL_NULL_PTR(year.GetReignTitle(ancientBooksContainer));
    }
}

void DatabaseGenerateBaseTesting::YearTesting::UnorthodoxReignTitleMappingTest(const Year& year)
{
    ASSERT_EQUAL(year.GetUnorthodoxReignTitle().size(), year.GetUnorthodoxReignTitle(ancientBooksContainer).size());
}

void DatabaseGenerateBaseTesting::YearTesting::UnorthodoxYearMappingTest(const Year& year)
{
    ASSERT_EQUAL(year.GetUnorthodoxYear().size(), year.GetUnorthodoxYear(ancientBooksContainer).size());
}
