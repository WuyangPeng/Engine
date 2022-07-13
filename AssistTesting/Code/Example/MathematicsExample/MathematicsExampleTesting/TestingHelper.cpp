///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助测试版本：0.8.0.10 (2022/07/12 15:10)

#include "Testing.h"
#include "TestingHelper.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestSuite.h"

using namespace std::literals;

MathematicsExample::TestingHelper::TestingHelper(int argc, char** argv)
    : ParentType{ argc, argv, "数学例子"s }
{
    InitSuite();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(MathematicsExample, TestingHelper)

void MathematicsExample::TestingHelper::InitSuite() noexcept
{
}
