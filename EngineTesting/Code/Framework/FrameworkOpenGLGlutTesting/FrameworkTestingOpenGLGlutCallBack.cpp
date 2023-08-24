///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.3 (2023/08/11 16:52)

#include "FrameworkTestingOpenGLGlutCallBack.h"
#include "Testing.h"
#include "System/Windows/WindowsCreate.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Helper/UnitTestSuiteMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestSuite.h"
#include "Framework/OpenGLGlutFrame/OpenGLGlutCallBackUnitTestSuiteDetail.h"

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
