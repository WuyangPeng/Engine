///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/19 14:15)

#include "Rendering/RenderingExport.h"

#include "BspNode.h"
#include "System/Helper/PragmaWarning.h"
#include "System/Helper/PragmaWarning/PolymorphicPointerCast.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/StreamDetail.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "Mathematics/Algebra/PlaneDetail.h"

CORE_TOOLS_RTTI_DEFINE(Rendering, BspNode);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, BspNode);
CORE_TOOLS_FACTORY_DEFINE(Rendering, BspNode);

Rendering::BspNode::BspNodeSharedPtr Rendering::BspNode::Create()
{
    return std::make_shared<ClassType>(NodeCreate::Init);
}

Rendering::BspNode::BspNode(NodeCreate nodeCreate)
    : ParentType{ nodeCreate },
      modelPlane{ 0.0f, 0.0f, 0.0f, 0.0f },
      worldPlane{ 0.0f, 0.0f, 0.0f, 0.0f }
{
    SpatialSharedPtr spatialSharedPtr{};
    AttachChild(spatialSharedPtr);
    AttachChild(spatialSharedPtr);
    AttachChild(spatialSharedPtr);

    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, BspNode)

Rendering::BspNode::BspNode(const Mathematics::PlaneF& modelPlane)
    : ParentType{ NodeCreate::Init },
      modelPlane{ modelPlane },
      worldPlane{ modelPlane }
{
    SpatialSharedPtr spatialSharedPtr{};
    AttachChild(spatialSharedPtr);
    AttachChild(spatialSharedPtr);
    AttachChild(spatialSharedPtr);

    RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::SpatialSharedPtr Rendering::BspNode::GetContainingNode(const Mathematics::APointF& point)
{
    RENDERING_CLASS_IS_VALID_1;

    auto posChild = GetPositiveChild();
    auto negChild = GetNegativeChild();

    if (posChild || negChild)
    {
        if (worldPlane.WhichSide(point) < Mathematics::NumericalValueSymbol::Zero)
        {
            auto bspChild = boost::polymorphic_pointer_cast<BspNode>(negChild);
            if (bspChild)
            {
                return bspChild->GetContainingNode(point);
            }
            else
            {
                return negChild;
            }
        }
        else
        {
            auto bspChild = boost::polymorphic_pointer_cast<BspNode>(negChild);
            if (bspChild)
            {
                return bspChild->GetContainingNode(point);
            }
            else
            {
                return posChild;
            }
        }
    }

    return boost::polymorphic_pointer_cast<Spatial>(shared_from_this());
}

CoreTools::ObjectInterfaceSharedPtr Rendering::BspNode::CloneObject() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return std::make_shared<ClassType>(*this);
}

bool Rendering::BspNode::UpdateWorldData(double applicationTime)
{
    RENDERING_CLASS_IS_VALID_1;

    const auto result = Node::UpdateWorldData(applicationTime);

    worldPlane = modelPlane.GetHomogeneousPoint() * GetWorldTransform().GetInverseMatrix();

    return result;
}

void Rendering::BspNode::GetVisibleSet(Culler& culler, bool noCull)
{
    RENDERING_CLASS_IS_VALID_1;

    auto posChild = GetPositiveChild();
    auto copChild = GetCoplanarChild();
    auto negChild = GetNegativeChild();

    const auto camera = culler.GetCamera();
    const auto positionSide = worldPlane.WhichSide(camera->GetPosition());
    const auto frustumSide = culler.WhichSide(worldPlane);

    if (positionSide > Mathematics::NumericalValueSymbol::Zero)
    {
        if (frustumSide <= Mathematics::NumericalValueSymbol::Zero)
        {
            if (negChild)
            {
                negChild->OnGetVisibleSet(culler, noCull);
            }
        }

        if (frustumSide == Mathematics::NumericalValueSymbol::Zero)
        {
            if (copChild)
            {
                copChild->OnGetVisibleSet(culler, noCull);
            }
        }

        if (frustumSide >= Mathematics::NumericalValueSymbol::Zero)
        {
            if (posChild)
            {
                posChild->OnGetVisibleSet(culler, noCull);
            }
        }
    }
    else if (positionSide < Mathematics::NumericalValueSymbol::Zero)
    {
        if (frustumSide >= Mathematics::NumericalValueSymbol::Zero)
        {
            if (posChild)
            {
                posChild->OnGetVisibleSet(culler, noCull);
            }
        }

        if (frustumSide == Mathematics::NumericalValueSymbol::Zero)
        {
            if (copChild)
            {
                copChild->OnGetVisibleSet(culler, noCull);
            }
        }

        if (frustumSide <= Mathematics::NumericalValueSymbol::Zero)
        {
            if (negChild)
            {
                negChild->OnGetVisibleSet(culler, noCull);
            }
        }
    }
    else
    {
        const auto ndd = Dot(worldPlane.GetNormal(), camera->GetDirectionVector());
        if (ndd >= 0.0f)
        {
            if (posChild)
            {
                posChild->OnGetVisibleSet(culler, noCull);
            }

            if (copChild)
            {
                copChild->OnGetVisibleSet(culler, noCull);
            }

            if (negChild)
            {
                negChild->OnGetVisibleSet(culler, noCull);
            }
        }
        else
        {
            if (negChild)
            {
                negChild->OnGetVisibleSet(culler, noCull);
            }

            if (copChild)
            {
                copChild->OnGetVisibleSet(culler, noCull);
            }

            if (posChild)
            {
                posChild->OnGetVisibleSet(culler, noCull);
            }
        }
    }
}

