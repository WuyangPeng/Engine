///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/21 20:31)

#include "AncientBooksContainerTesting.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerCore/Helper/DatabaseGenerateServerCoreClassInvariantMacro.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

DatabaseGenerateServerBaseTesting::AncientBooksContainerTesting::AncientBooksContainerTesting(const OStreamShared& stream, const AncientBooksContainer& ancientBooksContainer)
    : ParentType{ stream }, ancientBooksContainer{ ancientBooksContainer }
{
    DATABASE_GENERATE_SERVER_CORE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(DatabaseGenerateServerBaseTesting, AncientBooksContainerTesting)

void DatabaseGenerateServerBaseTesting::AncientBooksContainerTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void DatabaseGenerateServerBaseTesting::AncientBooksContainerTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ContainerTest);
}

void DatabaseGenerateServerBaseTesting::AncientBooksContainerTesting::ContainerTest()
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