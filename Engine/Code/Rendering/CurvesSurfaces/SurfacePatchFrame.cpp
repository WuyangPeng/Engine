///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/12 14:00)

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