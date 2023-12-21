/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.2 (2023/12/08 09:48)

#include "Rendering/RenderingExport.h"

#include "Node.h"
#include "Detail/NodeImpl.h"
#include "System/Helper/PragmaWarning/PolymorphicPointerCast.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "Mathematics/Algebra/BoundingSphereDetail.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(Rendering, Node)

CORE_TOOLS_RTTI_DEFINE(Rendering, Node);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, Node);
CORE_TOOLS_FACTORY_DEFINE(Rendering, Node);
CORE_TOOLS_DEFAULT_NAMES_USE_IMPL_DEFINE(Rendering, Node)

Rendering::Node::NodeSharedPtr Rendering::Node::Create(const std::string& name)
{
    return std::make_shared<ClassType>(name, NodeCreate::Init);
}

Rendering::Node::Node(const std::string& name, NodeCreate nodeCreate)
    : ParentType{ name }, impl{ CoreTools::ImplCreateUseDefaultConstruction::Default }
{
    System::UnusedFunction(nodeCreate);

    RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::Node::Node(const Node& rhs)
    : ParentType{ rhs }, impl{ CoreTools::ImplCreateUseDefaultConstruction::Default }
{
    const int count = rhs.GetNumChildren();

    for (auto index = 0; index < count; ++index)
    {
        const auto original = rhs.GetConstChild(index);

        const auto controller = boost::polymorphic_pointer_cast<Spatial>(original->Clone());

        controller->SetParent(nullptr);

        AttachChild(controller);
    }

    RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::Node& Rendering::Node::operator=(const Node& rhs)
{
    RENDERING_CLASS_IS_VALID_1;

    ParentType::operator=(rhs);

    impl->Clear();

    const auto count = rhs.GetNumChildren();

    for (auto index = 0; index < count; ++index)
    {
        const auto original = rhs.GetConstChild(index);

        const auto controller = boost::polymorphic_pointer_cast<Spatial>(original->Clone());

        controller->SetParent(nullptr);
        AttachChild(controller);
    }

    return *this;
}

Rendering::Node::Node(Node&& rhs) noexcept
    : ParentType(std::move(rhs)), impl{ std::move(rhs.impl) }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::Node& Rendering::Node::operator=(Node&& rhs) noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    impl = std::move(rhs.impl);

    ParentType::operator=(std::move(rhs));

    return *this;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, Node)

int Rendering::Node::GetNumChildren() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetNumChildren();
}

int Rendering::Node::DetachChild(const SpatialSharedPtr& child)
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->DetachChild(child);
}

Rendering::Spatial::SpatialSharedPtr Rendering::Node::DetachChildAt(int index)
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->DetachChildAt(index);
}

void Rendering::Node::DetachAllChildren()
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->DetachAllChildren();
}

Rendering::Spatial::SpatialSharedPtr Rendering::Node::SetChild(int index, const SpatialSharedPtr& child)
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->SetChild(index, child, boost::polymorphic_pointer_cast<Spatial>(shared_from_this()));
}

Rendering::Spatial::SpatialSharedPtr Rendering::Node::GetChild(int index)
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->GetChild(index);
}

Rendering::Spatial::ConstSpatialSharedPtr Rendering::Node::GetConstChild(int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetConstChild(index);
}

int Rendering::Node::AttachChild(const SpatialSharedPtr& child)
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->AttachChild(child, boost::polymorphic_pointer_cast<Spatial>(shared_from_this()));
}

bool Rendering::Node::UpdateWorldData(double applicationTime)
{
    RENDERING_CLASS_IS_VALID_1;

    auto result = ParentType::UpdateWorldData(applicationTime);

    if (impl->UpdateWorldData(applicationTime))
    {
        result = true;
    }

    return result;
}

void Rendering::Node::UpdateWorldBound()
{
    RENDERING_CLASS_IS_VALID_1;

    if (!GetWorldBoundIsCurrent())
    {
        const auto bound = impl->GetWorldBound();
        BoundGrowToContain(bound);
    }
}

void Rendering::Node::GetVisibleSet(Culler& culler, const CameraSharedPtr& camera, bool noCull)
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->GetVisibleSet(culler, camera, noCull);
}

Rendering::Node::Node(LoadConstructor value)
    : ParentType{ value }, impl{ CoreTools::ImplCreateUseDefaultConstruction::Default }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

int Rendering::Node::GetStreamingSize() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    auto size = ParentType::GetStreamingSize();

    size += impl->GetStreamingSize();

    return size;
}

int64_t Rendering::Node::Register(CoreTools::ObjectRegister& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    const auto registerId = ParentType::Register(target);
    if (registerId != 0)
    {
        impl->Register(target);
    }

    return registerId;
}

void Rendering::Node::Save(CoreTools::BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target);

    ParentType::Save(target);

    impl->Save(target);

    CORE_TOOLS_END_DEBUG_STREAM_SAVE(target);
}

void Rendering::Node::Link(CoreTools::ObjectLink& source)
{
    RENDERING_CLASS_IS_VALID_1;

    ParentType::Link(source);

    impl->Link(source);
}

void Rendering::Node::PostLink()
{
    RENDERING_CLASS_IS_VALID_1;

    ParentType::PostLink();
}

void Rendering::Node::Load(CoreTools::BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_1;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source);

    ParentType::Load(source);

    impl->Load(source);

    CORE_TOOLS_END_DEBUG_STREAM_LOAD(source);
}

Rendering::Node::ControllerSharedPtr Rendering::Node::Clone() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return std::make_shared<ClassType>(*this);
}

Rendering::PickRecordContainer Rendering::Node::ExecuteRecursive(const APoint& origin, const AVector& direction, float tMin, float tMax) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->ExecuteRecursive(origin, direction, tMin, tMax);
}

bool Rendering::Node::UpdateChildWorldData(double applicationTime)
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->UpdateWorldData(applicationTime);
}

CoreTools::ObjectInterfaceSharedPtr Rendering::Node::CloneObject() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return std::make_shared<ClassType>(*this);
}
