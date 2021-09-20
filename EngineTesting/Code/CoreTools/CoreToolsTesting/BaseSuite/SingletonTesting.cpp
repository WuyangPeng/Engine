///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.2.2 (2021/08/27 12:56)

#include "SingletonTesting.h"
#include "Detail/SingletonSubclass.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

CoreTools::SingletonTesting::SingletonTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, SingletonTesting)

void CoreTools::SingletonTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::SingletonTesting::MainTest()
{
    SingletonSubclass::Create();

    ASSERT_NOT_THROW_EXCEPTION_0(SingletonPtrTest);

    SingletonSubclass::Destroy();
}

void CoreTools::SingletonTesting::SingletonPtrTest()
{
    ASSERT_UNEQUAL_NULL_PTR(SingletonSubclass::GetSingletonPtr());

    SingletonSubclass::GetSingleton().DoNothing();
}
