///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/18 15:44)

#include "StreamTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/Stream.h"

using std::string;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(CoreTools, StreamTesting)

void CoreTools::StreamTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(StreamTest);
}

void CoreTools::StreamTesting::StreamTest()
{
    string testValue{ "TestValue" };

    const auto size = Stream::GetStreamingSize(testValue);

    ASSERT_LESS_EQUAL(testValue.size(), size - sizeof(int));
    ASSERT_EQUAL((size - sizeof(int)) % 4, 0u);
}
