///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 14:03)

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

Rendering::ControlledObjectImpl::~ControlledObjectImpl()
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
    RENDERING_ASSERTION_0(0 <= index && index < GetNumControllers(), "索引错误在GetController\n");

    return controllers.at(index).object;
}

Rendering::ControllerInterfaceSharedPtr Rendering::ControlledObjectImpl::GetController(int index)
{
    RENDERING_CLASS_IS_VALID_CONST_1;
    RENDERING_ASSERTION_0(0 <= index && index < GetNumControllers(), "索引错误在GetController\n");

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

    controller->SetObject(realThis);

    controllers.emplace_back(controller);
}

void Rendering::ControlledObjectImpl::AttachControllerInCopy(const ControllerInterfaceSharedPtr& controller)
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

    controller->SetObjectInCopy(realThis);

    controllers.emplace_back(controller);
}

const Rendering::ControllerInterface* Rendering::ControlledObjectImpl::GetControllerObject() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return object.object.get();
}

void Rendering::ControlledObjectImpl::SetObject(ControllerInterface* aObject)
{
    RENDERING_CLASS_IS_VALID_1;

    if (aObject != nullptr)
    {
        object.object = boost::polymorphic_pointer_cast<ControllerInterface>(aObject->shared_from_this());
    }
}

Rendering::ControllerInterface* Rendering::ControlledObjectImpl::GetControllerObject() noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    return object.object.get();
}

void Rendering::ControlledObjectImpl::DetachController(const ControllerInterfaceSharedPtr& controller)
{
    RENDERING_CLASS_IS_VALID_1;

    auto findIndex = -1;

    for (auto i = 0u; i < controllers.size(); ++i)
    {
        if (controller == controllers.at(i).object)
        {
            // 取消绑定的控制器对象。
            controller->SetObject(nullptr);

            findIndex = i;
            break;
        }
    }

    if (findIndex != -1)
    {
        // 删除数组中的控制器对象，保持数组连续
        for (auto i = findIndex + 1; i < boost::numeric_cast<int>(controllers.size()); ++i)
        {
            const auto i0 = i - 1;
            controllers.at(i0) = controllers.at(i);
        }
        controllers.pop_back();
    }
}

void Rendering::ControlledObjectImpl::DetachAllControllers()
{
    RENDERING_CLASS_IS_VALID_1;

    for (const auto& controller : controllers)
    {
        // 取消绑定的控制器对象。
        controller.object->SetObject(nullptr);
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

std::vector<CoreTools::ObjectSharedPtr> Rendering::ControlledObjectImpl::GetAllObjectsByName(const std::string& name)
{
    RENDERING_CLASS_IS_VALID_1;

    std::vector<CoreTools::ObjectSharedPtr> objects{};

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

std::vector<CoreTools::ConstObjectSharedPtr> Rendering::ControlledObjectImpl::GetAllConstObjectsByName(const std::string& name) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    std::vector<CoreTools::ConstObjectSharedPtr> objects{};

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

    auto size = CoreTools::GetStreamSize(int32_t{});

    if (!controllers.empty())
    {
        size += boost::numeric_cast<int32_t>(CoreTools::GetStreamSize(controllers.at(0)) * controllers.size());
    }

    size += CoreTools::GetStreamSize(object);

    return size;
}

void Rendering::ControlledObjectImpl::Register(CoreTools::ObjectRegister& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    if (!controllers.empty())
    {
        target.RegisterContainer(controllers);
    }

    target.Register(object);
}

void Rendering::ControlledObjectImpl::Save(CoreTools::BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    if (!controllers.empty())
    {
        target.WriteObjectAssociatedContainerWithNumber(controllers);
    }
    else
    {
        constexpr int zero = 0;
        target.Write(zero);
    }

    target.WriteObjectAssociated(object);
}

void Rendering::ControlledObjectImpl::Link(CoreTools::ObjectLink& source)
{
    RENDERING_CLASS_IS_VALID_1;

    if (!controllers.empty())
    {
        source.ResolveLinkContainer(controllers);
    }

    source.ResolveLink(object);
}

void Rendering::ControlledObjectImpl::Load(CoreTools::BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_1;

    int32_t size{ 0 };
    source.Read(size);

    controllers.resize(size);

    if (!controllers.empty())
    {
        source.ReadObjectAssociatedContainer(controllers);
    }

    source.ReadObjectAssociated(object);
}
