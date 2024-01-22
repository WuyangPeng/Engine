/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/12 16:39)

#include "Testing.h"
#include "TestingHelper.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestSuite.h"

using namespace std::literals;

MathematicsExample::TestingHelper::TestingHelper(int argc, char** argv)
    : ParentType{ argc, argv, "Distance Aligned Boxes ����"s }
{
    InitSuite();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(MathematicsExample, TestingHelper)

void MathematicsExample::TestingHelper::InitSuite() noexcept
{
}
