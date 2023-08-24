///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.3 (2023/08/11 14:18)

#include "FrameworkTestingAndroidCallBack.h"
#include "Testing.h"
#include "System/Windows/WindowsCreate.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Helper/UnitTestSuiteMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestSuite.h"
#include "Framework/AndroidFrame/AndroidCallBackUnitTestSuiteDetail.h"

Framework::FrameworkTestingAndroidCallBack::FrameworkTestingAndroidCallBack(int64_t delta)
    : ParentType{ delta, "����ܿ⡿��Ԫ�����׼�" }
{
    InitSuite();

    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, FrameworkTestingAndroidCallBack)

void Framework::FrameworkTestingAndroidCallBack::InitSuite()
{
    AddAndroidFrameSuite();
}

void Framework::FrameworkTestingAndroidCallBack::AddAndroidFrameSuite()
{
    auto androidFrameSuite = GenerateSuite("��׿���");

    System::AndroidApp* app = GetAndroidApp();

    ADD_TEST_USE_PARAMETER_1(androidFrameSuite, AndroidProcessManagerTesting, app);
    ADD_TEST_USE_PARAMETER_1(androidFrameSuite, AndroidProcessTesting, app);
    ADD_TEST_USE_PARAMETER_1(androidFrameSuite, AndroidCallBackInterfaceTesting, app);
    ADD_TEST_USE_PARAMETER_1(androidFrameSuite, AndroidCallBackTesting, app);
    ADD_TEST(androidFrameSuite, AndroidMessageLoopTesting);
    ADD_TEST(androidFrameSuite, AndroidFrameBuildTesting);
    ADD_TEST(androidFrameSuite, AndroidCallBackUnitTestSuiteTesting);

    AddSuite(androidFrameSuite);
}
