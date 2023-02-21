///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/18 15:42)

#include "InTopLevelTesting.h"
#include "CoreTools/ObjectSystems/NullObject.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/InTopLevel.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include <vector>

using std::vector;

CoreTools::InTopLevelTesting::InTopLevelTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, InTopLevelTesting)

void CoreTools::InTopLevelTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::InTopLevelTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(BasisTest);
}

void CoreTools::InTopLevelTesting::BasisTest() noexcept
{
}
