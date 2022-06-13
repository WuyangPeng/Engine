///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/12 18:52)

#include "ProcessTokenTesting.h"
#include "System/Threading/Flags/ThreadToolsFlags.h"
#include "System/Threading/Process.h"
#include "System/Threading/ProcessTools.h"
#include "System/Threading/ThreadTools.h"
#include "System/Windows/Engineering.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using std::max;
using namespace std::literals;

System::ProcessTokenTesting::ProcessTokenTesting(const OStreamShared& stream)
    : ParentType{ stream },
      tokenStandardAccessFlags{ TokenStandardAccess::Delete,
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
      processFullPath{ GetEngineeringDirectory() + SYSTEM_TEXT("ProcessTest"s) + GetEngineeringSuffix() + GetEngineeringExeSuffix() },
      randomEngine{ GetEngineRandomSeed() },
      maxSize{ max(tokenStandardAccessFlags.size(), tokenSpecificAccessFlags.size()) }
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
    shuffle(tokenStandardAccessFlags.begin(), tokenStandardAccessFlags.end(), randomEngine);
    shuffle(tokenSpecificAccessFlags.begin(), tokenSpecificAccessFlags.end(), randomEngine);

    ASSERT_NOT_THROW_EXCEPTION_0(ThreadTest);

    return true;
}

void System::ProcessTokenTesting::ThreadTest()
{
    for (auto index = 0u; index < maxSize; ++index)
    {
        auto tokenStandardAccess = tokenStandardAccessFlags.at(index % tokenStandardAccessFlags.size());
        auto tokenSpecificAccess = tokenSpecificAccessFlags.at(index % tokenSpecificAccessFlags.size());

        WindowsHandle tokenHandle{ nullptr };
        ASSERT_TRUE(OpenSysemProcessToken(GetCurrentProcessHandle(), tokenStandardAccess, tokenSpecificAccess, &tokenHandle));

        ASSERT_UNEQUAL_NULL_PTR(tokenHandle);

        ASSERT_TRUE(CloseTokenHandle(tokenHandle));
    }
}
