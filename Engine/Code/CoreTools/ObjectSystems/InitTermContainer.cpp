///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/24 23:07)

#include "CoreTools/CoreToolsExport.h"

#include "InitTermContainer.h"
#include "System/Helper/PragmaWarning.h"
#include "CoreTools/Contract/Noexcept.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::InitTermContainer::InitTermContainer() noexcept
    : numFunction{ 0 }, executeFunction{}
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

bool CoreTools::InitTermContainer::IsValid() const noexcept
{
    if (0 <= numFunction && numFunction <= maxElements)
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

void CoreTools::InitTermContainer::AddExecuteFunction(ExecuteFunction function)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    if (numFunction < maxElements)
    {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26482)

        executeFunction[numFunction++] = function;

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

    auto index = 0;
    for (auto function : executeFunction)
    {
        if (index < numFunction)
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
