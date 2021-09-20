// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/06 14:33)

#include "StreamTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/Stream.h"

using std::string;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(CoreTools, StreamTesting)

void CoreTools::StreamTesting ::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(StreamTest);
}

void CoreTools::StreamTesting ::StreamTest()
{
    string testValue{ "TestValue" };

    const auto size = Stream::GetStreamingSize(testValue);

    ASSERT_LESS_EQUAL(testValue.size(), size - sizeof(int));
    ASSERT_EQUAL((size - sizeof(int)) % 4, 0u);
}
