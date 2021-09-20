// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ���渨�����԰汾��0.0.0.1 (2019/09/28 20:48)

#include "TestingHelper.h"
#include "Testing.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

CMAIN_FUNCTION_HELPER_SUBCLASS_COMPLETE_DEFINE(BookOpenGL, TestingHelper, "�鼮 OpenGL")

void BookOpenGL::TestingHelper
	::AddSuites()
{
	AddOpenGLSuperBibleSuite();
	AddOpenGLShadingLanguageSuite();
	AddOpenGLProgrammingGuideSuite();
	AddOpenGLES30ProgrammingGuideSuite();
	
	AddOpenGLReferenceManualSuite();	
	AddComputerGraphicsWithOpenGLSuite();	
	AddComputerGraphicsUsingOpenGLSuite();
}

void BookOpenGL::TestingHelper
	::AddOpenGLSuperBibleSuite()
{
	ADD_TEST_BEGIN(openGLSuperBibleSuite, "OpenGL ��������");

	AddOpenGLSuperBibleFourthEditionSuite(openGLSuperBibleSuite);
	AddOpenGLSuperBibleFifthEditionSuite(openGLSuperBibleSuite);

	ADD_TEST_END(openGLSuperBibleSuite);
}

void BookOpenGL::TestingHelper
	::AddOpenGLSuperBibleFourthEditionSuite(Suite& openGLSuperBibleSuite)
{
	ADD_TEST_BEGIN(openGLSuperBibleFourthEditionSuite, "OpenGL �������� ��4��");

	openGLSuperBibleSuite.AddSuite(openGLSuperBibleFourthEditionSuite);
}

void BookOpenGL::TestingHelper
	::AddOpenGLSuperBibleFifthEditionSuite(Suite& openGLSuperBibleSuite)
{
	ADD_TEST_BEGIN(openGLSuperBibleFifthEditionSuite, "OpenGL �������� ��5��");

	openGLSuperBibleSuite.AddSuite(openGLSuperBibleFifthEditionSuite);
}

void BookOpenGL::TestingHelper
	::AddOpenGLShadingLanguageSuite()
{
	ADD_TEST_BEGIN(openGLShadingLanguageSuite, "OpenGL ��ɫ����");

	ADD_TEST_END(openGLShadingLanguageSuite);
}

void BookOpenGL::TestingHelper
	::AddOpenGLProgrammingGuideSuite()
{
	ADD_TEST_BEGIN(openGLProgrammingGuideSuite, "OpenGL ���ָ��");

	AddOpenGLProgrammingGuideSeventhEditionSuite(openGLProgrammingGuideSuite);
	AddOpenGLProgrammingGuideNinthEditionSuite(openGLProgrammingGuideSuite);

	ADD_TEST_END(openGLProgrammingGuideSuite);
}

void BookOpenGL::TestingHelper
	::AddOpenGLProgrammingGuideSeventhEditionSuite(Suite& openGLProgrammingGuideSuite)
{
	ADD_TEST_BEGIN(openGLProgrammingGuideSeventhEditionSuit, "OpenGL ���ָ�� ��7��");

	openGLProgrammingGuideSuite.AddSuite(openGLProgrammingGuideSeventhEditionSuit);
}

void BookOpenGL::TestingHelper
	::AddOpenGLProgrammingGuideNinthEditionSuite(Suite& openGLProgrammingGuideSuite)
{
	ADD_TEST_BEGIN(openGLProgrammingGuideNinthEditionSuite, "OpenGL ���ָ�� ��9��");

	openGLProgrammingGuideSuite.AddSuite(openGLProgrammingGuideNinthEditionSuite);
}

void BookOpenGL::TestingHelper
	::AddOpenGLES30ProgrammingGuideSuite()
{
	ADD_TEST_BEGIN(openGLES30ProgrammingGuideSuite, "OpenGL ES 3.0���ָ��");

	ADD_TEST_END(openGLES30ProgrammingGuideSuite);
}

void BookOpenGL::TestingHelper
	::AddOpenGLReferenceManualSuite()
{
	ADD_TEST_BEGIN(openGLReferenceManualSuite, "OpenGL �ο��ֲ�");

	ADD_TEST_END(openGLReferenceManualSuite);
}

void BookOpenGL::TestingHelper
	::AddComputerGraphicsWithOpenGLSuite()
{
	ADD_TEST_BEGIN(computerGraphicsWithOpenGLSuite, "�����ͼ��ѧ��OpenGL��");

	ADD_TEST_END(computerGraphicsWithOpenGLSuite);
}

void BookOpenGL::TestingHelper
	::AddComputerGraphicsUsingOpenGLSuite()
{
	ADD_TEST_BEGIN(computerGraphicsUsingOpenGLSuite, "�����ͼ��ѧ��OpenGL�棩��");

	ADD_TEST_END(computerGraphicsUsingOpenGLSuite);
}

