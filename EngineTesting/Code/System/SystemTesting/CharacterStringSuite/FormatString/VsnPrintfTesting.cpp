///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/08/31 16:14)

#include "VsnPrintFTesting.h"
#include "System/CharacterString/FormatStringDetail.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using namespace std::literals;

System::VsnPrintFTesting::VsnPrintFTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, VsnPrintFTesting)

void System::VsnPrintFTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::VsnPrintFTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(VsnPrintFTest);
}

void System::VsnPrintFTesting::VsnPrintFTest()
{
    const auto vsnPrintFTestResult = "7vsnprintf1"s;

    BufferType buffer{};

    VsnPrintFUseIndefiniteParameterTest(boost::numeric_cast<int>(vsnPrintFTestResult.size()), buffer.data(), bufferSize, "%d%s%d", 7, "vsnprintf", 1);

    ASSERT_EQUAL(std::string{ buffer.data() }, vsnPrintFTestResult);
}

void System::VsnPrintFTesting::VsnPrintFUseIndefiniteParameterTest(int testStringSize, char* buffer, size_t size, const char* format, ...)
{
#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)
#include SYSTEM_WARNING_DISABLE(26492)
#include SYSTEM_WARNING_DISABLE(26826)

    va_list arguments{};
    va_start(arguments, format);

    const auto count = VsnPrintF(buffer, size, format, arguments);

    va_end(arguments);

    ASSERT_EQUAL(count, testStringSize);

#include SYSTEM_WARNING_POP
}
