/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/12 17:35)

#include "Helper.h"
#include "TestingHelper.h"
#include "System/Time/DeltaTime.h"
#include "CoreTools/Helper/MainFunctionMacro.h"

#include "System/Helper/PragmaWarning/Vld.h"

int main(int argc, char** argv)
{
    {
        CMainFunctionHelper::Helper helper{ argc, argv };
        std::ignore = helper.Run();
    }

    {
        CMainFunctionHelper::TestingHelper testingHelper{ argc, argv };
        std::ignore = testingHelper.Run();
    }

    System::SystemPause();

    return 0;
}
