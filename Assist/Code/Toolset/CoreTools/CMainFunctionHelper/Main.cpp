// Copyright (c) 2011-2020
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
//
// ÒıÇæ¸¨Öú°æ±¾£º0.0.2.0 (2020/01/03 22:50)

#include "Helper.h"
#include "TestingHelper.h"
#include "System/Time/DeltaTime.h"
#include "CoreTools/Helper/MainFunctionMacro.h"

#include <vld.h>

int main(int argc, char* argv[])
{
    CMainFunctionHelper::Helper helper{ argc, argv };
    [[maybe_unused]] const auto value0 = helper.Run();

    CMainFunctionHelper::TestingHelper testingHelper{ argc, argv };
    [[maybe_unused]] const auto value1 = testingHelper.Run();

    System::SystemPause();

    return 0;
}
