///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.6 (2023/04/24 15:33)

#include "StreamTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/Stream.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

CoreTools::StreamTesting::StreamTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, StreamTesting)

void CoreTools::StreamTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::StreamTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(StreamTest);
}

void CoreTools::StreamTesting::StreamTest()
{
    std::string testValue{ "TestValue" };

    const auto size = Stream::GetStreamingSize(testValue);

    ASSERT_LESS_EQUAL(testValue.size(), size - sizeof(int));
    ASSERT_EQUAL((size - sizeof(int)) % 4, 0u);
}
