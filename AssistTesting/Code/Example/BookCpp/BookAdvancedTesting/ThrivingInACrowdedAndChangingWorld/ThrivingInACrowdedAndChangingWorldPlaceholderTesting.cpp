///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助测试版本：0.7.2.7 (2021/11/30 21:59)

#include "ThrivingInACrowdedAndChangingWorldPlaceholderTesting.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "Example/BookCpp/ThrivingInACrowdedAndChangingWorld/Helper/ThrivingInACrowdedAndChangingWorldClassInvariantMacro.h"

BookAdvanced::ThrivingInACrowdedAndChangingWorld::ThrivingInACrowdedAndChangingWorldPlaceholderTesting::ThrivingInACrowdedAndChangingWorldPlaceholderTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BookAdvanced::ThrivingInACrowdedAndChangingWorld, ThrivingInACrowdedAndChangingWorldPlaceholderTesting)

void BookAdvanced::ThrivingInACrowdedAndChangingWorld::ThrivingInACrowdedAndChangingWorldPlaceholderTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void BookAdvanced::ThrivingInACrowdedAndChangingWorld::ThrivingInACrowdedAndChangingWorldPlaceholderTesting::MainTest() noexcept
{
}
