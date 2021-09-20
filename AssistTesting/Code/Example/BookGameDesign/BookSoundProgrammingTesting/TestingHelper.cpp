// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ���渨�����԰汾��0.0.0.1 (2019/09/28 20:51)

#include "TestingHelper.h"
#include "Testing.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

CMAIN_FUNCTION_HELPER_SUBCLASS_COMPLETE_DEFINE(BookSoundProgramming, TestingHelper, "�鼮 ��Ч���")

void BookSoundProgramming::TestingHelper
	::AddSuites()
{
	AddBeginningGameAudioProgrammingSuite();
}

void BookSoundProgramming::TestingHelper
	::AddBeginningGameAudioProgrammingSuite()
{
	ADD_TEST_BEGIN(beginningGameAudioProgrammingSuite, "��Ϸ��Ч���");



	ADD_TEST_END(beginningGameAudioProgrammingSuite);
}

