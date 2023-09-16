///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/01 14:07)

#include "AdjustTokenGroupsTesting.h"
#include "System/Helper/SecuritySidMacro.h"
#include "System/Security/Flags/SecurityBaseFlags.h"
#include "System/Security/SecurityBase.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::AdjustTokenGroupsTesting::AdjustTokenGroupsTesting(const OStreamShared& stream)
    : ParentType{ stream },
      securityTokenAttributesGroups{ SecurityTokenAttributesGroup::Mandatory,
                                     SecurityTokenAttributesGroup::EnabledByDefault,
                                     SecurityTokenAttributesGroup::Enabled,
                                     SecurityTokenAttributesGroup::Owner,
                                     SecurityTokenAttributesGroup::UseForDenyOnly,
                                     SecurityTokenAttributesGroup::Integrity,
                                     SecurityTokenAttributesGroup::IntegrityEnabled,
                                     SecurityTokenAttributesGroup::LogonId,
                                     SecurityTokenAttributesGroup::Resource,
                                     SecurityTokenAttributesGroup::ValidAttributes }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, AdjustTokenGroupsTesting)

void System::AdjustTokenGroupsTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::AdjustTokenGroupsTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(GetAdjustTokenGroupsTest);
}

void System::AdjustTokenGroupsTesting::GetAdjustTokenGroupsTest()
{
    const auto tokenHandle = OpenProcessToken();

    ASSERT_NOT_THROW_EXCEPTION_1(DoGetAdjustTokenGroupsTest, tokenHandle);

    ASSERT_NOT_THROW_EXCEPTION_1(CloseTokenTest, tokenHandle);
}

void System::AdjustTokenGroupsTesting::DoGetAdjustTokenGroupsTest(WindowsHandle tokenHandle)
{
    for (auto securityTokenAttributesGroup : securityTokenAttributesGroups)
    {
        ASSERT_NOT_THROW_EXCEPTION_2(GroupsTest, securityTokenAttributesGroup, tokenHandle);
    }
}

void System::AdjustTokenGroupsTesting::GroupsTest(SecurityTokenAttributesGroup securityTokenAttributesGroup, WindowsHandle tokenHandle)
{
    auto sid = GetSecuritySid();

    SecurityTokenGroups state{};
    state.GroupCount = 1;
    state.Groups[0].Sid = &sid;
    state.Groups[0].Attributes = EnumCastUnderlying(securityTokenAttributesGroup);

    SecurityTokenGroups previousState{};
    WindowsDWord returnLength{ 0 };
    ASSERT_TRUE(GetAdjustTokenGroups(tokenHandle, true, &state, sizeof(state), &previousState, &returnLength));
}
