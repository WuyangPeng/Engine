// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ���渨���汾��0.0.0.1 (2019/08/28 21:22)

#include "TestingHelper.h"
#include "Testing.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

CMAIN_FUNCTION_HELPER_SUBCLASS_COMPLETE_DEFINE(BookCOM, TestingHelper, "�鼮 ����ϵͳ COM")

void BookCOM::TestingHelper
	::AddSuites()
{
	AddInsideCOMSuite();
	AddEssentialCOMSuite();
}

void BookCOM::TestingHelper
	::AddInsideCOMSuite()
{
	ADD_TEST_BEGIN(insideCOMSuite, "COM ������Ļ");



	ADD_TEST_END(insideCOMSuite);
}

void BookCOM::TestingHelper
	::AddEssentialCOMSuite()
{
	ADD_TEST_BEGIN(essentialCOMSuite, "Essential COM");



	ADD_TEST_END(essentialCOMSuite);

}

