/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.3 (2023/12/23 22:12)

#include "DatabaseGenerate/DatabaseGenerateBase/AncientBooks/Day.h"
#include "DatabaseGenerate/DatabaseGenerateBase/AncientBooks/DayContainerDetail.h"
#include "DatabaseGenerate/DatabaseGenerateCore/Helper/DatabaseGenerateCoreClassInvariantMacro.h"
#include "DayTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

DatabaseGenerateBaseTesting::DayTesting::DayTesting(const OStreamShared& stream, const AncientBooksContainer& ancientBooksContainer)
    : ParentType{ stream },
      ancientBooksContainer{ ancientBooksContainer },
      dayContainer{ ancientBooksContainer.GetDayContainer() }
{
    DATABASE_GENERATE_CORE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(DatabaseGenerateBaseTesting, DayTesting)

void DatabaseGenerateBaseTesting::DayTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void DatabaseGenerateBaseTesting::DayTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(EffectiveTest);
}

void DatabaseGenerateBaseTesting::DayTesting::EffectiveTest()
{
    for (const auto& day : dayContainer->GetContainer())
    {
        ASSERT_NOT_THROW_EXCEPTION_1(NameTest, *day);
    }
}

void DatabaseGenerateBaseTesting::DayTesting::NameTest(const Day& day)
{
    ASSERT_FALSE(day.GetName().empty());
}
