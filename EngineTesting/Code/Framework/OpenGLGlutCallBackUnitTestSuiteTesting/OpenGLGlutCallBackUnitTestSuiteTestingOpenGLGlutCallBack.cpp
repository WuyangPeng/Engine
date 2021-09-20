// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ������԰汾��0.0.0.4 (2019/09/17 09:37)

#include "Testing.h"
#include "OpenGLGlutCallBackUnitTestSuiteTestingOpenGLGlutCallBack.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestSuite.h"
#include "System/Window/WindowCreate.h"

using std::string;
using std::ostream;
using std::shared_ptr;
using CoreTools::UnitTestComposite;

OpenGLGlutCallBackUnitTestSuiteTesting::OpenGLGlutCallBackUnitTestSuiteTestingOpenGLGlutCallBack
	::OpenGLGlutCallBackUnitTestSuiteTestingOpenGLGlutCallBack(int64_t delta)
	:ParentType(delta, "��OpenGL Glut Call Back Unit Test Suite Testing����Ԫ�����׼�")
{
 

	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

OpenGLGlutCallBackUnitTestSuiteTesting::OpenGLGlutCallBackUnitTestSuiteTestingOpenGLGlutCallBack
	::~OpenGLGlutCallBackUnitTestSuiteTestingOpenGLGlutCallBack()
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(OpenGLGlutCallBackUnitTestSuiteTesting,OpenGLGlutCallBackUnitTestSuiteTestingOpenGLGlutCallBack)

void OpenGLGlutCallBackUnitTestSuiteTesting::OpenGLGlutCallBackUnitTestSuiteTestingOpenGLGlutCallBack
   ::AddSuite()
{
	ADD_TEST_BEGIN(openGLGlutFrameSuite,"OpenGL GLUT ��ܴ���");

	//ADD_TEST_USE_PARAMETER_1(openGLGlutFrameSuite, OpenGLGlutCallBackUnitTestSuiteTesting, this);

	DoAddSuite(openGLGlutFrameSuite);
}

string OpenGLGlutCallBackUnitTestSuiteTesting::OpenGLGlutCallBackUnitTestSuiteTestingOpenGLGlutCallBack
	::GetSuiteName() const
{
	return "��OpenGL Glut Call Back Unit Test Suite Testing����Ԫ�����׼�";
}

