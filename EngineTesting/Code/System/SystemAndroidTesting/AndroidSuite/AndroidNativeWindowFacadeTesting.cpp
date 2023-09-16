///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/08/31 13:44)

#include "AndroidNativeWindowFacadeTesting.h"
#include "System/Android/AndroidNativeWindowFacade.h"
#include "System/Android/Flags/AndroidNativeWindowFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::AndroidNativeWindowFacadeTesting::AndroidNativeWindowFacadeTesting(const OStreamShared& streamShared, AndroidApp* androidApp)
    : ParentType{ streamShared }, androidNativeWindow{ GetAndroidNativeWindow(androidApp) }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

System::AndroidNativeWindow* System::AndroidNativeWindowFacadeTesting::GetAndroidNativeWindow(AndroidApp* androidApp)
{
    if (androidApp == nullptr)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("androidApp为空。"))
    }

    const auto androidNativeWindow = androidApp->GetNativeWindow();

    if (androidNativeWindow == nullptr)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("NativeWindow为空。"))
    }

    return androidNativeWindow;
}

#ifdef OPEN_CLASS_INVARIANT

bool System::AndroidNativeWindowFacadeTesting::IsValid() const noexcept
{
    if (ParentType::IsValid() && androidNativeWindow != nullptr)
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

void System::AndroidNativeWindowFacadeTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::AndroidNativeWindowFacadeTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(AndroidNativeWindowTest);
    ASSERT_NOT_THROW_EXCEPTION_0(AndroidNativeWindowLockTest);
}

void System::AndroidNativeWindowFacadeTesting::AndroidNativeWindowTest()
{
    AndroidNativeWindowFacade androidNativeWindowFacade{ androidNativeWindow };

    androidNativeWindowFacade.Acquire();
    androidNativeWindowFacade.Release();
    ASSERT_EQUAL(androidNativeWindowFacade.GetWidth(), 0);
    ASSERT_EQUAL(androidNativeWindowFacade.GetHeight(), 0);
    ASSERT_ENUM_EQUAL(androidNativeWindowFacade.GetFormat(), WindowFormat::RGBA8888);
    ASSERT_EQUAL(androidNativeWindowFacade.SetBuffersGeometry(0, 0, WindowFormat::RGB565), 0);
}

void System::AndroidNativeWindowFacadeTesting::AndroidNativeWindowLockTest()
{
    AndroidNativeWindowFacade androidNativeWindowFacade{ androidNativeWindow };

    AndroidNativeWindowBuffer outBuffer{};
    AndroidRect inOutDirtyBounds{};

    ASSERT_EQUAL(androidNativeWindowFacade.Lock(&outBuffer, &inOutDirtyBounds), 0);
    ASSERT_EQUAL(androidNativeWindowFacade.UnlockAndPost(), 0);
}
