///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/10/25 14:19)

#include "StreamSizeTesting.h"
#include "Detail/StreamSizeTestingEnum.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/CoreToolsTesting/HelperSuite/Detail/MacroTestEnum.h"
#include "CoreTools/CoreToolsTesting/HelperSuite/Detail/TestingObject.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using namespace std::literals;

CoreTools::StreamSizeTesting::StreamSizeTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, StreamSizeTesting)

void CoreTools::StreamSizeTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::StreamSizeTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(StreamSizeTest);

    ObjectManager::Create();

    ASSERT_NOT_THROW_EXCEPTION_0(Int16StreamTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ObjectAssociatedTest);
    ASSERT_NOT_THROW_EXCEPTION_0(BoolStreamTest);
    ASSERT_NOT_THROW_EXCEPTION_0(EnumStreamTest);
    ASSERT_NOT_THROW_EXCEPTION_0(StringStreamTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ConstCharStreamTest);
    ASSERT_NOT_THROW_EXCEPTION_0(VectorStreamTest);
    ASSERT_NOT_THROW_EXCEPTION_0(VectorStringStreamTest);
    ASSERT_NOT_THROW_EXCEPTION_0(VectorConstCharStreamTest);
    ASSERT_NOT_THROW_EXCEPTION_0(VectorObjectAssociatedTest);

    ObjectManager::Destroy();
}

void CoreTools::StreamSizeTesting::StreamSizeTest()
{
    ASSERT_EQUAL(GetStreamSize(char{ 0 }), boost::numeric_cast<int>(sizeof(char)));
    ASSERT_EQUAL(GetStreamSize(short{ 0 }), boost::numeric_cast<int>(sizeof(short)));
    ASSERT_EQUAL(GetStreamSize(int{ 0 }), boost::numeric_cast<int>(sizeof(int)));
    ASSERT_EQUAL(GetStreamSize(long{ 0 }), boost::numeric_cast<int>(sizeof(long)));
    ASSERT_EQUAL(GetStreamSize(long long{ 0 }), boost::numeric_cast<int>(sizeof(long long)));

    ASSERT_EQUAL(GetStreamSize(unsigned char{ 0 }), boost::numeric_cast<int>(sizeof(unsigned char)));
    ASSERT_EQUAL(GetStreamSize(unsigned short{ 0 }), boost::numeric_cast<int>(sizeof(unsigned short)));
    ASSERT_EQUAL(GetStreamSize(unsigned int{ 0 }), boost::numeric_cast<int>(sizeof(unsigned int)));
    ASSERT_EQUAL(GetStreamSize(unsigned long{ 0 }), boost::numeric_cast<int>(sizeof(unsigned long)));
    ASSERT_EQUAL(GetStreamSize(unsigned long long{ 0 }), boost::numeric_cast<int>(sizeof(unsigned long long)));

    ASSERT_EQUAL(GetStreamSize(float{ 0.0f }), boost::numeric_cast<int>(sizeof(float)));
    ASSERT_EQUAL(GetStreamSize(double{ 0.0 }), boost::numeric_cast<int>(sizeof(double)));
    ASSERT_EQUAL(GetStreamSize(long double{ 0.0 }), boost::numeric_cast<int>(sizeof(long double)));

    ASSERT_EQUAL(GetStreamSize(bool{ false }), 4);
    ASSERT_EQUAL(GetStreamSize(StreamSizeTestingEnum::TestingEnum), 4);

    std::string testString{ "TestString" };
    ASSERT_EQUAL(GetStreamSize(testString), Stream::GetStreamingSize(testString));
    ASSERT_EQUAL(GetStreamSize(testString.c_str()), Stream::GetStreamingSize(testString));

    std::string_view testStringView{ "TestString" };
    ASSERT_EQUAL(GetStreamSize(testStringView), Stream::GetStreamingSize(testStringView));
}

void CoreTools::StreamSizeTesting::Int16StreamTest()
{
    constexpr int16_t value{ 0 };

    ASSERT_EQUAL(CoreTools::GetStreamSize(value), boost::numeric_cast<int>(sizeof(int16_t)));
}

void CoreTools::StreamSizeTesting::ObjectAssociatedTest()
{
    const TestingObjectSharedPtr testingObject{};

    const ObjectAssociated objectAssociated{ testingObject };

    ASSERT_EQUAL(CoreTools::GetStreamSize(objectAssociated), gObjectSize);
}

void CoreTools::StreamSizeTesting::BoolStreamTest()
{
    constexpr auto value = false;

    ASSERT_EQUAL(CoreTools::GetStreamSize(value), gDefaultSize);
}

void CoreTools::StreamSizeTesting::EnumStreamTest()
{
    constexpr auto macroTestEnum = MacroTestEnum::One;

    ASSERT_EQUAL(CoreTools::GetStreamSize(macroTestEnum), boost::numeric_cast<int>(sizeof(MacroTestEnum)));
}

void CoreTools::StreamSizeTesting::StringStreamTest()
{
    auto value = "value"s;

    ASSERT_EQUAL(CoreTools::GetStreamSize(value), Stream::GetStreamingSize(value));
}

void CoreTools::StreamSizeTesting::ConstCharStreamTest()
{
    const auto* value = "value";

    ASSERT_EQUAL(CoreTools::GetStreamSize(value), Stream::GetStreamingSize(value));
}

void CoreTools::StreamSizeTesting::VectorStreamTest()
{
    const std::vector<int> value(9);

    ASSERT_EQUAL(CoreTools::GetStreamSize(value), boost::numeric_cast<int>(gDefaultSize + value.size() * sizeof(int)));
}

void CoreTools::StreamSizeTesting::VectorStringStreamTest()
{
    const std::vector<std::string> value{ "123", "4567", "poi12" };

    ASSERT_EQUAL(CoreTools::GetStreamSize(value), gDefaultSize + Stream::GetStreamingSize("123") + Stream::GetStreamingSize("4567") + Stream::GetStreamingSize("poi12"));
}

void CoreTools::StreamSizeTesting::VectorConstCharStreamTest()
{
    const std::vector value{ "12", "4567", "poi12o" };

    ASSERT_EQUAL(CoreTools::GetStreamSize(value), gDefaultSize + Stream::GetStreamingSize("123") + Stream::GetStreamingSize("4567") + Stream::GetStreamingSize("poi12"));
}

void CoreTools::StreamSizeTesting::VectorObjectAssociatedTest()
{
    const ObjectAssociated objectAssociated{ std::make_shared<TestingObject>("123") };
    const std::vector result{ objectAssociated, objectAssociated, objectAssociated, objectAssociated };

    ASSERT_EQUAL(CoreTools::GetStreamSize(result), boost::numeric_cast<int>(gObjectSize * result.size() + gDefaultSize));
}
