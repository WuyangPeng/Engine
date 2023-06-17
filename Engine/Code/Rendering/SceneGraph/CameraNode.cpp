///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 11:16)

#include "Rendering/RenderingExport.h"

#include "CameraNode.h"
#include "Detail/CameraNodeImpl.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "Mathematics/Algebra/AVectorDetail.h"
#include "Mathematics/Algebra/MatrixDetail.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(Rendering, CameraNode)

CORE_TOOLS_RTTI_DEFINE(Rendering, CameraNode);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, CameraNode);
CORE_TOOLS_FACTORY_DEFINE(Rendering, CameraNode);

Rendering::CameraNode::CameraNode(const CameraSharedPtr& camera)
    : ParentType{ NodeCreate::Init }, impl{ camera }
{
    const auto transform = impl->GetLocalTransform();

    SetLocalTransform(transform);

    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, CameraNode)

void Rendering::CameraNode::SetCamera(const CameraSharedPtr& camera)
{
    RENDERING_CLASS_IS_VALID_1;

    impl->SetCamera(camera);

    const auto transform = impl->GetLocalTransform();

    SetLocalTransform(transform);

    Update();
}

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, CameraNode, GetCamera, Rendering::ConstCameraSharedPtr)

bool Rendering::CameraNode::UpdateWorldData(double applicationTime)
{
    RENDERING_CLASS_IS_VALID_1;

    const auto result = ParentType::UpdateWorldData(applicationTime);

    const auto worldTransform = GetWorldTransform();
    const auto cameraPosition = worldTransform.GetTranslate();
    const auto rotate = worldTransform.GetRotate();

    const auto cameraDirectionVector = rotate.GetColumn(0);
    const auto cameraUpVector = rotate.GetColumn(1);
    const auto cameraRightVector = rotate.GetColumn(2);

    impl->SetFrame(cameraPosition, Mathematics::AVector{ cameraDirectionVector }, Mathematics::AVector{ cameraUpVector }, Mathematics::AVector{ cameraRightVector });

    return result;
}

CoreTools::ObjectSharedPtr Rendering::CameraNode::GetObjectByName(const std::string& name)
{
    RENDERING_CLASS_IS_VALID_1;

    auto found = ParentType::GetObjectByName(name);
    if (found != nullptr)
    {
        return found;
    }
    else
    {
        return impl->GetObjectByName(name);
    }
}

std::vector<CoreTools::ObjectSharedPtr> Rendering::CameraNode::GetAllObjectsByName(const std::string& name)
{
    RENDERING_CLASS_IS_VALID_1;

    auto parentObjects = ParentType::GetAllObjectsByName(name);

    auto implObjects = impl->GetAllObjectsByName(name);
    parentObjects.insert(parentObjects.end(), implObjects.begin(), implObjects.end());

    return parentObjects;
}

CoreTools::ConstObjectSharedPtr Rendering::CameraNode::GetConstObjectByName(const std::string& name) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    auto found = ParentType::GetConstObjectByName(name);
    if (found != nullptr)
    {
        return found;
    }
    else
    {
        return impl->GetConstObjectByName(name);
    }
}

std::vector<CoreTools::ConstObjectSharedPtr> Rendering::CameraNode::GetAllConstObjectsByName(const std::string& name) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    auto parentObjects = ParentType::GetAllConstObjectsByName(name);

    auto implObjects = impl->GetAllConstObjectsByName(name);
    parentObjects.insert(parentObjects.end(), implObjects.begin(), implObjects.end());

    return parentObjects;
}

Rendering::CameraNode::CameraNode(LoadConstructor value)
    : ParentType{ value }, impl{ CameraSharedPtr{} }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

int Rendering::CameraNode::GetStreamingSize() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    auto size = ParentType::GetStreamingSize();

    size += impl->GetStreamingSize();

    return size;
}

int64_t Rendering::CameraNode::Register(CoreTools::ObjectRegister& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    const auto registerID = ParentType::Register(target);
    if (registerID != 0)
    {
        impl->Register(target);
    }

    return registerID;
}

void Rendering::CameraNode::Save(CoreTools::BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target);

    ParentType::Save(target);

    impl->Save(target);

    CORE_TOOLS_END_DEBUG_STREAM_SAVE(target);
}

void Rendering::CameraNode::Link(CoreTools::ObjectLink& source)
{
    RENDERING_CLASS_IS_VALID_1;

    ParentType::Link(source);

    impl->Link(source);
}

void Rendering::CameraNode::PostLink()
{
    RENDERING_CLASS_IS_VALID_1;

    ParentType::PostLink();
}

void Rendering::CameraNode::Load(CoreTools::BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_1;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source);

    ParentType::Load(source);

    impl->Load(source);

    CORE_TOOLS_END_DEBUG_STREAM_LOAD(source);
}

Rendering::CameraNode::ControllerInterfaceSharedPtr Rendering::CameraNode::Clone() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return std::make_shared<ClassType>(*this);
}

CoreTools::ObjectInterfaceSharedPtr Rendering::CameraNode::CloneObject() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return std::make_shared<ClassType>(*this);
}
