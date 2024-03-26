/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/05 22:27)

#include "Toolset/System/SystemToolset/SystemToolsetExport.h"

#include "TcpSocketSend.h"
#include "System/Network/Flags/SocketPrototypesFlags.h"
#include "System/Network/SocketPrototypes.h"
#include "Toolset/System/SystemToolset/Helper/SystemToolsetClassInvariantMacro.h"

SystemToolset::TcpSocketSend::TcpSocketSend(WinSocket winSocket) noexcept
    : ParentType{ winSocket }
{
    SYSTEM_TOOLSET_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(SystemToolset, TcpSocketSend)

void SystemToolset::TcpSocketSend::Send() noexcept
{
    SYSTEM_TOOLSET_CLASS_IS_VALID_1;

    auto ret = 0;
    do
    {
        ret = System::Send(GetWinSocket(), GetBuffer(), System::defaultBufferSize, System::SocketSend::Default);

    } while (ret == System::socketError);
}
