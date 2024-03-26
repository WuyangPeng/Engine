/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/03 21:04)

#ifndef SYSTEM_NETWORK_WINDOWS_SOCK_EX_USING_H
#define SYSTEM_NETWORK_WINDOWS_SOCK_EX_USING_H

#include "System/Helper/Platform.h"
#include "System/Threading/Using/ThreadUsing.h"
#include "System/Windows/Using/WindowsUsing.h"

#ifdef SYSTEM_PLATFORM_WIN32

    #include <WinSock2.h>

#endif  // SYSTEM_PLATFORM_WIN32

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32

    using WinSockConditionProc = LPCONDITIONPROC;

    using WinSockBuf = WSABUF;
    using WinSockBufPtr = LPWSABUF;
    using QualityOfService = QOS;
    using QualityOfServicePtr = LPQOS;
    using WinSockFlowSpec = FLOWSPEC;
    using WinSockFlowSpecPtr = LPFLOWSPEC;
    using WinSockEvent = WSAEVENT;

    using SocketAddressList = SOCKET_ADDRESS_LIST;
    using SocketAddressListPtr = PSOCKET_ADDRESS_LIST;
    using SocketAddress = SOCKET_ADDRESS;
    using SocketAddressPtr = PSOCKET_ADDRESS;
    using SocketProtocolInfo = WSAPROTOCOL_INFO;
    using SocketProtocolInfoPtr = LPWSAPROTOCOL_INFO;
    constexpr WindowsDWord protocolLen{ WSAPROTOCOL_LEN };
    using SocketProtocolChain = WSAPROTOCOLCHAIN;
    using SocketProtocolChainPtr = LPWSAPROTOCOLCHAIN;
    constexpr WindowsDWord protocolChain{ MAX_PROTOCOL_CHAIN };
    using SocketNetworkEvents = WSANETWORKEVENTS;
    using SocketNetworkEventsPtr = LPWSANETWORKEVENTS;
    using SocketOverlapped = WSAOVERLAPPED;
    using SocketOverlappedPtr = LPWSAOVERLAPPED;

    using SocketOverlappedCompletionRoutine = LPWSAOVERLAPPED_COMPLETION_ROUTINE;
    using SocketMsg = WSAMSG;
    using SocketMsgPtr = LPWSAMSG;
    using SocketGroup = GROUP;
    using SocketQuerySet = WSAQUERYSET;
    using SocketQuerySetPtr = LPWSAQUERYSET;

    using SocketGuidPtr = LPGUID;
    using SocketVersion = WSAVERSION;
    using SocketVersionPtr = LPWSAVERSION;
    using SocketEComparator = WSAECOMPARATOR;
    using SocketEComparatorPtr = LPWSAECOMPARATOR;
    using SocketAfProtocols = AFPROTOCOLS;
    using SocketAfProtocolsPtr = LPAFPROTOCOLS;
    using SocketBlob = BLOB;
    using SocketBlobPtr = LPBLOB;
    using SocketCsAddressInfo = CSADDR_INFO;
    using SocketCsAddressInfoPtr = LPCSADDR_INFO;
    using SocketCompletion = WSACOMPLETION;
    using SocketCompletionPtr = LPWSACOMPLETION;
    using SocketCompletionType = WSACOMPLETIONTYPE;
    using SocketCompletionTypePtr = LPWSACOMPLETIONTYPE;
    using SocketServiceClassInfo = WSASERVICECLASSINFO;
    using SocketServiceClassInfoPtr = LPWSASERVICECLASSINFO;
    using SocketNsClassInfo = WSANSCLASSINFO;
    using SocketNsClassInfoPtr = LPWSANSCLASSINFO;
    using SocketNamespaceInfo = WSANAMESPACE_INFO;
    using SocketNamespaceInfoPtr = LPWSANAMESPACE_INFO;
    using SocketNamespaceInfoEx = WSANAMESPACE_INFOEX;
    using SocketNamespaceInfoExPtr = LPWSANAMESPACE_INFOEX;
    using SocketESetServiceOp = WSAESETSERVICEOP;
    using SocketESetServiceOpPtr = LPWSAESETSERVICEOP;

    using SocketPollFd = WSAPOLLFD;
    using SocketPollFdPtr = LPWSAPOLLFD;

