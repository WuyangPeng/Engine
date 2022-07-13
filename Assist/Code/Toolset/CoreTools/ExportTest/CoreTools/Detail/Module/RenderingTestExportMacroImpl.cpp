///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.0.10 (2022/07/01 14:09)

#include "Rendering/RenderingExport.h"

#include "RenderingTestExportMacroImpl.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

Rendering::RenderingTestExportMacroImpl::RenderingTestExportMacroImpl(int count) noexcept
    : mCount{ count }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, RenderingTestExportMacroImpl)

int Rendering::RenderingTestExportMacroImpl::GetCount() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return mCount;
}

void Rendering::RenderingTestExportMacroImpl::SetCount(int count) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    mCount = count;
}