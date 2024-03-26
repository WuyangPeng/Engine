/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/13 16:12)

#include "AcceptTesting.h"
#include "System/Network/Flags/SocketPrototypesFlags.h"
#include "System/Network/SocketPrototypes.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::AcceptTesting::AcceptTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, AcceptTesting)

void System::AcceptTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(WinSockStartUpTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CreateTcpClientProcessTest);

    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);

    ASSERT_NOT_THROW_EXCEPTION_0(WinSockCleanupTest);
}

void System::AcceptTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(AcceptTest);
}

void System::AcceptTesting::PrintTipsMessage()
{
    GetStream() << "�������ʧ�ܻᵼ�����õȴ���\n";
}

void System::AcceptTesting::AcceptTest()
{
    const auto socketHandle = CreateTcpSocket();
    ASSERT_TRUE_FAILURE_THROW(IsSocketValid(socketHandle), "����Tcp Socketʧ�ܡ�");

    ASSERT_NOT_THROW_EXCEPTION_1(DoAcceptTest, socketHandle);

    ASSERT_NOT_THROW_EXCEPTION_1(CloseSocketTest, socketHandle);
}

void System::AcceptTesting::DoAcceptTest(WinSocket socketHandle)
{
    auto address = AcceptInit(socketHandle);

    int addressLength{ sizeof(address) };
    const auto acceptHandle = Accept(socketHandle, &address, &addressLength);
    ASSERT_TRUE_FAILURE_THROW(IsSocketValid(acceptHandle), "����Accept Socketʧ�ܡ�");

    ASSERT_NOT_THROW_EXCEPTION_1(RecvTest, acceptHandle);

    ASSERT_NOT_THROW_EXCEPTION_1(CloseSocketTest, acceptHandle);
}

System::WinSockInternetAddress System::AcceptTesting::AcceptInit(WinSocket socketHandle)
{
    const auto address = GetAddress(GetTcpPort());

    ASSERT_TRUE(Bind(socketHandle, &address));
    ASSERT_TRUE(Listen(socketHandle, 5));

    GetStream() << "����accept�ȴ��ͻ������ӣ�\n";

    return address;
}

void System::AcceptTesting::RecvTest(WinSocket acceptHandle)
{
    CharBufferType buffer{};
    auto index = 0;
    auto remain = defaultBufferSize - 1;

    while (0 < remain)
    {
        const auto recvCount = DoRecvTest(acceptHandle, index, remain, buffer);

        if (recvCount == socketError)
        {
            break;
        }

        remain -= recvCount;
        index += recvCount;
    }

    const std::string result{ buffer.data() };

    ASSERT_EQUAL(result, "Hello");
}

int System::AcceptTesting::DoRecvTest(WinSocket acceptHandle, int index, int remain, CharBufferType& buffer)
{
    const auto recvCount = Recv(acceptHandle, &buffer.at(index), remain, SocketReceive::Default);

    ASSERT_UNEQUAL(recvCount, socketError);

    return recvCount;
}
