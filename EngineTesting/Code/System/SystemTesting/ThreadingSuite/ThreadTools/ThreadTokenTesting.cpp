/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/12 18:19)

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

System::ThreadTokenTesting::ThreadTokenTesting(const OStreamShared& stream)
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
      randomEngine{ GetEngineRandomSeed() },
      maxSize{ std::max(tokenStandardAccesses.size(), tokenSpecificAccesses.size()) }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
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
    std::ranges::shuffle(tokenStandardAccesses, randomEngine);
    std::ranges::shuffle(tokenSpecificAccesses, randomEngine);

    ASSERT_NOT_THROW_EXCEPTION_0(ThreadTest);

    return true;
}

void System::ThreadTokenTesting::ThreadTest()
{
    const auto mutexHandle = CreateSystemMutex(nullptr, false, nullptr);
    ASSERT_NOT_THROW_EXCEPTION_1(DoThreadTest, mutexHandle);

    ASSERT_NOT_THROW_EXCEPTION_1(CloseMutexTest, mutexHandle);
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
    std::ignore = WaitForSystemMutex(threadParameter);

    std::ignore = ReleaseSystemMutex(threadParameter);

    return exitFunctionCode;
}

void System::ThreadTokenTesting::DoThreadTest(ThreadHandle mutexHandle)
{
#ifdef SYSTEM_PLATFORM_WIN32

    ASSERT_TRUE(IsSystemMutexValid(mutexHandle));

    ASSERT_TRUE(WaitForSystemMutex(mutexHandle));

    ASSERT_TRUE(ImpersonateThreadSelf(SecurityImpersonation));

    WindowsDWord threadId{ 0 };
    const auto threadHandle = CreateSystemThread(nullptr, 0, ClassType::ThreadStartRoutine, this, ThreadCreation::Default, &threadId);

    ASSERT_NOT_THROW_EXCEPTION_3(TokenThreadTest, threadHandle, threadId, mutexHandle);

    ASSERT_NOT_THROW_EXCEPTION_1(CloseThreadTest, threadHandle);

#endif  // !SYSTEM_PLATFORM_WIN32
}

void System::ThreadTokenTesting::TokenThreadTest(ThreadHandle threadHandle, WindowsDWord threadId, ThreadHandle mutexHandle)
{
#ifdef SYSTEM_PLATFORM_WIN32

    ASSERT_TRUE(IsThreadHandleValid(threadHandle));
    ASSERT_LESS(0u, threadId);

    for (auto index = 0u; index < maxSize; ++index)
    {
        ASSERT_NOT_THROW_EXCEPTION_2(DoTokenThreadTest, index, threadHandle);
    }

    ASSERT_TRUE(ReleaseSystemMutex(mutexHandle));
    ASSERT_TRUE(WaitForSystemThread(threadHandle));

#endif  // !SYSTEM_PLATFORM_WIN32
}

void System::ThreadTokenTesting::DoTokenThreadTest(size_t index, ThreadHandle threadHandle)
{
    const auto tokenStandardAccess = tokenStandardAccesses.at(index % tokenStandardAccesses.size());
    const auto tokenSpecificAccess = tokenSpecificAccesses.at(index % tokenSpecificAccesses.size());

    ASSERT_NOT_THROW_EXCEPTION_3(TokenTest, threadHandle, tokenStandardAccess, tokenSpecificAccess);
}
