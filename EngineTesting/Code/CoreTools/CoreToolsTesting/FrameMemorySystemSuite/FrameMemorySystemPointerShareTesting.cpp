// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ������԰汾��0.0.2.3 (2020/03/06 18:10)

#include "FrameMemorySystemPointerShareTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h" 

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(CoreTools, FrameMemorySystemPointerShareTesting)

void CoreTools::FrameMemorySystemPointerShareTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(FrameMemorySystemPointerTest);
}

void CoreTools::FrameMemorySystemPointerShareTesting ::FrameMemorySystemPointerTest() noexcept
{
	 
}