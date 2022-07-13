///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.8.0.10 (2022/06/30 16:39)

#include "Helper.h"
#include "TestingHelper.h"
#include "System/Time/DeltaTime.h"
#include "CoreTools/Helper/MainFunctionMacro.h"

#include <vld.h>

int main(int argc, char** argv)
{
    {
        CMainFunctionHelper::Helper helper{ argc, argv };
        MAYBE_UNUSED const auto value0 = helper.Run();
    }

    {
        CMainFunctionHelper::TestingHelper testingHelper{ argc, argv };
        MAYBE_UNUSED const auto value1 = testingHelper.Run();
    }

    System::SystemPause();

    return 0;
}
