///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.4 (2022/11/05 22:55)

#include "AndroidInputMotionEventFacadeTesting.h"
#include "System/Android/AndroidInputMotionEventFacade.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::AndroidInputMotionEventFacadeTesting::AndroidInputMotionEventFacadeTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, AndroidInputMotionEventFacadeTesting)

void System::AndroidInputMotionEventFacadeTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::AndroidInputMotionEventFacadeTesting::MainTest() noexcept
{
    // SystemAndroidTesting有Android函数的测试。
}
