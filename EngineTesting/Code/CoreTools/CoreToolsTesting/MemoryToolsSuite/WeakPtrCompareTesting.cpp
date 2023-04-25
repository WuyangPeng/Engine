///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.6 (2023/04/13 11:32)

#include "WeakPtrCompareTesting.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "CoreTools/Helper/UnitTest/AssertTestMacro.h"
#include "CoreTools/MemoryTools/WeakPtrCompare.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

CoreTools::WeakPtrCompareTesting::WeakPtrCompareTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, WeakPtrCompareTesting)

void CoreTools::WeakPtrCompareTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::WeakPtrCompareTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(WeakPtrCompareTest);
}

void CoreTools::WeakPtrCompareTesting::WeakPtrCompareTest()
{
    const auto lhsSharedPtr = std::make_shared<int>(50);
    const auto rhsSharedPtr = std::make_shared<int>(30);

    const auto lhsWeakPtr = lhsSharedPtr;
    const auto rhsWeakPtr = rhsSharedPtr;

    ASSERT_FALSE(WeakPtrEqual<int>()(lhsWeakPtr, rhsWeakPtr));
    ASSERT_TRUE(WeakPtrEqual<int>()(lhsWeakPtr, lhsWeakPtr));
    ASSERT_TRUE(WeakPtrEqual<int>()(rhsWeakPtr, rhsWeakPtr));

    ASSERT_TRUE(WeakPtrUnequal<int>()(lhsWeakPtr, rhsWeakPtr));
    ASSERT_FALSE(WeakPtrUnequal<int>()(lhsWeakPtr, lhsWeakPtr));
    ASSERT_FALSE(WeakPtrUnequal<int>()(rhsWeakPtr, rhsWeakPtr));

    ASSERT_FALSE(WeakPtrLess<int>()(lhsWeakPtr, rhsWeakPtr));
    ASSERT_FALSE(WeakPtrLess<int>()(lhsWeakPtr, lhsWeakPtr));
    ASSERT_FALSE(WeakPtrLess<int>()(rhsWeakPtr, rhsWeakPtr));

    ASSERT_FALSE(WeakPtrLessEqual<int>()(lhsWeakPtr, rhsWeakPtr));
    ASSERT_TRUE(WeakPtrLessEqual<int>()(lhsWeakPtr, lhsWeakPtr));
    ASSERT_TRUE(WeakPtrLessEqual<int>()(rhsWeakPtr, rhsWeakPtr));

    ASSERT_TRUE(WeakPtrGreater<int>()(lhsWeakPtr, rhsWeakPtr));
    ASSERT_FALSE(WeakPtrGreater<int>()(lhsWeakPtr, lhsWeakPtr));
    ASSERT_FALSE(WeakPtrGreater<int>()(rhsWeakPtr, rhsWeakPtr));

    ASSERT_TRUE(WeakPtrGreaterEqual<int>()(lhsWeakPtr, rhsWeakPtr));
    ASSERT_TRUE(WeakPtrGreaterEqual<int>()(lhsWeakPtr, lhsWeakPtr));
    ASSERT_TRUE(WeakPtrGreaterEqual<int>()(rhsWeakPtr, rhsWeakPtr));
}