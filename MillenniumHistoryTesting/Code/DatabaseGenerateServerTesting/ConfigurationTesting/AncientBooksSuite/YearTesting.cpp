///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.0 (2023/06/24 12:17)

#include "DatabaseGenerateServer/DatabaseGenerateServerBase/AncientBooks/Year.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerBase/AncientBooks/YearContainerDetail.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerCore/Helper/DatabaseGenerateServerCoreClassInvariantMacro.h"
#include "YearTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

DatabaseGenerateServerBaseTesting::YearTesting::YearTesting(const OStreamShared& stream, const AncientBooksContainer& ancientBooksContainer)
    : ParentType{ stream }, ancientBooksContainer{ ancientBooksContainer }
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
    const auto yearContainer = ancientBooksContainer.GetYearContainer();

    for (const auto& year : yearContainer->GetContainer())
    {
        ASSERT_GREATER(year->GetSexagenaryCycle(), 0);
        ASSERT_UNEQUAL_NULL_PTR(year->GetSexagenaryCycle(ancientBooksContainer));

        if (0 < year->GetReignTitle())
        {
            ASSERT_UNEQUAL_NULL_PTR(year->GetReignTitle(ancientBooksContainer));
        }

        ASSERT_EQUAL(year->GetUnorthodoxReignTitle().size(), year->GetUnorthodoxReignTitle(ancientBooksContainer).size());
        ASSERT_EQUAL(year->GetUnorthodoxYear().size(), year->GetUnorthodoxYear(ancientBooksContainer).size());
    }
}
