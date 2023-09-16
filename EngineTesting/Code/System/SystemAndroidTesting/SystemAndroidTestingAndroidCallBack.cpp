///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/08/31 13:44)

#include "SystemAndroidTestingAndroidCallBack.h"
#include "Testing.h"
#include "System/Windows/WindowsCreate.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/Helper/UnitTestSuiteMacro.h"
#include "Framework/AndroidFrame/AndroidCallBackUnitTestSuiteDetail.h"

System::SystemAndroidTestingAndroidCallBack::SystemAndroidTestingAndroidCallBack(int64_t delta)
    : ParentType{ delta, "��ϵͳ�⡿Android��Ԫ�����׼�" }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, SystemAndroidTestingAndroidCallBack)

void System::SystemAndroidTestingAndroidCallBack::InitSuite()
{
    AddAndroidSuite();
}

void System::SystemAndroidTestingAndroidCallBack::AddAndroidSuite()
{
    auto androidSuite = GenerateSuite("��׿");

    auto androidApp = GetAndroidApp();

    ADD_TEST(androidSuite, AndroidInputEventFacadeTesting);
    ADD_TEST(androidSuite, AndroidInputMotionEventFacadeTesting);
    ADD_TEST(androidSuite, AndroidLooperTesting);
    ADD_TEST_USE_PARAMETER_1(androidSuite, AndroidInputQueueFacadeTesting, androidApp);
    ADD_TEST_USE_PARAMETER_1(androidSuite, AndroidNativeWindowFacadeTesting, androidApp);
    ADD_TEST(androidSuite, AndroidNativeAppGlueTesting);

    AddSuite(androidSuite);
}
