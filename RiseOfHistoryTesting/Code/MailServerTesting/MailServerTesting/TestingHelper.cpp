/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.2 (2023/12/17 19:56)

#include "Testing.h"
#include "TestingHelper.h"
#include "CoreTools/Helper/ClassInvariant/UserClassInvariantMacro.h"

MailServerTesting::TestingHelper::TestingHelper(int argc, char** argv)
    : ParentType{ argc, argv, "邮件服务器单元测试" }
{
    InitSuite();

    USER_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(MailServerTesting, TestingHelper)

void MailServerTesting::TestingHelper::InitSuite() noexcept
{
}


 