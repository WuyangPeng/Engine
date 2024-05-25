/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.9 (2024/04/26 15:53)

#include "IntelCheckSumTesting.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/CyclicRedundancyCheck/IntelCheckSum.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

#include <array>

CoreTools::IntelCheckSumTesting::IntelCheckSumTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, IntelCheckSumTesting)

void CoreTools::IntelCheckSumTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::IntelCheckSumTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(SumTest);
}

void CoreTools::IntelCheckSumTesting::SumTest()
{
    const auto buffer = GetBufferType();

    const IntelCheckSum intelCheckSum{ buffer.data(), boost::numeric_cast<int>(buffer.size()) };

    auto sum = 0;
    for (const char c : buffer)
    {
        sum += c;
    }

    ASSERT_EQUAL(-sum, intelCheckSum.GetIntelCheckSum());
}

CoreTools::IntelCheckSumTesting::BufferType CoreTools::IntelCheckSumTesting::GetBufferType()
{
    BufferType buffer{};

    for (auto i = 0; i < bufferSize; ++i)
    {
        buffer.at(i) = boost::numeric_cast<char>(i - bufferSize / 2);
    }

    return buffer;
}
