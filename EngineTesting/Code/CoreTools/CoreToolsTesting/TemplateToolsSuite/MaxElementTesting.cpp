/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.9 (2024/04/23 12:37)

#include "MaxElementTesting.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "CoreTools/Helper/UnitTest/AssertTestMacro.h"
#include "CoreTools/TemplateTools/MaxElement.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Base/Math.h"

CoreTools::MaxElementTesting::MaxElementTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, MaxElementTesting)

void CoreTools::MaxElementTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::MaxElementTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MaxElementTest);
    ASSERT_THROW_EXCEPTION_0(MaxElementExceptionTest);
}

void CoreTools::MaxElementTesting::MaxElementTest()
{
    ASSERT_EQUAL(MaxElement<int>({ 1, 5, 13, 6, 7, 8 }), 13);

    ASSERT_APPROXIMATE(MaxElement<double>({ 1.2, 5.6, 13.7, 26.1, 7.0, 8.0 }), 26.1, Mathematics::MathD::GetZeroTolerance());
}

void CoreTools::MaxElementTesting::MaxElementExceptionTest()
{
    std::ignore = MaxElement<int>({});
}
