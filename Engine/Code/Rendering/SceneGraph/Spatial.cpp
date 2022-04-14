// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 引擎版本：0.0.0.3 (2019/07/22 18:22)

#include "Rendering/RenderingExport.h"

#include "Culler.h"
#include "Spatial.h"
#include "Detail/SpatialData.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"

using std::make_shared;
using std::string;
using std::vector;
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
#include SYSTEM_WARNING_DISABLE(26492)
#include SYSTEM_WARNING_DISABLE(26455)
#include SYSTEM_WARNING_DISABLE(26473)
#include SYSTEM_WARNING_DISABLE(26456)
CORE_TOOLS_RTTI_DEFINE(Rendering, Spatial);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, Spatial);
CORE_TOOLS_ABSTRACT_FACTORY_DEFINE(Rendering, Spatial);

Rendering::Spatial::Spatial()
    : ParentType{}, m_Parent{ nullptr }, m_SpatialDataPtr{ make_shared<SpatialData>() }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::Spatial::~Spatial()
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::Spatial::Spatial(const Spatial& rhs)
    : ParentType(rhs), m_Parent{ rhs.m_Parent }, m_SpatialDataPtr{ make_shared<SpatialData>(*rhs.m_SpatialDataPtr) }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::Spatial& Rendering::Spatial::operator=(const Spatial& rhs)
{
    ;

    ParentType::operator=(rhs);

    m_Parent = rhs.m_Parent;

    m_SpatialDataPtr = make_shared<SpatialData>(*rhs.m_SpatialDataPtr);

    return *this;
}

#ifdef OPEN_CLASS_INVARIANT
bool Rendering::Spatial::IsValid() const noexcept
{
    if (ParentType::IsValid() && m_SpatialDataPtr != nullptr)
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

void Rendering::Spatial::SetParent(Spatial* parent) noexcept
{
    ;

    m_Parent = parent;
}

bool Rendering::Spatial::Update(double applicationTime)
{
    ;

    return Update(applicationTime, true);
}

bool Rendering::Spatial::Update(double applicationTime, bool initiator)
{
    ;

    const auto result = UpdateWorldData(applicationTime);
    UpdateWorldBound();
    if (initiator)
    {
        PropagateBoundToRoot();
    }

    return result;
}

bool Rendering::Spatial::UpdateWorldData(double applicationTime)
{
    ;

    // 更新世界变换。
    if (!m_SpatialDataPtr->GetWorldTransformIsCurrent())
    {
        if (m_Parent != nullptr)
        {
            m_SpatialDataPtr->SetLocalTransformToWorldTransform(m_Parent->GetWorldTransform());
        }
        else
        {
            m_SpatialDataPtr->SetLocalTransformToWorldTransform();
        }
    }

    // 更新与该对象相关的任何控制器。
    return ParentType::UpdateControllers(applicationTime);
}

void Rendering::Spatial::PropagateBoundToRoot()
{
    ;

    if (m_Parent)
    {
        m_Parent->UpdateWorldBound();
        m_Parent->PropagateBoundToRoot();
    }
}

Rendering::Spatial* Rendering::Spatial::GetParent() noexcept
{
    ;

    return const_cast<Spatial*>(static_cast<const ClassType*>(this)->GetParent());
}

const Rendering::Spatial* Rendering::Spatial::GetParent() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return m_Parent;
}

void Rendering::Spatial::OnGetVisibleSet(Culler& culler, bool noCull)
{
    ;

    const auto cullingMode = m_SpatialDataPtr->GetCullingMode();

    if (cullingMode == CullingMode::Always)
    {
        return;
    }

    if (cullingMode == CullingMode::Never)
    {
        noCull = true;
    }

    const auto savePlaneState = culler.GetPlaneState();
    if (noCull || culler.IsVisible(m_SpatialDataPtr->GetWorldBound()))
    {
        GetVisibleSet(culler, noCull);
    }
    culler.SetPlaneState(savePlaneState);
}

void Rendering::Spatial::SetLocalTransform(const TransformF& transform) noexcept
{
    ;

    return m_SpatialDataPtr->SetLocalTransform(transform);
}

