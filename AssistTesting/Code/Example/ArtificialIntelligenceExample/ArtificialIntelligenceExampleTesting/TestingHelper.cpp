///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨�����԰汾��0.9.0.12 (2023/06/12 19:42)

#include "Testing.h"
#include "TestingHelper.h"
#include "CoreTools/Helper/ClassInvariant/ArtificialIntelligenceClassInvariantMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestSuite.h"

ArtificialIntelligenceExample::TestingHelper::TestingHelper(int argc, char** argv)
    : ParentType{ argc, argv, "�˹���������" }
{
    InitSuite();

    ARTIFICIAL_INTELLIGENCE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(ArtificialIntelligenceExample, TestingHelper)

// private
void ArtificialIntelligenceExample::TestingHelper ::InitSuite() noexcept
{
}