///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/28 10:20)

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
    SYSTEM_TOOLSET_CLASS_IS_VALID_CONST_1;

    auto ret = 0;
    do
    {
        ret = System::Send(GetWinSocket(), GetBuffer(), bufferSize, System::SocketSend::Default);

    } while (ret == System::socketError);
}
