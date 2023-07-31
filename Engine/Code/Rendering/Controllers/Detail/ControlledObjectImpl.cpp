///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/24 11:01)

#include "Rendering/RenderingExport.h"

#include "ControlledObjectImpl.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectLinkDetail.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/ObjectRegisterDetail.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "Rendering/Controllers/ControllerInterface.h"

Rendering::ControlledObjectImpl::ControlledObjectImpl(ControllerInterface* realThis) noexcept
    : controllers{}, realThis{ realThis }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::ControlledObjectImpl::~ControlledObjectImpl() noexcept
{
    RENDERING_SELF_CLASS_IS_VALID_1;

    CoreTools::NoexceptNoReturn(*this, &ClassType::DetachAllControllers);
}

#ifdef OPEN_CLASS_INVARIANT

bool Rendering::ControlledObjectImpl::IsValid() const noexcept
{
    if (realThis != nullptr)
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

bool Rendering::ControlledObjectImpl::Update(double applicationTime)
{
    RENDERING_CLASS_IS_VALID_1;

    return UpdateControllers(applicationTime);
}

int Rendering::ControlledObjectImpl::GetNumControllers() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return boost::numeric_cast<int>(controllers.size());
}

Rendering::ConstControllerInterfaceSharedPtr Rendering::ControlledObjectImpl::GetConstController(int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return controllers.at(index).object;
}

Rendering::ControllerInterfaceSharedPtr Rendering::ControlledObjectImpl::GetController(int index)
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return controllers.at(index).object;
}

void Rendering::ControlledObjectImpl::AttachController(const ControllerInterfaceSharedPtr& controller)
{
    RENDERING_CLASS_IS_VALID_1;

    // 测试控制器是否已经在数组中。
    for (const auto& value : controllers)
    {
        if (controller == value.object)
        {
            return;
        }
    }

    controller->SetControllerObject(boost::polymorphic_pointer_cast<ControllerInterface>(realThis->shared_from_this()));

    controllers.emplace_back(controller);
}

void Rendering::ControlledObjectImpl::DetachController(const ControllerInterfaceSharedPtr& controller)
{
    RENDERING_CLASS_IS_VALID_1;

    for (auto iter = controllers.cbegin(); iter != controllers.cend(); ++iter)
    {
        if (controller == iter->object)
        {
            // 取消绑定的控制器对象。
            controller->SetControllerObject(nullptr);
            controllers.erase(iter);
            break;
        }
    }
}

void Rendering::ControlledObjectImpl::DetachAllControllers()
{
    RENDERING_CLASS_IS_VALID_1;

    for (const auto& controller : controllers)
    {
        // 取消绑定的控制器对象。
        controller.object->SetControllerObject(nullptr);
    }

    controllers.clear();
}

bool Rendering::ControlledObjectImpl::UpdateControllers(double applicationTime)
{
    RENDERING_CLASS_IS_VALID_1;

    auto someoneUpdated = false;
    for (const auto& controller : controllers)
    {
        if (controller.object->Update(applicationTime))
        {
            someoneUpdated = true;
        }
    }
    return someoneUpdated;
}

CoreTools::ObjectSharedPtr Rendering::ControlledObjectImpl::GetObjectByName(const std::string& name)
{
    RENDERING_CLASS_IS_VALID_1;

    for (const auto& controller : controllers)
    {
        if (controller.object->GetName() == name)
        {
            return controller.object;
        }
    }

    return nullptr;
}

Rendering::ControlledObjectImpl::ObjectSharedPtrContainer Rendering::ControlledObjectImpl::GetAllObjectsByName(const std::string& name)
{
    RENDERING_CLASS_IS_VALID_1;

    ObjectSharedPtrContainer objects{};

    for (const auto& controller : controllers)
    {
        if (controller.object->GetName() == name)
        {
            objects.emplace_back(controller.object);
        }
    }

    return objects;
}

CoreTools::ConstObjectSharedPtr Rendering::ControlledObjectImpl::GetConstObjectByName(const std::string& name) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    for (const auto& controller : controllers)
    {
        if (controller.object->GetName() == name)
        {
            return controller.object;
        }
    }

    return nullptr;
}

Rendering::ControlledObjectImpl::ConstObjectSharedPtrContainer Rendering::ControlledObjectImpl::GetAllConstObjectsByName(const std::string& name) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    ConstObjectSharedPtrContainer objects{};

    for (const auto& controller : controllers)
    {
        if (controller.object->GetName() == name)
        {
            objects.emplace_back(controller.object);
        }
    }

    return objects;
}

int Rendering::ControlledObjectImpl::GetStreamingSize() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return CoreTools::GetStreamSize(controllers);
}

void Rendering::ControlledObjectImpl::Register(ObjectRegister& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    if (!controllers.empty())
    {
        target.RegisterContainer(controllers);
    }
}

void Rendering::ControlledObjectImpl::Save(BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    target.WriteObjectAssociatedContainerWithNumber(controllers);
}

void Rendering::ControlledObjectImpl::Link(CoreTools::ObjectLink& source)
{
    RENDERING_CLASS_IS_VALID_1;

    if (!controllers.empty())
    {
        source.ResolveLinkContainer(controllers);
    }
}

void Rendering::ControlledObjectImpl::Load(CoreTools::BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_1;

    source.ReadObjectAssociatedContainer(controllers);
}
