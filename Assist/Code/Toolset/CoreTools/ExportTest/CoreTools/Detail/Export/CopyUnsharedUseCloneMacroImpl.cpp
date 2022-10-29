///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.1.3 (2022/10/18 22:23)

#include "Toolset/CoreTools/ExportTest/ExportTestExport.h"

#include "CopyUnsharedUseCloneMacroImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

using std::make_shared;

ExportTest::CopyUnsharedUseCloneMacroImpl::CopyUnsharedUseCloneMacroImpl(int count) noexcept
    : count{ count }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(ExportTest, CopyUnsharedUseCloneMacroImpl)

int ExportTest::CopyUnsharedUseCloneMacroImpl::GetCount() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return count;
}

void ExportTest::CopyUnsharedUseCloneMacroImpl::SetCount(int aCount) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    count = aCount;
}

ExportTest::CopyUnsharedUseCloneMacroImpl::SharedPtr ExportTest::CopyUnsharedUseCloneMacroImpl::Clone() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return make_shared<ClassType>(*this);
}
