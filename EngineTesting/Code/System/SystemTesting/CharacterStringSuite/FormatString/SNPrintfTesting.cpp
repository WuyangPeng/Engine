///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/15 13:23)

#include "SNPrintfTesting.h"
#include "System/CharacterString/FormatStringDetail.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

#include <array>

using std::array;
using std::string;
using namespace std::literals;

#define OPEN_SNPRINTF_ERROR
#undef OPEN_SNPRINTF_ERROR

System::SNPrintfTesting::SNPrintfTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, SNPrintfTesting)

void System::SNPrintfTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::SNPrintfTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(SnprintTest);
}

void System::SNPrintfTesting::SnprintTest()
{
    constexpr auto bufferSize = 256;
    const auto result = "5snprintf8"s;

    array<char, bufferSize> buffer{ 'a' };

    const auto count = SNPrintf(buffer.data(), result.size() + 1, bufferSize, "%d%s%d", 5, "snprintf", 8);

    ASSERT_EQUAL(count, boost::numeric_cast<int>(result.size()));
    ASSERT_EQUAL(string{ buffer.data() }, result);

#ifdef OPEN_SNPRINTF_ERROR

    SNPrintf(buffer.data(), result.size() + 1, bufferSize, "%d%s%d", 5, result, 8);

#endif  // OPEN_SNPRINTF_ERROR
}