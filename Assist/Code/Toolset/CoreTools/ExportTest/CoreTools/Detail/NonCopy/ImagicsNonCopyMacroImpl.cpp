/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/06 10:12)

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
