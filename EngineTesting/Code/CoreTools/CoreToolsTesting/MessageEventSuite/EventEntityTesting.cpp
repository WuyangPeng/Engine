// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/06 19:01)

#include "EventEntityTesting.h"  
#include "Detail/Entity.h"
#include "CoreTools/Helper/AssertMacro.h"   
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/MessageEvent/EntityManagerDetail.h"

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(CoreTools, EventEntityTesting)

void CoreTools::EventEntityTesting
	::MainTest()
{
	EntityManager::Create();

	ASSERT_NOT_THROW_EXCEPTION_0(EventTest);

	EntityManager::Destroy();
}

void CoreTools::EventEntityTesting
	::EventTest()
{
	auto entity = ENTITY_MANAGER_SINGLETON.MakeEntity<Entity>(1);

	ASSERT_EQUAL(entity->GetValue(), 1);

	CallbackParameters callbackParameters{};
	callbackParameters.SetValue(0, 10);

	Telegram<> telegram{ 1,5,3,2,callbackParameters };

	entity->EventFunction(telegram);

	ASSERT_EQUAL(entity->GetValue(), 11);
}
