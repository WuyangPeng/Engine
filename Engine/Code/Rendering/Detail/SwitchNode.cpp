///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 13:54)

#include "Rendering/RenderingExport.h"

#include "SwitchNode.h"
#include "Flags/SwitchNodeType.h"
#include "System/Helper/PragmaWarning.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "Mathematics/Algebra/BoundingSphereDetail.h"

CORE_TOOLS_RTTI_DEFINE(Rendering, SwitchNode);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, SwitchNode);
CORE_TOOLS_FACTORY_DEFINE(Rendering, SwitchNode);

Rendering::SwitchNode::SwitchNodeSharedPtr Rendering::SwitchNode::Create()
{
    return std::make_shared<ClassType>(NodeCreate::Init);
}

Rendering::SwitchNode::SwitchNode(NodeCreate nodeCreate)
    : ParentType{ "SwitchNode", nodeCreate }, activeChild{ System::EnumCastUnderlying(SwitchNodeType::InvalidChild) }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, SwitchNode)

void Rendering::SwitchNode::GetVisibleSet(Culler& culler, const CameraSharedPtr& camera, bool noCull)
{
    if (activeChild != System::EnumCastUnderlying(SwitchNodeType::InvalidChild))
    {
        // 所有视觉对象在活跃的子树中，添加到可见组。
        auto child = GetChild(activeChild);
        if (child)
        {
            child->OnGetVisibleSet(culler, camera, noCull);
        }
    }
}

Rendering::ControllerInterfaceSharedPtr Rendering::SwitchNode::Clone() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return std::make_shared<ClassType>(*this);
}

Rendering::SwitchNode::SwitchNode(LoadConstructor value)
    : ParentType{ value }, activeChild{ System::EnumCastUnderlying(SwitchNodeType::InvalidChild) }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

void Rendering::SwitchNode::SetActiveChild(int aActiveChild)
{
    RENDERING_CLASS_IS_VALID_1;
    RENDERING_ASSERTION_0(aActiveChild == System::EnumCastUnderlying(SwitchNodeType::InvalidChild) || aActiveChild < GetNumChildren(), "指定的活跃子节点无效\n");

    activeChild = aActiveChild;
}

int Rendering::SwitchNode::GetActiveChild() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return activeChild;
}

void Rendering::SwitchNode::DisableAllChildren() noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    activeChild = System::EnumCastUnderlying(SwitchNodeType::InvalidChild);
}

int Rendering::SwitchNode::GetStreamingSize() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    auto size = ParentType::GetStreamingSize();

    size += CoreTools::GetStreamSize(activeChild);

    return size;
}

int64_t Rendering::SwitchNode::Register(CoreTools::ObjectRegister& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return ParentType::Register(target);
}

void Rendering::SwitchNode::Save(CoreTools::BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target);

    ParentType::Save(target);

    target.Write(activeChild);

    CORE_TOOLS_END_DEBUG_STREAM_SAVE(target);
}

void Rendering::SwitchNode::Link(CoreTools::ObjectLink& source)
{
    RENDERING_CLASS_IS_VALID_1;

    ParentType::Link(source);
}

void Rendering::SwitchNode::PostLink()
{
    RENDERING_CLASS_IS_VALID_1;

    ParentType::PostLink();
}

void Rendering::SwitchNode::Load(CoreTools::BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_1;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source);

    ParentType::Load(source);

    source.Read(activeChild);

    CORE_TOOLS_END_DEBUG_STREAM_LOAD(source);
}

Rendering::PickRecordContainer Rendering::SwitchNode::ExecuteRecursive(const APoint& origin, const AVector& direction, float tMin, float tMax) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    auto container = PickRecordContainer::Create();

    const auto active = GetActiveChild();
    if (active != System::EnumCastUnderlying(SwitchNodeType::InvalidChild))
    {
        if (GetWorldBound().TestIntersection(origin, direction, tMin, tMax))
        {
            auto child = GetConstChild(active);
            if (child)
            {
                auto childContainer = child->ExecuteRecursive(origin, direction, tMin, tMax);

                container.InsertPickRecord(childContainer);
            }
        }
    }

    return container;
}

CoreTools::ObjectInterface::ObjectInterfaceSharedPtr Rendering::SwitchNode::CloneObject() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return std::make_shared<ClassType>(*this);
}
