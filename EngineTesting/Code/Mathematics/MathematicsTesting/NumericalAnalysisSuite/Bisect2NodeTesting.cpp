///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/06/02 16:15)

#include "Bisect2NodeTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, Bisect2NodeTesting)

void Mathematics::Bisect2NodeTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ValueTest);
    ASSERT_NOT_THROW_EXCEPTION_0(NextNodeTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SameSignTest);
}

void Mathematics::Bisect2NodeTesting::ValueTest() noexcept
{
}

void Mathematics::Bisect2NodeTesting::NextNodeTest() noexcept
{
}

void Mathematics::Bisect2NodeTesting::SameSignTest() noexcept
{
}
