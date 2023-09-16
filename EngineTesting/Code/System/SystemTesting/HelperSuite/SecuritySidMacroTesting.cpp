///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/01 09:53)

#include "SecuritySidMacroTesting.h"
#include "System/Helper/SecuritySidMacro.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::SecuritySidMacroTesting::SecuritySidMacroTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, SecuritySidMacroTesting)

void System::SecuritySidMacroTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::SecuritySidMacroTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(NullSecuritySidTest);
    ASSERT_NOT_THROW_EXCEPTION_0(WorldSecuritySidTest);
    ASSERT_NOT_THROW_EXCEPTION_0(LocalSecuritySidTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CreatorSecuritySidTest);
    ASSERT_NOT_THROW_EXCEPTION_0(NonUniqueSecurityTest);
    ASSERT_NOT_THROW_EXCEPTION_0(NtSecurityTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ResourceManagerSecurityTest);
    ASSERT_NOT_THROW_EXCEPTION_0(MandatoryLabelSecurityTest);
}

void System::SecuritySidMacroTesting::NullSecuritySidTest()
{
    constexpr SecuritySidIdentifierAuthority identifierAuthority SYSTEM_SECURITY_NULL_SID_AUTHORITY;
    ASSERT_NOT_THROW_EXCEPTION_2(SecurityTest, identifierAuthority, 0u);
}

void System::SecuritySidMacroTesting::WorldSecuritySidTest()
{
    constexpr SecuritySidIdentifierAuthority identifierAuthority SYSTEM_SECURITY_WORLD_SID_AUTHORITY;
    ASSERT_NOT_THROW_EXCEPTION_2(SecurityTest, identifierAuthority, 1u);
}

void System::SecuritySidMacroTesting::LocalSecuritySidTest()
{
    constexpr SecuritySidIdentifierAuthority identifierAuthority SYSTEM_SECURITY_LOCAL_SID_AUTHORITY;
    ASSERT_NOT_THROW_EXCEPTION_2(SecurityTest, identifierAuthority, 2u);
}

void System::SecuritySidMacroTesting::CreatorSecuritySidTest()
{
    constexpr SecuritySidIdentifierAuthority identifierAuthority SYSTEM_SECURITY_CREATOR_SID_AUTHORITY;
    ASSERT_NOT_THROW_EXCEPTION_2(SecurityTest, identifierAuthority, 3u);
}

void System::SecuritySidMacroTesting::NonUniqueSecurityTest()
{
    constexpr SecuritySidIdentifierAuthority identifierAuthority SYSTEM_SECURITY_NON_UNIQUE_AUTHORITY;
    ASSERT_NOT_THROW_EXCEPTION_2(SecurityTest, identifierAuthority, 4u);
}

void System::SecuritySidMacroTesting::NtSecurityTest()
{
    constexpr SecuritySidIdentifierAuthority identifierAuthority SYSTEM_SECURITY_NT_AUTHORITY;
    ASSERT_NOT_THROW_EXCEPTION_2(SecurityTest, identifierAuthority, 5u);
}

void System::SecuritySidMacroTesting::ResourceManagerSecurityTest()
{
    constexpr SecuritySidIdentifierAuthority identifierAuthority SYSTEM_SECURITY_RESOURCE_MANAGER_AUTHORITY;
    ASSERT_NOT_THROW_EXCEPTION_2(SecurityTest, identifierAuthority, 9u);
}

void System::SecuritySidMacroTesting::MandatoryLabelSecurityTest()
{
    constexpr SecuritySidIdentifierAuthority identifierAuthority SYSTEM_SECURITY_MANDATORY_LABEL_AUTHORITY;
    ASSERT_NOT_THROW_EXCEPTION_2(SecurityTest, identifierAuthority, 16u);
}

void System::SecuritySidMacroTesting::SecurityTest(const SecuritySidIdentifierAuthority& identifierAuthority, uint32_t endValue)
{
    auto index = 0;
    for (const auto value : identifierAuthority.Value)
    {
        if (index == endSecuritySidIndex)
        {
            ASSERT_EQUAL(identifierAuthority.Value[endSecuritySidIndex], endValue);
        }
        else
        {
            ASSERT_EQUAL(value, 0u);
        }

        ++index;
    }
}
