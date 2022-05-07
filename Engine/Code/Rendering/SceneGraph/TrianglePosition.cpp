///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.0.6 (2022/04/03 16:29)

#include "Rendering/RenderingExport.h"

#include "TrianglePosition.h"
#include "Detail/TrianglePositionImpl.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "Mathematics/Algebra/APointDetail.h"

using std::make_shared;

Rendering::TrianglePosition::TrianglePosition(const APoint& firstPosition, const APoint& secondPosition, const APoint& thirdPosition)
    : impl{ firstPosition, secondPosition, thirdPosition }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, TrianglePosition)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, TrianglePosition, GetFirstPosition, Rendering::TrianglePosition::APoint)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, TrianglePosition, GetSecondPosition, Rendering::TrianglePosition::APoint)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, TrianglePosition, GetThirdPosition, Rendering::TrianglePosition::APoint)