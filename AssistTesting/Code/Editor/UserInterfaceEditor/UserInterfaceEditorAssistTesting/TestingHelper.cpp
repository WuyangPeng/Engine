///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/31 19:20)

#include "Testing.h"
#include "TestingHelper.h"
#include "CoreTools/Helper/ClassInvariant/UserClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestSuite.h"

UserInterfaceEditorAssistTesting::TestingHelper::TestingHelper(int argc, char** argv)
    : ParentType{ argc, argv, "用户界面编辑器辅助" }
{
    InitSuite();

    USER_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(UserInterfaceEditorAssistTesting, TestingHelper)

void UserInterfaceEditorAssistTesting::TestingHelper::InitSuite() noexcept
{
}
