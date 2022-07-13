///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.0.10 (2022/07/05 10:26)

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
