///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/13 19:24)

#include "FrameworkTestingOpenGLGlutCallBack.h"
#include "Testing.h"
#include "System/OpenGL/OpenGLGlut.h"
#include "System/OpenGL/OpenGLInit.h"
#include "System/Windows/WindowsCreate.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Helper/UnitTestSuiteMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestSuite.h"

Framework::FrameworkTestingOpenGLGlutCallBack::FrameworkTestingOpenGLGlutCallBack(int64_t delta)
    : ParentType(delta, "����ܿ⡿��Ԫ�����׼�")
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, FrameworkTestingOpenGLGlutCallBack)

void Framework::FrameworkTestingOpenGLGlutCallBack::AddSuite()
{
    AddOpenGLGlutFrameSuite();
}

std::string Framework::FrameworkTestingOpenGLGlutCallBack::GetSuiteName() const
{
    return "����ܿ⡿��Ԫ�����׼�";
}

void Framework::FrameworkTestingOpenGLGlutCallBack::AddOpenGLGlutFrameSuite()
{
    auto openGLGlutFrameSuite = GenerateSuite("OpenGL GLUT ��ܴ���");

    ADD_TEST(openGLGlutFrameSuite, OpenGLGlutProcessManagerTesting);
    ADD_TEST(openGLGlutFrameSuite, OpenGLGlutProcessTesting);
    ADD_TEST(openGLGlutFrameSuite, OpenGLGlutCallBackInterfaceTesting);
    ADD_TEST(openGLGlutFrameSuite, OpenGLGlutCallBackTesting);
    ADD_TEST(openGLGlutFrameSuite, OpenGLGlutFrameBuildTesting);
    ADD_TEST(openGLGlutFrameSuite, OpenGLGlutCallBackUnitTestSuiteTesting);

    DoAddSuite(openGLGlutFrameSuite);
}
