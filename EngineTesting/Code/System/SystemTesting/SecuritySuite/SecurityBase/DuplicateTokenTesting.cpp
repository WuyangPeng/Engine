///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/01 14:08)

#include "DuplicateTokenTesting.h"
#include "System/Security/SecurityBase.h"
#include "System/Threading/Flags/ThreadToolsFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/TemplateTools/MaxElement.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::DuplicateTokenTesting::DuplicateTokenTesting(const OStreamShared& osPtr)
    : ParentType{ osPtr },
      securityImpersonationLevels{ SecurityAnonymous,
                                   SecurityIdentification,
                                   SecurityImpersonation,
                                   SecurityDelegation },
      securityTokenTypes{ TokenPrimary, TokenImpersonation },
      tokenStandardAccesses{ TokenStandardAccess::Default,
                             TokenStandardAccess::Delete,
                             TokenStandardAccess::ReadControl,
                             TokenStandardAccess::WriteDac,
                             TokenStandardAccess::WriteOwner },
      tokenSpecificAccesses{ TokenSpecificAccess::Default,
                             TokenSpecificAccess::AssignPrimary,
                             TokenSpecificAccess::Duplicate,
                             TokenSpecificAccess::Impersonate,
                             TokenSpecificAccess::Query,
                             TokenSpecificAccess::QuerySource,
                             TokenSpecificAccess::AdjustPrivileges,
                             TokenSpecificAccess::AdjustGroups,
                             TokenSpecificAccess::AdjustDefault,
                             TokenSpecificAccess::AdjustSessionId,
                             TokenSpecificAccess::AllAccessP,
                             TokenSpecificAccess::AllAccess,
                             TokenSpecificAccess::Read,
                             TokenSpecificAccess::Write,
                             TokenSpecificAccess::Execute },
      randomEngine{ GetEngineRandomSeed() },
      maxSize{ CoreTools::MaxElement({ securityImpersonationLevels.size(), securityTokenTypes.size(), tokenStandardAccesses.size(), tokenSpecificAccesses.size() }) }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, DuplicateTokenTesting)

void System::DuplicateTokenTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::DuplicateTokenTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(RandomShuffleFlags);
}

bool System::DuplicateTokenTesting::RandomShuffleFlags()
{
    std::ranges::shuffle(securityImpersonationLevels, randomEngine);
    std::ranges::shuffle(securityTokenTypes, randomEngine);
    std::ranges::shuffle(tokenStandardAccesses, randomEngine);
    std::ranges::shuffle(tokenSpecificAccesses, randomEngine);

    ASSERT_NOT_THROW_EXCEPTION_0(DuplicateTokenTest);

    return true;
}

void System::DuplicateTokenTesting::DuplicateTokenTest()
{
    const auto tokenHandle = OpenProcessToken();

    ASSERT_NOT_THROW_EXCEPTION_1(DoDuplicateTokenTest, tokenHandle);

    ASSERT_NOT_THROW_EXCEPTION_1(CloseTokenTest, tokenHandle);
}

void System::DuplicateTokenTesting::DoDuplicateTokenTest(WindowsHandle tokenHandle)
{
    for (auto index = 0u; index < maxSize; ++index)
    {
        const auto securityImpersonation = securityImpersonationLevels.at(index % securityImpersonationLevels.size());

        ASSERT_NOT_THROW_EXCEPTION_2(DuplicateTest, tokenHandle, securityImpersonation);

        ASSERT_NOT_THROW_EXCEPTION_3(WindowSecurityAttributesDuplicateTest, index, tokenHandle, securityImpersonation);
    }
}

void System::DuplicateTokenTesting::DuplicateTest(WindowsHandle tokenHandle, SecurityImpersonationLevel securityImpersonation)
{
    WindowsHandle duplicateTokenHandle{ nullptr };
    ASSERT_TRUE(DuplicateSystemToken(tokenHandle, securityImpersonation, &duplicateTokenHandle));
    ASSERT_UNEQUAL_NULL_PTR(duplicateTokenHandle);

    ASSERT_NOT_THROW_EXCEPTION_1(CloseTokenTest, duplicateTokenHandle);
}

void System::DuplicateTokenTesting::WindowSecurityAttributesDuplicateTest(size_t index, WindowsHandle tokenHandle, SecurityImpersonationLevel securityImpersonation)
{
    const auto securityToken = securityTokenTypes.at(index % securityTokenTypes.size());
    const auto tokenStandardAccess = tokenStandardAccesses.at(index % tokenStandardAccesses.size());
    const auto tokenSpecificAccess = tokenSpecificAccesses.at(index % tokenSpecificAccesses.size());

    WindowsHandle duplicateTokenHandle{ nullptr };
    WindowSecurityAttributes tokenAttributes{};
    ASSERT_TRUE(DuplicateSystemToken(tokenHandle, tokenStandardAccess, tokenSpecificAccess, &tokenAttributes, securityImpersonation, securityToken, &duplicateTokenHandle));
    ASSERT_UNEQUAL_NULL_PTR(duplicateTokenHandle);

    ASSERT_NOT_THROW_EXCEPTION_1(CloseTokenTest, duplicateTokenHandle);
}