#else  // !SYSTEM_PLATFORM_WIN32

    struct WinSockBuf
    {
        WindowsULong len;
        char* buf;
    };
    using WinSockBufPtr = WinSockBuf*;

    struct WinSockFlowSpec
    {
        WindowsULong TokenRate;
        WindowsULong TokenBucketSize;
        WindowsULong PeakBandwidth;
        WindowsULong Latency;
        WindowsULong DelayVariation;
        WindowsULong ServiceType;
        WindowsULong MaxSduSize;
        WindowsULong MinimumPolicedSize;
    };
    using WinSockFlowSpecPtr = WinSockFlowSpec*;

    struct QualityOfService
    {
        WinSockFlowSpec SendingFlowspec;
        WinSockFlowSpec ReceivingFlowspec;
        WinSockBuf ProviderSpecific;
    };
    using QualityOfServicePtr = QualityOfService*;

    using WinSockConditionProc = int (*)(WinSockBufPtr callerId,
                                         WinSockBufPtr callerData,
                                         QualityOfServicePtr sQOS,
                                         QualityOfServicePtr gQOS,
                                         WinSockBufPtr calleeId,
                                         WinSockBufPtr calleeData,
                                         unsigned int* g,
                                         WindowsDWordPtrSizeType callbackData);
    using WinSockEvent = void*;

    struct SocketAddress
    {
        WinSockAddress* lpSockaddr;
        int iSockaddrLength;
    };
    using SocketAddressPtr = SocketAddress*;

    struct SocketAddressList
    {
        int iAddressCount;
        SocketAddress Address[1];
    };
    using SocketAddressListPtr = SocketAddressList*;

    constexpr WindowsDWord protocolChain{ 7 };
    struct SocketProtocolChain
    {
        int ChainLen;
        uint32_t ChainEntries[protocolChain];
    };
    using SocketProtocolChainPtr = SocketProtocolChain*;

    constexpr WindowsDWord protocolLen{ 255 };
    struct SocketProtocolInfo
    {
        uint32_t dwServiceFlags1;
        uint32_t dwServiceFlags2;
        uint32_t dwServiceFlags3;
        uint32_t dwServiceFlags4;
        uint32_t dwProviderFlags;
        SystemGloballyUniqueIdentifier ProviderId;
        uint32_t dwCatalogEntryId;
        SocketProtocolChain ProtocolChain;
        int iVersion;
        int iAddressFamily;
        int iMaxSockAddr;
        int iMinSockAddr;
        int iSocketType;
        int iProtocol;
        int iProtocolMaxOffset;
        int iNetworkByteOrder;
        int iSecurityScheme;
        uint32_t dwMessageSize;
        uint32_t dwProviderReserved;
        wchar_t szProtocol[protocolLen + 1];
    };
    using SocketProtocolInfoPtr = SocketProtocolInfo*;

    struct SocketNetworkEvents
    {
        long lNetworkEvents;
        int iErrorCode[10];
    };
    using SocketNetworkEventsPtr = SocketNetworkEvents*;

    struct SocketOverlapped
    {
        uint32_t Internal;
        uint32_t InternalHigh;
        uint32_t Offset;
        uint32_t OffsetHigh;
        WinSockEvent hEvent;
    };
    using SocketOverlappedPtr = SocketOverlapped*;

    using SocketOverlappedCompletionRoutine = void (*)(uint32_t error, uint32_t transferred, SocketOverlappedPtr overlapped, uint32_t flags);

    struct SocketMsg
    {
        WinSockAddress* name;
        int namelen;
        WinSockBufPtr lpBuffers;
        unsigned long dwBufferCount;
        WinSockBuf Control;
        unsigned long dwFlags;
    };
    using SocketMsgPtr = SocketMsg*;
    using SocketGroup = unsigned int;

    using SocketGuidPtr = SystemGloballyUniqueIdentifier*;

    enum SocketEComparator
    {
        COMP_EQUAL = 0,
        COMP_NOTLESS
    };
    using SocketEComparatorPtr = SocketEComparator*;

    struct SocketVersion
    {
        uint32_t dwVersion;
        SocketEComparator ecHow;
    };
    using SocketVersionPtr = SocketVersion*;

    struct SocketAfProtocols
    {
        int iAddressFamily;
        int iProtocol;
    };
    using SocketAfProtocolsPtr = SocketAfProtocols*;

    struct SocketBlob
    {
        unsigned long cbSize;
        uint8_t* pBlobData;
    };
    using SocketBlobPtr = SocketBlob*;

    struct SocketCsAddressInfo
    {
        SocketAddress LocalAddr;
        SocketAddress RemoteAddr;
        int iSocketType;
        int iProtocol;
    };
    using SocketCsAddressInfoPtr = SocketCsAddressInfo*;

    struct SocketQuerySet
    {
        uint32_t dwSize;
        TChar* lpszServiceInstanceName;
        SocketGuidPtr lpServiceClassId;
        SocketVersionPtr lpVersion;
        TChar* lpszComment;
        uint32_t dwNameSpace;
        SocketGuidPtr lpNSProviderId;
        TChar* lpszContext;
        uint32_t dwNumberOfProtocols;
        SocketAfProtocolsPtr lpafpProtocols;
        TChar* lpszQueryString;
        uint32_t dwNumberOfCsAddrs;
        SocketCsAddressInfoPtr lpcsaBuffer;
        uint32_t dwOutputFlags;
        SocketBlobPtr lpBlob;
    };
    using SocketQuerySetPtr = SocketQuerySet*;

    enum SocketCompletionType
    {
        NSP_NOTIFY_IMMEDIATELY = 0,
        NSP_NOTIFY_HWND,
        NSP_NOTIFY_EVENT,
        NSP_NOTIFY_PORT,
        NSP_NOTIFY_APC,
    };
    using SocketCompletionTypePtr = SocketCompletionType*;

    struct SocketCompletion
    {
        SocketCompletionType Type;
        union
        {
            struct
            {
                WindowsHWnd hWnd;
                uint32_t uMsg;
                uint64_t context;
            } WindowMessage;
            struct
            {
                SocketOverlappedPtr lpOverlapped;
            } Event;
            struct
            {
                SocketOverlappedPtr lpOverlapped;
                SocketOverlappedCompletionRoutine lpfnCompletionProc;
            } Apc;
            struct
            {
                SocketOverlappedPtr lpOverlapped;
                ThreadHandle hPort;
                uint64_t Key;
            } Port;
        } Parameters;
    };
    using SocketCompletionPtr = SocketCompletion*;

    struct SocketNsClassInfo
    {
        TChar* lpszName;
        uint32_t dwNameSpace;
        uint32_t dwValueType;
        uint32_t dwValueSize;
        void* lpValue;
    };
    using SocketNsClassInfoPtr = SocketNsClassInfo*;

    struct SocketServiceClassInfo
    {
        SocketGuidPtr lpServiceClassId;
        TChar* lpszServiceClassName;
        uint32_t dwCount;
        SocketNsClassInfoPtr lpClassInfos;
    };
    using SocketServiceClassInfoPtr = SocketServiceClassInfo*;

    struct SocketNamespaceInfo
    {
        SystemGloballyUniqueIdentifier NSProviderId;
        uint32_t dwNameSpace;
        int fActive;
        uint32_t dwVersion;
        TChar* lpszIdentifier;
    };
    using SocketNamespaceInfoPtr = SocketNamespaceInfo*;

    struct SocketNamespaceInfoEx
    {
        SystemGloballyUniqueIdentifier NSProviderId;
        uint32_t dwNameSpace;
        int fActive;
        uint32_t dwVersion;
        TChar* lpszIdentifier;
        SocketBlob ProviderSpecific;
    };
    using SocketNamespaceInfoExPtr = SocketNamespaceInfoEx*;

    enum SocketESetServiceOp
    {
        RNRSERVICE_REGISTER = 0,
        RNRSERVICE_DEREGISTER,
        RNRSERVICE_DELETE
    };
    using SocketESetServiceOpPtr = SocketESetServiceOp*;

    struct SocketPollFd
    {
        WinSocket fd;
        short events;
        short revents;
    };
    using SocketPollFdPtr = SocketPollFd*;

#endif  // SYSTEM_PLATFORM_WIN32
}

#endif  // SYSTEM_NETWORK_WINDOWS_SOCK_EX_USING_H