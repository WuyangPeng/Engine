///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/08/31 16:13)

#include "StrCatTesting.h"
#include "System/CharacterString/FormatStringDetail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using namespace std::literals;

System::StrCatTesting::StrCatTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, StrCatTesting)

void System::StrCatTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::StrCatTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(StrCatTest);
}

void System::StrCatTesting::StrCatTest()
{
    const auto result = "2strcat4"s;

    BufferType buffer{ '2' };

    ASSERT_TRUE(StrCat(buffer.data(), bufferSize, "strcat4"));

    ASSERT_EQUAL(std::string{ buffer.data() }, result);
}
