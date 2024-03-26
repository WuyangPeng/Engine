/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/06 09:57)

#include "Framework/FrameworkExport.h"

#include "FrameworkTestExportCopyMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/Detail/CopyModule/FrameworkTestExportCopyMacroImpl.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(Framework, FrameworkTestExportCopyMacro)

Framework::FrameworkTestExportCopyMacro::FrameworkTestExportCopyMacro(int count)
    : impl{ count }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Framework, FrameworkTestExportCopyMacro)

int Framework::FrameworkTestExportCopyMacro::GetCount() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return impl->GetCount();
}

void Framework::FrameworkTestExportCopyMacro::SetCount(int count)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    impl->SetCount(count);
}
