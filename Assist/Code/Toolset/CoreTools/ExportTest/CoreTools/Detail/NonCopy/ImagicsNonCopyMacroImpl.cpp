///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.9.0.4 (2023/03/17 09:05)

#include "Imagics/ImagicsExport.h"

#include "ImagicsNonCopyMacroImpl.h"
#include "CoreTools/Helper/ClassInvariant/ImagicsClassInvariantMacro.h"

Imagics::ImagicsNonCopyMacroImpl::ImagicsNonCopyMacroImpl(int count) noexcept
    : count{ count }
{
    IMAGICS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Imagics, ImagicsNonCopyMacroImpl)

int Imagics::ImagicsNonCopyMacroImpl::GetCount() const noexcept
{
    IMAGICS_CLASS_IS_VALID_CONST_9;

    return count;
}

void Imagics::ImagicsNonCopyMacroImpl::SetCount(int aCount) noexcept
{
    IMAGICS_CLASS_IS_VALID_9;

    count = aCount;
}
