// Copyright (c) 2011-2020
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
//
// ÒıÇæ²âÊÔ°æ±¾£º0.0.2.3 (2020/03/06 14:29)

#include "InitTermTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

bool CoreTools::InitTermTesting ::sm_TerminateCall{ false };
bool CoreTools::InitTermTesting ::sm_InitializeCall{ false };
bool CoreTools::InitTermTesting ::sm_TestBegin{ false };

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(CoreTools, InitTermTesting)

void CoreTools::InitTermTesting ::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(InitTermTest);
}

void CoreTools::InitTermTesting ::InitTermTest() noexcept
{
}
