///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.1.6 (2021/07/11 20:38)

#include "AndroidInputMotionEventTesting.h"
#include "System/Android/AndroidInputMotionEvent.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::AndroidInputMotionEventTesting::AndroidInputMotionEventTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, AndroidInputMotionEventTesting)

void System::AndroidInputMotionEventTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::AndroidInputMotionEventTesting::MainTest() noexcept
{
    // SystemAndroidTesting有Android函数的测试。
}
