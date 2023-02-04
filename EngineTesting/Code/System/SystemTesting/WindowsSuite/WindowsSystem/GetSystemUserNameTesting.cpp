///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.1 (2023/02/02 20:49)

#include "GetSystemUserNameTesting.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/Windows/WindowsSystem.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

#include <array>

System::GetSystemUserNameTesting::GetSystemUserNameTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, GetSystemUserNameTesting)

void System::GetSystemUserNameTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::GetSystemUserNameTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(GetSystemUserNameTest);
}

void System::GetSystemUserNameTesting::GetSystemUserNameTest()
{
    constexpr auto bufferSize = 256;
    std::array<TChar, bufferSize> buffer{};

    auto bufferCount = boost::numeric_cast<WindowsDWord>(buffer.size());
    ASSERT_TRUE(GetSystemUserName(buffer.data(), &bufferCount));
}