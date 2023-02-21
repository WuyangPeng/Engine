///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.9.0.2 (2023/02/07 19:32)

#include "Framework/FrameworkExport.h"

#include "FrameworkTestExportMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/Detail/Module/FrameworkTestExportMacroImpl.h"

Framework::FrameworkTestExportMacro::FrameworkTestExportMacro(int count)
    : impl{ count }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Framework, FrameworkTestExportMacro)

int Framework::FrameworkTestExportMacro::GetCount() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return impl->GetCount();
}

void Framework::FrameworkTestExportMacro::SetCount(int count) noexcept
{
    FRAMEWORK_CLASS_IS_VALID_9;

    impl->SetCount(count);
}