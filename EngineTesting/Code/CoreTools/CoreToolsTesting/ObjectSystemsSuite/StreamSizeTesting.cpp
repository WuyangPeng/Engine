///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/18 15:44)

#include "StreamSizeTesting.h"
#include "Detail/StreamSizeTestingEnum.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/ObjectInterface.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "System/Helper/PragmaWarning/NumericCast.h"

using std::string;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(CoreTools, StreamSizeTesting)

void CoreTools::StreamSizeTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(StreamSizeTest);
}

void CoreTools::StreamSizeTesting::StreamSizeTest()
{
    ASSERT_EQUAL(GetStreamSize(char{ 0 }), (int)sizeof(char));
    ASSERT_EQUAL(GetStreamSize(short{ 0 }), (int)sizeof(short));
    ASSERT_EQUAL(GetStreamSize(int{ 0 }), (int)sizeof(int));
    ASSERT_EQUAL(GetStreamSize(long{ 0 }), (int)sizeof(long));

    ASSERT_EQUAL(GetStreamSize(unsigned char{ 0 }), (int)sizeof(unsigned char));
    ASSERT_EQUAL(GetStreamSize(unsigned short{ 0 }), (int)sizeof(unsigned short));
    ASSERT_EQUAL(GetStreamSize(unsigned int{ 0 }), (int)sizeof(unsigned int));
    ASSERT_EQUAL(GetStreamSize(unsigned long{ 0 }), (int)sizeof(unsigned long));

    ASSERT_EQUAL(GetStreamSize(float{ 0.0f }), (int)sizeof(float));
    ASSERT_EQUAL(GetStreamSize(double{ 0.0 }), (int)sizeof(double));

    ASSERT_EQUAL(GetStreamSize(bool{ false }), 4);
    ASSERT_EQUAL(GetStreamSize(StreamSizeTestingEnum::TestingEnum), 4);

    ASSERT_EQUAL(GetStreamSize(static_cast<char*>(nullptr)), 8);
    ASSERT_EQUAL(GetStreamSize(static_cast<short*>(nullptr)), 8);
    ASSERT_EQUAL(GetStreamSize(static_cast<int*>(nullptr)), 8);
    ASSERT_EQUAL(GetStreamSize(static_cast<long*>(nullptr)), 8);
    ASSERT_EQUAL(GetStreamSize(static_cast<unsigned char*>(nullptr)), 8);
    ASSERT_EQUAL(GetStreamSize(static_cast<unsigned short*>(nullptr)), 8);
    ASSERT_EQUAL(GetStreamSize(static_cast<unsigned int*>(nullptr)), 8);
    ASSERT_EQUAL(GetStreamSize(static_cast<unsigned long*>(nullptr)), 8);
    ASSERT_EQUAL(GetStreamSize(static_cast<float*>(nullptr)), 8);
    ASSERT_EQUAL(GetStreamSize(static_cast<double*>(nullptr)), 8);
    ASSERT_EQUAL(GetStreamSize(std::shared_ptr<string>()), 8);

    string testString{ "TestString" };
    ASSERT_EQUAL(GetStreamSize(testString), boost::numeric_cast<int>(Stream::GetStreamingSize(testString)));
    ASSERT_EQUAL(GetStreamSize(testString.c_str()), boost::numeric_cast<int>(Stream::GetStreamingSize(testString)));
}
