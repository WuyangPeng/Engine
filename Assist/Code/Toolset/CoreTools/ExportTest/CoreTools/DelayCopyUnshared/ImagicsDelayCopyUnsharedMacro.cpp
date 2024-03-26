/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/06 10:01)

#include "Imagics/ImagicsExport.h"

#include "ImagicsDelayCopyUnsharedMacro.h"
#include "CoreTools/Helper/ClassInvariant/ImagicsClassInvariantMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/Detail/DelayCopyUnshared/ImagicsDelayCopyUnsharedMacroImpl.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(Imagics, ImagicsDelayCopyUnsharedMacro)

Imagics::ImagicsDelayCopyUnsharedMacro::ImagicsDelayCopyUnsharedMacro(int count)
    : impl{ count }
{
    IMAGICS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Imagics, ImagicsDelayCopyUnsharedMacro)

int Imagics::ImagicsDelayCopyUnsharedMacro::GetCount() const noexcept
{
    IMAGICS_CLASS_IS_VALID_CONST_9;

    return impl->GetCount();
}

void Imagics::ImagicsDelayCopyUnsharedMacro::SetCount(int count)
{
    IMAGICS_CLASS_IS_VALID_9;

    impl->SetCount(count);
}

const void* Imagics::ImagicsDelayCopyUnsharedMacro::GetAddress() const noexcept
{
    IMAGICS_CLASS_IS_VALID_CONST_9;

    return &(*impl);
}