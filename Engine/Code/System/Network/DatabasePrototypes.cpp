///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.7.1.4 (2021/06/04 14:51)

#include "System/SystemExport.h"

#include "DatabasePrototypes.h"
#include "Using/SocketPrototypesUsing.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/PragmaWarning.h"

System::WinSockHostent* System::GetHostByAddr(const WinSockInAddr* addr, ProtocolFamilies type) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    #include STSTEM_WARNING_PUSH
    #include SYSTEM_WARNING_DISABLE(4996)
    #include SYSTEM_WARNING_DISABLE(26490)

    return ::gethostbyaddr(reinterpret_cast<const char*>(addr), sizeof(WinSockInAddr), EnumCastUnderlying(type));

    #include STSTEM_WARNING_POP

#else  // !SYSTEM_PLATFORM_WIN32

    NullFunction<const WinSockInAddr*, ProtocolFamilies>(addr, type);

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

    NullFunction<const char*>(name);

    return nullptr;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::GetHostName(char* name, int namelen) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::gethostname(name, namelen) != g_SocketError)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    NullFunction<char*>(name, namelen);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WinSockServent* System::GetServentByPort(int port, const char* proto) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::getservbyport(port, proto);

#else  // !SYSTEM_PLATFORM_WIN32

    NullFunction<int, const char*>(port, proto);

    return nullptr;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WinSockServent* System::GetServentByName(const char* name, const char* proto) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::getservbyname(name, proto);

#else  // !SYSTEM_PLATFORM_WIN32

    NullFunction<const char*, const char*>(name, proto);

    return nullptr;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WinSockProtoent* System::GetProtoentByNumber(int proto) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::getprotobynumber(proto);

#else  // !SYSTEM_PLATFORM_WIN32

    NullFunction<int>(proto);

    return nullptr;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WinSockProtoent* System::GetProtoentByName(const char* name) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::getprotobyname(name);

#else  // !SYSTEM_PLATFORM_WIN32

    NullFunction<const char*>(name);

    return nullptr;

#endif  // SYSTEM_PLATFORM_WIN32
}
