///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.2.1 (2021/07/31 22:00)

#include "AndroidNativeAppGlueTesting.h"
#include "System/Android/AndroidNativeAppGlue.h"
#include "System/Windows/WindowsProcess.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::AndroidNativeAppGlueTesting::AndroidNativeAppGlueTesting(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, AndroidNativeAppGlueTesting)

void System::AndroidNativeAppGlueTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::AndroidNativeAppGlueTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(VirtualAndroidNativeAppGlueTest);
}

void System::AndroidNativeAppGlueTesting::VirtualAndroidNativeAppGlueTest()
{
    AppDummy();

    AndroidApp androidApp{};

    auto windowHWnd = CreateVirtualWindow(&androidApp, SYSTEM_TEXT("Android Virtual Window Test"), nullptr, nullptr);
    ASSERT_UNEQUAL_NULL_PTR_FAILURE_THROW(windowHWnd, "创建窗口失败。");

    ASSERT_TRUE(DestroySystemWindow(windowHWnd));
}
