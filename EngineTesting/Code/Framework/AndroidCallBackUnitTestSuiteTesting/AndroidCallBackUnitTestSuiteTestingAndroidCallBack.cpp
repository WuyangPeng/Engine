// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ������԰汾��0.0.0.4 (2019/09/10 14:36)

#include "AndroidCallBackUnitTestSuiteTestingAndroidCallBack.h"
#include "AndroidFrameSuite/AndroidCallBackUnitTestSuiteTesting.h"
#include "Testing.h"
#include "System/Windows/WindowsCreate.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestSuite.h"

using CoreTools::UnitTestComposite;
using std::ostream;
using std::shared_ptr;
using std::string;

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

    //ADD_TEST_USE_PARAMETER_1(androidFrameSuite, AndroidCallBackUnitTestSuiteTesting, this);

    AddSuite(androidFrameSuite);
}
