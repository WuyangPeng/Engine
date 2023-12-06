/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.1 (2023/11/30 22:36)

#include "DatabaseGenerate/DatabaseGenerateBase/AncientBooks/Month.h"
#include "DatabaseGenerate/DatabaseGenerateBase/AncientBooks/MonthContainerDetail.h"
#include "DatabaseGenerate/DatabaseGenerateCore/Helper/DatabaseGenerateCoreClassInvariantMacro.h"
#include "MonthTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

DatabaseGenerateBaseTesting::MonthTesting::MonthTesting(const OStreamShared& stream, const AncientBooksContainer& ancientBooksContainer)
    : ParentType{ stream },
      ancientBooksContainer{ ancientBooksContainer },
      monthContainer{ ancientBooksContainer.GetMonthContainer() }
{
    DATABASE_GENERATE_CORE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(DatabaseGenerateBaseTesting, MonthTesting)

void DatabaseGenerateBaseTesting::MonthTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void DatabaseGenerateBaseTesting::MonthTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(EffectiveTest);
}

void DatabaseGenerateBaseTesting::MonthTesting::EffectiveTest()
{
    for (const auto& month : monthContainer->GetContainer())
    {
        ASSERT_NOT_THROW_EXCEPTION_1(NameTest, *month);
    }
}

void DatabaseGenerateBaseTesting::MonthTesting::NameTest(const Month& month)
{
    ASSERT_FALSE(month.GetName().empty());
}
