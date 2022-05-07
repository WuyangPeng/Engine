// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 引擎测试版本：0.0.0.4 (2019/09/17 09:37)

#include "OpenGLGlutCallBackUnitTestSuiteTestingOpenGLGlutCallBack.h"
#include "Testing.h"
#include "System/Windows/WindowsCreate.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestSuite.h"

using CoreTools::UnitTestComposite;
using std::ostream;
using std::shared_ptr;
using std::string;

OpenGLGlutCallBackUnitTestSuiteTesting::OpenGLGlutCallBackUnitTestSuiteTestingOpenGLGlutCallBack::OpenGLGlutCallBackUnitTestSuiteTestingOpenGLGlutCallBack(int64_t delta)
    : ParentType(delta, "【OpenGL Glut Call Back Unit Test Suite Testing】单元测试套件")
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(OpenGLGlutCallBackUnitTestSuiteTesting, OpenGLGlutCallBackUnitTestSuiteTestingOpenGLGlutCallBack)

void OpenGLGlutCallBackUnitTestSuiteTesting::OpenGLGlutCallBackUnitTestSuiteTestingOpenGLGlutCallBack::AddSuite()
{
    auto openGLGlutFrameSuite = GenerateSuite("OpenGL GLUT 框架创建");

    //ADD_TEST_USE_PARAMETER_1(openGLGlutFrameSuite, OpenGLGlutCallBackUnitTestSuiteTesting, this);

    DoAddSuite(openGLGlutFrameSuite);
}

string OpenGLGlutCallBackUnitTestSuiteTesting::OpenGLGlutCallBackUnitTestSuiteTestingOpenGLGlutCallBack::GetSuiteName() const
{
    return "【OpenGL Glut Call Back Unit Test Suite Testing】单元测试套件";
}
