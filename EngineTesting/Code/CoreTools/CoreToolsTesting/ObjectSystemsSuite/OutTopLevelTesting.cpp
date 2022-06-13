///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/18 15:43)

#include "OutTopLevelTesting.h"
#include "Detail/NullObject.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/Object.h"
#include "CoreTools/ObjectSystems/OutTopLevel.h"

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(CoreTools, OutTopLevelTesting)

void CoreTools::OutTopLevelTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(TopLevelTest);
}

void CoreTools::OutTopLevelTesting::TopLevelTest() noexcept
{
}
