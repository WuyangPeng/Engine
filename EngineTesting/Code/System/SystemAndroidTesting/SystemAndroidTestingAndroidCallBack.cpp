///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.2 (2022/09/04 20:42)

#include "SystemAndroidTestingAndroidCallBack.h"
#include "Testing.h"
#include "System/Windows/WindowsCreate.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/Helper/UnitTestSuiteMacro.h"

using std::string;
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

    ADD_TEST(androidSuite, AndroidInputKeyEventTesting);
    ADD_TEST(androidSuite, AndroidInputMotionEventTesting);
    ADD_TEST_USE_PARAMETER_1(androidSuite, AndroidLooperTesting, androidApp);
    ADD_TEST_USE_PARAMETER_1(androidSuite, AndroidInputQueueTesting, androidApp);

    if (androidApp != nullptr)
    {
        ADD_TEST_USE_PARAMETER_1(androidSuite, AndroidNativeWindowTesting, androidApp->GetAndroidNativeWindow());
    }

    ADD_TEST(androidSuite, AndroidNativeAppGlueTesting);

    AddSuite(androidSuite);
}
