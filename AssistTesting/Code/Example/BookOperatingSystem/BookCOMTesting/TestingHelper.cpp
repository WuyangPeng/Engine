// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 引擎辅助版本：0.0.0.1 (2019/08/28 21:22)

#include "TestingHelper.h"
#include "Testing.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

CMAIN_FUNCTION_HELPER_SUBCLASS_COMPLETE_DEFINE(BookCOM, TestingHelper, "书籍 操作系统 COM")

void BookCOM::TestingHelper
	::AddSuites()
{
	AddInsideCOMSuite();
	AddEssentialCOMSuite();
}

void BookCOM::TestingHelper
	::AddInsideCOMSuite()
{
	ADD_TEST_BEGIN(insideCOMSuite, "COM 技术内幕");



	ADD_TEST_END(insideCOMSuite);
}

void BookCOM::TestingHelper
	::AddEssentialCOMSuite()
{
	ADD_TEST_BEGIN(essentialCOMSuite, "Essential COM");



	ADD_TEST_END(essentialCOMSuite);

}

