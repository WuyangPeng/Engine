/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/05 22:27)

#include "Toolset/System/SystemToolset/SystemToolsetExport.h"

#include "UdpSocketSend.h"
#include "System/Network/Flags/SocketPrototypesFlags.h"
#include "System/Network/SocketPrototypes.h"
#include "Toolset/System/SystemToolset/Helper/SystemToolsetClassInvariantMacro.h"

#include <iostream>

SystemToolset::UdpSocketSend::UdpSocketSend(WinSocket winSocket)
    : ParentType{ winSocket },
      connectParameter{ "Configuration/EnvironmentVariable.json", "UdpPort" }
{
    SYSTEM_TOOLSET_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(SystemToolset, UdpSocketSend)

void SystemToolset::UdpSocketSend::Send()
{
    SYSTEM_TOOLSET_CLASS_IS_VALID_1;

    const auto internetAddress = connectParameter.GetWinSockInternetAddress();

    std::cout << "׼��������Ϣ\n";

    auto ret = 0;
    do
    {
        ret = SendTo(GetWinSocket(), GetBuffer(), System::defaultBufferSize, System::SocketSend::Default, &internetAddress);

    } while (ret == System::socketError);
}
