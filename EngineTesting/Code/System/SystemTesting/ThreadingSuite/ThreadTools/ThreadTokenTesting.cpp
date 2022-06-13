///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/12 18:58)

#include "ThreadTokenTesting.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/Threading/Flags/ThreadFlags.h"
#include "System/Threading/Flags/ThreadToolsFlags.h"
#include "System/Threading/Mutex.h"
#include "System/Threading/Thread.h"
#include "System/Threading/ThreadTools.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using std::max;

System::ThreadTokenTesting::ThreadTokenTesting(const OStreamShared& stream)
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
      randomEngine{ GetEngineRandomSeed() },
      maxSize{ max(tokenStandardAccessFlags.size(), tokenSpecificAccessFlags.size()) }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, ThreadTokenTesting)

void System::ThreadTokenTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::ThreadTokenTesting::MainTest()
{
    ASSERT_EXECUTE_LOOP_TESTING_NOT_THROW_EXCEPTION(RandomShuffleFlags);
}

bool System::ThreadTokenTesting::RandomShuffleFlags()
{
    shuffle(tokenStandardAccessFlags.begin(), tokenStandardAccessFlags.end(), randomEngine);
    shuffle(tokenSpecificAccessFlags.begin(), tokenSpecificAccessFlags.end(), randomEngine);

    ASSERT_NOT_THROW_EXCEPTION_0(ThreadTest);

    return true;
}

void System::ThreadTokenTesting::ThreadTest()
{
    auto mutexHandle = CreateSystemMutex(nullptr, false, nullptr);
    ASSERT_TRUE(IsSystemMutexValid(mutexHandle));

    ASSERT_TRUE(WaitForSystemMutex(mutexHandle));

    ASSERT_TRUE(ImpersonateThreadSelf(SecurityImpersonation));

    WindowsDWord threadID{ 0 };
    auto threadHandle = CreateSystemThread(nullptr, 0, ClassType::ThreadStartRoutine, this, ThreadCreation::Default, &threadID);

    ASSERT_TRUE(IsThreadHandleValid(threadHandle));
    ASSERT_LESS(0u, threadID);

    for (auto index = 0u; index < maxSize; ++index)
    {
        auto tokenStandardAccess = tokenStandardAccessFlags.at(index % tokenStandardAccessFlags.size());
        auto tokenSpecificAccess = tokenSpecificAccessFlags.at(index % tokenSpecificAccessFlags.size());

        TokenTest(threadHandle, tokenStandardAccess, tokenSpecificAccess);
    }

    ASSERT_TRUE(ReleaseSystemMutex(mutexHandle));
    ASSERT_TRUE(WaitForSystemThread(threadHandle));

    ASSERT_TRUE(CloseSystemThread(threadHandle));
    ASSERT_TRUE(CloseSystemMutex(mutexHandle));
}

void System::ThreadTokenTesting::TokenTest(ThreadHandle threadHandle, TokenStandardAccess tokenStandardAccess, TokenSpecificAccess tokenSpecificAccess)
{
    WindowsHandle tokenHandle{ nullptr };
    ASSERT_TRUE(OpenSystemThreadToken(GetCurrentSystemThread(), tokenStandardAccess, tokenSpecificAccess, true, &tokenHandle));

    if (tokenSpecificAccess == TokenSpecificAccess::Impersonate)
    {
        ASSERT_TRUE(SetSystemThreadToken(&threadHandle, tokenHandle));
    }

    ASSERT_TRUE(CloseTokenHandle(tokenHandle));
}

System::WindowsDWord System::ThreadTokenTesting::ThreadStartRoutine(void* threadParameter) noexcept
{
    MAYBE_UNUSED const auto waitResult = WaitForSystemMutex(threadParameter);

    MAYBE_UNUSED const auto releaseResult = ReleaseSystemMutex(threadParameter);

    return 1u;
}