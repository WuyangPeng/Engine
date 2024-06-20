/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.1.0 (2024/06/20 15:54)

#include "Testing.h"
#include "TestingHelper.h"
#include "CoreTools/Helper/ClassInvariant/UserClassInvariantMacro.h"

ServerManagerTesting::TestingHelper::TestingHelper(int argc, char** argv)
    : ParentType{ argc, argv, "�����������ߺ��ĵ�Ԫ����" }
{
    InitSuite();

    USER_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(ServerManagerTesting, TestingHelper)

void ServerManagerTesting::TestingHelper::InitSuite() noexcept
{
}
