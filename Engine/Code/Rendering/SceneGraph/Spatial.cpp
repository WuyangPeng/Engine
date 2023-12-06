///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 11:18)

#include "Rendering/RenderingExport.h"

#include "Culler.h"
#include "Spatial.h"
#include "Detail/SpatialData.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/StreamSize.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(Rendering, Spatial)

CORE_TOOLS_RTTI_DEFINE(Rendering, Spatial);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, Spatial);
CORE_TOOLS_ABSTRACT_FACTORY_DEFINE(Rendering, Spatial);

Rendering::Spatial::Spatial(MAYBE_UNUSED CoreTools::DisableNotThrow disableNotThrow)
    : ParentType{ "Spatial" }, parent{ nullptr }, impl{ CoreTools::ImplCreateUseDefaultConstruction::Default }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

bool Rendering::Spatial::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

void Rendering::Spatial::SetParent(Spatial* aParent) noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    parent = aParent;
}

bool Rendering::Spatial::Update(double applicationTime)
{
    RENDERING_CLASS_IS_VALID_1;

    return Update(applicationTime, true);
}

bool Rendering::Spatial::Update(double applicationTime, bool initiator)
{
    RENDERING_CLASS_IS_VALID_1;

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
    RENDERING_CLASS_IS_VALID_1;

    // 更新世界变换。
    if (!impl->GetWorldTransformIsCurrent())
    {
        if (parent != nullptr)
        {
            impl->SetLocalTransformToWorldTransform(parent->GetWorldTransform());
        }
        else
        {
            impl->SetLocalTransformToWorldTransform();
        }
    }

    // 更新与该对象相关的任何控制器。
    return ParentType::Update(applicationTime);
}

void Rendering::Spatial::PropagateBoundToRoot()
{
    RENDERING_CLASS_IS_VALID_1;

    if (parent)
    {
        parent->UpdateWorldBound();
        parent->PropagateBoundToRoot();
    }
}

Rendering::Spatial* Rendering::Spatial::GetParent() noexcept
{
    RENDERING_CLASS_IS_VALID_1;

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26473)
#include SYSTEM_WARNING_DISABLE(26492)

    return const_cast<Spatial*>(static_cast<const ClassType*>(this)->GetParent());

#include SYSTEM_WARNING_POP
}

const Rendering::Spatial* Rendering::Spatial::GetParent() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return parent;
}

void Rendering::Spatial::OnGetVisibleSet(Culler& culler, bool noCull)
{
    RENDERING_CLASS_IS_VALID_1;

    const auto cullingMode = impl->GetCullingMode();

    if (cullingMode == CullingMode::Always)
    {
        return;
    }

    if (cullingMode == CullingMode::Never)
    {
        noCull = true;
    }

    const auto savePlaneState = culler.GetPlaneState();
    if (noCull || culler.IsVisible(impl->GetWorldBound()))
    {
        GetVisibleSet(culler, noCull);
    }
    culler.SetPlaneState(savePlaneState);
}

void Rendering::Spatial::SetLocalTransform(const Mathematics::TransformF& transform) noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->SetLocalTransform(transform);
}

void Rendering::Spatial::SetWorldTransform(const Mathematics::TransformF& transform) noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->DirectSetWorldTransform(transform);
}

void Rendering::Spatial::SetWorldBound(const Mathematics::BoundingSphereF& bound) noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->DirectSetWorldBound(bound);
}

void Rendering::Spatial::SetCullingMode(CullingMode culling) noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->SetCullingMode(culling);
}

void Rendering::Spatial::InitWorldBound()
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->InitWorldBound();
}

void Rendering::Spatial::BoundGrowToContain(const Mathematics::BoundingSphereF& worldBound)
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->SetWorldBound(worldBound);
}

Mathematics::TransformF Rendering::Spatial::GetLocalTransform() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetLocalTransform();
}

Mathematics::TransformF Rendering::Spatial::GetWorldTransform() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetWorldTransform();
}

Mathematics::BoundingSphereF Rendering::Spatial::GetWorldBound() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetWorldBound();
}

Rendering::CullingMode Rendering::Spatial::GetCullingMode() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetCullingMode();
}

bool Rendering::Spatial::GetWorldBoundIsCurrent() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetWorldBoundIsCurrent();
}

// 流支持
Rendering::Spatial::Spatial(LoadConstructor value)
    : ParentType{ value }, parent{ nullptr }, impl{ CoreTools::ImplCreateUseDefaultConstruction::Default }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

int Rendering::Spatial::GetStreamingSize() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    auto size = ParentType::GetStreamingSize();

    size += impl->GetStreamingSize();

    // parent 不保存

    return size;
}

int64_t Rendering::Spatial::Register(CoreTools::ObjectRegister& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    // m_Parent不需要注册，由于parent本身必须发起注册调用其孩子,“this”就是其中之一。
    return ParentType::Register(target);
}

void Rendering::Spatial::Save(CoreTools::BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target);

    ParentType::Save(target);

    impl->Save(target);

    // m_Parent没有保存。它将被设置在 Node::Link，
    // 当子节点的指针链接解析Node::SetChild。

    CORE_TOOLS_END_DEBUG_STREAM_SAVE(target);
}

void Rendering::Spatial::Link(CoreTools::ObjectLink& source)
{
    RENDERING_CLASS_IS_VALID_1;

    ParentType::Link(source);

    // m_Parent没有保存。它将被设置在 Node::Link，
    // 当子节点的指针链接解析Node::SetChild。
}

void Rendering::Spatial::PostLink()
{
    RENDERING_CLASS_IS_VALID_1;

    ParentType::PostLink();

    // parent = dynamic_cast<Spatial*>(GetController());
}

void Rendering::Spatial::Load(CoreTools::BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_1;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source);

    ParentType::Load(source);

    impl->Load(source);

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
    RENDERING_CLASS_IS_VALID_1;

    return impl->SetLocalTransformTranslate(translate);
}

void Rendering::Spatial::SetLocalTransformRotate(const Matrix& rotate) noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->SetLocalTransformRotate(rotate);
}

void Rendering::Spatial::SetWorldTransformOnUpdate(const Mathematics::TransformF& transform) noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    impl->SetWorldTransformOnUpdate(transform);
}
