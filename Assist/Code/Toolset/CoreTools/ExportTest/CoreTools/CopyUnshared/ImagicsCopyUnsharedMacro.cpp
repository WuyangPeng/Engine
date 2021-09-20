///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.1 (2021/08/12 15:21)

#include "Imagics/ImagicsExport.h"

#include "ImagicsCopyUnsharedMacro.h"
#include "CoreTools/Helper/ClassInvariant/ImagicsClassInvariantMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/Detail/CopyUnshared/ImagicsCopyUnsharedMacroImpl.h"

Imagics::ImagicsCopyUnsharedMacro::ImagicsCopyUnsharedMacro(int count)
    : impl{ count }
{
    IMAGICS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Imagics, ImagicsCopyUnsharedMacro)

int Imagics::ImagicsCopyUnsharedMacro::GetCount() const noexcept
{
    IMAGICS_CLASS_IS_VALID_CONST_9;

    return impl->GetCount();
}

void Imagics::ImagicsCopyUnsharedMacro::SetCount(int count) noexcept
{
    IMAGICS_CLASS_IS_VALID_9;

    impl->SetCount(count);
}

COPY_UNSHARED_CLONE_SELF_DEFINE(Imagics, ImagicsCopyUnsharedMacro)