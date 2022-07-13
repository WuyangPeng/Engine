///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.0.10 (2022/06/30 19:00)

#include "Rendering/RenderingExport.h"

#include "RenderingMacroSharedImpl.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

Rendering::RenderingMacroSharedImpl::RenderingMacroSharedImpl(int count) noexcept
    : mCount{ count }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, RenderingMacroSharedImpl)

int Rendering::RenderingMacroSharedImpl::GetCount() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return mCount;
}

void Rendering::RenderingMacroSharedImpl::SetCount(int count) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    mCount = count;
}