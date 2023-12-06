/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.1 (2023/11/20 16:28)

#include "Rendering/RenderingExport.h"

#include "ControllerInterface.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/ObjectRegisterDetail.h"
#include "CoreTools/ObjectSystems/StreamSize.h"

CORE_TOOLS_RTTI_DEFINE(Rendering, ControllerInterface)
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, ControllerInterface);
CORE_TOOLS_ABSTRACT_FACTORY_DEFINE(Rendering, ControllerInterface);
CORE_TOOLS_DEFAULT_OBJECT_LOAD_CONSTRUCTOR_DEFINE(Rendering, ControllerInterface);

Rendering::ControllerInterface::ControllerInterface(const std::string& name)
    : ParentType{ name }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, ControllerInterface)

Rendering::ControllerInterface::ConstControllerSharedPtr Rendering::ControllerInterface::GetController() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    THROW_EXCEPTION(SYSTEM_TEXT("Controller禁止调用GetController"))
}

Rendering::ControllerInterface::ControllerSharedPtr Rendering::ControllerInterface::GetController()
{
    RENDERING_CLASS_IS_VALID_1;

    THROW_EXCEPTION(SYSTEM_TEXT("Controller禁止调用GetController"))
}

void Rendering::ControllerInterface::SetController(const ControllerSharedPtr& controller)
{
    RENDERING_CLASS_IS_VALID_1;

    System::UnusedFunction(controller);

    THROW_EXCEPTION(SYSTEM_TEXT("Controller禁止调用SetController"))
}

Rendering::ControllerInterface::ConstControllerSharedPtr Rendering::ControllerInterface::GetConstController(int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    System::UnusedFunction(index);

    THROW_EXCEPTION(SYSTEM_TEXT("Controller禁止调用GetConstController"))
}

Rendering::ControllerInterface::ControllerSharedPtr Rendering::ControllerInterface::GetController(int index)
{
    RENDERING_CLASS_IS_VALID_1;

    System::UnusedFunction(index);

    THROW_EXCEPTION(SYSTEM_TEXT("Controller禁止调用GetController"))
}

void Rendering::ControllerInterface::AttachController(const ControllerSharedPtr& controller)
{
    RENDERING_CLASS_IS_VALID_1;

    System::UnusedFunction(controller);

    THROW_EXCEPTION(SYSTEM_TEXT("Controller禁止调用AttachController"))
}

void Rendering::ControllerInterface::DetachController(const ControllerSharedPtr& controller)
{
    RENDERING_CLASS_IS_VALID_1;

    System::UnusedFunction(controller);

    THROW_EXCEPTION(SYSTEM_TEXT("Controller禁止调用DetachController"))
}

void Rendering::ControllerInterface::DetachAllControllers()
{
    RENDERING_CLASS_IS_VALID_1;

    THROW_EXCEPTION(SYSTEM_TEXT("Controller禁止调用DetachAllControllers"))
}

int Rendering::ControllerInterface::GetNumControllers() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    CoreTools::DisableNoexcept();

    return 0;
}