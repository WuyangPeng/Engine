///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.9.0.2 (2023/02/07 19:38)

#include "Imagics/ImagicsExport.h"

#include "ImagicsMacroShared.h"
#include "CoreTools/Helper/ClassInvariant/ImagicsClassInvariantMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/Detail/Shared/ImagicsMacroSharedImpl.h"

Imagics::ImagicsMacroShared::ImagicsMacroShared(int count)
    : impl{ count }
{
    IMAGICS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Imagics, ImagicsMacroShared)

int Imagics::ImagicsMacroShared::GetCount() const noexcept
{
    IMAGICS_CLASS_IS_VALID_CONST_9;

    return impl->GetCount();
}

void Imagics::ImagicsMacroShared::SetCount(int count) noexcept
{
    IMAGICS_CLASS_IS_VALID_9;

    impl->SetCount(count);
}

const void* Imagics::ImagicsMacroShared::GetAddress() const noexcept
{
    IMAGICS_CLASS_IS_VALID_CONST_9;

    return &(*impl);
}