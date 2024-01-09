/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/28 16:09)

#include "Rendering/RenderingExport.h"

#include "Culler.h"
#include "Detail/CullerImpl.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(Rendering, Culler)

Rendering::Culler::Culler(const ConstCameraSharedPtr& camera)
    : impl{ camera }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, Culler)

void Rendering::Culler::SetCamera(const ConstCameraSharedPtr& camera)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetCamera(camera);
}

Rendering::ConstCameraSharedPtr Rendering::Culler::GetCamera() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetCamera();
}

void Rendering::Culler::SetFrustum(const Container& frustum)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetFrustum(frustum);
}

Rendering::Culler::Container Rendering::Culler::GetFrustum() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetFrustum();
}

void Rendering::Culler::Insert(const VisualSharedPtr& visible)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->Insert(visible);
}

int Rendering::Culler::GetNumVisible() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetNumVisible();
}

Rendering::ConstVisualSharedPtr Rendering::Culler::GetVisible(int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetVisible(index);
}

int Rendering::Culler::GetPlaneQuantity() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetPlaneQuantity();
}

void Rendering::Culler::SetPlaneState(uint32_t planeState)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetPlaneState(planeState);
}

uint32_t Rendering::Culler::GetPlaneState() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetPlaneState();
}

void Rendering::Culler::PushPlane(const Plane& plane)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->PushPlane(plane);
}

void Rendering::Culler::PopPlane()
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->PopPlane();
}

bool Rendering::Culler::IsVisible(const BoundingSphere& bound)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->IsVisible(bound);
}

Rendering::Culler::NumericalValueSymbol Rendering::Culler::WhichSide(const Plane& plane) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->WhichSide(plane);
}

Rendering::Culler::Plane Rendering::Culler::GetPlane(int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetPlane(index);
}

Rendering::Culler::VisualContainerIter Rendering::Culler::begin()
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->begin();
}

Rendering::Culler::VisualContainerIter Rendering::Culler::end()
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->end();
}

void Rendering::Culler::ComputeVisibleSet(const CameraSharedPtr& camera, const SpatialSharedPtr& scene)
{
    RENDERING_CLASS_IS_VALID_9;
    RENDERING_ASSERTION_0(scene != nullptr, "裁剪需要一个场景\n");

    impl->PushViewFrustumPlanes(*camera);
    impl->Clear();
    scene->OnGetVisibleSet(*this, camera, false);
}