Rendering::BspNode::BspNode(LoadConstructor value)
    : ParentType{ value }, modelPlane{ 0.0f, 0.0f, 0.0f, 0.0f }, worldPlane{ 0.0f, 0.0f, 0.0f, 0.0f }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

void Rendering::BspNode::Load(CoreTools::BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_1;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source);

    ParentType::Load(source);

    source.ReadAggregate(modelPlane);
    source.ReadAggregate(worldPlane);

    CORE_TOOLS_END_DEBUG_STREAM_LOAD(source);
}

void Rendering::BspNode::Link(CoreTools::ObjectLink& source)
{
    RENDERING_CLASS_IS_VALID_1;

    ParentType::Link(source);
}

void Rendering::BspNode::PostLink()
{
    RENDERING_CLASS_IS_VALID_1;

    ParentType::PostLink();
}

int64_t Rendering::BspNode::Register(CoreTools::ObjectRegister& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return ParentType::Register(target);
}

void Rendering::BspNode::Save(CoreTools::BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target);

    ParentType::Save(target);

    target.WriteAggregate(modelPlane);
    target.WriteAggregate(worldPlane);

    CORE_TOOLS_END_DEBUG_STREAM_SAVE(target);
}

int Rendering::BspNode::GetStreamingSize() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    auto size = ParentType::GetStreamingSize();
    size += CoreTools::GetStreamSize(modelPlane);
    size += CoreTools::GetStreamSize(worldPlane);
    return size;
}

Rendering::SpatialSharedPtr Rendering::BspNode::AttachPositiveChild(const SpatialSharedPtr& child)
{
    RENDERING_CLASS_IS_VALID_1;

    AttachChild(child);

    return child;
}

Rendering::SpatialSharedPtr Rendering::BspNode::AttachCoplanarChild(const SpatialSharedPtr& child)
{
    RENDERING_CLASS_IS_VALID_1;

    AttachChild(child);

    return child;
}

Rendering::SpatialSharedPtr Rendering::BspNode::AttachNegativeChild(const SpatialSharedPtr& child)
{
    RENDERING_CLASS_IS_VALID_1;

    AttachChild(child);

    return child;
}

Rendering::SpatialSharedPtr Rendering::BspNode::DetachPositiveChild()
{
    RENDERING_CLASS_IS_VALID_1;

    return DetachChildAt(0);
}

Rendering::SpatialSharedPtr Rendering::BspNode::DetachCoplanarChild()
{
    RENDERING_CLASS_IS_VALID_1;

    return DetachChildAt(1);
}

Rendering::SpatialSharedPtr Rendering::BspNode::DetachNegativeChild()
{
    RENDERING_CLASS_IS_VALID_1;

    return DetachChildAt(2);
}

Rendering::SpatialSharedPtr Rendering::BspNode::GetPositiveChild()
{
    RENDERING_CLASS_IS_VALID_1;

    return GetChild(0);
}

Rendering::SpatialSharedPtr Rendering::BspNode::GetCoplanarChild()
{
    RENDERING_CLASS_IS_VALID_1;

    return GetChild(1);
}

Rendering::SpatialSharedPtr Rendering::BspNode::GetNegativeChild()
{
    RENDERING_CLASS_IS_VALID_1;

    return GetChild(2);
}

const Mathematics::PlaneF& Rendering::BspNode::GetWorldPlane() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return worldPlane;
}
