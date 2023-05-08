///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.6 (2023/04/26 10:59)

#include "UnitTestStreamTesting.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "CoreTools/Helper/UnitTest/AssertTestMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

CoreTools::UnitTestStreamTesting::UnitTestStreamTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, UnitTestStreamTesting)

void CoreTools::UnitTestStreamTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::UnitTestStreamTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(UnitTestStreamTest);
}

void CoreTools::UnitTestStreamTesting::UnitTestStreamTest()
{
    const OStreamShared oStreamShared{ true };

    UnitTestStreamTesting unitTestCompositeTesting{ oStreamShared };

    ASSERT_FALSE(unitTestCompositeTesting.IsStreamSharedFile());

    unitTestCompositeTesting.GetStream() << "这里打印测试文本。\n";
}
