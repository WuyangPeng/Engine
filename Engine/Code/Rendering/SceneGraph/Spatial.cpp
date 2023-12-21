/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.2 (2023/12/07 10:30)

#include "Rendering/RenderingExport.h"

#include "Culler.h"
#include "NullSpatial.h"
#include "Spatial.h"
#include "Flags/CullingModeFlags.h"
#include "Detail/SpatialFactory.h"
#include "Detail/SpatialImpl.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/StreamSize.h"

COPY_UNSHARED_CLONE_SELF_USE_CLONE_DEFINE(Rendering, Spatial)

CORE_TOOLS_RTTI_DEFINE(Rendering, Spatial);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, Spatial);
CORE_TOOLS_ABSTRACT_FACTORY_DEFINE(Rendering, Spatial);

Rendering::Spatial::Spatial(const std::string& name)
    : ParentType{ name }, impl{ CoreTools::ImplCreateUseFactory::Default, CullingMode::Dynamic, false }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::Spatial::Spatial(const std::string& name, bool isNull)
    : ParentType{ name }, impl{ CoreTools::ImplCreateUseFactory::Default, CullingMode::Dynamic, isNull }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, Spatial)

void Rendering::Spatial::SetParent(const SpatialSharedPtr& parent)
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->SetParent(parent);
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

    // 更新与该对象相关的任何控制器。
    const auto result = ParentType::Update(applicationTime);

    // 更新世界变换。
    if (!impl->GetWorldTransformIsCurrent())
    {
        if (const auto parent = GetParent();
            !parent->IsNullObject())
        {
            impl->SetLocalTransformToWorldTransform(parent->GetWorldTransform());
        }
        else
        {
            impl->SetLocalTransformToWorldTransform();
        }
    }

    return result;
}

void Rendering::Spatial::PropagateBoundToRoot()
{
    RENDERING_CLASS_IS_VALID_1;

    if (const auto parent = GetParent();
        !parent->IsNullObject())
    {
        parent->UpdateWorldBound();
        parent->PropagateBoundToRoot();
    }
}

Rendering::Spatial::SpatialSharedPtr Rendering::Spatial::GetParent()
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->GetParent();
}

Rendering::Spatial::ConstSpatialSharedPtr Rendering::Spatial::GetParent() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetParent();
}

void Rendering::Spatial::OnGetVisibleSet(Culler& culler, const CameraSharedPtr& camera, bool noCull)
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
        GetVisibleSet(culler, camera, noCull);
    }
    culler.SetPlaneState(savePlaneState);
}

void Rendering::Spatial::SetLocalTransform(const Transform& transform) noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->SetLocalTransform(transform);
}

void Rendering::Spatial::SetWorldTransform(const Transform& transform) noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->DirectSetWorldTransform(transform);
}

void Rendering::Spatial::SetWorldBound(const BoundingSphere& bound) noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->SetWorldBound(bound);
}

void Rendering::Spatial::SetCullingMode(CullingMode culling) noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->SetCullingMode(culling);
}

const Rendering::Spatial::SpatialSharedPtr& Rendering::Spatial::GetNullObject()
{
    static SpatialSharedPtr spatial{ std::make_shared<NullSpatial>("nullSpatial") };

    return spatial;
}

void Rendering::Spatial::InitWorldBound()
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->InitWorldBound();
}

void Rendering::Spatial::BoundGrowToContain(const BoundingSphere& worldBound)
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->GrowToContain(worldBound);
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

Rendering::Spatial::Spatial(LoadConstructor loadConstructor)
    : ParentType{ loadConstructor }, impl{ CoreTools::ImplCreateUseFactory::Default, CullingMode::Dynamic, false }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

int Rendering::Spatial::GetStreamingSize() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    auto size = ParentType::GetStreamingSize();

    size += impl->GetStreamingSize();

    return size;
}

int64_t Rendering::Spatial::Register(CoreTools::ObjectRegister& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return ParentType::Register(target);
}

void Rendering::Spatial::Save(CoreTools::BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target);

    ParentType::Save(target);

    impl->Save(target);

    CORE_TOOLS_END_DEBUG_STREAM_SAVE(target);
}

void Rendering::Spatial::Link(CoreTools::ObjectLink& source)
{
    RENDERING_CLASS_IS_VALID_1;

    ParentType::Link(source);
}

void Rendering::Spatial::PostLink()
{
    RENDERING_CLASS_IS_VALID_1;

    ParentType::PostLink();
}

void Rendering::Spatial::Load(CoreTools::BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_1;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source);

    ParentType::Load(source);

    impl->Load(source);

    CORE_TOOLS_END_DEBUG_STREAM_LOAD(source);
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

void Rendering::Spatial::SetWorldTransformOnUpdate(const Transform& transform) noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    impl->SetWorldTransformOnUpdate(transform);
}

Rendering::PickRecordContainer Rendering::Spatial::ExecuteRecursive(const APoint& origin, const AVector& direction, float tMin, float tMax) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    System::UnusedFunction(origin, direction, tMin, tMax);

    return PickRecordContainer::Create();
}