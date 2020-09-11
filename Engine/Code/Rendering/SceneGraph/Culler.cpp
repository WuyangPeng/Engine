// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/22 17:26)

#include "Rendering/RenderingExport.h"

#include "Culler.h"
#include "Detail/CullerImpl.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/MemoryTools/ThirdSubclassSmartPointerDetail.h"
#include "CoreTools/MemoryTools/ConstThirdSubclassSmartPointerDetail.h"

using std::make_shared;
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26440)
Rendering::Culler
    ::Culler(const ConstCameraSmartPointer& camera)
	: m_Impl{ make_shared<ImplType>(camera) }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(Rendering,Culler)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering,Culler,SetCamera,ConstCameraSmartPointer,void)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering,Culler,GetCamera,Rendering::ConstCameraSmartPointer)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering,Culler,SetFrustum,const float*,void)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering,Culler,GetFrustum,const float*) 

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering,Culler,Insert, VisualSmartPointer,void)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering,Culler,GetPlaneQuantity,int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering,Culler,GetPlanes,const Rendering::Culler::Plane*)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering,Culler,SetPlaneState,unsigned int,void)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering,Culler,GetPlaneState,unsigned int)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering,Culler,PushPlane,Plane,void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering,Culler,PopPlane,void)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering,Culler,IsVisible,FloatBound,bool)

bool Rendering::Culler
    ::IsVisible (int numVertices, const APoint* vertices,bool ignoreNearPlane) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;
    
    return m_Impl->IsVisible(numVertices,vertices,ignoreNearPlane);
}

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering,Culler,WhichSide,Plane,Rendering::Culler::NumericalValueSymbol)

void Rendering::Culler
    ::ComputeVisibleSet(SpatialSmartPointer scene)
{
	RENDERING_CLASS_IS_VALID_1;
	RENDERING_ASSERTION_0(scene != SpatialSmartPointer(), "裁剪需要一个场景\n");

	SetFrustum(m_Impl->GetCamera()->GetFrustum());
	m_Impl->Clear();
	scene->OnGetVisibleSet(*this, false);
}

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering,Culler,GetNumVisible,int)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering,Culler,GetVisible,int,const Rendering::ConstVisualSmartPointer)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, Culler, begin,Rendering::Culler::VisualContainerIter)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, Culler, end, Rendering::Culler::VisualContainerIter)
#include STSTEM_WARNING_POP