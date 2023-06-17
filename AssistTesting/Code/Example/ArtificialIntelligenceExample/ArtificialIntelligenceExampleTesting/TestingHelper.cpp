///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助测试版本：0.9.0.12 (2023/06/12 19:42)

#include "Testing.h"
#include "TestingHelper.h"
#include "CoreTools/Helper/ClassInvariant/ArtificialIntelligenceClassInvariantMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestSuite.h"

ArtificialIntelligenceExample::TestingHelper::TestingHelper(int argc, char** argv)
    : ParentType{ argc, argv, "人工智能例子" }
{
    InitSuite();

    ARTIFICIAL_INTELLIGENCE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(ArtificialIntelligenceExample, TestingHelper)

// private
void ArtificialIntelligenceExample::TestingHelper ::InitSuite() noexcept
{
}
