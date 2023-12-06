/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.1 (2023/11/30 22:35)

#include "AncientBooksContainerTesting.h"
#include "DatabaseGenerate/DatabaseGenerateCore/Helper/DatabaseGenerateCoreClassInvariantMacro.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

DatabaseGenerateBaseTesting::AncientBooksContainerTesting::AncientBooksContainerTesting(const OStreamShared& stream, const AncientBooksContainer& ancientBooksContainer)
    : ParentType{ stream }, ancientBooksContainer{ ancientBooksContainer }
{
    DATABASE_GENERATE_CORE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(DatabaseGenerateBaseTesting, AncientBooksContainerTesting)

void DatabaseGenerateBaseTesting::AncientBooksContainerTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void DatabaseGenerateBaseTesting::AncientBooksContainerTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ContainerTest);
}

void DatabaseGenerateBaseTesting::AncientBooksContainerTesting::ContainerTest()
{
    ASSERT_UNEQUAL_NULL_PTR(ancientBooksContainer.GetArticleContainer());
    ASSERT_UNEQUAL_NULL_PTR(ancientBooksContainer.GetBookContainer());
    ASSERT_UNEQUAL_NULL_PTR(ancientBooksContainer.GetCalendarContainer());
    ASSERT_UNEQUAL_NULL_PTR(ancientBooksContainer.GetCategoryContainer());
    ASSERT_UNEQUAL_NULL_PTR(ancientBooksContainer.GetCharacterContainer());
    ASSERT_UNEQUAL_NULL_PTR(ancientBooksContainer.GetCountryContainer());
    ASSERT_UNEQUAL_NULL_PTR(ancientBooksContainer.GetDayContainer());
    ASSERT_UNEQUAL_NULL_PTR(ancientBooksContainer.GetEmperorContainer());
    ASSERT_UNEQUAL_NULL_PTR(ancientBooksContainer.GetGatherContainer());
    ASSERT_UNEQUAL_NULL_PTR(ancientBooksContainer.GetGenusContainer());
    ASSERT_UNEQUAL_NULL_PTR(ancientBooksContainer.GetGeographicContainer());
    ASSERT_UNEQUAL_NULL_PTR(ancientBooksContainer.GetIdentityContainer());
    ASSERT_UNEQUAL_NULL_PTR(ancientBooksContainer.GetImperialCourtContainer());
    ASSERT_UNEQUAL_NULL_PTR(ancientBooksContainer.GetMonthContainer());
    ASSERT_UNEQUAL_NULL_PTR(ancientBooksContainer.GetReignTitleContainer());
    ASSERT_UNEQUAL_NULL_PTR(ancientBooksContainer.GetSexagenaryCycleContainer());
    ASSERT_UNEQUAL_NULL_PTR(ancientBooksContainer.GetSourceContainer());
    ASSERT_UNEQUAL_NULL_PTR(ancientBooksContainer.GetVersionContainer());
    ASSERT_UNEQUAL_NULL_PTR(ancientBooksContainer.GetYearContainer());
}