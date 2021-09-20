// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ���渨�����԰汾��0.0.0.1 (2019/09/27 21:53)

#include "TestingHelper.h"
#include "Testing.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

CMAIN_FUNCTION_HELPER_SUBCLASS_COMPLETE_DEFINE(BookATL, TestingHelper, "�鼮 ����ϵͳ ATL")

void BookATL::TestingHelper
	::AddSuites()
{
	AddATLDevelopersGuideSuite();
	AddATLInteranlsSuite();
}

void BookATL::TestingHelper
	::AddATLDevelopersGuideSuite()
{
	ADD_TEST_BEGIN(atlDevelopersGuideSuit, "ATL ����ָ��");



	ADD_TEST_END(atlDevelopersGuideSuit);
}

void BookATL::TestingHelper
	::AddATLInteranlsSuite()
{
	ADD_TEST_BEGIN(atlInteranlsSuit, "������� ATL");



	ADD_TEST_END(atlInteranlsSuit);
}

