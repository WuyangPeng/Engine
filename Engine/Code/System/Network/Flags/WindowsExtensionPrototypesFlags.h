/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/03 20:37)

#ifndef SYSTEM_NETWORK_WINDOWS_EXTENSION_PROTOTYPES_FLAGS_H
#define SYSTEM_NETWORK_WINDOWS_EXTENSION_PROTOTYPES_FLAGS_H

#include "System/Helper/Platform.h"

#ifdef SYSTEM_PLATFORM_WIN32

    #include <WinSock2.h>

#endif  // SYSTEM_PLATFORM_WIN32

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32

    enum class WinSockStartUpReturn
    {
        Successful = 0L,
        SysNotReady = WSASYSNOTREADY,
        VerNotSupported = WSAVERNOTSUPPORTED,
        EInProgress = WSAEINPROGRESS,
        EProcLim = WSAEPROCLIM,
        EFault = WSAEFAULT,
    };

    enum class WinSockCleanupReturn
    {
        Successful = 0L,
        NotInitialised = WSANOTINITIALISED,
        ENetDown = WSAENETDOWN,
        EInProgress = WSAEINPROGRESS,
    };

    enum class WinSockLastError
    {
        ErrorSuccess = ERROR_SUCCESS,
        BaseErr = WSABASEERR,
        EInterrupted = WSAEINTR,
        EBadFile = WSAEBADF,
        EAccess = WSAEACCES,
        EFault = WSAEFAULT,
        EInvalid = WSAEINVAL,
        EmFile = WSAEMFILE,
        EWouldBlock = WSAEWOULDBLOCK,
        EInProgress = WSAEINPROGRESS,
        EAlready = WSAEALREADY,
        ENotSock = WSAENOTSOCK,
        EDestAddressReq = WSAEDESTADDRREQ,
        EMsgSize = WSAEMSGSIZE,
        EProtoType = WSAEPROTOTYPE,
        ENoProtoOpt = WSAENOPROTOOPT,
        EProtoNoSupport = WSAEPROTONOSUPPORT,
        ESockTNoSupport = WSAESOCKTNOSUPPORT,
        EOpNotSupp = WSAEOPNOTSUPP,
        EPfNoSupport = WSAEPFNOSUPPORT,
        EAfNoSupport = WSAEAFNOSUPPORT,
        EAddressInUse = WSAEADDRINUSE,
        EAddressNotAvail = WSAEADDRNOTAVAIL,
        ENetDown = WSAENETDOWN,
        ENetUnReach = WSAENETUNREACH,
        ENetReset = WSAENETRESET,
        EConnAborted = WSAECONNABORTED,
        EConnReset = WSAECONNRESET,
        ENoBuffers = WSAENOBUFS,
        EIsConn = WSAEISCONN,
        ENotConn = WSAENOTCONN,
        EShutDown = WSAESHUTDOWN,
        ETooManyRefs = WSAETOOMANYREFS,
        ETimeDOut = WSAETIMEDOUT,
        EConnRefUsed = WSAECONNREFUSED,
        ELoop = WSAELOOP,
        ENameTooLong = WSAENAMETOOLONG,
        EHostDown = WSAEHOSTDOWN,
        EHostUnReach = WSAEHOSTUNREACH,
        ENotEmpty = WSAENOTEMPTY,
        EProcLim = WSAEPROCLIM,
        EUsers = WSAEUSERS,
        EDiskQuot = WSAEDQUOT,
        EStale = WSAESTALE,
        ERemote = WSAEREMOTE,
        SysNotReady = WSASYSNOTREADY,
        VerNotSupported = WSAVERNOTSUPPORTED,
        NotInitialised = WSANOTINITIALISED,
        EDisconnection = WSAEDISCON,
        NoMore = WSAENOMORE,
        Cancelled = WSAECANCELLED,
        EInvalidProcTable = WSAEINVALIDPROCTABLE,
        EInvalidProvider = WSAEINVALIDPROVIDER,
        EProviderFailedInit = WSAEPROVIDERFAILEDINIT,
        SysCallFailure = WSASYSCALLFAILURE,
        ServiceNotFound = WSASERVICE_NOT_FOUND,
        TypeNotFound = WSATYPE_NOT_FOUND,
        ENoMore = WSA_E_NO_MORE,
        ECancelled = WSA_E_CANCELLED,
        ERefused = WSAEREFUSED,
        HostNotFound = WSAHOST_NOT_FOUND,
        TryAgain = WSATRY_AGAIN,
        NoRecovery = WSANO_RECOVERY,
        NoData = WSANO_DATA,
        QosReceivers = WSA_QOS_RECEIVERS,
        QosSenders = WSA_QOS_SENDERS,
        QosNoSenders = WSA_QOS_NO_SENDERS,
        QosNoReceivers = WSA_QOS_NO_RECEIVERS,
        QosRequestConfirmed = WSA_QOS_REQUEST_CONFIRMED,
        QosAdmissionFailure = WSA_QOS_ADMISSION_FAILURE,
        QosPolicyFailure = WSA_QOS_POLICY_FAILURE,
        QosBadStyle = WSA_QOS_BAD_STYLE,
        QosBadObject = WSA_QOS_BAD_OBJECT,
        QosTrafficCtrlError = WSA_QOS_TRAFFIC_CTRL_ERROR,
        QosGenericError = WSA_QOS_GENERIC_ERROR,
        QosEServiceType = WSA_QOS_ESERVICETYPE,
        QosEFlowSpec = WSA_QOS_EFLOWSPEC,
        QosEProvSpecBuf = WSA_QOS_EPROVSPECBUF,
        QosEFilterStyle = WSA_QOS_EFILTERSTYLE,
        QosEFilterType = WSA_QOS_EFILTERTYPE,
        QosEFilterCount = WSA_QOS_EFILTERCOUNT,
        QosEObjLength = WSA_QOS_EOBJLENGTH,
        QosEFlowCount = WSA_QOS_EFLOWCOUNT,
        QosEUnknownPsObj = WSA_QOS_EUNKOWNPSOBJ,
        QosEPolicyObj = WSA_QOS_EPOLICYOBJ,
        QosEFlowDesc = WSA_QOS_EFLOWDESC,
        QosEpsFlowSpec = WSA_QOS_EPSFLOWSPEC,
        QosEpsFilterSpec = WSA_QOS_EPSFILTERSPEC,
        QosESdModeObj = WSA_QOS_ESDMODEOBJ,
        QosEShapeRateObj = WSA_QOS_ESHAPERATEOBJ,
        QosReservedPeType = WSA_QOS_RESERVED_PETYPE,
        SecureHostNotFound = WSA_SECURE_HOST_NOT_FOUND,
        IpsecNamePolicyError = WSA_IPSEC_NAME_POLICY_ERROR,
    };

    enum class WinSockSelectEvent
    {
        Connect = FD_CONNECT,
        Close = FD_CLOSE,
        Accept = FD_ACCEPT,
        AddressListChange = FD_ADDRESS_LIST_CHANGE,
        GroupQos = FD_GROUP_QOS,
        Oob = FD_OOB,
        Qos = FD_QOS,
        Read = FD_READ,
        Write = FD_WRITE,
        RoutingInterfaceChange = FD_ROUTING_INTERFACE_CHANGE,
        AllEvents = FD_ALL_EVENTS,
    };

