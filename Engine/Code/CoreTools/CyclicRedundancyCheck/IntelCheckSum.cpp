///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.4 (2023/03/22 19:23)

#include "CoreTools/CoreToolsExport.h"

#include "IntelCheckSum.h"
#include "System/Helper/PragmaWarning.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::IntelCheckSum::IntelCheckSum(const char* data, int length) noexcept
    : intelCheckSum{ 0 }
{
    Calculation(data, length);

    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, IntelCheckSum)

int CoreTools::IntelCheckSum::GetIntelCheckSum() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return intelCheckSum;
}

void CoreTools::IntelCheckSum::Calculation(const char* data, int length) noexcept
{
    if (data != nullptr)
    {
        auto sum = 0;
        for (auto i = 0; i < length; ++i)
        {
#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)

            sum += data[i];

#include SYSTEM_WARNING_POP
        }

        intelCheckSum = -sum;
    }
}
