///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨�����԰汾��0.9.0.12 (2023/06/12 20:03)

#include "Testing.h"
#include "TestingHelper.h"
#include "CoreTools/Helper/ClassInvariant/UserInterfaceClassInvariantMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestSuite.h"

UserInterfaceExample::TestingHelper::TestingHelper(int argc, char** argv)
    : ParentType{ argc, argv, "�û����桤����" }
{
    InitSuite();

    USER_INTERFACE_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(UserInterfaceExample, TestingHelper)

void UserInterfaceExample::TestingHelper::InitSuite() noexcept
{
}
