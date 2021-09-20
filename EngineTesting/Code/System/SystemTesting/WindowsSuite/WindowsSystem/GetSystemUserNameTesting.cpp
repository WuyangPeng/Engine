///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.1.6 (2021/07/08 22:42)

#include "GetSystemUserNameTesting.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/Windows/WindowsSystem.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

#include <array>

using std::array;

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
    array<TChar, bufferSize> buffer{};

    auto bufferCount = boost::numeric_cast<WindowsDWord>(buffer.size());
    ASSERT_TRUE(GetSystemUserName(buffer.data(), &bufferCount));
}