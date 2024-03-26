/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/13 16:16)

#include "WinSocketSendToTesting.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/Helper/PragmaWarning/PropertyTree.h"
#include "System/Helper/WindowsMacro.h"
#include "System/Network/Flags/SocketPrototypesFlags.h"
#include "System/Network/SocketPrototypes.h"
#include "System/Network/WindowsExtensionPrototypes.h"
#include "System/Network/WindowsSockEx.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::WinSocketSendToTesting::WinSocketSendToTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, WinSocketSendToTesting)

void System::WinSocketSendToTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(WinSockStartUpTest);

    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);

    ASSERT_NOT_THROW_EXCEPTION_0(WinSockCleanupTest);
}

void System::WinSocketSendToTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(SendToTest);
}

void System::WinSocketSendToTesting::SendToTest()
{
    const auto socketHandle = GetWinSocket(ProtocolFamilies::Inet, SocketTypes::Dgram, SocketProtocols::Udp, nullptr, 0, 0);
    ASSERT_TRUE_FAILURE_THROW(IsSocketValid(socketHandle), "����Udp Socketʧ�ܡ�");

    ASSERT_NOT_THROW_EXCEPTION_1(DoSendToTest, socketHandle);

    ASSERT_NOT_THROW_EXCEPTION_1(CloseSocketTest, socketHandle);
}

void System::WinSocketSendToTesting::DoSendToTest(WinSocket socketHandle)
{
    const auto serverHostname = CoreTools::StringConversion::StandardConversionMultiByte(GetConnectHostname());

    const auto address = GetAddress(80, serverHostname);

    std::string sendMessage{ "GET /index.html HTTP/1.0\r\n\r\n" };

    MessageType iov{ sendMessage.begin(), sendMessage.end() };

    ASSERT_NOT_THROW_EXCEPTION_3(ResultTest, socketHandle, address, iov);
}

void System::WinSocketSendToTesting::ResultTest(WinSocket socketHandle, const WinSockInternetAddress& address, MessageType& iov)
{
    uint32_t sendNum{ 0 };

    do
    {
        WindowsDWord numberOfBytesSent{};

        if (const auto sendResult = WinSocketSendToTest(iov, sendNum, socketHandle, address, numberOfBytesSent);
            sendResult == 0)
        {
            sendNum += numberOfBytesSent;
        }
        else
        {
            break;
        }

    } while (sendNum < iov.size());
}

int System::WinSocketSendToTesting::WinSocketSendToTest(MessageType& iov, uint32_t sendNum, WinSocket socketHandle, WinSockInternetAddress address, WindowsDWord& numberOfBytesSent)
{
    WinSockBuf buffer{};
    buffer.buf = &iov.at(sendNum);
    buffer.len = boost::numeric_cast<uint32_t>(iov.size() - sendNum);

    constexpr int length{ sizeof(WinSockInternetAddress) };

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)

    const auto sendResult = WinSocketSendTo(socketHandle, &buffer, 1, &numberOfBytesSent, 0, reinterpret_cast<const WinSockAddress*>(&address), length, nullptr, nullptr);

#include SYSTEM_WARNING_POP

    return sendResult;
}
