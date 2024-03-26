/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/13 16:14)

#include "SelectTesting.h"
#include "System/Network/Flags/SocketPrototypesFlags.h"
#include "System/Network/SocketPrototypes.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

#include <thread>

System::SelectTesting::SelectTesting(const OStreamShared& stream)
    : ParentType{ stream }, winSockFdSet{}, mutex{}
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, SelectTesting)

void System::SelectTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(WinSockStartUpTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CreateTcpClientProcessTest);

    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);

    ASSERT_NOT_THROW_EXCEPTION_0(WinSockCleanupTest);
}

void System::SelectTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(SelectTest);
}

void System::SelectTesting::SelectTest()
{
    const auto socketHandle = CreateTcpSocket();
    ASSERT_TRUE_FAILURE_THROW(IsSocketValid(socketHandle), "����Tcp Socketʧ�ܡ�");

    ASSERT_NOT_THROW_EXCEPTION_1(DoSelectTest, socketHandle);

    ASSERT_NOT_THROW_EXCEPTION_1(CloseSocketTest, socketHandle);
}

void System::SelectTesting::DoSelectTest(WinSocket socketHandle)
{
    std::thread thread{ &ClassType::SelectThreadTest, this };

    auto address = AcceptInit(socketHandle);
    int addressLength{ sizeof(address) };
    const auto acceptHandle = Accept(socketHandle, &address, &addressLength);
    ASSERT_TRUE_FAILURE_THROW(IsSocketValid(acceptHandle), "����Accept Socketʧ�ܡ�");

    ASSERT_NOT_THROW_EXCEPTION_1(WinSockSetFdTest, acceptHandle);

    thread.join();

    ASSERT_NOT_THROW_EXCEPTION_1(CloseSocketTest, acceptHandle);
}

System::WinSockInternetAddress System::SelectTesting::AcceptInit(WinSocket socketHandle)
{
    const auto address = GetAddress(GetTcpPort());

    ASSERT_TRUE(Bind(socketHandle, &address));
    ASSERT_TRUE(Listen(socketHandle, 5));

    return address;
}

void System::SelectTesting::WinSockSetFdTest(WinSocket acceptHandle)
{
    std::lock_guard lockGuard{ mutex };

    WinSockSetFd(acceptHandle, &winSockFdSet);
}

void System::SelectTesting::SelectThreadTest()
{
    for (;;)
    {
        std::lock_guard lockGuard{ mutex };

        auto readWinSockFdSet = winSockFdSet;

        if (const auto result = Select(0, &readWinSockFdSet, nullptr, nullptr, nullptr);
            result != socketError)
        {
            ASSERT_NOT_THROW_EXCEPTION_1(SelectSuccess, readWinSockFdSet);

            break;
        }
    }
}

System::WinSocket System::SelectTesting::GetWinSocket(size_t index) const noexcept
{
#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26482)

    return winSockFdSet.fd_array[index];

#include SYSTEM_WARNING_POP
}

void System::SelectTesting::SelectSuccess(WinSockFdSet& readWinSockFdSet)
{
    for (auto i = 0u; i < winSockFdSet.fd_count; i++)
    {
        ASSERT_NOT_THROW_EXCEPTION_2(DoSelectSuccess, i, readWinSockFdSet);
    }
}

void System::SelectTesting::DoSelectSuccess(size_t index, WinSockFdSet& readWinSockFdSet)
{
    if (WinSockFdIsSet(GetWinSocket(index), &readWinSockFdSet))
    {
        ASSERT_NOT_THROW_EXCEPTION_1(RecvTest, index);

        ASSERT_NOT_THROW_EXCEPTION_1(WinSockFdClearTest, index);
    }
}

void System::SelectTesting::WinSockFdClearTest(size_t index) noexcept
{
    WinSockFdClear(GetWinSocket(index), &winSockFdSet);
}

void System::SelectTesting::RecvTest(size_t index)
{
    CharBufferType buffer{};
    auto count = 0;
    auto remain = defaultBufferSize - 1;

    while (0 < remain)
    {
        const auto recvCount = Recv(GetWinSocket(index), &buffer.at(count), remain, SocketReceive::Default);

        ASSERT_UNEQUAL(recvCount, socketError);

        if (recvCount == socketError)
        {
            break;
        }

        remain -= recvCount;
        count += recvCount;
    }

    const std::string recvResult{ buffer.data() };

    ASSERT_EQUAL(recvResult, "Hello");
}
