///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助测试版本：0.8.0.10 (2022/07/12 11:55)

#include "Testing.h"
#include "TestingHelper.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Helper/UnitTestSuiteMacro.h"

FrameworkExample::TestingHelper::TestingHelper(int argc, char** argv)
    : ParentType{ argc, argv, "【框架例子】单元测试套件" }
{
    InitSuite();

    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(FrameworkExample, TestingHelper)

void FrameworkExample::TestingHelper::InitSuite() noexcept
{
}
