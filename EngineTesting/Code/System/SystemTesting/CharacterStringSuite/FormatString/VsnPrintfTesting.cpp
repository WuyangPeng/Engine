///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.3 (2022/10/14 21:22)

#include "VsnPrintfTesting.h"
#include "System/CharacterString/FormatStringDetail.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

#include <array>

using std::array;
using std::string;
using namespace std::literals;

System::VsnPrintfTesting::VsnPrintfTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, VsnPrintfTesting)

void System::VsnPrintfTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::VsnPrintfTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(VsnprintfTest);
}

void System::VsnPrintfTesting::VsnprintfTest()
{
    constexpr auto bufferSize = 256;
    const auto vsnprintfTestResult = "7vsnprintf1"s;

    array<char, bufferSize> buffer{};

    DoVsnprintfTest(boost::numeric_cast<int>(vsnprintfTestResult.size()), buffer.data(), bufferSize, "%d%s%d", 7, "vsnprintf", 1);

    ASSERT_EQUAL(string{ buffer.data() }, vsnprintfTestResult);
}

void System::VsnPrintfTesting::DoVsnprintfTest(int testStringSize, char* buffer, size_t size, const char* format, ...)
{
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)
#include SYSTEM_WARNING_DISABLE(26492)

    va_list arguments{};
    va_start(arguments, format);

#include STSTEM_WARNING_POP

    const auto count = VsnPrintf(buffer, size, format, arguments);

    va_end(arguments);

    ASSERT_EQUAL(count, testStringSize);
}
