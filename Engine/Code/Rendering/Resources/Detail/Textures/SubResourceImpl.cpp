///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 11:28)

#include "Rendering/RenderingExport.h"

#include "SubResourceImpl.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

Rendering::SubResourceImpl::SubResourceImpl(int item, int level, const SpanIterator& data, int rowPitch, int slicePitch) noexcept
    : item{ item }, level{ level }, data{ data }, rowPitch{ rowPitch }, slicePitch{ slicePitch }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, SubResourceImpl)

int Rendering::SubResourceImpl::GetItem() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return item;
}

int Rendering::SubResourceImpl::GetLevel() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return level;
}

Rendering::SubResourceImpl::SpanIterator Rendering::SubResourceImpl::GetData() noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return data;
}

int Rendering::SubResourceImpl::GetRowPitch() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return rowPitch;
}

int Rendering::SubResourceImpl::GetSlicePitch() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return slicePitch;
}
