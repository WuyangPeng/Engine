// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ������԰汾��0.0.0.3 (2019/09/06 09:40)

#include "ParticleControllerTest.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"

#include SYSTEM_WARNING_DISABLE(26440)
#include SYSTEM_WARNING_DISABLE(26455)
CORE_TOOLS_RTTI_DEFINE(Rendering, ParticleControllerTest);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, ParticleControllerTest);
CORE_TOOLS_FACTORY_DEFINE(Rendering, ParticleControllerTest);
CORE_TOOLS_DEFAULT_OBJECT_LOAD_CONSTRUCTOR_DEFINE(Rendering, ParticleControllerTest);

Rendering::ParticleControllerTest::ParticleControllerTest()
    : ParentType{ CoreTools::DisableNotThrow::Disable }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, ParticleControllerTest)

Rendering::ParticleControllerTest::ControllerInterfaceSharedPtr Rendering::ParticleControllerTest::Clone() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return std::make_shared<ClassType>(*this);
}

CoreTools::ObjectInterface::ObjectInterfaceSharedPtr Rendering::ParticleControllerTest::CloneObject() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return std::make_shared<ClassType>(*this);
}
