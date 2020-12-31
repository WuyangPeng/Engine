//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/28 13:41)

#ifndef SYSTEM_HELPER_PRAGMA_WARNING_ACE_H
#define SYSTEM_HELPER_PRAGMA_WARNING_ACE_H

#ifdef NETWORK_USE_ACE

    #include "System/Helper/PragmaWarning.h"

    #include STSTEM_WARNING_PUSH

    #if defined(NDEBUG)
        #include SYSTEM_WARNING_DISABLE(4996)
    #endif  // defined(NDEBUG)

    #include SYSTEM_WARNING_DISABLE(6320)
    #include SYSTEM_WARNING_DISABLE(6387)
    #include SYSTEM_WARNING_DISABLE(26400)
    #include SYSTEM_WARNING_DISABLE(26401)
    #include SYSTEM_WARNING_DISABLE(26409)
    #include SYSTEM_WARNING_DISABLE(26429)
    #include SYSTEM_WARNING_DISABLE(26432)
    #include SYSTEM_WARNING_DISABLE(26440)
    #include SYSTEM_WARNING_DISABLE(26446)
    #include SYSTEM_WARNING_DISABLE(26447)
    #include SYSTEM_WARNING_DISABLE(26451)
    #include SYSTEM_WARNING_DISABLE(26455)
    #include SYSTEM_WARNING_DISABLE(26460)
    #include SYSTEM_WARNING_DISABLE(26461)
    #include SYSTEM_WARNING_DISABLE(26465)
    #include SYSTEM_WARNING_DISABLE(26471)
    #include SYSTEM_WARNING_DISABLE(26472)
    #include SYSTEM_WARNING_DISABLE(26473)
    #include SYSTEM_WARNING_DISABLE(26474)
    #include SYSTEM_WARNING_DISABLE(26476)
    #include SYSTEM_WARNING_DISABLE(26477)
    #include SYSTEM_WARNING_DISABLE(26481)
    #include SYSTEM_WARNING_DISABLE(26482)
    #include SYSTEM_WARNING_DISABLE(26485)
    #include SYSTEM_WARNING_DISABLE(26486)
    #include SYSTEM_WARNING_DISABLE(26487)
    #include SYSTEM_WARNING_DISABLE(26489)
    #include SYSTEM_WARNING_DISABLE(26490)
    #include SYSTEM_WARNING_DISABLE(26492)
    #include SYSTEM_WARNING_DISABLE(26493)
    #include SYSTEM_WARNING_DISABLE(26494)
    #include SYSTEM_WARNING_DISABLE(26496)
    #include SYSTEM_WARNING_DISABLE(26497)
    #include SYSTEM_WARNING_DISABLE(26812)
    #include SYSTEM_WARNING_DISABLE(26814)
    #include SYSTEM_WARNING_DISABLE(26818)

    #include <ace/Handle_Set.h>
    #include <ace/INET_Addr.h>
    #include <ace/OS_main.h>
    #include <ace/SOCK_Acceptor.h>
    #include <ace/SOCK_Connector.h>
    #include <ace/SOCK_Stream.h>

    #include STSTEM_WARNING_POP

#endif  // NETWORK_USE_ACE

#endif  // SYSTEM_HELPER_PRAGMA_WARNING_ACE_H
