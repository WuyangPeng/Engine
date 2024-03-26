/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/05 22:25)

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
    return System::IsSocketValid(winSocket);
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
