// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ������԰汾��0.0.0.4 (2019/09/10 14:36)

#include "Testing.h"
#include "System/Window/WindowCreate.h"
#include "AndroidCallBackUnitTestSuiteTestingAndroidCallBack.h"
#include "CoreTools/UnitTestSuite/UnitTestSuite.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "AndroidFrameSuite/AndroidCallBackUnitTestSuiteTesting.h"

using std::string;
using std::ostream;
using std::shared_ptr;
using CoreTools::UnitTestComposite;

AndroidCallBackUnitTestSuiteTesting::AndroidCallBackUnitTestSuiteTestingAndroidCallBack
	::AndroidCallBackUnitTestSuiteTestingAndroidCallBack(int64_t delta)
	:ParentType(delta, "��Android Call Back Unit Test Suite Testing����Ԫ�����׼�")
{
 

	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

AndroidCallBackUnitTestSuiteTesting::AndroidCallBackUnitTestSuiteTestingAndroidCallBack
	::~AndroidCallBackUnitTestSuiteTestingAndroidCallBack()
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(AndroidCallBackUnitTestSuiteTesting,AndroidCallBackUnitTestSuiteTestingAndroidCallBack)

void AndroidCallBackUnitTestSuiteTesting::AndroidCallBackUnitTestSuiteTestingAndroidCallBack
   ::AddSuite()
{
	ADD_TEST_BEGIN(androidFrameSuite,"��׿���");

	//ADD_TEST_USE_PARAMETER_1(androidFrameSuite, AndroidCallBackUnitTestSuiteTesting, this);

	DoAddSuite(androidFrameSuite);
}

 

