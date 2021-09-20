// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
//
// ÒýÇæ°æ±¾£º0.0.0.3 (2019/07/22 17:26)

#include "Rendering/RenderingExport.h"

#include "Culler.h"
#include "Detail/CullerImpl.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

using std::make_shared;
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26440)
Rendering::Culler ::Culler(const ConstCameraSharedPtr& camera)
    : impl{ camera }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, Culler)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, Culler, SetCamera, ConstCameraSharedPtr, void)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, Culler, GetCamera, Rendering::ConstCameraSharedPtr)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, Culler, SetFrustum, const float*, void)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, Culler, GetFrustum, const float*)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, Culler, Insert, VisualSharedPtr, void)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, Culler, GetPlaneQuantity, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, Culler, GetPlanes, const Rendering::Culler::Plane*)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, Culler, SetPlaneState, unsigned int, void)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, Culler, GetPlaneState, unsigned int)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, Culler, PushPlane, Plane, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, Culler, PopPlane, void)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, Culler, IsVisible, FloatBound, bool)

bool Rendering::Culler ::IsVisible(int numVertices, const APoint* vertices, bool ignoreNearPlane) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->IsVisible(numVertices, vertices, ignoreNearPlane);
}

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, Culler, WhichSide, Plane, Rendering::Culler::NumericalValueSymbol)

void Rendering::Culler ::ComputeVisibleSet(SpatialSharedPtr scene)
{
    RENDERING_CLASS_IS_VALID_1;
    RENDERING_ASSERTION_0(scene != SpatialSharedPtr(), "²Ã¼ôÐèÒªÒ»¸ö³¡¾°\n");

    SetFrustum(impl->GetCamera()->GetFrustum());
    impl->Clear();
    scene->OnGetVisibleSet(*this, false);
}

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, Culler, GetNumVisible, int)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, Culler, GetVisible, int, const Rendering::ConstVisualSharedPtr)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, Culler, begin, Rendering::Culler::VisualContainerIter)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, Culler, end, Rendering::Culler::VisualContainerIter)
#include STSTEM_WARNING_POP