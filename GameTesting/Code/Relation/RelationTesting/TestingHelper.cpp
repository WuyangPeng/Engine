///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������Ϸ���԰汾��0.8.0.11 (2022/07/18 15:52)

#include "Testing.h"
#include "TestingHelper.h"
#include "CoreTools/Helper/ClassInvariant/UserClassInvariantMacro.h"

Relation::TestingHelper::TestingHelper(int argc, char** argv)
    : ParentType{ argc, argv, "��ϵ" }
{
    InitSuite();

    USER_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Relation, TestingHelper)

void Relation::TestingHelper::InitSuite() noexcept
{
}
