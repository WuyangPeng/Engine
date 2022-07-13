///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.8.0.10 (2022/07/05 10:26)

#include "MacintoshMainFunctionHelper1.h"
#include "Framework/Helper/MainFunctionMacro.h"
#include "Framework/MainFunctionHelper/EnvironmentDirectory.h"

#include <vld.h>

int main()
{
    EXCEPTION_TRY
    {
        Framework::EnvironmentDirectory environmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") };

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26414)

        auto helper = std::make_shared<Framework::MacintoshMainFunctionHelper1>(environmentDirectory);

#include STSTEM_WARNING_POP

        return helper->Run();
    }
    EXCEPTION_ENTRY_POINT_CATCH

    return -1;
}
