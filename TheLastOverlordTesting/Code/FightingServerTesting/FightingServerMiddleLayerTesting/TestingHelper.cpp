///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���İ������԰汾��0.8.0.12 (2022/08/01 11:46)

#include "Testing.h"
#include "TestingHelper.h"
#include "CoreTools/Helper/ClassInvariant/UserClassInvariantMacro.h"

FightingServerTesting::TestingHelper::TestingHelper(int argc, char** argv)
    : ParentType{ argc, argv, "ս������������������" }
{
    InitSuite();

    USER_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(FightingServerTesting, TestingHelper)

void FightingServerTesting::TestingHelper::InitSuite() noexcept
{
}
