///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/09/01 11:06)

#include "WinSocketAcceptTesting.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/Network/Flags/SocketPrototypesFlags.h"
#include "System/Network/SocketPrototypes.h"
#include "System/Network/WindowsSockEx.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::WinSocketAcceptTesting::WinSocketAcceptTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, WinSocketAcceptTesting)

void System::WinSocketAcceptTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(WinSockStartUpTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CreateTcpClientProcessTest);

    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);

    ASSERT_NOT_THROW_EXCEPTION_0(WinSockCleanupTest);
}

void System::WinSocketAcceptTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(AcceptTest);
}

void System::WinSocketAcceptTesting::AcceptTest()
{
    const auto socketHandle = GetWinSocket(ProtocolFamilies::Inet, SocketTypes::Stream, SocketProtocols::Tcp, nullptr, 0, 0);
    ASSERT_TRUE_FAILURE_THROW(IsSocketValid(socketHandle), "����Tcp Socketʧ�ܡ�");

    ASSERT_NOT_THROW_EXCEPTION_1(DoAcceptTest, socketHandle);

    ASSERT_NOT_THROW_EXCEPTION_1(CloseSocketTest, socketHandle);
}

void System::WinSocketAcceptTesting::DoAcceptTest(WinSocket socketHandle)
{
    auto address = AcceptInit(socketHandle);

    int addressLength{ sizeof(address) };

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)

    const auto acceptHandle = WinSocketAccept(socketHandle, reinterpret_cast<WinSockAddress*>(&address), &addressLength, nullptr, 0);

#include SYSTEM_WARNING_POP

    ASSERT_TRUE_FAILURE_THROW(IsSocketValid(acceptHandle), "����Accept Socketʧ�ܡ�");

    ASSERT_NOT_THROW_EXCEPTION_1(RecvTest, acceptHandle);

    ASSERT_NOT_THROW_EXCEPTION_1(CloseSocketTest, acceptHandle);
}

System::WinSockInternetAddress System::WinSocketAcceptTesting::AcceptInit(WinSocket socketHandle)
{
    const auto address = GetAddress(GetTcpPort());

    ASSERT_TRUE(Bind(socketHandle, &address));
    ASSERT_TRUE(Listen(socketHandle, 5));

    GetStream() << "����accept�ȴ��ͻ������ӣ�\n";

    return address;
}

void System::WinSocketAcceptTesting::RecvTest(WinSocket acceptHandle)
{
    BufferType buffer{};

    auto index = 0;
    auto remain = bufferSize - 1;

    while (0 < remain)
    {
        WindowsDWord numberOfBytesRecvd{ 0 };

        const auto recvCount = DoRecvTest(buffer, index, remain, acceptHandle, numberOfBytesRecvd);

        if (recvCount == socketError)
        {
            break;
        }

        remain -= boost::numeric_cast<int>(numberOfBytesRecvd);
        index += boost::numeric_cast<int>(numberOfBytesRecvd);
    }

    const std::string result{ buffer.data() };

    ASSERT_EQUAL(result, "Hello");
}

int System::WinSocketAcceptTesting::DoRecvTest(BufferType& buffer, int index, int remain, WinSocket acceptHandle, WindowsDWord& numberOfBytesRecvd)
{
    WinSockBuf winSockBuf{};
    winSockBuf.buf = &buffer.at(index);
    winSockBuf.len = remain;

    WindowsDWord flags{ 0 };
    const auto recvCount = WinSocketRecv(acceptHandle, &winSockBuf, 1, &numberOfBytesRecvd, &flags, nullptr, nullptr);

    ASSERT_UNEQUAL(recvCount, socketError);

    return recvCount;
}

void System::WinSocketAcceptTesting::PrintTipsMessage()
{
    GetStream() << "�������ʧ�ܻᵼ�����õȴ���\n";
}
