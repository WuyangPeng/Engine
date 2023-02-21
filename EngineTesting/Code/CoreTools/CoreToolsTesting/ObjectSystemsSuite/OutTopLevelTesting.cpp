///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/18 15:43)

#include "OutTopLevelTesting.h"
#include "CoreTools/ObjectSystems/NullObject.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/Object.h"
#include "CoreTools/ObjectSystems/OutTopLevel.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
CoreTools::OutTopLevelTesting::OutTopLevelTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, OutTopLevelTesting)

void CoreTools::OutTopLevelTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::OutTopLevelTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(TopLevelTest);
}

void CoreTools::OutTopLevelTesting::TopLevelTest() noexcept
{
}
