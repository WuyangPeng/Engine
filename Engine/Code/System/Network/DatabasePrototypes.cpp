///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/08/29 17:46)

#include "System/SystemExport.h"

#include "DatabasePrototypes.h"
#include "Using/SocketPrototypesUsing.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/PragmaWarning.h"
#include "System/Helper/Tools.h"

System::WinSockHostEnt* System::GetHostByAddress(const InternetAddress* address, ProtocolFamilies type) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    #include SYSTEM_WARNING_PUSH
    #include SYSTEM_WARNING_DISABLE(4996)
    #include SYSTEM_WARNING_DISABLE(26490)

    return ::gethostbyaddr(reinterpret_cast<const char*>(address), sizeof(InternetAddress), EnumCastUnderlying(type));

    #include SYSTEM_WARNING_POP

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(address, type);

    return nullptr;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WinSockHostEnt* System::GetHostByName(const char* name) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    #include SYSTEM_WARNING_PUSH
    #include SYSTEM_WARNING_DISABLE(4996)

    return ::gethostbyname(name);

    #include SYSTEM_WARNING_POP

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(name);

    return nullptr;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::GetHostName(char* name, int nameLength) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::gethostname(name, nameLength) != socketError)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(name, nameLength);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WinSockServEnt* System::GetServerByPort(int port, const char* proto) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::getservbyport(port, proto);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(port, proto);

    return nullptr;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WinSockServEnt* System::GetServerByName(const char* name, const char* proto) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::getservbyname(name, proto);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(name, proto);

    return nullptr;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WinSockProtoEnt* System::GetProtoByNumber(int proto) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::getprotobynumber(proto);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(proto);

    return nullptr;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WinSockProtoEnt* System::GetProtoByName(const char* name) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::getprotobyname(name);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(name);

    return nullptr;

#endif  // SYSTEM_PLATFORM_WIN32
}