void Rendering::Spatial::SetWorldTransform(const TransformF& transform) noexcept
{
    ;

    return m_SpatialDataPtr->DirectSetWorldTransform(transform);
}

void Rendering::Spatial::SetWorldBound(const BoundF& bound) noexcept
{
    ;

    return m_SpatialDataPtr->DirectSetWorldBound(bound);
}

void Rendering::Spatial::SetCullingMode(CullingMode culling) noexcept
{
    ;

    return m_SpatialDataPtr->SetCullingMode(culling);
}

void Rendering::Spatial::InitWorldBound()
{
    ;

    return m_SpatialDataPtr->InitWorldBound();
}

void Rendering::Spatial::BoundGrowToContain(const BoundF& worldBound)
{
    ;

    return m_SpatialDataPtr->SetWorldBound(worldBound);
}

const Rendering::TransformF Rendering::Spatial::GetLocalTransform() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return m_SpatialDataPtr->GetLocalTransform();
}

const Rendering::TransformF Rendering::Spatial::GetWorldTransform() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return m_SpatialDataPtr->GetWorldTransform();
}

const Rendering::BoundF Rendering::Spatial::GetWorldBound() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return m_SpatialDataPtr->GetWorldBound();
}

Rendering::CullingMode Rendering::Spatial::GetCullingMode() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return m_SpatialDataPtr->GetCullingMode();
}

bool Rendering::Spatial::GetWorldBoundIsCurrent() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return m_SpatialDataPtr->GetWorldBoundIsCurrent();
}

// 流支持
Rendering::Spatial::Spatial(LoadConstructor value)
    : ParentType{ value }, m_Parent{ nullptr }, m_SpatialDataPtr{ make_shared<SpatialData>() }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

int Rendering::Spatial::GetStreamingSize() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    auto size = ParentType::GetStreamingSize();

    size += m_SpatialDataPtr->GetStreamingSize();

    // m_Parent 不保存

    return size;
}

uint64_t Rendering::Spatial::Register(CoreTools::ObjectRegister& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    const auto uniqueID = ParentType::Register(target);

    // m_Parent不需要注册，由于parent本身必须发起注册调用其孩子,“this”就是其中之一。
    return uniqueID;
}

void Rendering::Spatial::Save(CoreTools::BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target);

    ParentType::Save(target);

    m_SpatialDataPtr->Save(target);

    // m_Parent没有保存。它将被设置在 Node::Link，
    // 当子节点的指针链接解析Node::SetChild。

    CORE_TOOLS_END_DEBUG_STREAM_SAVE(target);
}

void Rendering::Spatial::Link(CoreTools::ObjectLink& source)
{
    ;

    ParentType::Link(source);

    // m_Parent没有保存。它将被设置在 Node::Link，
    // 当子节点的指针链接解析Node::SetChild。
}

void Rendering::Spatial::PostLink()
{
    ;

    ParentType::PostLink();

    m_Parent = dynamic_cast<Spatial*>(GetControllerObject());
}

void Rendering::Spatial::Load(CoreTools::BufferSource& source)
{
    ;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source);

    ParentType::Load(source);

    m_SpatialDataPtr->Load(source);

    // m_Parent没有保存。它将被设置在 Node::Link，
    // 当子节点的指针链接解析Node::SetChild。

    CORE_TOOLS_END_DEBUG_STREAM_LOAD(source);
}

Rendering::PickRecordContainer Rendering::Spatial::ExecuteRecursive([[maybe_unused]] const APoint& origin, [[maybe_unused]] const AVector& direction, [[maybe_unused]] float tMin, [[maybe_unused]] float tMax) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return PickRecordContainer::Create();
}

void Rendering::Spatial::SetLocalTransformTranslate(const APoint& translate) noexcept
{
    ;

    return m_SpatialDataPtr->SetLocalTransformTranslate(translate);
}

void Rendering::Spatial::SetLocalTransformRotate(const Matrix& rotate) noexcept
{
    ;

    return m_SpatialDataPtr->SetLocalTransformRotate(rotate);
}

void Rendering::Spatial::SetWorldTransformOnUpdate(const TransformF& transform) noexcept
{
    ;

    m_SpatialDataPtr->SetWorldTransformOnUpdate(transform);
}

#include STSTEM_WARNING_POP