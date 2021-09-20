///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.1.4 (2021/06/04 11:29)

#include "DuplicateTokenTesting.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/Security/SecurityBase.h"
#include "System/Threading/Flags/ThreadToolsFlags.h"
#include "System/Threading/Process.h"
#include "System/Threading/ProcessTools.h"
#include "System/Threading/ThreadTools.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/TemplateTools/MaxElement.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

#include <array>

using std::array;
using std::vector;

System::DuplicateTokenTesting::DuplicateTokenTesting(const OStreamShared& osPtr)
    : ParentType{ osPtr },
      securityImpersonationLevel{ SecurityAnonymous, SecurityIdentification, SecurityImpersonation, SecurityDelegation },
      securityTokenType{ TokenPrimary, TokenImpersonation },
      tokenStandardAccessFlags{ TokenStandardAccess::Default,
                                TokenStandardAccess::Delete,
                                TokenStandardAccess::ReadControl,
                                TokenStandardAccess::WriteDac,
                                TokenStandardAccess::WriteOwner },
      tokenSpecificAccessFlags{ TokenSpecificAccess::Default,
                                TokenSpecificAccess::AssignPrimary,
                                TokenSpecificAccess::Duplicate,
                                TokenSpecificAccess::Impersonate,
                                TokenSpecificAccess::Query,
                                TokenSpecificAccess::QuerySource,
                                TokenSpecificAccess::AdjustPrivileges,
                                TokenSpecificAccess::AdjustGroups,
                                TokenSpecificAccess::AdjustDefault,
                                TokenSpecificAccess::AdjustSessionID,
                                TokenSpecificAccess::AllAccessP,
                                TokenSpecificAccess::AllAccess,
                                TokenSpecificAccess::Read,
                                TokenSpecificAccess::Write,
                                TokenSpecificAccess::Execute },
      randomEngine{ GetEngineRandomSeed() },
      maxSize{ CoreTools::MaxElement({ securityImpersonationLevel.size(), securityTokenType.size(), tokenStandardAccessFlags.size(), tokenSpecificAccessFlags.size() }) }
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
    shuffle(securityImpersonationLevel.begin(), securityImpersonationLevel.end(), randomEngine);
    shuffle(securityTokenType.begin(), securityTokenType.end(), randomEngine);
    shuffle(tokenStandardAccessFlags.begin(), tokenStandardAccessFlags.end(), randomEngine);
    shuffle(tokenSpecificAccessFlags.begin(), tokenSpecificAccessFlags.end(), randomEngine);

    ASSERT_NOT_THROW_EXCEPTION_0(DuplicateTokenTest);

    return true;
}

void System::DuplicateTokenTesting::DuplicateTokenTest()
{
    WindowsHandle tokenHandle{ nullptr };
    ASSERT_TRUE(OpenSysemProcessToken(GetCurrentProcessHandle(), TokenStandardAccess::Default, TokenSpecificAccess::AllAccess, &tokenHandle));

    for (auto index = 0u; index < maxSize; ++index)
    {
        auto securityImpersonation = securityImpersonationLevel.at(index % securityImpersonationLevel.size());
        auto securityToken = securityTokenType.at(index % securityTokenType.size());
        auto tokenStandardAccess = tokenStandardAccessFlags.at(index % tokenStandardAccessFlags.size());
        auto tokenSpecificAccess = tokenSpecificAccessFlags.at(index % tokenSpecificAccessFlags.size());

        WindowsHandle duplicateTokenHandle{ nullptr };
        ASSERT_TRUE(DuplicateSystemToken(tokenHandle, securityImpersonation, &duplicateTokenHandle));
        ASSERT_UNEQUAL_NULL_PTR(duplicateTokenHandle);
        ASSERT_TRUE(CloseTokenHandle(duplicateTokenHandle));

        WindowsHandle newToken{ nullptr };
        WindowSecurityAttributes tokenAttributes{};
        ASSERT_TRUE(DuplicateSystemToken(tokenHandle, tokenStandardAccess, tokenSpecificAccess, &tokenAttributes, securityImpersonation, securityToken, &newToken));
        ASSERT_UNEQUAL_NULL_PTR(newToken);
        ASSERT_TRUE(CloseTokenHandle(newToken));
    }

    ASSERT_TRUE(CloseTokenHandle(tokenHandle));
}
