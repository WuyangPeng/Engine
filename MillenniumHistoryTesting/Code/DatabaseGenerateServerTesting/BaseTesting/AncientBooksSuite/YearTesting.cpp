///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.0 (2023/06/24 12:17)

#include "DatabaseGenerateServer/DatabaseGenerateServerBase/AncientBooks/Year.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerBase/AncientBooks/YearContainerDetail.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerCore/Helper/DatabaseGenerateServerCoreClassInvariantMacro.h"
#include "YearTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

DatabaseGenerateServerBaseTesting::YearTesting::YearTesting(const OStreamShared& stream, const AncientBooksContainer& ancientBooksContainer)
    : ParentType{ stream },
      ancientBooksContainer{ ancientBooksContainer },
      yearContainer{ ancientBooksContainer.GetYearContainer() }
{
    DATABASE_GENERATE_SERVER_CORE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(DatabaseGenerateServerBaseTesting, YearTesting)

void DatabaseGenerateServerBaseTesting::YearTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void DatabaseGenerateServerBaseTesting::YearTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MappingTest);
}

void DatabaseGenerateServerBaseTesting::YearTesting::MappingTest()
{
    for (const auto& year : yearContainer->GetContainer())
    {
        ASSERT_NOT_THROW_EXCEPTION_1(SexagenaryCycleMappingTest, *year);
        ASSERT_NOT_THROW_EXCEPTION_1(ReignTitleMappingTest, *year);
        ASSERT_NOT_THROW_EXCEPTION_1(UnorthodoxReignTitleMappingTest, *year);
        ASSERT_NOT_THROW_EXCEPTION_1(UnorthodoxYearMappingTest, *year);
    }
}

void DatabaseGenerateServerBaseTesting::YearTesting::SexagenaryCycleMappingTest(const Year& year)
{
    ASSERT_GREATER(year.GetSexagenaryCycle(), 0);
    ASSERT_UNEQUAL_NULL_PTR(year.GetSexagenaryCycle(ancientBooksContainer));
}

void DatabaseGenerateServerBaseTesting::YearTesting::ReignTitleMappingTest(const Year& year)
{
    if (0 < year.GetReignTitle())
    {
        ASSERT_UNEQUAL_NULL_PTR(year.GetReignTitle(ancientBooksContainer));
    }
}

void DatabaseGenerateServerBaseTesting::YearTesting::UnorthodoxReignTitleMappingTest(const Year& year)
{
    ASSERT_EQUAL(year.GetUnorthodoxReignTitle().size(), year.GetUnorthodoxReignTitle(ancientBooksContainer).size());
}

void DatabaseGenerateServerBaseTesting::YearTesting::UnorthodoxYearMappingTest(const Year& year)
{
    ASSERT_EQUAL(year.GetUnorthodoxYear().size(), year.GetUnorthodoxYear(ancientBooksContainer).size());
}
