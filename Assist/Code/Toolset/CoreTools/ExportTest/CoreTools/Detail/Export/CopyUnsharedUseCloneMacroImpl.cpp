///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.1 (2021/08/13 20:45)

#include "Toolset/CoreTools/ExportTest/ExportTestExport.h"

#include "CopyUnsharedUseCloneMacroImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

using std::make_shared;

ExportTest::CopyUnsharedUseCloneMacroImpl::CopyUnsharedUseCloneMacroImpl(int count) noexcept
    : m_Count{ count }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(ExportTest, CopyUnsharedUseCloneMacroImpl)

int ExportTest::CopyUnsharedUseCloneMacroImpl::GetCount() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return m_Count;
}

void ExportTest::CopyUnsharedUseCloneMacroImpl::SetCount(int count) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    m_Count = count;
}

ExportTest::CopyUnsharedUseCloneMacroImpl::SharedPtr ExportTest::CopyUnsharedUseCloneMacroImpl::Clone() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return make_shared<ClassType>(*this);
}
