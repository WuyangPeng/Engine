/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/13 17:22)

#include "SystemDirectoryTesting.h"
#include "System/Windows/WindowsSystem.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

#include <vector>

System::SystemDirectoryTesting::SystemDirectoryTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
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

    std::vector<TChar> buffer(size0);

    const auto size1 = GetSystemCurrentDirectory(size0, buffer.data());
    ASSERT_EQUAL(size0, size1 + 1);

    const String directory{ buffer.begin(), buffer.end() };

    ASSERT_FALSE(directory.empty());
    ASSERT_EQUAL(directory.size(), size0);

    ASSERT_TRUE(SetSystemCurrentDirectory(directory.c_str()));
}