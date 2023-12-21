///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 11:16)

#include "Rendering/RenderingExport.h"

#include "Culler.h"
#include "Detail/CullerImpl.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

Rendering::Culler::Culler(const ConstCameraSharedPtr& camera)
    : impl{ camera }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, Culler)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR_NOEXCEPT(Rendering, Culler, SetCamera, ConstCameraSharedPtr, void)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, Culler, GetCamera, Rendering::ConstCameraSharedPtr)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, Culler, SetFrustum, Container, void)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, Culler, GetFrustum, Rendering::Culler::Container)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, Culler, Insert, VisualSharedPtr, void)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, Culler, GetPlaneQuantity, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, Culler, GetPlanes, const Rendering::Culler::Plane*)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V_NOEXCEPT(Rendering, Culler, SetPlaneState, unsigned int, void)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, Culler, GetPlaneState, int)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR_NOEXCEPT(Rendering, Culler, PushPlane, Plane, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, Culler, PopPlane, void)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR_NOEXCEPT(Rendering, Culler, IsVisible, Mathematics::BoundingSphereF, bool)

bool Rendering::Culler::IsVisible(int numVertices, const APoint* vertices, bool ignoreNearPlane) const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->IsVisible(numVertices, vertices, ignoreNearPlane);
}

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, Culler, WhichSide, Plane, Rendering::Culler::NumericalValueSymbol)

void Rendering::Culler::ComputeVisibleSet(SpatialSharedPtr scene)
{
    RENDERING_CLASS_IS_VALID_1;
    RENDERING_ASSERTION_0(scene != nullptr, "裁剪需要一个场景\n");

    SetFrustum(impl->GetCamera()->GetFrustum());
    impl->Clear();
    scene->OnGetVisibleSet(*this, Camera::Create(false, DepthType::ZeroToOne, 0.0f), false);
}

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, Culler, GetNumVisible, int)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, Culler, GetVisible, int, Rendering::ConstVisualSharedPtr)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, Culler, begin, Rendering::Culler::VisualContainerIter)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, Culler, end, Rendering::Culler::VisualContainerIter)

void Rendering::Culler::ComputeVisibleSet(MAYBE_UNUSED const CameraSharedPtr& scene, MAYBE_UNUSED const SpatialSharedPtr& shared) noexcept
{
}
