/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/07 17:24)

#include "VersionTesting.h"
#include "System/Helper/Version.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::VersionTesting::VersionTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
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

    constexpr auto revision = gTcreVersion % maxSubversion;
    constexpr auto build = gTcreVersion / maxSubversion % maxSubversion;
    constexpr auto minor = gTcreVersion / (maxSubversion * maxSubversion) % maxSubversion;
    constexpr auto major = gTcreVersion / (maxSubversion * maxSubversion * maxSubversion) % maxSubversion;

    ASSERT_GREATER_EQUAL(revision, 0);
    ASSERT_GREATER_EQUAL(build, 0);
    ASSERT_GREATER_EQUAL(minor, 0);
    ASSERT_GREATER_EQUAL(major, 0);

    ASSERT_LESS(0, revision + build + minor + major);
}