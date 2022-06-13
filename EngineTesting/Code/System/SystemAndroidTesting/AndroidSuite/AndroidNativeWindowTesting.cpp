///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/12 13:40)

#include "AndroidNativeWindowTesting.h"
#include "System/Android/AndroidNativeWindow.h"
#include "System/Android/Flags/AndroidNativeWindowFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::AndroidNativeWindowTesting::AndroidNativeWindowTesting(const OStreamShared& streamShared, AndroidNativeWindow* androidNativeWindow)
    : ParentType{ streamShared }, androidNativeWindow{ androidNativeWindow }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

bool System::AndroidNativeWindowTesting::IsValid() const noexcept
{
    if (ParentType::IsValid() && androidNativeWindow != nullptr)
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

void System::AndroidNativeWindowTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::AndroidNativeWindowTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(AndroidNativeWindowTest);
}

void System::AndroidNativeWindowTesting::AndroidNativeWindowTest()
{
    AndroidNativeWindowAcquire(androidNativeWindow);
    AndroidNativeWindowRelease(androidNativeWindow);
    ASSERT_EQUAL(AndroidNativeWindowGetWidth(androidNativeWindow), 0);
    ASSERT_EQUAL(AndroidNativeWindowGetHeight(androidNativeWindow), 0);
    ASSERT_ENUM_EQUAL(AndroidNativeWindowGetFormat(androidNativeWindow), WindowFormat::RGBA8888);
    ASSERT_EQUAL(AndroidNativeWindowSetBuffersGeometry(androidNativeWindow, 0, 0, WindowFormat::RGB565), 0);
    ASSERT_EQUAL(AndroidNativeWindowLock(androidNativeWindow, nullptr, nullptr), 0);
    ASSERT_EQUAL(AndroidNativeWindowUnlockAndPost(androidNativeWindow), 0);
}
