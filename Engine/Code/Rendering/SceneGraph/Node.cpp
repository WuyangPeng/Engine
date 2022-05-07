///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.5 (2022/04/02 15:26)

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
#include "Rendering/DataTypes/BoundDetail.h"

using std::make_shared;
using std::string;
using std::vector;

COPY_UNSHARED_CLONE_SELF_DEFINE(Rendering, Node)

CORE_TOOLS_RTTI_DEFINE(Rendering, Node);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, Node);
CORE_TOOLS_FACTORY_DEFINE(Rendering, Node);
CORE_TOOLS_DEFAULT_NAMES_USE_IMPL_DEFINE(Rendering, Node);

Rendering::Node::NodeSharedPtr Rendering::Node::Create()
{
    return std::make_shared<ClassType>(NodeCreate::Init);
}

Rendering::Node::Node(MAYBE_UNUSED NodeCreate nodeCreate)
    : ParentType{ CoreTools::DisableNotThrow::Disable }, impl{ this }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::Node::Node(const Node& rhs)
    : ParentType{ rhs }, impl{ this }
{
    const int count = rhs.GetNumChildren();

    for (auto index = 0; index < count; ++index)
    {
        auto original = rhs.GetConstChild(index);

        auto controller = boost::polymorphic_pointer_cast<Spatial>(original->Clone());

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
        auto original = rhs.GetConstChild(index);

        auto controller = boost::polymorphic_pointer_cast<Spatial>(original->Clone());

        controller->SetParent(nullptr);
        AttachChild(controller);
    }

    return *this;
}

Rendering::Node::Node(Node&& rhs) noexcept
    : ParentType(std::move(rhs)), impl{ std::move(rhs.impl) }
{
    impl->ChangeRealThis(this);

    RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::Node& Rendering::Node::operator=(Node&& rhs) noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    ParentType::operator=(std::move(rhs));

    impl = std::move(rhs.impl);

    impl->ChangeRealThis(this);

    return *this;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, Node)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, Node, GetNumChildren, int)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, Node, AttachChild, SpatialSharedPtr, int)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, Node, DetachChild, SpatialSharedPtr, int)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, Node, DetachChildAt, int, Rendering::SpatialSharedPtr)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, Node, GetChild, int, Rendering::SpatialSharedPtr)

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

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, Node, GetConstChild, int, Rendering::ConstSpatialSharedPtr)

void Rendering::Node::UpdateWorldBound()
{
    RENDERING_CLASS_IS_VALID_1;

    if (!GetWorldBoundIsCurrent())
    {
        const auto bound = impl->GetWorldBound();
        BoundGrowToContain(bound);
    }
}

void Rendering::Node::GetVisibleSet(Culler& culler, bool noCull)
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->GetVisibleSet(culler, noCull);
}

Rendering::Node::Node(LoadConstructor value)
    : ParentType{ value }, impl{ this }
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

uint64_t Rendering::Node::Register(CoreTools::ObjectRegister& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    const auto uniqueID = ParentType::Register(target);
    if (uniqueID != 0)
    {
        impl->Register(target);
    }

    return uniqueID;
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

Rendering::Node::ControllerInterfaceSharedPtr Rendering::Node::Clone() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return std::make_shared<ClassType>(*this);
}

Rendering::PickRecordContainer Rendering::Node::ExecuteRecursive(const APoint& origin, const AVector& direction, float tMin, float tMax) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    auto container = PickRecordContainer::Create();

    if (GetWorldBound().TestIntersection(origin, direction, tMin, tMax))
    {
        for (auto i = 0; i < GetNumChildren(); ++i)
        {
            auto child = GetConstChild(i);
            if (child)
            {
                auto childContainer = child->ExecuteRecursive(origin, direction, tMin, tMax);

                container.InsertPickRecord(childContainer);
            }
        }
    }

    return container;
}

bool Rendering::Node::UpdateImplWorldData(double applicationTime)
{
    return impl->UpdateWorldData(applicationTime);
}

CoreTools::ObjectInterfaceSharedPtr Rendering::Node::CloneObject() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return std::make_shared<ClassType>(*this);
}
