///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.9.0.2 (2023/02/07 19:04)

#include "Imagics/ImagicsExport.h"

#include "ImagicsDelayCopyUnsharedMacroImpl.h"
#include "CoreTools/Helper/ClassInvariant/ImagicsClassInvariantMacro.h"

Imagics::ImagicsDelayCopyUnsharedMacroImpl::ImagicsDelayCopyUnsharedMacroImpl(int count) noexcept
    : count{ count }
{
    IMAGICS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Imagics, ImagicsDelayCopyUnsharedMacroImpl)

int Imagics::ImagicsDelayCopyUnsharedMacroImpl::GetCount() const noexcept
{
    IMAGICS_CLASS_IS_VALID_CONST_9;

    return count;
}

void Imagics::ImagicsDelayCopyUnsharedMacroImpl::SetCount(int aCount) noexcept
{
    IMAGICS_CLASS_IS_VALID_9;

    count = aCount;
}
