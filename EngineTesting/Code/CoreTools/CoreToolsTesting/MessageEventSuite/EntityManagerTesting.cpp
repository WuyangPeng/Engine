// Copyright (c) 2011-2020
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒıÇæ²âÊÔ°æ±¾£º0.0.2.3 (2020/03/06 19:01)

#include "EntityManagerTesting.h"  
#include "Detail/Entity.h"
#include "CoreTools/Helper/AssertMacro.h"   
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/MessageEvent/EntityManagerDetail.h"

using std::shared_ptr;
using std::make_shared;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(CoreTools, EntityManagerTesting)

void CoreTools::EntityManagerTesting
	::MainTest()
{
	EntityManager::Create();

	ASSERT_NOT_THROW_EXCEPTION_0(ManagerTest);

	EntityManager::Destroy();
}

void CoreTools::EntityManagerTesting ::ManagerTest() noexcept
{
	 
}
