///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨�����԰汾��0.7.2.7 (2021/11/30 21:59)

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
