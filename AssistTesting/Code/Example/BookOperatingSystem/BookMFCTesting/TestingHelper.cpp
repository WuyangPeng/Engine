// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 引擎辅助测试版本：0.0.0.1 (2019/09/28 10:12)

#include "TestingHelper.h"
#include "Testing.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

CMAIN_FUNCTION_HELPER_SUBCLASS_COMPLETE_DEFINE(BookMFC, TestingHelper, "书籍 操作系统 MFC")

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
	ADD_TEST_BEGIN(ivorHortonsBeginningVisualCppSuite, "Visual C++ 入门经典"); 

	AddIvorHortonsBeginningVisualCppFifthEditionSuite(ivorHortonsBeginningVisualCppSuite);
	AddIvorHortonsBeginningVisualCppSeventhEditionSuite(ivorHortonsBeginningVisualCppSuite);

	ADD_TEST_END(ivorHortonsBeginningVisualCppSuite);
}

void BookMFC::TestingHelper
	::AddIvorHortonsBeginningVisualCppFifthEditionSuite(Suite& ivorHortonsBeginningVisualCppSuite)
{
	ADD_TEST_BEGIN(ivorHortonsBeginningVisualCppFifthEditionSuite, "Visual C++ 入门经典 第5版 ");
	 

	ivorHortonsBeginningVisualCppSuite.AddSuite(ivorHortonsBeginningVisualCppFifthEditionSuite);
}

void BookMFC::TestingHelper
	::AddIvorHortonsBeginningVisualCppSeventhEditionSuite(Suite& ivorHortonsBeginningVisualCppSuite)
{
	ADD_TEST_BEGIN(ivorHortonsBeginningVisualCppSeventhEditionSuite, "Visual C++ 入门经典 第7版 ");


	ivorHortonsBeginningVisualCppSuite.AddSuite(ivorHortonsBeginningVisualCppSeventhEditionSuite);
}

void BookMFC::TestingHelper
	::AddProgrammingWindowsWithMFCSuite()
{
	ADD_TEST_BEGIN(programmingWindowsWithMFCSuite, "MFC Windows程序设计");

	ADD_TEST_END(programmingWindowsWithMFCSuite);
}

void BookMFC::TestingHelper
	::AddMFCBlackBookSuite()
{
	ADD_TEST_BEGIN(mfcBlackBookSuite, "MFC 技术内幕");

	ADD_TEST_END(mfcBlackBookSuite);
}



