//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.0.2 (2020/09/11 10:58)

#include "CoreTools/CoreToolsExport.h"

#include "InitTermContainer.h"
#include "System/Helper/PragmaWarning.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::InitTermContainer::InitTermContainer() noexcept
    : m_NumFunction{ 0 }, m_ExecuteFunction{}
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
bool CoreTools::InitTermContainer::IsValid() const noexcept
{
    if (0 <= m_NumFunction && m_NumFunction <= sm_MaxElements)
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

void CoreTools::InitTermContainer::AddExecuteFunction(ExecuteFunction function)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    if (m_NumFunction < sm_MaxElements)
    {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26482)
        m_ExecuteFunction[m_NumFunction++] = function;
#include STSTEM_WARNING_POP
    }
    else
    {
        CORE_TOOLS_ASSERTION_0(false, "增加sm_MaxElements的值和重编译CoreTools库\n");
    }
}

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26440) // 无法保证function()调用不抛出异常，编译器误报。
void CoreTools::InitTermContainer::Execute()
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    int index = 0;
    for (auto function : m_ExecuteFunction)
    {
        if (index < m_NumFunction)
        {
            if (function != nullptr)
            {
                function();
            }
        }
        else
        {
            break;
        }

        ++index;
    }
}
#include STSTEM_WARNING_POP