///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.9.0.4 (2023/03/16 20:20)

#include "Imagics/ImagicsExport.h"

#include "ImagicsTestExportMacroImpl.h"
#include "CoreTools/Helper/ClassInvariant/ImagicsClassInvariantMacro.h"

Imagics::ImagicsTestExportMacroImpl::ImagicsTestExportMacroImpl(int count) noexcept
    : count{ count }
{
    IMAGICS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Imagics, ImagicsTestExportMacroImpl)

int Imagics::ImagicsTestExportMacroImpl::GetCount() const noexcept
{
    IMAGICS_CLASS_IS_VALID_CONST_9;

    return count;
}

void Imagics::ImagicsTestExportMacroImpl::SetCount(int aCount) noexcept
{
    IMAGICS_CLASS_IS_VALID_9;

    count = aCount;
}
