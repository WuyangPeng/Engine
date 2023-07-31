///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.2 (2023/07/28 14:52)

#include "Helper.h"
#include "TestingHelper.h"
#include "System/Time/DeltaTime.h"
#include "CoreTools/Helper/MainFunctionMacro.h"

#include <vld.h>

int main(int argc, char** argv)
{
    {
        CMainFunctionHelper::Helper helper{ argc, argv };
        MAYBE_UNUSED const auto result = helper.Run();
    }

    {
        CMainFunctionHelper::TestingHelper testingHelper{ argc, argv };
        MAYBE_UNUSED const auto result = testingHelper.Run();
    }

    System::SystemPause();

    return 0;
}
