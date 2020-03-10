// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/25 16:45)

#include "Rendering/RenderingExport.h"

#include "PrincipalCurvatureInfo.h"
#include "Detail/PrincipalCurvatureInfoImpl.h"
#include "CoreTools/Helper/MemberFunctionMacro.h" 
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

using std::make_shared;

Rendering::PrincipalCurvatureInfo
	::PrincipalCurvatureInfo(float principalCurvature0, float principalCurvature1,const AVector& principalDirection0,const  AVector& principalDirection1 )
	:m_Impl{ make_shared<ImplType>(principalCurvature0,principalCurvature1,principalDirection0,principalDirection1) }
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(Rendering, PrincipalCurvatureInfo)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, PrincipalCurvatureInfo,GetPrincipalCurvature0, float)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, PrincipalCurvatureInfo,GetPrincipalCurvature1,float)
 

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, PrincipalCurvatureInfo,GetPrincipalDirection0,const Rendering::PrincipalCurvatureInfo::AVector)
 
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, PrincipalCurvatureInfo,GetPrincipalDirection1,const Rendering::PrincipalCurvatureInfo::AVector)