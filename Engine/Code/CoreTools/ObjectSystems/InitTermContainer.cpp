//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.7.1.1 (2020/10/22 15:08)

#include "CoreTools/CoreToolsExport.h"

#include "InitTermContainer.h"
#include "System/Helper/PragmaWarning.h"
#include "CoreTools/Contract/Noexcept.h"
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
        CORE_TOOLS_ASSERTION_0(false, "����sm_MaxElements��ֵ���ر���CoreTools��\n");
    }
}

void CoreTools::InitTermContainer::Execute()
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    // �޷���֤function()���ò��׳��쳣���������󱨡�
    CoreTools::DisableNoexcept();

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
