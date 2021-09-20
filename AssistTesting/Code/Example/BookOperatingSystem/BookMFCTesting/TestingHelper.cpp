// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ���渨�����԰汾��0.0.0.1 (2019/09/28 10:12)

#include "TestingHelper.h"
#include "Testing.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

CMAIN_FUNCTION_HELPER_SUBCLASS_COMPLETE_DEFINE(BookMFC, TestingHelper, "�鼮 ����ϵͳ MFC")

void BookMFC::TestingHelper
	::AddSuites()
{
	AddIvorHortonsBeginningVisualCppSuite();
	AddProgrammingWindowsWithMFCSuite();
	AddMFCBlackBookSuite();
}

void BookMFC::TestingHelper
	::AddIvorHortonsBeginningVisualCppSuite()
{
	ADD_TEST_BEGIN(ivorHortonsBeginningVisualCppSuite, "Visual C++ ���ž���"); 

	AddIvorHortonsBeginningVisualCppFifthEditionSuite(ivorHortonsBeginningVisualCppSuite);
	AddIvorHortonsBeginningVisualCppSeventhEditionSuite(ivorHortonsBeginningVisualCppSuite);

	ADD_TEST_END(ivorHortonsBeginningVisualCppSuite);
}

void BookMFC::TestingHelper
	::AddIvorHortonsBeginningVisualCppFifthEditionSuite(Suite& ivorHortonsBeginningVisualCppSuite)
{
	ADD_TEST_BEGIN(ivorHortonsBeginningVisualCppFifthEditionSuite, "Visual C++ ���ž��� ��5�� ");
	 

	ivorHortonsBeginningVisualCppSuite.AddSuite(ivorHortonsBeginningVisualCppFifthEditionSuite);
}

void BookMFC::TestingHelper
	::AddIvorHortonsBeginningVisualCppSeventhEditionSuite(Suite& ivorHortonsBeginningVisualCppSuite)
{
	ADD_TEST_BEGIN(ivorHortonsBeginningVisualCppSeventhEditionSuite, "Visual C++ ���ž��� ��7�� ");


	ivorHortonsBeginningVisualCppSuite.AddSuite(ivorHortonsBeginningVisualCppSeventhEditionSuite);
}

void BookMFC::TestingHelper
	::AddProgrammingWindowsWithMFCSuite()
{
	ADD_TEST_BEGIN(programmingWindowsWithMFCSuite, "MFC Windows�������");

	ADD_TEST_END(programmingWindowsWithMFCSuite);
}

void BookMFC::TestingHelper
	::AddMFCBlackBookSuite()
{
	ADD_TEST_BEGIN(mfcBlackBookSuite, "MFC ������Ļ");

	ADD_TEST_END(mfcBlackBookSuite);
}



