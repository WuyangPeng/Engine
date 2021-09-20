// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 引擎辅助测试版本：0.0.0.1 (2019/09/28 20:51)

#include "TestingHelper.h"
#include "Testing.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

CMAIN_FUNCTION_HELPER_SUBCLASS_COMPLETE_DEFINE(BookSoundProgramming, TestingHelper, "书籍 音效编程")

void BookSoundProgramming::TestingHelper
	::AddSuites()
{
	AddBeginningGameAudioProgrammingSuite();
}

void BookSoundProgramming::TestingHelper
	::AddBeginningGameAudioProgrammingSuite()
{
	ADD_TEST_BEGIN(beginningGameAudioProgrammingSuite, "游戏音效编程");



	ADD_TEST_END(beginningGameAudioProgrammingSuite);
}

