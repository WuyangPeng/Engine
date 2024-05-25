/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.9 (2024/05/18 20:28)

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

    const std::weak_ptr lhsWeakPtr{ lhsSharedPtr };
    const std::weak_ptr rhsWeakPtr{ rhsSharedPtr };

    ASSERT_NOT_THROW_EXCEPTION_2(WeakPtrEqualTest, lhsWeakPtr, rhsWeakPtr);
    ASSERT_NOT_THROW_EXCEPTION_2(WeakPtrUnequalTest, lhsWeakPtr, rhsWeakPtr);
    ASSERT_NOT_THROW_EXCEPTION_2(WeakPtrLessTest, lhsWeakPtr, rhsWeakPtr);
    ASSERT_NOT_THROW_EXCEPTION_2(WeakPtrLessEqualTest, lhsWeakPtr, rhsWeakPtr);
    ASSERT_NOT_THROW_EXCEPTION_2(WeakPtrGreaterTest, lhsWeakPtr, rhsWeakPtr);
    ASSERT_NOT_THROW_EXCEPTION_2(WeakPtrGreaterEqualTest, lhsWeakPtr, rhsWeakPtr);
}

void CoreTools::WeakPtrCompareTesting::WeakPtrEqualTest(const WeakPtr& lhsWeakPtr, const WeakPtr& rhsWeakPtr)
{
    ASSERT_FALSE(WeakPtrEqual<int>()(lhsWeakPtr, rhsWeakPtr));
    ASSERT_TRUE(WeakPtrEqual<int>()(lhsWeakPtr, lhsWeakPtr));
    ASSERT_TRUE(WeakPtrEqual<int>()(rhsWeakPtr, rhsWeakPtr));
}

void CoreTools::WeakPtrCompareTesting::WeakPtrUnequalTest(const WeakPtr& lhsWeakPtr, const WeakPtr& rhsWeakPtr)
{
    ASSERT_TRUE(WeakPtrUnequal<int>()(lhsWeakPtr, rhsWeakPtr));
    ASSERT_FALSE(WeakPtrUnequal<int>()(lhsWeakPtr, lhsWeakPtr));
    ASSERT_FALSE(WeakPtrUnequal<int>()(rhsWeakPtr, rhsWeakPtr));
}

void CoreTools::WeakPtrCompareTesting::WeakPtrLessTest(const WeakPtr& lhsWeakPtr, const WeakPtr& rhsWeakPtr)
{
    ASSERT_FALSE(WeakPtrLess<int>()(lhsWeakPtr, rhsWeakPtr));
    ASSERT_FALSE(WeakPtrLess<int>()(lhsWeakPtr, lhsWeakPtr));
    ASSERT_FALSE(WeakPtrLess<int>()(rhsWeakPtr, rhsWeakPtr));
}

void CoreTools::WeakPtrCompareTesting::WeakPtrLessEqualTest(const WeakPtr& lhsWeakPtr, const WeakPtr& rhsWeakPtr)
{
    ASSERT_FALSE(WeakPtrLessEqual<int>()(lhsWeakPtr, rhsWeakPtr));
    ASSERT_TRUE(WeakPtrLessEqual<int>()(lhsWeakPtr, lhsWeakPtr));
    ASSERT_TRUE(WeakPtrLessEqual<int>()(rhsWeakPtr, rhsWeakPtr));
}

void CoreTools::WeakPtrCompareTesting::WeakPtrGreaterTest(const WeakPtr& lhsWeakPtr, const WeakPtr& rhsWeakPtr)
{
    ASSERT_TRUE(WeakPtrGreater<int>()(lhsWeakPtr, rhsWeakPtr));
    ASSERT_FALSE(WeakPtrGreater<int>()(lhsWeakPtr, lhsWeakPtr));
    ASSERT_FALSE(WeakPtrGreater<int>()(rhsWeakPtr, rhsWeakPtr));
}

void CoreTools::WeakPtrCompareTesting::WeakPtrGreaterEqualTest(const WeakPtr& lhsWeakPtr, const WeakPtr& rhsWeakPtr)
{
    ASSERT_TRUE(WeakPtrGreaterEqual<int>()(lhsWeakPtr, rhsWeakPtr));
    ASSERT_TRUE(WeakPtrGreaterEqual<int>()(lhsWeakPtr, lhsWeakPtr));
    ASSERT_TRUE(WeakPtrGreaterEqual<int>()(rhsWeakPtr, rhsWeakPtr));
}
