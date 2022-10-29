///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.3 (2022/10/14 21:22)

#include "StrcatTesting.h"
#include "System/CharacterString/FormatStringDetail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

#include <array>

using std::array;
using std::string;
using namespace std::literals;

System::StrcatTesting::StrcatTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, StrcatTesting)

void System::StrcatTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::StrcatTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(StrcatTest);
}

void System::StrcatTesting::StrcatTest()
{
    constexpr auto bufferSize = 256;
    const auto result = "2strcat4"s;

    array<char, bufferSize> buffer{ '2' };

    ASSERT_TRUE(Strcat(buffer.data(), bufferSize, "strcat4"));

    ASSERT_EQUAL(string{ buffer.data() }, result);
}
