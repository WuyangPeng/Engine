// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ���渨�����԰汾��0.0.2.2 (2020/01/25 19:37)

#include "Testing.h"
#include "TestingHelper.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestSuite.h"

using namespace std::literals;

MathematicsExample::TestingHelper::TestingHelper(int argc, char** argv)
    : ParentType{ argc, argv, "��ѧ����"s }
{
    InitSuite();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(MathematicsExample, TestingHelper)

void MathematicsExample::TestingHelper::InitSuite() noexcept 
{
}
