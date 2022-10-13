///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.1.2 (2022/09/18 14:39)

#include "VersionTesting.h"
#include "System/Helper/Version.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::VersionTesting::VersionTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, VersionTesting)

void System::VersionTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::VersionTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(VersionTest);
}

void System::VersionTesting::VersionTest()
{
    constexpr auto maxSubversion = 100;

    constexpr auto revision = gTCREVersion % maxSubversion;
    constexpr auto build = gTCREVersion / maxSubversion % maxSubversion;
    constexpr auto minor = gTCREVersion / (maxSubversion * maxSubversion) % maxSubversion;
    constexpr auto major = gTCREVersion / (maxSubversion * maxSubversion * maxSubversion) % maxSubversion;

    ASSERT_GREATER_EQUAL(revision, 0);
    ASSERT_GREATER_EQUAL(build, 0);
    ASSERT_GREATER_EQUAL(minor, 0);
    ASSERT_GREATER_EQUAL(major, 0);

    ASSERT_TRUE(0 < revision || 0 < build || 0 < minor || 0 < major);
}