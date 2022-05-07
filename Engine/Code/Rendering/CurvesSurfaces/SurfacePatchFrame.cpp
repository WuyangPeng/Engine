///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/18 15:32)

#include "Rendering/RenderingExport.h"

#include "SurfacePatchFrame.h"
#include "Detail/SurfacePatchFrameImpl.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

Rendering::SurfacePatchFrame::SurfacePatchFrame(const APoint& position, const AVector& tangent0, const AVector& tangent1, const AVector& normal)
    : impl{ position, tangent0, tangent1, normal }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, SurfacePatchFrame)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, SurfacePatchFrame, GetPosition, Rendering::SurfacePatchFrame::APoint)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, SurfacePatchFrame, GetTangent0, Rendering::SurfacePatchFrame::AVector)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, SurfacePatchFrame, GetTangent1, Rendering::SurfacePatchFrame::AVector)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, SurfacePatchFrame, GetNormal, Rendering::SurfacePatchFrame::AVector)