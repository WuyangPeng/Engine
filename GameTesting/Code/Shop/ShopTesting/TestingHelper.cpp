///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������Ϸ���԰汾��0.9.0.12 (2023/06/17 11:25)

#include "Testing.h"
#include "TestingHelper.h"
#include "CoreTools/Helper/ClassInvariant/UserClassInvariantMacro.h"

Shop::TestingHelper::TestingHelper(int argc, char** argv)
    : ParentType{ argc, argv, "�̵�" }
{
    InitSuite();

    USER_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Shop, TestingHelper)

void Shop::TestingHelper::InitSuite() noexcept
{
}
