﻿///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.6 (2023/04/13 11:31)

#include "RawPtrCompareTesting.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "CoreTools/Helper/UnitTest/AssertTestMacro.h"
#include "CoreTools/MemoryTools/RawIterators.h"
#include "CoreTools/MemoryTools/RawPtrCompare.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

CoreTools::RawPtrCompareTesting::RawPtrCompareTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, RawPtrCompareTesting)

void CoreTools::RawPtrCompareTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::RawPtrCompareTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(RawPtrCompareTest);
}

void CoreTools::RawPtrCompareTesting::RawPtrCompareTest()
{
    std::vector<int> container{};
    for (auto i = 0; i < 20; ++i)
    {
        container.emplace_back(i);
    }

    const RawConstIterator lhsRawConstIterator{ container.data() };

    const auto rhsRawConstIterator = lhsRawConstIterator + 5;

    ASSERT_FALSE(RawPtrEqual<int>()(lhsRawConstIterator, rhsRawConstIterator));
    ASSERT_TRUE(RawPtrEqual<int>()(lhsRawConstIterator, lhsRawConstIterator));
    ASSERT_TRUE(RawPtrEqual<int>()(rhsRawConstIterator, rhsRawConstIterator));

    ASSERT_TRUE(RawPtrUnequal<int>()(lhsRawConstIterator, rhsRawConstIterator));
    ASSERT_FALSE(RawPtrUnequal<int>()(lhsRawConstIterator, lhsRawConstIterator));
    ASSERT_FALSE(RawPtrUnequal<int>()(rhsRawConstIterator, rhsRawConstIterator));

    ASSERT_TRUE(RawPtrLess<int>()(lhsRawConstIterator, rhsRawConstIterator));
    ASSERT_FALSE(RawPtrLess<int>()(lhsRawConstIterator, lhsRawConstIterator));
    ASSERT_FALSE(RawPtrLess<int>()(rhsRawConstIterator, rhsRawConstIterator));

    ASSERT_TRUE(RawPtrLessEqual<int>()(lhsRawConstIterator, rhsRawConstIterator));
    ASSERT_TRUE(RawPtrLessEqual<int>()(lhsRawConstIterator, lhsRawConstIterator));
    ASSERT_TRUE(RawPtrLessEqual<int>()(rhsRawConstIterator, rhsRawConstIterator));

    ASSERT_FALSE(RawPtrGreater<int>()(lhsRawConstIterator, rhsRawConstIterator));
    ASSERT_FALSE(RawPtrGreater<int>()(lhsRawConstIterator, lhsRawConstIterator));
    ASSERT_FALSE(RawPtrGreater<int>()(rhsRawConstIterator, rhsRawConstIterator));

    ASSERT_FALSE(RawPtrGreaterEqual<int>()(lhsRawConstIterator, rhsRawConstIterator));
    ASSERT_TRUE(RawPtrGreaterEqual<int>()(lhsRawConstIterator, lhsRawConstIterator));
    ASSERT_TRUE(RawPtrGreaterEqual<int>()(rhsRawConstIterator, rhsRawConstIterator));
}