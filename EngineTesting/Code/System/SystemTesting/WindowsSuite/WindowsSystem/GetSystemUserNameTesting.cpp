/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/13 17:21)

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
    SYSTEM_SELF_CLASS_IS_VALID_1;
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
    TCharBufferType buffer{};

    auto bufferCount = boost::numeric_cast<WindowsDWord>(buffer.size());
    ASSERT_TRUE(GetSystemUserName(buffer.data(), &bufferCount));
}