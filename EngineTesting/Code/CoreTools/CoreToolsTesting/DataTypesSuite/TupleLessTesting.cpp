///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/10/25 11:30)

#include "TupleLessTesting.h"
#include "CoreTools/DataTypes/TupleDetail.h"
#include "CoreTools/DataTypes/TupleLessDetail.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "CoreTools/Helper/UnitTest/AssertTestMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

CoreTools::TupleLessTesting::TupleLessTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, TupleLessTesting)

void CoreTools::TupleLessTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::TupleLessTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(TupleLessTest);
}

void CoreTools::TupleLessTesting::TupleLessTest()
{
    const Tuple<4, int> lhsTuple{ 1, 2, 3, 4 };
    const Tuple<4, int> rhsTuple{ 4, 5, 3, 2 };

    const TupleLess<4, int> tupleLess0{ 0 };
    ASSERT_TRUE(tupleLess0(lhsTuple, rhsTuple));

    const TupleLess<4, int> tupleLess1{ 1 };
    ASSERT_TRUE(tupleLess1(lhsTuple, rhsTuple));

    const TupleLess<4, int> tupleLess2{ 2 };
    ASSERT_FALSE(tupleLess2(lhsTuple, rhsTuple));

    const TupleLess<4, int> tupleLess3{ 3 };
    ASSERT_FALSE(tupleLess3(lhsTuple, rhsTuple));
}
