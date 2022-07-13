///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨�����԰汾��0.8.0.10 (2022/07/11 18:49)

#include "Testing.h"
#include "TestingHelper.h"
#include "CoreTools/Helper/ClassInvariant/ArtificialIntellegenceClassInvariantMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestSuite.h"

ArtificialIntellegenceExample::TestingHelper::TestingHelper(int argc, char** argv)
    : ParentType{ argc, argv, "�˹���������" }
{
    InitSuite();

    ARTIFICIAL_INTELLEGENCE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(ArtificialIntellegenceExample, TestingHelper)

// private
void ArtificialIntellegenceExample::TestingHelper ::InitSuite() noexcept
{
}
