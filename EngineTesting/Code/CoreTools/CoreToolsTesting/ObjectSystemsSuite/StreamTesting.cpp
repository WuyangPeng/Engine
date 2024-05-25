/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.9 (2024/04/22 21:04)

#include "StreamTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
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
