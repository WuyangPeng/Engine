///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.4 (2022/11/05 22:50)

#include "SystemAndroidTestingAndroidCallBack.h"
#include "Testing.h"
#include "System/Windows/WindowsCreate.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/Helper/UnitTestSuiteMacro.h"

using namespace std::literals;

System::SystemAndroidTestingAndroidCallBack::SystemAndroidTestingAndroidCallBack(int64_t delta)
    : ParentType{ delta, "【系统库】Android单元测试套件"s }
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
    auto androidSuite = GenerateSuite("安卓"s);

    auto androidApp = GetAndroidApp();

    ADD_TEST(androidSuite, AndroidInputEventFacadeTesting);
    ADD_TEST(androidSuite, AndroidInputMotionEventFacadeTesting);
    ADD_TEST(androidSuite, AndroidLooperTesting);
    ADD_TEST_USE_PARAMETER_1(androidSuite, AndroidInputQueueFacadeTesting, androidApp);
    ADD_TEST_USE_PARAMETER_1(androidSuite, AndroidNativeWindowFacadeTesting, androidApp);
    ADD_TEST(androidSuite, AndroidNativeAppGlueTesting);

    AddSuite(androidSuite);
}
