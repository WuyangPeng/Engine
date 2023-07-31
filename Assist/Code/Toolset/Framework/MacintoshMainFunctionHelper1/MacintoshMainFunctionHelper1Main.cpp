///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/28 14:06)

#include "MacintoshMainFunctionHelper1.h"
#include "Framework/Helper/MainFunctionMacro.h"
#include "Framework/MainFunctionHelper/EnvironmentDirectory.h"

#include <vld.h>

int main()
{
    EXCEPTION_TRY
    {
        const Framework::EnvironmentDirectory environmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") };

        const auto helper = Framework::MacintoshMainFunctionHelper1::Create(environmentDirectory);

        return helper->Run();
    }
    EXCEPTION_ENTRY_POINT_CATCH

    return -1;
}
