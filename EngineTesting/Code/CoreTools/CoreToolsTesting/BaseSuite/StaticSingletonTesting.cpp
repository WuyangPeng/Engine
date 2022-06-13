///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/19 14:44)

#include "StaticSingletonTesting.h"
#include "Detail/StaticSingletonSubclass.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

CoreTools::StaticSingletonTesting::StaticSingletonTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, StaticSingletonTesting)

void CoreTools::StaticSingletonTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::StaticSingletonTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(StaticSingletonTest);
}

void CoreTools::StaticSingletonTesting::StaticSingletonTest()
{
    ASSERT_UNEQUAL_NULL_PTR(StaticSingletonSubclass::GetSingletonPtr());

    StaticSingletonSubclass::GetSingleton().DoNothing();
}
