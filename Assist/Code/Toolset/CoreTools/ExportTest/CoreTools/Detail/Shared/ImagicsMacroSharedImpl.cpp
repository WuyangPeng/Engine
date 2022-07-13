///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.8.0.10 (2022/06/30 19:02)

#include "Imagics/ImagicsExport.h"

#include "ImagicsMacroSharedImpl.h"
#include "CoreTools/Helper/ClassInvariant/ImagicsClassInvariantMacro.h"

Imagics::ImagicsMacroSharedImpl::ImagicsMacroSharedImpl(int count) noexcept
    : mCount{ count }
{
    IMAGICS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Imagics, ImagicsMacroSharedImpl)

int Imagics::ImagicsMacroSharedImpl::GetCount() const noexcept
{
    IMAGICS_CLASS_IS_VALID_CONST_9;

    return mCount;
}

void Imagics::ImagicsMacroSharedImpl::SetCount(int count) noexcept
{
    IMAGICS_CLASS_IS_VALID_9;

    mCount = count;
}
