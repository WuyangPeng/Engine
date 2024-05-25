/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.9 (2024/04/23 12:38)

#include "RangeIterationTesting.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "CoreTools/Helper/UnitTest/AssertTestMacro.h"
#include "CoreTools/TemplateTools/RangeIteration.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

CoreTools::RangeIterationTesting::RangeIterationTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, RangeIterationTesting)

void CoreTools::RangeIterationTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::RangeIterationTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(RangeIterationTest);
}

void CoreTools::RangeIterationTesting::RangeIterationTest()
{
    std::vector container{ 5, 6, 9, 41 };

    const auto reverse = Reverse(container);

    auto index = 0;
    for (const auto element : reverse)
    {
        ASSERT_EQUAL(container.at(container.size() - index - 1), element);
        ++index;
    }
}