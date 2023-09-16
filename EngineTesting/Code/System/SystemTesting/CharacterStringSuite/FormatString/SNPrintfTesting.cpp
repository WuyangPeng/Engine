///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/08/31 16:12)

#include "SnPrintFTesting.h"
#include "System/CharacterString/FormatStringDetail.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using namespace std::literals;

#define OPEN_SN_PRINT_F_ERROR
#undef OPEN_SN_PRINT_F_ERROR

System::SnPrintFTesting::SnPrintFTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, SnPrintFTesting)

void System::SnPrintFTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::SnPrintFTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(PrintTest);
}

void System::SnPrintFTesting::PrintTest()
{
    const auto result = "5snprintf8"s;

    BufferType buffer{ 'a' };

    const auto count = SnPrintF(buffer.data(), result.size() + 1, bufferSize - 1, "%d%s%d", 5, "snprintf", 8);

    ASSERT_EQUAL(count, boost::numeric_cast<int>(result.size()));
    ASSERT_EQUAL(std::string{ buffer.data() }, result);

#ifdef OPEN_SN_PRINT_F_ERROR

    SnPrintF(buffer.data(), result.size() + 1, bufferSize - 1, "%d%s%d", 5, result, 8);

#endif  // OPEN_SN_PRINT_F_ERROR
}