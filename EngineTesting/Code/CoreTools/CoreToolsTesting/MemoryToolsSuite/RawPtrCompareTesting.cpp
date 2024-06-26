﻿/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.9 (2024/05/18 20:16)

#include "RawPtrCompareTesting.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "CoreTools/Helper/UnitTest/AssertTestMacro.h"
#include "CoreTools/MemoryTools/RawIterators.h"
#include "CoreTools/MemoryTools/RawPtrCompare.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

#include <numeric>

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
    ContainerType container(size);
    std::iota(container.begin(), container.end(), 0);

    const RawConstIterator lhsRawConstIterator{ container.data() };

    const auto rhsRawConstIterator = lhsRawConstIterator + 5;

    ASSERT_NOT_THROW_EXCEPTION_2(RawPtrEqualTest, lhsRawConstIterator, rhsRawConstIterator);
    ASSERT_NOT_THROW_EXCEPTION_2(RawPtrUnequalTest, lhsRawConstIterator, rhsRawConstIterator);
    ASSERT_NOT_THROW_EXCEPTION_2(RawPtrLessTest, lhsRawConstIterator, rhsRawConstIterator);
    ASSERT_NOT_THROW_EXCEPTION_2(RawPtrLessEqualTest, lhsRawConstIterator, rhsRawConstIterator);
    ASSERT_NOT_THROW_EXCEPTION_2(RawPtrGreaterTest, lhsRawConstIterator, rhsRawConstIterator);
    ASSERT_NOT_THROW_EXCEPTION_2(RawPtrGreaterEqualTest, lhsRawConstIterator, rhsRawConstIterator);
}

void CoreTools::RawPtrCompareTesting::RawPtrEqualTest(const RawConstIteratorType& lhsRawConstIterator, const RawConstIteratorType& rhsRawConstIterator)
{
    ASSERT_FALSE(RawPtrEqual<int>()(lhsRawConstIterator, rhsRawConstIterator));
    ASSERT_TRUE(RawPtrEqual<int>()(lhsRawConstIterator, lhsRawConstIterator));
    ASSERT_TRUE(RawPtrEqual<int>()(rhsRawConstIterator, rhsRawConstIterator));
}

void CoreTools::RawPtrCompareTesting::RawPtrUnequalTest(const RawConstIteratorType& lhsRawConstIterator, const RawConstIteratorType& rhsRawConstIterator)
{
    ASSERT_TRUE(RawPtrUnequal<int>()(lhsRawConstIterator, rhsRawConstIterator));
    ASSERT_FALSE(RawPtrUnequal<int>()(lhsRawConstIterator, lhsRawConstIterator));
    ASSERT_FALSE(RawPtrUnequal<int>()(rhsRawConstIterator, rhsRawConstIterator));
}

void CoreTools::RawPtrCompareTesting::RawPtrLessTest(const RawConstIteratorType& lhsRawConstIterator, const RawConstIteratorType& rhsRawConstIterator)
{
    ASSERT_TRUE(RawPtrLess<int>()(lhsRawConstIterator, rhsRawConstIterator));
    ASSERT_FALSE(RawPtrLess<int>()(lhsRawConstIterator, lhsRawConstIterator));
    ASSERT_FALSE(RawPtrLess<int>()(rhsRawConstIterator, rhsRawConstIterator));
}

void CoreTools::RawPtrCompareTesting::RawPtrLessEqualTest(const RawConstIteratorType& lhsRawConstIterator, const RawConstIteratorType& rhsRawConstIterator)
{
    ASSERT_TRUE(RawPtrLessEqual<int>()(lhsRawConstIterator, rhsRawConstIterator));
    ASSERT_TRUE(RawPtrLessEqual<int>()(lhsRawConstIterator, lhsRawConstIterator));
    ASSERT_TRUE(RawPtrLessEqual<int>()(rhsRawConstIterator, rhsRawConstIterator));
}

void CoreTools::RawPtrCompareTesting::RawPtrGreaterTest(const RawConstIteratorType& lhsRawConstIterator, const RawConstIteratorType& rhsRawConstIterator)
{
    ASSERT_FALSE(RawPtrGreater<int>()(lhsRawConstIterator, rhsRawConstIterator));
    ASSERT_FALSE(RawPtrGreater<int>()(lhsRawConstIterator, lhsRawConstIterator));
    ASSERT_FALSE(RawPtrGreater<int>()(rhsRawConstIterator, rhsRawConstIterator));
}

void CoreTools::RawPtrCompareTesting::RawPtrGreaterEqualTest(const RawConstIteratorType& lhsRawConstIterator, const RawConstIteratorType& rhsRawConstIterator)
{
    ASSERT_FALSE(RawPtrGreaterEqual<int>()(lhsRawConstIterator, rhsRawConstIterator));
    ASSERT_TRUE(RawPtrGreaterEqual<int>()(lhsRawConstIterator, lhsRawConstIterator));
    ASSERT_TRUE(RawPtrGreaterEqual<int>()(rhsRawConstIterator, rhsRawConstIterator));
}
