// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ���渨���汾��0.0.0.2 (2019/09/28 16:43)

#include "TestingHelper.h"
#include "Testing.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

CMAIN_FUNCTION_HELPER_SUBCLASS_COMPLETE_DEFINE(BookGraphics, TestingHelper, "�鼮 ͼ��ѧ")

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
	ADD_TEST_BEGIN(interactiveComputerGraphicsSuite, "����ʽ�����ͼ��ѧ");

	AddInteractiveComputerGraphicsFifthEditionSuite(interactiveComputerGraphicsSuite);
	AddInteractiveComputerGraphicsSeventhEditionSuite(interactiveComputerGraphicsSuite);

	ADD_TEST_END(interactiveComputerGraphicsSuite);
}

void BookGraphics::TestingHelper
	::AddInteractiveComputerGraphicsFifthEditionSuite(Suite& interactiveComputerGraphicsSuite)
{
	ADD_TEST_BEGIN(interactiveComputerGraphicsFifthEditionSuite, "����ʽ�����ͼ��ѧ ��5��");



	interactiveComputerGraphicsSuite.AddSuite(interactiveComputerGraphicsFifthEditionSuite);
}

void BookGraphics::TestingHelper
	::AddInteractiveComputerGraphicsSeventhEditionSuite(Suite& interactiveComputerGraphicsSuite)
{
	ADD_TEST_BEGIN(interactiveComputerGraphicsSeventhEditionSuite, "����ʽ�����ͼ��ѧ ��7��");



	interactiveComputerGraphicsSuite.AddSuite(interactiveComputerGraphicsSeventhEditionSuite);
}

void BookGraphics::TestingHelper
	::Add3DGamesSuite()
{
	ADD_TEST_BEGIN(threeDGamesSuite, "3D��Ϸ");

	Add3DGamesRealTimeRenderingAndSoftwareTechnologySuite(threeDGamesSuite);
	Add3DGamesAnimationAndAdvancedRealTimeRenderingSuite(threeDGamesSuite);

	ADD_TEST_END(threeDGamesSuite);
}

void BookGraphics::TestingHelper
	::Add3DGamesRealTimeRenderingAndSoftwareTechnologySuite(Suite& threeDGamesSuite)
{
	ADD_TEST_BEGIN(threeDGamesRealTimeRenderingAndSoftwareTechnologySuite, "3D��Ϸ ʵʱ��Ⱦ���������");



	threeDGamesSuite.AddSuite(threeDGamesRealTimeRenderingAndSoftwareTechnologySuite);
}

void BookGraphics::TestingHelper
	::Add3DGamesAnimationAndAdvancedRealTimeRenderingSuite(Suite& threeDGamesSuite)
{
	ADD_TEST_BEGIN(threeDGamesAnimationAndAdvancedRealTimeRenderingSuite, "3D��Ϸ ������߼�ʵʱ��Ⱦ����");



	threeDGamesSuite.AddSuite(threeDGamesAnimationAndAdvancedRealTimeRenderingSuite);
}

void BookGraphics::TestingHelper
	::Add3DComputerGraphicsSuite()
{
	ADD_TEST_BEGIN(threeDComputerGraphicsSuite, "3D�����ͼ��ѧ");



	ADD_TEST_END(threeDComputerGraphicsSuite);
}

void BookGraphics::TestingHelper
	::AddComputerGraphicsSuite()
{
	ADD_TEST_BEGIN(computerGraphicsSuite, "�����ͼ��ѧ�������Ӿ�������OpenGL��̼����� ");



	ADD_TEST_END(computerGraphicsSuite);
}

void BookGraphics::TestingHelper
	::AddComputerGraphicsPrinciplesAndPracticeSuite()
{
	ADD_TEST_BEGIN(computerGraphicsPrinciplesAndPracticeSuite, "�����ͼ��ѧԭ��ʵ������C��������");



	ADD_TEST_END(computerGraphicsPrinciplesAndPracticeSuite);
}

void BookGraphics::TestingHelper
	::AddFundamentalsOfComputerGraphicsSuite()
{
	ADD_TEST_BEGIN(fundamentalsOfComputerGraphicsSuite, "�����ͼ��ѧ");



	ADD_TEST_END(fundamentalsOfComputerGraphicsSuite);
}

void BookGraphics::TestingHelper
	::AddMichaelAbrashsGraphicsProgrammingBlackBookSuite()
{
	ADD_TEST_BEGIN(michaelAbrashsGraphicsProgrammingBlackBookSuite, "ͼ�γ��򿪷���Աָ��");



	ADD_TEST_END(michaelAbrashsGraphicsProgrammingBlackBookSuite);
}

void BookGraphics::TestingHelper
	::AddTheCgTutorialSuite()
{
	ADD_TEST_BEGIN(theCgTutorialSuite, "Cg�̳̣��ɱ��ʵʱͼ��Ȩ��ָ��");



	ADD_TEST_END(theCgTutorialSuite);
}

