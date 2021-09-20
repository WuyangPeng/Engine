// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/06 19:00)

#include "BaseEntityTesting.h"
#include "Detail/Entity.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/MessageEvent/EntityManager.h"

using std::make_shared;
using std::shared_ptr;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(CoreTools, BaseEntityTesting)

void CoreTools::BaseEntityTesting ::MainTest()
{
    EntityManager::Create();

    ASSERT_NOT_THROW_EXCEPTION_0(BaseTest);

    EntityManager::Destroy();
}
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26414)
void CoreTools::BaseEntityTesting ::BaseTest()
{
    shared_ptr<Entity> entity{ make_shared<Entity>() };

    entity->Register();

    ASSERT_LESS(0, entity->GetEntityID());
}
#include STSTEM_WARNING_POP
