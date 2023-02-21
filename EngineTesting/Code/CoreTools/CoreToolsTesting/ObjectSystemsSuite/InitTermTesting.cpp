///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/18 15:42)

#include "InitTermTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
bool CoreTools::InitTermTesting::terminateCall{ false };
bool CoreTools::InitTermTesting::initializeCall{ false };
bool CoreTools::InitTermTesting::testBegin{ false };
CoreTools::InitTermTesting::InitTermTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, InitTermTesting)

void CoreTools::InitTermTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::InitTermTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(InitTermTest);
}

void CoreTools::InitTermTesting::InitTermTest() noexcept
{
}
