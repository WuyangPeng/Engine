// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/06 17:06)

#include "DllFunctionHelperTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/Threading/DllMutex.h"
#include "CoreTools/MainFunctionHelper/DllFunctionHelper.h"

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(CoreTools, DllFunctionHelperTesting)

void CoreTools::DllFunctionHelperTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(DllMutexTest);
}

void CoreTools::DllFunctionHelperTesting
	::DllMutexTest()
{
	DllMutex mutex{};

	DllFunctionHelper::InitializeMutex(&mutex);
	DllFunctionHelper::DeleteMutex(&mutex);
}

