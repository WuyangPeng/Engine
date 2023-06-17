///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/13 23:27)

#include "OpenGLGlutCallBack.h"
#include "Testing.h"
#include "System/Windows/WindowsCreate.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Helper/UnitTestSuiteMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestSuite.h"

OpenGLGlutCallBackUnitTestSuiteTesting::OpenGLGlutCallBack::OpenGLGlutCallBack(int64_t delta)
    : ParentType(delta, "��OpenGL Glut Call Back Unit Test Suite Testing����Ԫ�����׼�")
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(OpenGLGlutCallBackUnitTestSuiteTesting, OpenGLGlutCallBack)

void OpenGLGlutCallBackUnitTestSuiteTesting::OpenGLGlutCallBack::AddSuite()
{
    auto openGLGlutFrameSuite = GenerateSuite("OpenGL GLUT ��ܴ���");

    ADD_TEST_USE_PARAMETER_1(openGLGlutFrameSuite, OpenGLGlutCallBackUnitTestSuiteTesting, this);

    DoAddSuite(openGLGlutFrameSuite);
}

std::string OpenGLGlutCallBackUnitTestSuiteTesting::OpenGLGlutCallBack::GetSuiteName() const
{
    return "��OpenGL Glut Call Back Unit Test Suite Testing����Ԫ�����׼�";
}
