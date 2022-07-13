///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.0.10 (2022/07/01 14:10)

#include "Toolset/CoreTools/ExportTest/ExportTestExport.h"

#include "ExportSharedImplMacroSharedImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

ExportTest::ExportSharedImplMacroSharedImpl::ExportSharedImplMacroSharedImpl(int count) noexcept
    : mCount{ count }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(ExportTest, ExportSharedImplMacroSharedImpl)

int ExportTest::ExportSharedImplMacroSharedImpl::GetCount() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return mCount;
}

void ExportTest::ExportSharedImplMacroSharedImpl::SetCount(int count) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    mCount = count;
}
