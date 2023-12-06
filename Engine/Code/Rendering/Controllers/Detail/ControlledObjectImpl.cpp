/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.1 (2023/11/21 09:16)

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

Rendering::ControlledObjectImpl::ControlledObjectImpl() noexcept
    : controllers{}
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::ControlledObjectImpl::~ControlledObjectImpl() noexcept
{
    RENDERING_SELF_CLASS_IS_VALID_9;

    CoreTools::NoexceptNoReturn(*this, &ClassType::DetachAllControllers);
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, ControlledObjectImpl)

bool Rendering::ControlledObjectImpl::Update(double applicationTime)
{
    RENDERING_CLASS_IS_VALID_9;

    auto someoneUpdated = false;
    for (const auto& element : controllers)
    {
        if (element.object->Update(applicationTime))
        {
            someoneUpdated = true;
        }
    }
    return someoneUpdated;
}

int Rendering::ControlledObjectImpl::GetNumControllers() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return boost::numeric_cast<int>(controllers.size());
}

Rendering::ControlledObjectImpl::ConstControllerSharedPtr Rendering::ControlledObjectImpl::GetConstController(int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return controllers.at(index).object;
}

Rendering::ControlledObjectImpl::ControllerSharedPtr Rendering::ControlledObjectImpl::GetController(int index)
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return controllers.at(index).object;
}

void Rendering::ControlledObjectImpl::AttachController(const ControllerInterfaceSharedPtr& aController, const ControllerInterfaceSharedPtr& self)
{
    RENDERING_CLASS_IS_VALID_9;

    // ���Կ������Ƿ��Ѿ��������С�
    for (const auto& value : controllers)
    {
        if (aController == value.object)
        {
            // �����������б��У��������ִ���κβ�����
            return;
        }
    }

    aController->SetController(self);

    // ���������ڵ�ǰ�б��У����������
    controllers.emplace_back(aController);
}

void Rendering::ControlledObjectImpl::DetachController(const ControllerInterfaceSharedPtr& aController)
{
    RENDERING_CLASS_IS_VALID_9;

    for (auto iter = controllers.cbegin(); iter != controllers.cend(); ++iter)
    {
        if (aController == iter->object)
        {
            // ȡ���󶨵Ŀ���������
            aController->SetController(nullptr);

            // ���б���ɾ����������
            controllers.erase(iter);
            break;
        }
    }
}

void Rendering::ControlledObjectImpl::DetachAllControllers()
{
    RENDERING_CLASS_IS_VALID_9;

    for (const auto& element : controllers)
    {
        // ȡ���󶨵Ŀ���������
        element.object->SetController(nullptr);
    }

    controllers.clear();
}

CoreTools::ObjectSharedPtr Rendering::ControlledObjectImpl::GetObjectByName(const std::string& name)
{
    RENDERING_CLASS_IS_VALID_9;

    for (const auto& element : controllers)
    {
        if (element.object->GetName() == name)
        {
            return element.object;
        }
    }

    return Object::GetNullObject();
}

Rendering::ControlledObjectImpl::ObjectSharedPtrContainer Rendering::ControlledObjectImpl::GetAllObjectsByName(const std::string& name)
{
    RENDERING_CLASS_IS_VALID_9;

    ObjectSharedPtrContainer objects{};

    for (const auto& element : controllers)
    {
        if (element.object->GetName() == name)
        {
            objects.emplace_back(element.object);
        }
    }

    return objects;
}

CoreTools::ConstObjectSharedPtr Rendering::ControlledObjectImpl::GetConstObjectByName(const std::string& name) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    for (const auto& element : controllers)
    {
        if (element.object->GetName() == name)
        {
            return element.object;
        }
    }

    return Object::GetNullObject();
}

Rendering::ControlledObjectImpl::ConstObjectSharedPtrContainer Rendering::ControlledObjectImpl::GetAllConstObjectsByName(const std::string& name) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    ConstObjectSharedPtrContainer objects{};

    for (const auto& element : controllers)
    {
        if (element.object->GetName() == name)
        {
            objects.emplace_back(element.object);
        }
    }

    return objects;
}

int Rendering::ControlledObjectImpl::GetStreamingSize() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return GetStreamSize(controllers);
}

void Rendering::ControlledObjectImpl::Register(ObjectRegister& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    target.RegisterContainer(controllers);
}

void Rendering::ControlledObjectImpl::Save(BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    target.WriteObjectAssociatedContainerWithNumber(controllers);
}

void Rendering::ControlledObjectImpl::Link(ObjectLink& source)
{
    RENDERING_CLASS_IS_VALID_9;

    source.ResolveLinkContainer(controllers);
}

void Rendering::ControlledObjectImpl::Load(BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_9;

    source.ReadObjectAssociatedContainer(controllers);
}
