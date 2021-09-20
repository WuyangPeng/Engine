///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.2.2 (2021/08/26 14:18)

#include "AssertionTesting.h"
#include "CoreTools/Contract/Assertion.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using namespace std::literals;

CoreTools::AssertionTesting::AssertionTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, AssertionTesting)

void CoreTools::AssertionTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::AssertionTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(AssertionFailTest);
}

void CoreTools::AssertionTesting::AssertionFailTest()
{
    const auto promptMessage = "本次断言触发只是测试，并没有错误产生。"s;
    const auto cancelMessage = "请点击“否”取消。"s;

    const Assertion assertion{ false, CORE_TOOLS_FUNCTION_DESCRIBED, "%s%s\n", promptMessage, cancelMessage };
}
