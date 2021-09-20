// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 引擎辅助版本：0.0.0.2 (2019/09/28 16:43)

#include "TestingHelper.h"
#include "Testing.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

CMAIN_FUNCTION_HELPER_SUBCLASS_COMPLETE_DEFINE(BookGraphics, TestingHelper, "书籍 图形学")

void BookGraphics::TestingHelper
	::AddSuites()
{
	AddInteractiveComputerGraphicsSuite();	
	Add3DGamesSuite();
	Add3DComputerGraphicsSuite();
	AddComputerGraphicsSuite();
	
	AddComputerGraphicsPrinciplesAndPracticeSuite();
	AddFundamentalsOfComputerGraphicsSuite();
	AddMichaelAbrashsGraphicsProgrammingBlackBookSuite();
	AddTheCgTutorialSuite();
}

void BookGraphics::TestingHelper
	::AddInteractiveComputerGraphicsSuite()
{
	ADD_TEST_BEGIN(interactiveComputerGraphicsSuite, "交互式计算机图形学");

	AddInteractiveComputerGraphicsFifthEditionSuite(interactiveComputerGraphicsSuite);
	AddInteractiveComputerGraphicsSeventhEditionSuite(interactiveComputerGraphicsSuite);

	ADD_TEST_END(interactiveComputerGraphicsSuite);
}

void BookGraphics::TestingHelper
	::AddInteractiveComputerGraphicsFifthEditionSuite(Suite& interactiveComputerGraphicsSuite)
{
	ADD_TEST_BEGIN(interactiveComputerGraphicsFifthEditionSuite, "交互式计算机图形学 第5版");



	interactiveComputerGraphicsSuite.AddSuite(interactiveComputerGraphicsFifthEditionSuite);
}

void BookGraphics::TestingHelper
	::AddInteractiveComputerGraphicsSeventhEditionSuite(Suite& interactiveComputerGraphicsSuite)
{
	ADD_TEST_BEGIN(interactiveComputerGraphicsSeventhEditionSuite, "交互式计算机图形学 第7版");



	interactiveComputerGraphicsSuite.AddSuite(interactiveComputerGraphicsSeventhEditionSuite);
}

void BookGraphics::TestingHelper
	::Add3DGamesSuite()
{
	ADD_TEST_BEGIN(threeDGamesSuite, "3D游戏");

	Add3DGamesRealTimeRenderingAndSoftwareTechnologySuite(threeDGamesSuite);
	Add3DGamesAnimationAndAdvancedRealTimeRenderingSuite(threeDGamesSuite);

	ADD_TEST_END(threeDGamesSuite);
}

void BookGraphics::TestingHelper
	::Add3DGamesRealTimeRenderingAndSoftwareTechnologySuite(Suite& threeDGamesSuite)
{
	ADD_TEST_BEGIN(threeDGamesRealTimeRenderingAndSoftwareTechnologySuite, "3D游戏 实时渲染与软件技术");



	threeDGamesSuite.AddSuite(threeDGamesRealTimeRenderingAndSoftwareTechnologySuite);
}

void BookGraphics::TestingHelper
	::Add3DGamesAnimationAndAdvancedRealTimeRenderingSuite(Suite& threeDGamesSuite)
{
	ADD_TEST_BEGIN(threeDGamesAnimationAndAdvancedRealTimeRenderingSuite, "3D游戏 动画与高级实时渲染技术");



	threeDGamesSuite.AddSuite(threeDGamesAnimationAndAdvancedRealTimeRenderingSuite);
}

void BookGraphics::TestingHelper
	::Add3DComputerGraphicsSuite()
{
	ADD_TEST_BEGIN(threeDComputerGraphicsSuite, "3D计算机图形学");



	ADD_TEST_END(threeDComputerGraphicsSuite);
}

void BookGraphics::TestingHelper
	::AddComputerGraphicsSuite()
{
	ADD_TEST_BEGIN(computerGraphicsSuite, "计算机图形学（面向视觉交流的OpenGL编程技术） ");



	ADD_TEST_END(computerGraphicsSuite);
}

void BookGraphics::TestingHelper
	::AddComputerGraphicsPrinciplesAndPracticeSuite()
{
	ADD_TEST_BEGIN(computerGraphicsPrinciplesAndPracticeSuite, "计算机图形学原理及实践——C语言描述");



	ADD_TEST_END(computerGraphicsPrinciplesAndPracticeSuite);
}

void BookGraphics::TestingHelper
	::AddFundamentalsOfComputerGraphicsSuite()
{
	ADD_TEST_BEGIN(fundamentalsOfComputerGraphicsSuite, "计算机图形学");



	ADD_TEST_END(fundamentalsOfComputerGraphicsSuite);
}

void BookGraphics::TestingHelper
	::AddMichaelAbrashsGraphicsProgrammingBlackBookSuite()
{
	ADD_TEST_BEGIN(michaelAbrashsGraphicsProgrammingBlackBookSuite, "图形程序开发人员指南");



	ADD_TEST_END(michaelAbrashsGraphicsProgrammingBlackBookSuite);
}

void BookGraphics::TestingHelper
	::AddTheCgTutorialSuite()
{
	ADD_TEST_BEGIN(theCgTutorialSuite, "Cg教程：可编程实时图形权威指南");



	ADD_TEST_END(theCgTutorialSuite);
}

