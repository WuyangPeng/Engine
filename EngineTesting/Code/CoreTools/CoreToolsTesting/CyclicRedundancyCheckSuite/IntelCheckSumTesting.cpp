///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.6 (2023/04/11 16:04)

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
    constexpr auto bufferSize = 256;

    std::array<char, bufferSize> buff{};

    for (auto i = 0; i < bufferSize; ++i)
    {
        buff.at(i) = boost::numeric_cast<char>(i - bufferSize / 2);
    }

    const IntelCheckSum intelCheckSum{ buff.data(), boost::numeric_cast<int>(buff.size()) };

    auto sum = 0;
    for (auto i = 0u; i < buff.size(); ++i)
    {
        sum += buff.at(i);
    }

    ASSERT_EQUAL(-sum, intelCheckSum.GetIntelCheckSum());
}
