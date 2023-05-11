﻿///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.6 (2023/04/13 11:31)

#include "SharedPtrCompareTesting.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "CoreTools/Helper/UnitTest/AssertTestMacro.h"
#include "CoreTools/MemoryTools/SharedPtrCompare.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

CoreTools::SharedPtrCompareTesting::SharedPtrCompareTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, SharedPtrCompareTesting)

void CoreTools::SharedPtrCompareTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::SharedPtrCompareTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(SharedPtrCompareTest);
}

void CoreTools::SharedPtrCompareTesting::SharedPtrCompareTest()
{
    const auto lhsSharedPtr = std::make_shared<int>(50);
    const auto rhsSharedPtr = std::make_shared<int>(30);

    ASSERT_FALSE(SharedPtrEqual<int>()(lhsSharedPtr, rhsSharedPtr));
    ASSERT_TRUE(SharedPtrEqual<int>()(lhsSharedPtr, lhsSharedPtr));
    ASSERT_TRUE(SharedPtrEqual<int>()(rhsSharedPtr, rhsSharedPtr));

    ASSERT_TRUE(SharedPtrUnequal<int>()(lhsSharedPtr, rhsSharedPtr));
    ASSERT_FALSE(SharedPtrUnequal<int>()(lhsSharedPtr, lhsSharedPtr));
    ASSERT_FALSE(SharedPtrUnequal<int>()(rhsSharedPtr, rhsSharedPtr));

    ASSERT_FALSE(SharedPtrLess<int>()(lhsSharedPtr, rhsSharedPtr));
    ASSERT_FALSE(SharedPtrLess<int>()(lhsSharedPtr, lhsSharedPtr));
    ASSERT_FALSE(SharedPtrLess<int>()(rhsSharedPtr, rhsSharedPtr));

    ASSERT_FALSE(SharedPtrLessEqual<int>()(lhsSharedPtr, rhsSharedPtr));
    ASSERT_TRUE(SharedPtrLessEqual<int>()(lhsSharedPtr, lhsSharedPtr));
    ASSERT_TRUE(SharedPtrLessEqual<int>()(rhsSharedPtr, rhsSharedPtr));

    ASSERT_TRUE(SharedPtrGreater<int>()(lhsSharedPtr, rhsSharedPtr));
    ASSERT_FALSE(SharedPtrGreater<int>()(lhsSharedPtr, lhsSharedPtr));
    ASSERT_FALSE(SharedPtrGreater<int>()(rhsSharedPtr, rhsSharedPtr));

    ASSERT_TRUE(SharedPtrGreaterEqual<int>()(lhsSharedPtr, rhsSharedPtr));
    ASSERT_TRUE(SharedPtrGreaterEqual<int>()(lhsSharedPtr, lhsSharedPtr));
    ASSERT_TRUE(SharedPtrGreaterEqual<int>()(rhsSharedPtr, rhsSharedPtr));
}