#else  // !SYSTEM_PLATFORM_WIN32

    enum class WinSockStartUpReturn
    {
        Successful = 0L,
        SysNotReady = 10091L,
        VerNotSupported = 10092L,
        EInProgress = 10036L,
        EProcLim = 10067L,
        EFault = 10014L,
    };

    enum class WinSockCleanupReturn
    {
        Successful = 0L,
        NotInitialised = 10093L,
        ENetDown = 10050L,
        EInProgress = 10036L,
    };

    enum class WinSockLastError
    {
        ErrorSuccess = 0,
        BaseErr = 10000,
        EInterrupted = 10004L,
        EBadFile = 10009L,
        EAccess = 10013L,
        EFault = 10014L,
        EInvalid = 10022L,
        EmFile = 10024L,
        EWouldBlock = 10035L,
        EInProgress = 10036L,
        EAlready = 10037L,
        ENotSock = 10038L,
        EDestAddressReq = 10039L,
        EMsgSize = 10040L,
        EProtoType = 10041L,
        ENoProtoOpt = 10042L,
        EProtoNoSupport = 10043L,
        ESockTNoSupport = 10044L,
        EOpNotSupp = 10045L,
        EPfNoSupport = 10046L,
        EAfNoSupport = 10047L,
        EAddressInUse = 10048L,
        EAddressNotAvail = 10049L,
        ENetDown = 10050L,
        ENetUnReach = 10051L,
        ENetReset = 10052L,
        EConnAborted = 10053L,
        EConnReset = 10054L,
        ENoBuffers = 10055L,
        EIsConn = 10056L,
        ENotConn = 10057L,
        EShutDown = 10058L,
        ETooManyRefs = 10059L,
        ETimeDOut = 10060L,
        EConnRefUsed = 10061L,
        ELoop = 10062L,
        ENameTooLong = 10063L,
        EHostDown = 10064L,
        EHostUnReach = 10065L,
        ENotEmpty = 10066L,
        EProcLim = 10067L,
        EUsers = 10068L,
        EDiskQuot = 10069L,
        EStale = 10070L,
        ERemote = 10071L,
        SysNotReady = 10091L,
        VerNotSupported = 10092L,
        NotInitialised = 10093L,
        EDisconnection = 10101L,
        NoMore = 10102L,
        Cancelled = 10103L,
        EInvalidProcTable = 10104L,
        EInvalidProvider = 10105L,
        EProviderFailedInit = 10106L,
        SysCallFailure = 10107L,
        ServiceNotFound = 10108L,
        TypeNotFound = 10109L,
        ENoMore = 10110L,
        ECancelled = 10111L,
        ERefused = 10112L,
        HostNotFound = 11001L,
        TryAgain = 11002L,
        NoRecovery = 11003L,
        NoData = 11004L,
        QosReceivers = 11005L,
        QosSenders = 11006L,
        QosNoSenders = 11007L,
        QosNoReceivers = 11008L,
        QosRequestConfirmed = 11009L,
        QosAdmissionFailure = 11010L,
        QosPolicyFailure = 11011L,
        QosBadStyle = 11012L,
        QosBadObject = 11013L,
        QosTrafficCtrlError = 11014L,
        QosGenericError = 11015L,
        QosEServiceType = 11016L,
        QosEFlowSpec = 11017L,
        QosEProvSpecBuf = 11018L,
        QosEFilterStyle = 11019L,
        QosEFilterType = 11020L,
        QosEFilterCount = 11021L,
        QosEObjLength = 11022L,
        QosEFlowCount = 11023L,
        QosEUnknownPsObj = 11024L,
        QosEPolicyObj = 11025L,
        QosEFlowDesc = 11026L,
        QosEpsFlowSpec = 11027L,
        QosEpsFilterSpec = 11028L,
        QosESdModeObj = 11029L,
        QosEShapeRateObj = 11030L,
        QosReservedPeType = 11031L,
        SecureHostNotFound = 11032L,
        IpsecNamePolicyError = 11033L,
    };

    enum class WinSockSelectEvent
    {
        Connect = 0x10,
        Close = 0x20,
        Accept = 0x08,
        AddressListChange = (1 << 9),
        GroupQos = (1 << 7),
        Oob = 0x04,
        Qos = (1 << 6),
        Read = 0x01,
        Write = 0x02,
        RoutingInterfaceChange = (1 << 8),
        AllEvents = ((1 << 10) - 1),
    };

#endif  // SYSTEM_PLATFORM_WIN32
}

#endif  // SYSTEM_NETWORK_WINDOWS_EXTENSION_PROTOTYPES_FLAGS_H
