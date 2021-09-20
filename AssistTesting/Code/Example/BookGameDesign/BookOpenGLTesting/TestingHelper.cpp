// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 引擎辅助测试版本：0.0.0.1 (2019/09/28 20:48)

#include "TestingHelper.h"
#include "Testing.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

CMAIN_FUNCTION_HELPER_SUBCLASS_COMPLETE_DEFINE(BookOpenGL, TestingHelper, "书籍 OpenGL")

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
	ADD_TEST_BEGIN(openGLSuperBibleSuite, "OpenGL 超级宝典");

	AddOpenGLSuperBibleFourthEditionSuite(openGLSuperBibleSuite);
	AddOpenGLSuperBibleFifthEditionSuite(openGLSuperBibleSuite);

	ADD_TEST_END(openGLSuperBibleSuite);
}

void BookOpenGL::TestingHelper
	::AddOpenGLSuperBibleFourthEditionSuite(Suite& openGLSuperBibleSuite)
{
	ADD_TEST_BEGIN(openGLSuperBibleFourthEditionSuite, "OpenGL 超级宝典 第4版");

	openGLSuperBibleSuite.AddSuite(openGLSuperBibleFourthEditionSuite);
}

void BookOpenGL::TestingHelper
	::AddOpenGLSuperBibleFifthEditionSuite(Suite& openGLSuperBibleSuite)
{
	ADD_TEST_BEGIN(openGLSuperBibleFifthEditionSuite, "OpenGL 超级宝典 第5版");

	openGLSuperBibleSuite.AddSuite(openGLSuperBibleFifthEditionSuite);
}

void BookOpenGL::TestingHelper
	::AddOpenGLShadingLanguageSuite()
{
	ADD_TEST_BEGIN(openGLShadingLanguageSuite, "OpenGL 着色语言");

	ADD_TEST_END(openGLShadingLanguageSuite);
}

void BookOpenGL::TestingHelper
	::AddOpenGLProgrammingGuideSuite()
{
	ADD_TEST_BEGIN(openGLProgrammingGuideSuite, "OpenGL 编程指南");

	AddOpenGLProgrammingGuideSeventhEditionSuite(openGLProgrammingGuideSuite);
	AddOpenGLProgrammingGuideNinthEditionSuite(openGLProgrammingGuideSuite);

	ADD_TEST_END(openGLProgrammingGuideSuite);
}

void BookOpenGL::TestingHelper
	::AddOpenGLProgrammingGuideSeventhEditionSuite(Suite& openGLProgrammingGuideSuite)
{
	ADD_TEST_BEGIN(openGLProgrammingGuideSeventhEditionSuit, "OpenGL 编程指南 第7版");

	openGLProgrammingGuideSuite.AddSuite(openGLProgrammingGuideSeventhEditionSuit);
}

void BookOpenGL::TestingHelper
	::AddOpenGLProgrammingGuideNinthEditionSuite(Suite& openGLProgrammingGuideSuite)
{
	ADD_TEST_BEGIN(openGLProgrammingGuideNinthEditionSuite, "OpenGL 编程指南 第9版");

	openGLProgrammingGuideSuite.AddSuite(openGLProgrammingGuideNinthEditionSuite);
}

void BookOpenGL::TestingHelper
	::AddOpenGLES30ProgrammingGuideSuite()
{
	ADD_TEST_BEGIN(openGLES30ProgrammingGuideSuite, "OpenGL ES 3.0编程指南");

	ADD_TEST_END(openGLES30ProgrammingGuideSuite);
}

void BookOpenGL::TestingHelper
	::AddOpenGLReferenceManualSuite()
{
	ADD_TEST_BEGIN(openGLReferenceManualSuite, "OpenGL 参考手册");

	ADD_TEST_END(openGLReferenceManualSuite);
}

void BookOpenGL::TestingHelper
	::AddComputerGraphicsWithOpenGLSuite()
{
	ADD_TEST_BEGIN(computerGraphicsWithOpenGLSuite, "计算机图形学（OpenGL）");

	ADD_TEST_END(computerGraphicsWithOpenGLSuite);
}

void BookOpenGL::TestingHelper
	::AddComputerGraphicsUsingOpenGLSuite()
{
	ADD_TEST_BEGIN(computerGraphicsUsingOpenGLSuite, "计算机图形学（OpenGL版）南");

	ADD_TEST_END(computerGraphicsUsingOpenGLSuite);
}

