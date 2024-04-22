/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/11 22:21)

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
    return 0 <= numFunction && numFunction <= maxElements;
}

#endif  // OPEN_CLASS_INVARIANT

void CoreTools::InitTermContainer::AddExecuteFunction(ExecuteFunction function)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    if (numFunction < maxElements)
    {
        executeFunction.at(numFunction++) = function;
    }
    else
    {
        CORE_TOOLS_ASSERTION_0(false, "增加sm_MaxElements的值和重编译CoreTools库\n");
    }
}

void CoreTools::InitTermContainer::Execute()
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    /// 无法保证function()调用不抛出异常，编译器误报。
    DisableNoexcept();

    auto index = 0;
    for (const auto function : executeFunction)
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
