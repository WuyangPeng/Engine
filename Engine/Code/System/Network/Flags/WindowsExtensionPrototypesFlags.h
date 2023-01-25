///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.0 (2023/01/06 23:50)

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
        EIntr = WSAEINTR,
        EBadf = WSAEBADF,
        EAcces = WSAEACCES,
        EFault = WSAEFAULT,
        EInval = WSAEINVAL,
        EMFile = WSAEMFILE,
        EWouldBlock = WSAEWOULDBLOCK,
        EInProgress = WSAEINPROGRESS,
        EAlready = WSAEALREADY,
        ENotSock = WSAENOTSOCK,
        EDestAddrReq = WSAEDESTADDRREQ,
        EMsgSize = WSAEMSGSIZE,
        EProtoType = WSAEPROTOTYPE,
        ENoProtoOpt = WSAENOPROTOOPT,
        EProtoNoSupport = WSAEPROTONOSUPPORT,
        ESocktNoSupport = WSAESOCKTNOSUPPORT,
        EOpNotSupp = WSAEOPNOTSUPP,
        EPfNoSupport = WSAEPFNOSUPPORT,
        EAfNoSupport = WSAEAFNOSUPPORT,
        EAddrInuse = WSAEADDRINUSE,
        EAddrNotAvail = WSAEADDRNOTAVAIL,
        ENetDown = WSAENETDOWN,
        ENetUnreach = WSAENETUNREACH,
        ENetReset = WSAENETRESET,
        EConnAborted = WSAECONNABORTED,
        EConnReset = WSAECONNRESET,
        ENoBufs = WSAENOBUFS,
        EIsConn = WSAEISCONN,
        ENotConn = WSAENOTCONN,
        EShutDown = WSAESHUTDOWN,
        ETooManyRefs = WSAETOOMANYREFS,
        ETimeDout = WSAETIMEDOUT,
        EConnRefUsed = WSAECONNREFUSED,
        ELoop = WSAELOOP,
        ENameTooLong = WSAENAMETOOLONG,
        EHostDown = WSAEHOSTDOWN,
        EHostUnReach = WSAEHOSTUNREACH,
        ENotEmpty = WSAENOTEMPTY,
        EProcLim = WSAEPROCLIM,
        EUsers = WSAEUSERS,
        EDquot = WSAEDQUOT,
        EStale = WSAESTALE,
        ERemote = WSAEREMOTE,
        SysNotReady = WSASYSNOTREADY,
        VerNotSupported = WSAVERNOTSUPPORTED,
        NotInitialised = WSANOTINITIALISED,
        EDiscon = WSAEDISCON,
        NoMore = WSAENOMORE,
        Cancelled = WSAECANCELLED,
        EInvalidProctable = WSAEINVALIDPROCTABLE,
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
        QosEFlowspec = WSA_QOS_EFLOWSPEC,
        QosEProvspecBuf = WSA_QOS_EPROVSPECBUF,
        QosEFilterStyle = WSA_QOS_EFILTERSTYLE,
        QosEFiltertype = WSA_QOS_EFILTERTYPE,
        QosEFilterCount = WSA_QOS_EFILTERCOUNT,
        QosEObjLength = WSA_QOS_EOBJLENGTH,
        QosEFlowCount = WSA_QOS_EFLOWCOUNT,
        QosEUnkownpsObj = WSA_QOS_EUNKOWNPSOBJ,
        QosEPolicyObj = WSA_QOS_EPOLICYOBJ,
        QosEFlowDesc = WSA_QOS_EFLOWDESC,
        QosEpsFlowSpec = WSA_QOS_EPSFLOWSPEC,
        QosEpsFilterSpec = WSA_QOS_EPSFILTERSPEC,
        QosEsdmodeObj = WSA_QOS_ESDMODEOBJ,
        QosEshaperateObj = WSA_QOS_ESHAPERATEOBJ,
        QosReservedPetype = WSA_QOS_RESERVED_PETYPE,
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
        EIntr = 10004L,
        EBadf = 10009L,
        EAcces = 10013L,
        EFault = 10014L,
        EInval = 10022L,
        EMFile = 10024L,
        EWouldBlock = 10035L,
        EInProgress = 10036L,
        EAlready = 10037L,
        ENotSock = 10038L,
        EDestAddrReq = 10039L,
        EMsgSize = 10040L,
        EProtoType = 10041L,
        ENoProtoOpt = 10042L,
        EProtoNoSupport = 10043L,
        ESocktNoSupport = 10044L,
        EOpNotSupp = 10045L,
        EPfNoSupport = 10046L,
        EAfNoSupport = 10047L,
        EAddrInuse = 10048L,
        EAddrNotAvail = 10049L,
        ENetDown = 10050L,
        ENetUnreach = 10051L,
        ENetReset = 10052L,
        EConnAborted = 10053L,
        EConnReset = 10054L,
        ENoBufs = 10055L,
        EIsConn = 10056L,
        ENotConn = 10057L,
        EShutDown = 10058L,
        ETooManyRefs = 10059L,
        ETimeDout = 10060L,
        EConnRefUsed = 10061L,
        ELoop = 10062L,
        ENameTooLong = 10063L,
        EHostDown = 10064L,
        EHostUnReach = 10065L,
        ENotEmpty = 10066L,
        EProcLim = 10067L,
        EUsers = 10068L,
        EDquot = 10069L,
        EStale = 10070L,
        ERemote = 10071L,
        SysNotReady = 10091L,
        VerNotSupported = 10092L,
        NotInitialised = 10093L,
        EDiscon = 10101L,
        NoMore = 10102L,
        Cancelled = 10103L,
        EInvalidProctable = 10104L,
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
        QosEFlowspec = 11017L,
        QosEProvspecBuf = 11018L,
        QosEFilterStyle = 11019L,
        QosEFiltertype = 11020L,
        QosEFilterCount = 11021L,
        QosEObjLength = 11022L,
        QosEFlowCount = 11023L,
        QosEUnkownpsObj = 11024L,
        QosEPolicyObj = 11025L,
        QosEFlowDesc = 11026L,
        QosEpsFlowSpec = 11027L,
        QosEpsFilterSpec = 11028L,
        QosEsdmodeObj = 11029L,
        QosEshaperateObj = 11030L,
        QosReservedPetype = 11031L,
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
