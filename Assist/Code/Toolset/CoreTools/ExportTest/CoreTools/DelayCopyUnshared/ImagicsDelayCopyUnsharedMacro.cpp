///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.0.10 (2022/07/02 13:41)

#include "Imagics/ImagicsExport.h"

#include "ImagicsDelayCopyUnsharedMacro.h"
#include "CoreTools/Helper/ClassInvariant/ImagicsClassInvariantMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/Detail/DelayCopyUnshared/ImagicsDelayCopyUnsharedMacroImpl.h"

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

COPY_UNSHARED_CLONE_SELF_DEFINE(Imagics, ImagicsDelayCopyUnsharedMacro)