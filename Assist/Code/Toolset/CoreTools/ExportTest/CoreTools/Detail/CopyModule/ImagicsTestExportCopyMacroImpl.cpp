///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.1.3 (2022/10/18 22:14)

#include "Imagics/ImagicsExport.h"

#include "ImagicsTestExportCopyMacroImpl.h"
#include "CoreTools/Helper/ClassInvariant/ImagicsClassInvariantMacro.h"

Imagics::ImagicsTestExportCopyMacroImpl::ImagicsTestExportCopyMacroImpl(int count) noexcept
    : count{ count }
{
    IMAGICS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Imagics, ImagicsTestExportCopyMacroImpl)

int Imagics::ImagicsTestExportCopyMacroImpl::GetCount() const noexcept
{
    IMAGICS_CLASS_IS_VALID_CONST_9;

    return count;
}

void Imagics::ImagicsTestExportCopyMacroImpl::SetCount(int aCount) noexcept
{
    IMAGICS_CLASS_IS_VALID_9;

    count = aCount;
}
