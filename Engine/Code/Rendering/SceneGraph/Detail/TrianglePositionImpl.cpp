///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.5 (2022/04/01 19:04)

#include "Rendering/RenderingExport.h"

#include "TrianglePositionImpl.h"

#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "Mathematics/Algebra/APointDetail.h"

Rendering::TrianglePositionImpl::TrianglePositionImpl(const APoint& firstPosition, const APoint& secondPosition, const APoint& thirdPosition) noexcept
    : firstPosition{ firstPosition }, secondPosition{ secondPosition }, thirdPosition{ thirdPosition }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, TrianglePositionImpl)

Rendering::TrianglePositionImpl::APoint Rendering::TrianglePositionImpl::GetFirstPosition() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return firstPosition;
}

Rendering::TrianglePositionImpl::APoint Rendering::TrianglePositionImpl::GetSecondPosition() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return secondPosition;
}

Rendering::TrianglePositionImpl::APoint Rendering::TrianglePositionImpl::GetThirdPosition() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return thirdPosition;
}
