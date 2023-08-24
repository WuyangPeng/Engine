///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/11 14:18)

#include "FrameworkTestingAndroidCallBack.h"
#include "Testing.h"
#include "System/Windows/WindowsCreate.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Helper/UnitTestSuiteMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestSuite.h"
#include "Framework/AndroidFrame/AndroidCallBackUnitTestSuiteDetail.h"

Framework::FrameworkTestingAndroidCallBack::FrameworkTestingAndroidCallBack(int64_t delta)
    : ParentType{ delta, "【框架库】单元测试套件" }
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
    auto androidFrameSuite = GenerateSuite("安卓框架");

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
