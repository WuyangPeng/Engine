///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.0.6 (2022/04/20 11:37)

#include "Rendering/RenderingExport.h"

#include "PickRayImpl.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "Mathematics/Algebra/APointDetail.h"
#include "Mathematics/Algebra/AVectorDetail.h"

Rendering::PickRayImpl::PickRayImpl(bool result, const Mathematics::APointF& origin, const Mathematics::AVectorF& direction) noexcept
    : result{ result }, origin{ origin }, direction{ direction }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::PickRayImpl::PickRayImpl() noexcept
    : result{ false }, origin{}, direction{}
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, PickRayImpl)

bool Rendering::PickRayImpl::IsResult() const noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return result;
}

Mathematics::APointF Rendering::PickRayImpl::GetOrigin() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return origin;
}

Mathematics::AVectorF Rendering::PickRayImpl::GetDirection() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return direction;
}
