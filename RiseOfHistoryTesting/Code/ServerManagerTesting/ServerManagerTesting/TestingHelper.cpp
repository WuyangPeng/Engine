/// Copyright (c) 2010-2025
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.2.0 (2025/01/06 10:06)

#include "ServerManager/ServerManagerCore/Helper/ServerManagerCoreClassInvariantMacro.h"
#include "Testing.h"
#include "TestingHelper.h"

ServerManagerTesting::TestingHelper::TestingHelper(int argc, char** argv)
    : ParentType{ argc, argv, "�����������ߵ�Ԫ����" }
{
    InitSuite();

    SERVER_MANAGER_CORE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(ServerManagerTesting, TestingHelper)

void ServerManagerTesting::TestingHelper::InitSuite() noexcept
{
}