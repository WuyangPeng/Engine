///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.0 (2023/01/07 13:46)

#include "System/SystemExport.h"

#include "DatabasePrototypes.h"
#include "Using/SocketPrototypesUsing.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/PragmaWarning.h"

System::WinSockHostent* System::GetHostByAddress(const InternetAddress* address, ProtocolFamilies type) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    #include STSTEM_WARNING_PUSH
    #include SYSTEM_WARNING_DISABLE(4996)
    #include SYSTEM_WARNING_DISABLE(26490)

    return ::gethostbyaddr(reinterpret_cast<const char*>(address), sizeof(InternetAddress), EnumCastUnderlying(type));

    #include STSTEM_WARNING_POP

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(address, type);

    return nullptr;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WinSockHostent* System::GetHostByName(const char* name) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    #include STSTEM_WARNING_PUSH
    #include SYSTEM_WARNING_DISABLE(4996)

    return ::gethostbyname(name);

    #include STSTEM_WARNING_POP

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

    UnusedFunction(name, namelen);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WinSockServent* System::GetServentByPort(int port, const char* proto) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::getservbyport(port, proto);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(port, proto);

    return nullptr;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WinSockServent* System::GetServentByName(const char* name, const char* proto) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::getservbyname(name, proto);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(name, proto);

    return nullptr;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WinSockProtoent* System::GetProtoentByNumber(int proto) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::getprotobynumber(proto);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(proto);

    return nullptr;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WinSockProtoent* System::GetProtoentByName(const char* name) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::getprotobyname(name);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(name);

    return nullptr;

#endif  // SYSTEM_PLATFORM_WIN32
}
