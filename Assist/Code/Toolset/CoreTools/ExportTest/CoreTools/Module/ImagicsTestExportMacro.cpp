///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.1.3 (2022/10/18 22:57)

#include "Imagics/ImagicsExport.h"

#include "ImagicsTestExportMacro.h"
#include "CoreTools/Helper/ClassInvariant/ImagicsClassInvariantMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/Detail/Module/ImagicsTestExportMacroImpl.h"

Imagics::ImagicsTestExportMacro::ImagicsTestExportMacro(int count)
    : impl{ count }
{
    IMAGICS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Imagics, ImagicsTestExportMacro)

int Imagics::ImagicsTestExportMacro::GetCount() const noexcept
{
    IMAGICS_CLASS_IS_VALID_CONST_9;

    return impl->GetCount();
}

void Imagics::ImagicsTestExportMacro::SetCount(int count) noexcept
{
    IMAGICS_CLASS_IS_VALID_9;

    impl->SetCount(count);
}