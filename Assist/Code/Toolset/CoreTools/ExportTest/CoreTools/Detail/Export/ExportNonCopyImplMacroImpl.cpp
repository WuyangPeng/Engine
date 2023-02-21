///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.9.0.2 (2023/02/07 19:14)

#include "Toolset/CoreTools/ExportTest/ExportTestExport.h"

#include "ExportNonCopyImplMacroImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

ExportTest::ExportNonCopyImplMacroImpl::ExportNonCopyImplMacroImpl() noexcept
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(ExportTest, ExportNonCopyImplMacroImpl)
