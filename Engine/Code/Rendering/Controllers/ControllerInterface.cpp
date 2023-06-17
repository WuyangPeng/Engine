///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 14:06)

#include "Rendering/RenderingExport.h"

#include "ControllerInterface.h"

#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/ObjectRegisterDetail.h"
#include "CoreTools/ObjectSystems/StreamSize.h"

CORE_TOOLS_RTTI_DEFINE(Rendering, ControllerInterface);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, ControllerInterface);
CORE_TOOLS_ABSTRACT_FACTORY_DEFINE(Rendering, ControllerInterface);
CORE_TOOLS_DEFAULT_OBJECT_LOAD_CONSTRUCTOR_DEFINE(Rendering, ControllerInterface);

Rendering::ControllerInterface::ControllerInterface(MAYBE_UNUSED CoreTools::DisableNotThrow disableNotThrow)
    : ParentType{ "ControllerInterface" }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, ControllerInterface)

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26418)
void Rendering::ControllerInterface::AttachController(MAYBE_UNUSED ControllerInterfaceSharedPtr controller)
{
    RENDERING_CLASS_IS_VALID_1;
    RENDERING_ASSERTION_1(false, "Controller禁止调用AttachController");

    CoreTools::DisableNoexcept();
}
#include STSTEM_WARNING_POP

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26418)
void Rendering::ControllerInterface::DetachController(MAYBE_UNUSED ControllerInterfaceSharedPtr controller)
{
    RENDERING_CLASS_IS_VALID_1;
    RENDERING_ASSERTION_1(false, "Controller禁止调用DetachController");

    CoreTools::DisableNoexcept();
}
#include STSTEM_WARNING_POP

int Rendering::ControllerInterface::GetNumControllers() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    CoreTools::DisableNoexcept();

    return 0;
}

void Rendering::ControllerInterface::SetObjectInCopy(ControllerInterface* object)
{
    RENDERING_CLASS_IS_VALID_1;

    CoreTools::DisableNoexcept();

    SetObject(object);
}
