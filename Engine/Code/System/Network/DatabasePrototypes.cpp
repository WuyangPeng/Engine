//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/24 18:05)

#include "System/SystemExport.h"

#include "DatabasePrototypes.h"
#include "Using/SocketPrototypesUsing.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/PragmaWarning.h"

System::WinSockHostent* System::GetHostByAddr([[maybe_unused]] const WinSockInAddr* addr, [[maybe_unused]] ProtocolFamilies type) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    #include STSTEM_WARNING_PUSH
    #include SYSTEM_WARNING_DISABLE(4996)
    #include SYSTEM_WARNING_DISABLE(26490)

    return ::gethostbyaddr(reinterpret_cast<const char*>(addr), sizeof(WinSockInAddr), EnumCastUnderlying(type));

    #include STSTEM_WARNING_POP

#else  // !SYSTEM_PLATFORM_WIN32
    return nullptr;
#endif  // SYSTEM_PLATFORM_WIN32
}

System::WinSockHostent* System::GetHostByName([[maybe_unused]] const char* name) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    #include STSTEM_WARNING_PUSH
    #include SYSTEM_WARNING_DISABLE(4996)

    return ::gethostbyname(name);

    #include STSTEM_WARNING_POP

#else  // !SYSTEM_PLATFORM_WIN32
    return nullptr;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::GetHostName([[maybe_unused]] char* name, [[maybe_unused]] int namelen) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::gethostname(name, namelen) != g_SocketError)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

System::WinSockServent* System::GetServentByPort([[maybe_unused]] int port, [[maybe_unused]] const char* proto) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return ::getservbyport(port, proto);
#else  // !SYSTEM_PLATFORM_WIN32
    return nullptr;
#endif  // SYSTEM_PLATFORM_WIN32
}

System::WinSockServent* System::GetServentByName([[maybe_unused]] const char* name, [[maybe_unused]] const char* proto) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return ::getservbyname(name, proto);
#else  // !SYSTEM_PLATFORM_WIN32
    return nullptr;
#endif  // SYSTEM_PLATFORM_WIN32
}

System::WinSockProtoent* System::GetProtoentByNumber([[maybe_unused]] int proto) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return ::getprotobynumber(proto);
#else  // !SYSTEM_PLATFORM_WIN32
    return nullptr;
#endif  // SYSTEM_PLATFORM_WIN32
}

System::WinSockProtoent* System::GetProtoentByName([[maybe_unused]] const char* name) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return ::getprotobyname(name);
#else  // !SYSTEM_PLATFORM_WIN32
    return nullptr;
#endif  // SYSTEM_PLATFORM_WIN32
}
