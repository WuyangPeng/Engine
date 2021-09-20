///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.1 (2021/08/13 20:56)

#include "Imagics/ImagicsExport.h"

#include "ImagicsTestExportMacroImpl.h"
#include "CoreTools/Helper/ClassInvariant/ImagicsClassInvariantMacro.h"

Imagics::ImagicsTestExportMacroImpl::ImagicsTestExportMacroImpl(int count) noexcept
    : m_Count{ count }
{
    IMAGICS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Imagics, ImagicsTestExportMacroImpl)

int Imagics::ImagicsTestExportMacroImpl::GetCount() const noexcept
{
    IMAGICS_CLASS_IS_VALID_CONST_9;

    return m_Count;
}

void Imagics::ImagicsTestExportMacroImpl::SetCount(int count) noexcept
{
    IMAGICS_CLASS_IS_VALID_9;

    m_Count = count;
}
