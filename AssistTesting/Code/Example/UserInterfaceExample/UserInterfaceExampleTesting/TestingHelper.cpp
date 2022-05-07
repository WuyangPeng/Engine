// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 引擎辅助测试版本：0.0.2.2 (2020/01/27 14:02)

#include "Testing.h"
#include "TestingHelper.h"
#include "CoreTools/Helper/ClassInvariant/UserInterfaceClassInvariantMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestSuite.h"

UserInterfaceExample::TestingHelper::TestingHelper(int argc, char** argv)
    : ParentType{ argc, argv, "用户界面·例子" }
{
    InitSuite();

    USER_INTERFACE_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(UserInterfaceExample, TestingHelper)

void UserInterfaceExample::TestingHelper::InitSuite() noexcept
{
}
