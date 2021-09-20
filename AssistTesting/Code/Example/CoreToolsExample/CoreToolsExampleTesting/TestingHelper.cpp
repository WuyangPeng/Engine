///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助测试版本：0.7.2.1 (2021/07/28 15:36)

#include "Testing.h"
#include "TestingHelper.h"
#include "CoreTools/MainFunctionHelper/CMainFunctionTestingHelperDetail.h"
#include "Example/System/SystemExample/Helper/SystemExampleClassInvariantMacro.h"

CoreToolsExample::TestingHelper::TestingHelper(int argc, char** argv)
    : ParentType{ argc, argv, "核心工具·例子" }
{
    InitSuite();

    SYSTEM_EXAMPLE_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreToolsExample, TestingHelper)

void CoreToolsExample::TestingHelper::InitSuite() noexcept
{
}