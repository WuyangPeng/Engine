// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ������԰汾��0.0.2.3 (2020/03/06 17:19)

#include "ResourceManagerLockTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h" 

using std::make_shared;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(CoreTools, ResourceManagerLockTesting)

void CoreTools::ResourceManagerLockTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(LockTest);
}

void CoreTools::ResourceManagerLockTesting ::LockTest() noexcept
{
	 
}