///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.1.3 (2022/10/27 23:45)

#include "Toolset/System/SystemToolset/SystemToolsetExport.h"

#include "SocketSend.h"
#include "System/Network/SocketPrototypes.h"
#include "Toolset/System/SystemToolset/Helper/SystemToolsetClassInvariantMacro.h"

SystemToolset::SocketSend::SocketSend(WinSocket winSocket) noexcept
    : winSocket{ winSocket },
      buffer{ 'H', 'e', 'l', 'l', 'o' }
{
    SYSTEM_TOOLSET_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

bool SystemToolset::SocketSend::IsValid() const noexcept
{
    if (System::IsSocketValid(winSocket))
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

System::WinSocket SystemToolset::SocketSend::GetWinSocket() const noexcept
{
    SYSTEM_TOOLSET_CLASS_IS_VALID_CONST_1;

    return winSocket;
}

const char* SystemToolset::SocketSend::GetBuffer() const noexcept
{
    SYSTEM_TOOLSET_CLASS_IS_VALID_CONST_1;

    return buffer.data();
}