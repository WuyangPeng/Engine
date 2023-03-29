///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.9.0.4 (2023/03/17 09:09)

#include "Rendering/RenderingExport.h"

#include "RenderingTestExportCopyMacroImpl.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

Rendering::RenderingTestExportCopyMacroImpl::RenderingTestExportCopyMacroImpl(int count) noexcept
    : count{ count }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, RenderingTestExportCopyMacroImpl)

int Rendering::RenderingTestExportCopyMacroImpl::GetCount() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return count;
}

void Rendering::RenderingTestExportCopyMacroImpl::SetCount(int aCount) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    count = aCount;
}