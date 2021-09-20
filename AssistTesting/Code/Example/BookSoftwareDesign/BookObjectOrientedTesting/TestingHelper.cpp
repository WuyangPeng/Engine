// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ���渨�����԰汾��0.0.0.1 (2019/09/29 13:41)

#include "TestingHelper.h"
#include "Testing.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

CMAIN_FUNCTION_HELPER_SUBCLASS_COMPLETE_DEFINE(BookObjectOriented, TestingHelper, "�鼮 �������")

void BookObjectOriented::TestingHelper
	::AddSuites()
{
	AddObjectOrientedAnalysisAndDesignWithApplicationsSuite();
	AddObjectOrientedAnalysisDesignSuite();
	AddTheObjectOrientedThoughtProcessSuite();
}

void BookObjectOriented::TestingHelper
	::AddObjectOrientedAnalysisAndDesignWithApplicationsSuite()
{
	ADD_TEST_BEGIN(objectOrientedAnalysisAndDesignWithApplicationsSuite, "���������������");

	ADD_TEST_END(objectOrientedAnalysisAndDesignWithApplicationsSuite);
}

void BookObjectOriented::TestingHelper
	::AddObjectOrientedAnalysisDesignSuite()
{
	ADD_TEST_BEGIN(objectOrientedAnalysisDesignSuite, "��������������ƣ�UML 2.0�棩");

	ADD_TEST_END(objectOrientedAnalysisDesignSuite);
}

void BookObjectOriented::TestingHelper
	::AddTheObjectOrientedThoughtProcessSuite()
{
	ADD_TEST_BEGIN(theObjectOrientedThoughtProcessSuite, "д����ҿ��������������");

	ADD_TEST_END(theObjectOrientedThoughtProcessSuite);
}

