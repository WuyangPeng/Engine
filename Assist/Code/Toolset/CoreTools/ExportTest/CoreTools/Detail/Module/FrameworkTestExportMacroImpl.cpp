/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/06 10:10)

#include "Framework/FrameworkExport.h"

#include "FrameworkTestExportMacroImpl.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

Framework::FrameworkTestExportMacroImpl::FrameworkTestExportMacroImpl(int count) noexcept
    : count{ count }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Framework, FrameworkTestExportMacroImpl)

int Framework::FrameworkTestExportMacroImpl::GetCount() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return count;
}

void Framework::FrameworkTestExportMacroImpl::SetCount(int aCount) noexcept
{
    FRAMEWORK_CLASS_IS_VALID_9;

    count = aCount;
}