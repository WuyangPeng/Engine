///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/28 15:37)

#include "Imagics/ImagicsExport.h"

#include "ImagicsTestExportCopyMacro.h"
#include "CoreTools/Helper/ClassInvariant/ImagicsClassInvariantMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/Detail/CopyModule/ImagicsTestExportCopyMacroImpl.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(Imagics, ImagicsTestExportCopyMacro)

Imagics::ImagicsTestExportCopyMacro::ImagicsTestExportCopyMacro(int count)
    : impl{ count }
{
    IMAGICS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Imagics, ImagicsTestExportCopyMacro)

int Imagics::ImagicsTestExportCopyMacro::GetCount() const noexcept
{
    IMAGICS_CLASS_IS_VALID_CONST_9;

    return impl->GetCount();
}

void Imagics::ImagicsTestExportCopyMacro::SetCount(int count) noexcept
{
    IMAGICS_CLASS_IS_VALID_9;

    impl->SetCount(count);
}
