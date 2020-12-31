//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/24 17:59)

#ifndef SYSTEM_NETWORK_WINDOWS_SOCK_EX_FLAGS_H
#define SYSTEM_NETWORK_WINDOWS_SOCK_EX_FLAGS_H

#include "System/Helper/Platform.h"

#ifdef SYSTEM_PLATFORM_WIN32
    #include <WinSock2.h>
#endif  // SYSTEM_PLATFORM_WIN32

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32

    enum class WaitForMultipleEventsReturn : uint32_t
    {
        MaximumWaitEvents = WSA_MAXIMUM_WAIT_EVENTS,
        WaitFailed = WSA_WAIT_FAILED,
        WaitEvent0 = WSA_WAIT_EVENT_0,
        WaitIOCompletion = WSA_WAIT_IO_COMPLETION,
        WaitTimeout = WSA_WAIT_TIMEOUT,
        Infinite = WSA_INFINITE,
    };

    enum class ProtocolInfoService
    {
        Connectionless = XP1_CONNECTIONLESS,
        GuaranteedDelivery = XP1_GUARANTEED_DELIVERY,
        GuaranteedOrder = XP1_GUARANTEED_ORDER,
        MessageOriented = XP1_MESSAGE_ORIENTED,
        PseudoStream = XP1_PSEUDO_STREAM,
        GracefulClose = XP1_GRACEFUL_CLOSE,
        ExpeditedData = XP1_EXPEDITED_DATA,
        ConnectData = XP1_CONNECT_DATA,
        DisconnectData = XP1_DISCONNECT_DATA,
        SsupportBroadcast = XP1_SUPPORT_BROADCAST,
        SupportMultipoint = XP1_SUPPORT_MULTIPOINT,
        MultipointControlPlane = XP1_MULTIPOINT_CONTROL_PLANE,
        MultipointDataPlane = XP1_MULTIPOINT_DATA_PLANE,
        QosSupported = XP1_QOS_SUPPORTED,
        Interrupt = XP1_INTERRUPT,
        UniSend = XP1_UNI_SEND,
        UniRecv = XP1_UNI_RECV,
        IfsHandles = XP1_IFS_HANDLES,
        PartialMessage = XP1_PARTIAL_MESSAGE,
        SanSupportSdp = XP1_SAN_SUPPORT_SDP,
    };

    enum class ProtocolInfoProvider
    {
        MultipleProtoEntries = PFL_MULTIPLE_PROTO_ENTRIES,
        RecommendedProtoEntry = PFL_RECOMMENDED_PROTO_ENTRY,
        Hidden = PFL_HIDDEN,
        MatchesProtocolZero = PFL_MATCHES_PROTOCOL_ZERO,
        NetworkdirectProvider = PFL_NETWORKDIRECT_PROVIDER,
    };

#else  // !SYSTEM_PLATFORM_WIN32

    enum class WaitForMultipleEventsReturn : uint32_t
    {
        MaximumWaitEvents = (64),
        WaitFailed = (0xFFFFFFFF),
        WaitEvent0 = (0),
        WaitIOCompletion = (0x000000C0L),
        WaitTimeout = (258L),
        Infinite = (0xFFFFFFFF),
    };

    enum class ProtocolInfoService
    {
        Connectionless = 0x00000001,
        GuaranteedDelivery = 0x00000002,
        GuaranteedOrder = 0x00000004,
        MessageOriented = 0x00000008,
        PseudoStream = 0x00000010,
        GracefulClose = 0x00000020,
        ExpeditedData = 0x00000040,
        ConnectData = 0x00000080,
        DisconnectData = 0x00000100,
        SsupportBroadcast = 0x00000200,
        SupportMultipoint = 0x00000400,
        MultipointControlPlane = 0x00000800,
        MultipointDataPlane = 0x00001000,
        QosSupported = 0x00002000,
        Interrupt = 0x00004000,
        UniSend = 0x00008000,
        UniRecv = 0x00010000,
        IfsHandles = 0x00020000,
        PartialMessage = 0x00040000,
        SanSupportSdp = 0x00080000,
    };

    enum class ProtocolInfoProvider
    {
        MultipleProtoEntries = 0x00000001,
        RecommendedProtoEntry = 0x00000002,
        Hidden = 0x00000004,
        MatchesProtocolZero = 0x00000008,
        NetworkdirectProvider = 0x00000010,
    };

#endif  // SYSTEM_PLATFORM_WIN32
}

#endif  // SYSTEM_NETWORK_WINDOWS_SOCK_EX_FLAGS_H
