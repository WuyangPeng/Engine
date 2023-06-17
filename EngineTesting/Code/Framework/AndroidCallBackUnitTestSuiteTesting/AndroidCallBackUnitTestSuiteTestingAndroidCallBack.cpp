///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/13 17:44)

#include "AndroidCallBackUnitTestSuiteTestingAndroidCallBack.h"
#include "AndroidFrameSuite/AndroidCallBackUnitTestSuiteTesting.h"
#include "Testing.h"
#include "System/Windows/WindowsCreate.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Helper/UnitTestSuiteMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestSuite.h"

AndroidCallBackUnitTestSuiteTesting::AndroidCallBackUnitTestSuiteTestingAndroidCallBack::AndroidCallBackUnitTestSuiteTestingAndroidCallBack(int64_t delta)
    : ParentType(delta, "��Android Call Back Unit Test Suite Testing����Ԫ�����׼�")
{
    InitSuite();

    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(AndroidCallBackUnitTestSuiteTesting, AndroidCallBackUnitTestSuiteTestingAndroidCallBack)

void AndroidCallBackUnitTestSuiteTesting::AndroidCallBackUnitTestSuiteTestingAndroidCallBack::InitSuite()
{
    auto androidFrameSuite = GenerateSuite("��׿���");

    ADD_TEST_USE_PARAMETER_1(androidFrameSuite, AndroidCallBackUnitTestSuiteTesting, this);

    AddSuite(androidFrameSuite);
}
