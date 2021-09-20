// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ������԰汾��0.0.2.3 (2020/03/06 12:21)

#include "PoolTesting.h"
 
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#include <array>

using std::array;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(CoreTools, PoolTesting)

void CoreTools::PoolTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(PoolTest);
}

void CoreTools::PoolTesting ::PoolTest() noexcept
{
	 
}