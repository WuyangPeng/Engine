///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/01 15:17)

#include "ProcessTokenTesting.h"
#include "System/Threading/Flags/ThreadToolsFlags.h"
#include "System/Threading/Process.h"
#include "System/Threading/ProcessTools.h"
#include "System/Threading/ThreadTools.h"
#include "System/Windows/Engineering.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::ProcessTokenTesting::ProcessTokenTesting(const OStreamShared& stream)
    : ParentType{ stream },
      tokenStandardAccesses{ TokenStandardAccess::Delete,
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
      processFullPath{ GetEngineeringDirectory() + SYSTEM_TEXT("ProcessTest") + GetEngineeringSuffix() + GetEngineeringExeSuffix() },
      randomEngine{ GetEngineRandomSeed() },
      maxSize{ std::max(tokenStandardAccesses.size(), tokenSpecificAccesses.size()) }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, ProcessTokenTesting)

void System::ProcessTokenTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::ProcessTokenTesting::MainTest()
{
    ASSERT_EXECUTE_LOOP_TESTING_NOT_THROW_EXCEPTION(RandomShuffleFlags);
}

bool System::ProcessTokenTesting::RandomShuffleFlags()
{
    std::ranges::shuffle(tokenStandardAccesses, randomEngine);
    std::ranges::shuffle(tokenSpecificAccesses, randomEngine);

    ASSERT_NOT_THROW_EXCEPTION_0(OpenProcessTokenTest);

    return true;
}

void System::ProcessTokenTesting::OpenProcessTokenTest()
{
    for (auto index = 0u; index < maxSize; ++index)
    {
        ASSERT_NOT_THROW_EXCEPTION_1(DoOpenProcessTokenTest, index);
    }
}

void System::ProcessTokenTesting::DoOpenProcessTokenTest(size_t index)
{
    const auto tokenStandardAccess = tokenStandardAccesses.at(index % tokenStandardAccesses.size());
    const auto tokenSpecificAccess = tokenSpecificAccesses.at(index % tokenSpecificAccesses.size());

    WindowsHandle tokenHandle{ nullptr };
    ASSERT_TRUE(OpenSystemProcessToken(GetCurrentProcessHandle(), tokenStandardAccess, tokenSpecificAccess, &tokenHandle));

    ASSERT_UNEQUAL_NULL_PTR(tokenHandle);

    ASSERT_TRUE(CloseTokenHandle(tokenHandle));
}
