///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.2.1 (2021/08/19 14:09)

#include "../Detail/MacroTestEnum.h"
#include "../Detail/TestingObject.h"
#include "StreamSizeMacroTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/StreamMacro.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using std::make_shared;
using std::string;
using std::vector;
using namespace std::literals;

CoreTools::StreamSizeMacroTesting::StreamSizeMacroTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, StreamSizeMacroTesting)

void CoreTools::StreamSizeMacroTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::StreamSizeMacroTesting::MainTest()
{
    ObjectManager::Create();

    ASSERT_NOT_THROW_EXCEPTION_0(Int16StreamTest);
    ASSERT_NOT_THROW_EXCEPTION_0(PtrStreamTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SharedPtrStreamTest);
    ASSERT_NOT_THROW_EXCEPTION_0(BoolStreamTest);
    ASSERT_NOT_THROW_EXCEPTION_0(EnumStreamTest);
    ASSERT_NOT_THROW_EXCEPTION_0(StringStreamTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ConstCharStreamTest);
    ASSERT_NOT_THROW_EXCEPTION_0(VectorStreamTest);

    ObjectManager::Destroy();
}

void CoreTools::StreamSizeMacroTesting::Int16StreamTest()
{
    constexpr int16_t value{ 0 };

    ASSERT_EQUAL(CORE_TOOLS_STREAM_SIZE(value), boost::numeric_cast<int>(sizeof(int16_t)));
}

void CoreTools::StreamSizeMacroTesting::PtrStreamTest()
{
    int* ptr{ nullptr };

    ASSERT_EQUAL(CORE_TOOLS_STREAM_SIZE(ptr), g_ObjectSize);
}

void CoreTools::StreamSizeMacroTesting::SharedPtrStreamTest()
{
    TestingObjectSharedPtr testingObject{};

    ASSERT_EQUAL(CORE_TOOLS_STREAM_SIZE(testingObject), g_ObjectSize);
}

void CoreTools::StreamSizeMacroTesting::BoolStreamTest()
{
    constexpr auto value = false;

    ASSERT_EQUAL(CORE_TOOLS_STREAM_SIZE(value), g_DefaultSize);
}

void CoreTools::StreamSizeMacroTesting::EnumStreamTest()
{
    constexpr auto macroTestEnum = MacroTestEnum::One;

    ASSERT_EQUAL(CORE_TOOLS_STREAM_SIZE(macroTestEnum), boost::numeric_cast<int>(sizeof(MacroTestEnum)));
}

void CoreTools::StreamSizeMacroTesting::StringStreamTest()
{
    auto value = "value"s;

    ASSERT_EQUAL(CORE_TOOLS_STREAM_SIZE(value), Stream::GetStreamingSize(value));
}

void CoreTools::StreamSizeMacroTesting::ConstCharStreamTest()
{
    const char* value{ "value" };

    ASSERT_EQUAL(CORE_TOOLS_STREAM_SIZE(value), Stream::GetStreamingSize(value));
}

void CoreTools::StreamSizeMacroTesting::VectorStreamTest()
{
    vector<int> value(9);

    ASSERT_EQUAL(CORE_TOOLS_STREAM_SIZE(value), boost::numeric_cast<int>(g_DefaultSize + value.size() * sizeof(int)));
}
