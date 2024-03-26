/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/13 17:09)

#include "AndroidNativeAppGlueTesting.h"
#include "System/Android/AndroidNativeAppGlue.h"
#include "System/Windows/WindowsProcess.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::AndroidNativeAppGlueTesting::AndroidNativeAppGlueTesting(const OStreamShared& stream)
    : ParentType{ stream }, index{ 0 }
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

    const auto appName = SYSTEM_TEXT("Android Virtual Window Test") + ToString(index++);

    const auto windowHWnd = CreateVirtualWindow(&androidApp, appName, nullptr, nullptr);
    ASSERT_UNEQUAL_NULL_PTR_FAILURE_THROW(windowHWnd, "��������ʧ�ܡ�");

    ASSERT_TRUE(DestroySystemWindow(windowHWnd));
}
