///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.1 (2021/08/12 22:20)

#include "Rendering/RenderingExport.h"

#include "RenderingTestExportCopyMacroImpl.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

Rendering::RenderingTestExportCopyMacroImpl::RenderingTestExportCopyMacroImpl(int count) noexcept
    : m_Count{ count }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, RenderingTestExportCopyMacroImpl)

int Rendering::RenderingTestExportCopyMacroImpl::GetCount() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return m_Count;
}

void Rendering::RenderingTestExportCopyMacroImpl::SetCount(int count) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    m_Count = count;
}