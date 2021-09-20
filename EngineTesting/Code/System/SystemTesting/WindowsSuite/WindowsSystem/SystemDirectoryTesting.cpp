///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.1.6 (2021/07/08 22:42)

#include "SystemDirectoryTesting.h"
#include "System/Windows/WindowsSystem.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

#include <vector>

using std::vector;

System::SystemDirectoryTesting::SystemDirectoryTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, SystemDirectoryTesting)

void System::SystemDirectoryTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::SystemDirectoryTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(SystemDirectoryTest);
}

void System::SystemDirectoryTesting::SystemDirectoryTest()
{
    const auto size0 = GetSystemCurrentDirectory(0, nullptr);

    vector<TChar> buffer(size0);

    const auto size1 = GetSystemCurrentDirectory(size0, buffer.data());
    ASSERT_EQUAL(size0, size1 + 1);

    String directory{ buffer.begin(), buffer.end() };

    ASSERT_FALSE(directory.empty());
    ASSERT_EQUAL(directory.size(), size0);

    ASSERT_TRUE(SetSystemCurrentDirectory(directory.c_str()));
}