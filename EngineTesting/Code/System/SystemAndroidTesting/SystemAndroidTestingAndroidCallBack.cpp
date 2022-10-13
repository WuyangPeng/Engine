///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.1.2 (2022/09/04 20:42)

#include "SystemAndroidTestingAndroidCallBack.h"
#include "Testing.h"
#include "System/Windows/WindowsCreate.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/Helper/UnitTestSuiteMacro.h"

using std::string;
using namespace std::literals;

System::SystemAndroidTestingAndroidCallBack::SystemAndroidTestingAndroidCallBack(int64_t delta)
    : ParentType{ delta, "��ϵͳ�⡿Android��Ԫ�����׼�"s }
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
    auto androidSuite = GenerateSuite("��׿"s);

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
