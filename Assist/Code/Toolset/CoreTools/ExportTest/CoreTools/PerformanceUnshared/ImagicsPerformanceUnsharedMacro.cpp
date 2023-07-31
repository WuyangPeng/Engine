///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.2 (2023/07/31 10:23)

#include "Imagics/ImagicsExport.h"

#include "ImagicsPerformanceUnsharedMacro.h"
#include "CoreTools/Helper/ClassInvariant/ImagicsClassInvariantMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/Detail/PerformanceUnshared/ImagicsPerformanceUnsharedMacroImpl.h"

Imagics::ImagicsPerformanceUnsharedMacro::ImagicsPerformanceUnsharedMacro(int count)
    : impl{ count }
{
    IMAGICS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Imagics, ImagicsPerformanceUnsharedMacro)

int Imagics::ImagicsPerformanceUnsharedMacro::GetCount() const noexcept
{
    IMAGICS_CLASS_IS_VALID_CONST_9;

    return impl->GetCount();
}

const void* Imagics::ImagicsPerformanceUnsharedMacro::GetAddress() const noexcept
{
    IMAGICS_CLASS_IS_VALID_CONST_9;

    return &(*impl);
}