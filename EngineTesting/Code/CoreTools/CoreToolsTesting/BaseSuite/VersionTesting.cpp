/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/15 14:38)

#include "ThreadingCoreRenderEngineTesting/Version.h"
#include "VersionTesting.h"
#include "CoreTools/Base/Version.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

CoreTools::VersionTesting::VersionTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, VersionTesting)

void CoreTools::VersionTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::VersionTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(GetTcreFullVersionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(GetVersionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(GetTestingVersionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(IsAtLeastTest);
    ASSERT_NOT_THROW_EXCEPTION_0(GetTestingVersionAtLeastTest);
}

void CoreTools::VersionTesting::GetTcreFullVersionTest() noexcept
{
    static_assert(Version::GetTcreFullVersion() == gTcreVersion);
    static_assert(Version::GetTcreFullVersion() >= gTcreTestingVersion);
}

void CoreTools::VersionTesting::GetVersionTest()
{
    ASSERT_LESS_EQUAL(0, Version::GetMajor());
    ASSERT_LESS_EQUAL(0, Version::GetMinor());
    ASSERT_LESS_EQUAL(0, Version::GetBuild());
    ASSERT_LESS_EQUAL(0, Version::GetRevision());
    ASSERT_LESS_EQUAL(7u, Version::GetVersion().size());
}

void CoreTools::VersionTesting::GetTestingVersionTest()
{
    ASSERT_LESS_EQUAL(0, Version::GetMajor(gTcreTestingVersion));
    ASSERT_LESS_EQUAL(0, Version::GetMinor(gTcreTestingVersion));
    ASSERT_LESS_EQUAL(0, Version::GetBuild(gTcreTestingVersion));
    ASSERT_LESS_EQUAL(0, Version::GetRevision(gTcreTestingVersion));
    ASSERT_LESS_EQUAL(7u, Version::GetVersion(gTcreTestingVersion).size());
}

void CoreTools::VersionTesting::IsAtLeastTest()
{
    constexpr auto major = Version::GetMajor();
    constexpr auto minor = Version::GetMinor();
    constexpr auto build = Version::GetBuild();
    constexpr auto revision = Version::GetRevision();

    ASSERT_TRUE(Version::IsAtLeast(major, minor, build, revision));
    ASSERT_FALSE(Version::IsAtLeast(major + 1, minor, build, revision));
    ASSERT_FALSE(Version::IsAtLeast(major, minor + 1, build, revision));
    ASSERT_FALSE(Version::IsAtLeast(major, minor, build + 1, revision));
    ASSERT_FALSE(Version::IsAtLeast(major, minor, build, revision + 1));

    ASSERT_TRUE(Version::IsAtLeast(major - 1, minor, build, revision));
    ASSERT_TRUE(Version::IsAtLeast(major, minor - 1, build, revision));
    ASSERT_TRUE(Version::IsAtLeast(major, minor, build - 1, revision));
    ASSERT_TRUE(Version::IsAtLeast(major, minor, build, revision - 1));

    ASSERT_FALSE(Version::IsAtLeast(major + 1, minor - 2, build, revision));
    ASSERT_FALSE(Version::IsAtLeast(major, minor + 1, build, revision - 3));
    ASSERT_FALSE(Version::IsAtLeast(major, minor, build + 1, revision - 1));

    ASSERT_TRUE(Version::IsAtLeast(major - 1, minor + 3, build, revision));
    ASSERT_TRUE(Version::IsAtLeast(major, minor - 1, build, revision + 2));
    ASSERT_TRUE(Version::IsAtLeast(major, minor, build - 1, revision + 7));
}

void CoreTools::VersionTesting::GetTestingVersionAtLeastTest()
{
    constexpr auto major = Version::GetMajor();
    constexpr auto minor = Version::GetMinor();
    constexpr auto build = Version::GetBuild();
    constexpr auto revision = Version::GetRevision();

    ASSERT_TRUE(Version::IsAtLeast(gTcreTestingVersion, major, minor, build, revision));
    ASSERT_FALSE(Version::IsAtLeast(gTcreTestingVersion, major + 1, minor, build, revision));
    ASSERT_FALSE(Version::IsAtLeast(gTcreTestingVersion, major, minor + 1, build, revision));
    ASSERT_FALSE(Version::IsAtLeast(gTcreTestingVersion, major, minor, build + 1, revision));
    ASSERT_FALSE(Version::IsAtLeast(gTcreTestingVersion, major, minor, build, revision + 1));

    ASSERT_TRUE(Version::IsAtLeast(gTcreTestingVersion, major - 1, minor, build, revision));
    ASSERT_TRUE(Version::IsAtLeast(gTcreTestingVersion, major, minor - 1, build, revision));
    ASSERT_TRUE(Version::IsAtLeast(gTcreTestingVersion, major, minor, build - 1, revision));
    ASSERT_TRUE(Version::IsAtLeast(gTcreTestingVersion, major, minor, build, revision - 1));

    ASSERT_FALSE(Version::IsAtLeast(gTcreTestingVersion, major + 1, minor - 2, build, revision));
    ASSERT_FALSE(Version::IsAtLeast(gTcreTestingVersion, major, minor + 1, build, revision - 3));
    ASSERT_FALSE(Version::IsAtLeast(gTcreTestingVersion, major, minor, build + 1, revision - 1));

    ASSERT_TRUE(Version::IsAtLeast(gTcreTestingVersion, major - 1, minor + 3, build, revision));
    ASSERT_TRUE(Version::IsAtLeast(gTcreTestingVersion, major, minor - 1, build, revision + 2));
    ASSERT_TRUE(Version::IsAtLeast(gTcreTestingVersion, major, minor, build - 1, revision + 7));
}
