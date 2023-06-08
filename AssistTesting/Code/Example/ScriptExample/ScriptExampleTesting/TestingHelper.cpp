///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助测试版本：0.9.0.11 (2023/05/29 15:39)

#include "Testing.h"
#include "TestingHelper.h"
#include "CoreTools/Helper/ClassInvariant/ScriptClassInvariantMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestSuite.h"

using namespace std::literals;

ScriptExample::TestingHelper::TestingHelper(int argc, char** argv)
    : ParentType{ argc, argv, "脚本例子"s }
{
    InitSuite();

    SCRIPT_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(ScriptExample, TestingHelper)

void ScriptExample::TestingHelper::InitSuite() noexcept
{
}
