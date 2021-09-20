//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.7.1.1 (2020/10/20 10:18)

#include "CoreTools/CoreToolsExport.h"

#include "Memory.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::Memory::Memory(const FunctionDescribed& functionDescribe) noexcept
    : m_FunctionDescribed{  functionDescribe }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, Memory)

const CoreTools::FunctionDescribed& CoreTools::Memory::GetFunctionDescribed() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return m_FunctionDescribed;
}
