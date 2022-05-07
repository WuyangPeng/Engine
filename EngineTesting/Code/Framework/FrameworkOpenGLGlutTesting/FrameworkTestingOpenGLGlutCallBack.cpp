// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ������԰汾��0.0.0.4 (2019/09/11 10:03)

#include "FrameworkTestingOpenGLGlutCallBack.h"
#include "Testing.h"
#include "System/OpenGL/OpenGLGlut.h"
#include "System/OpenGL/OpenGLInit.h"
#include "System/Windows/WindowsCreate.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestSuite.h"

using std::string;

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

string Framework::FrameworkTestingOpenGLGlutCallBack::GetSuiteName() const
{
    return "����ܿ⡿��Ԫ�����׼�";
}

void Framework::FrameworkTestingOpenGLGlutCallBack::AddOpenGLGlutFrameSuite()
{
    auto openGLGlutFrameSuite = GenerateSuite("OpenGL GLUT ��ܴ���");

    // 	ADD_TEST(openGLGlutFrameSuite, OpenGLGlutProcessManagerTesting);
    // 	ADD_TEST(openGLGlutFrameSuite, OpenGLGlutProcessTesting);
    // 	ADD_TEST(openGLGlutFrameSuite, OpenGLGlutCallBackInterfaceTesting);
    // 	ADD_TEST(openGLGlutFrameSuite, OpenGLGlutCallBackTesting);
    // 	ADD_TEST(openGLGlutFrameSuite, OpenGLGlutFrameBuildTesting);
    // 	ADD_TEST(openGLGlutFrameSuite, OpenGLGlutCallBackUnitTestSuiteTesting);

    DoAddSuite(openGLGlutFrameSuite);
}
