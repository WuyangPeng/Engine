///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/16 18:45)

#include "Rendering/RenderingExport.h"

#include "PrincipalCurvatureInfo.h"
#include "Detail/PrincipalCurvatureInfoImpl.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

using std::make_shared;

Rendering::PrincipalCurvatureInfo::PrincipalCurvatureInfo(float principalCurvature0, float principalCurvature1, const AVector& principalDirection0, const AVector& principalDirection1)
    : impl{ principalCurvature0, principalCurvature1, principalDirection0, principalDirection1 }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, PrincipalCurvatureInfo)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, PrincipalCurvatureInfo, GetPrincipalCurvature0, float)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, PrincipalCurvatureInfo, GetPrincipalCurvature1, float)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, PrincipalCurvatureInfo, GetPrincipalDirection0, Rendering::PrincipalCurvatureInfo::AVector)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, PrincipalCurvatureInfo, GetPrincipalDirection1, Rendering::PrincipalCurvatureInfo::AVector)