/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/11 14:21)

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

    CharBufferType buffer{};

    VsnPrintFUseIndefiniteParameterTest(boost::numeric_cast<int>(vsnPrintFTestResult.size()), buffer.data(), defaultBufferSize, "%d%s%d", 7, "vsnprintf", 1);

    ASSERT_EQUAL(std::string{ buffer.data() }, vsnPrintFTestResult);
}

void System::VsnPrintFTesting::VsnPrintFUseIndefiniteParameterTest(int testStringSize, char* buffer, size_t size, const char* format, ...)
{
#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26826)

    va_list arguments{};
    va_start(arguments, format);

    const auto count = VsnPrintF(buffer, size, format, arguments);

    va_end(arguments);

#include SYSTEM_WARNING_POP

    ASSERT_EQUAL(count, testStringSize);
}
