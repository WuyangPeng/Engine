///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/12 11:28)

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
