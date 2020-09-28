//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/24 17:58)

#ifndef SYSTEM_NETWORK_WINDOWS_INTERNET_FLAGS_H
#define SYSTEM_NETWORK_WINDOWS_INTERNET_FLAGS_H

#include "System/Helper/EnumMacro.h"
#include "System/Helper/Platform.h"

#ifdef SYSTEM_PLATFORM_WIN32
    #include <WinInet.h>
#endif  // SYSTEM_PLATFORM_WIN32

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32

    enum class InternetOpenType
    {
        Preconfig = INTERNET_OPEN_TYPE_PRECONFIG,
        Direct = INTERNET_OPEN_TYPE_DIRECT,
        Proxy = INTERNET_OPEN_TYPE_PROXY,
        PreconfigWithNoAutoproxy = INTERNET_OPEN_TYPE_PRECONFIG_WITH_NO_AUTOPROXY,
    };

    enum class InternetType : uint32_t
    {
        Zero = 0,

        NoCacheWrite = INTERNET_FLAG_NO_CACHE_WRITE,
        IdnDirect = INTERNET_FLAG_IDN_DIRECT,
        IdnProxy = INTERNET_FLAG_IDN_PROXY,
        Reload = INTERNET_FLAG_RELOAD,
        RawData = INTERNET_FLAG_RAW_DATA,
        ExistingConnect = INTERNET_FLAG_EXISTING_CONNECT,
        Async = INTERNET_FLAG_ASYNC,
        Passive = INTERNET_FLAG_PASSIVE,

        DontCache = INTERNET_FLAG_DONT_CACHE,
        MakePersistent = INTERNET_FLAG_MAKE_PERSISTENT,
        FromCache = INTERNET_FLAG_FROM_CACHE,
        Offline = INTERNET_FLAG_OFFLINE,
        Secure = INTERNET_FLAG_SECURE,
        KeepConnection = INTERNET_FLAG_KEEP_CONNECTION,
        NoAutoRedirect = INTERNET_FLAG_NO_AUTO_REDIRECT,
        ReadPrefetch = INTERNET_FLAG_READ_PREFETCH,
        NoCookies = INTERNET_FLAG_NO_COOKIES,
        NoAuth = INTERNET_FLAG_NO_AUTH,
        RrestrictedZone = INTERNET_FLAG_RESTRICTED_ZONE,
        CacheIfNetFail = INTERNET_FLAG_CACHE_IF_NET_FAIL,
        IgnoreRedirectToHttp = INTERNET_FLAG_IGNORE_REDIRECT_TO_HTTP,
        IgnoreRedirectToHttps = INTERNET_FLAG_IGNORE_REDIRECT_TO_HTTPS,
        IgnoreCertDateInvalid = INTERNET_FLAG_IGNORE_CERT_DATE_INVALID,
        IgnoreCertCnInvalid = INTERNET_FLAG_IGNORE_CERT_CN_INVALID,
        Resynchronize = INTERNET_FLAG_RESYNCHRONIZE,
        Hyperlink = INTERNET_FLAG_HYPERLINK,
        NoUi = INTERNET_FLAG_NO_UI,
        PragmaNocache = INTERNET_FLAG_PRAGMA_NOCACHE,
        CacheAsync = INTERNET_FLAG_CACHE_ASYNC,
        FormsSubmit = INTERNET_FLAG_FORMS_SUBMIT,
        FwdBack = INTERNET_FLAG_FWD_BACK,
        NeedFile = INTERNET_FLAG_NEED_FILE,
        MustCacheRequest = INTERNET_FLAG_MUST_CACHE_REQUEST,
        TransferAscii = INTERNET_FLAG_TRANSFER_ASCII,
        TransferBinary = INTERNET_FLAG_TRANSFER_BINARY,
        SecurityInternetMask = SECURITY_INTERNET_MASK,
        SecurityIgnoreErrorMask = SECURITY_IGNORE_ERROR_MASK,
    };

    enum class QueryInfo
    {
        Number = HTTP_QUERY_FLAG_NUMBER,

        MimeVersion = HTTP_QUERY_MIME_VERSION,
        ContentType = HTTP_QUERY_CONTENT_TYPE,
        ContentTransferEncoding = HTTP_QUERY_CONTENT_TRANSFER_ENCODING,
        ContentID = HTTP_QUERY_CONTENT_ID,
        ContentDescription = HTTP_QUERY_CONTENT_DESCRIPTION,
        ContentLength = HTTP_QUERY_CONTENT_LENGTH,
        ContentLanguage = HTTP_QUERY_CONTENT_LANGUAGE,
        Allow = HTTP_QUERY_ALLOW,
        Public = HTTP_QUERY_PUBLIC,
        Date = HTTP_QUERY_DATE,
        Expires = HTTP_QUERY_EXPIRES,
        LastModified = HTTP_QUERY_LAST_MODIFIED,
        MessageID = HTTP_QUERY_MESSAGE_ID,
        Uri = HTTP_QUERY_URI,
        DerivedFrom = HTTP_QUERY_DERIVED_FROM,
        Cost = HTTP_QUERY_COST,
        Link = HTTP_QUERY_LINK,
        Pragma = HTTP_QUERY_PRAGMA,
        Version = HTTP_QUERY_VERSION,
        StatusCode = HTTP_QUERY_STATUS_CODE,
        StatusText = HTTP_QUERY_STATUS_TEXT,
        RawHeaders = HTTP_QUERY_RAW_HEADERS,
        RawHeadersCrlf = HTTP_QUERY_RAW_HEADERS_CRLF,
        Connection = HTTP_QUERY_CONNECTION,
        Accept = HTTP_QUERY_ACCEPT,
        AcceptCharset = HTTP_QUERY_ACCEPT_CHARSET,
        AcceptEncoding = HTTP_QUERY_ACCEPT_ENCODING,
        AcceptLanguage = HTTP_QUERY_ACCEPT_LANGUAGE,
        Authorization = HTTP_QUERY_AUTHORIZATION,
        ContentEncoding = HTTP_QUERY_CONTENT_ENCODING,
        Forwarded = HTTP_QUERY_FORWARDED,
        From = HTTP_QUERY_FROM,
        IfModifiedSince = HTTP_QUERY_IF_MODIFIED_SINCE,
        Location = HTTP_QUERY_LOCATION,
        OrigUri = HTTP_QUERY_ORIG_URI,
        Referer = HTTP_QUERY_REFERER,
        RetryAfter = HTTP_QUERY_RETRY_AFTER,
        Server = HTTP_QUERY_SERVER,
        Title = HTTP_QUERY_TITLE,
        UserAgent = HTTP_QUERY_USER_AGENT,
        WwwAuthenticate = HTTP_QUERY_WWW_AUTHENTICATE,
        ProxyAuthenticate = HTTP_QUERY_PROXY_AUTHENTICATE,
        AcceptRanges = HTTP_QUERY_ACCEPT_RANGES,
        SetCookie = HTTP_QUERY_SET_COOKIE,
        Cookie = HTTP_QUERY_COOKIE,
        RequestMethod = HTTP_QUERY_REQUEST_METHOD,
        Refresh = HTTP_QUERY_REFRESH,
        ContentDisposition = HTTP_QUERY_CONTENT_DISPOSITION,
    };

#else  // !SYSTEM_PLATFORM_WIN32

    enum class InternetOpenType
    {
        Preconfig = 0,
        Direct = 1,
        Proxy = 3,
        PreconfigWithNoAutoproxy = 4,
    };

    enum class InternetType : uint32_t
    {
        Zero = 0,

        NoCacheWrite = 0x04000000,
        IdnDirect = 0x00000001,
        IdnProxy = 0x00000002,
        Reload = 0x80000000,
        RawData = 0x40000000,
        ExistingConnect = 0x20000000,
        Async = 0x10000000,
        Passive = 0x08000000,

        DontCache = NoCacheWrite,
        MakePersistent = 0x02000000,
        FromCache = 0x01000000,
        Offline = FromCache,
        Secure = 0x00800000,
        KeepConnection = 0x00400000,
        NoAutoRedirect = 0x00200000,
        ReadPrefetch = 0x00100000,
        NoCookies = 0x00080000,
        NoAuth = 0x00040000,
        RrestrictedZone = 0x00020000,
        CacheIfNetFail = 0x00010000,
        IgnoreRedirectToHttp = 0x00008000,
        IgnoreRedirectToHttps = 0x00004000,
        IgnoreCertDateInvalid = 0x00002000,
        IgnoreCertCnInvalid = 0x00001000,
        Resynchronize = 0x00000800,
        Hyperlink = 0x00000400,
        NoUi = 0x00000200,
        PragmaNocache = 0x00000100,
        CacheAsync = 0x00000080,
        FormsSubmit = 0x00000040,
        FwdBack = 0x00000020,
        NeedFile = 0x00000010,
        MustCacheRequest = NeedFile,
        TransferAscii = 0x00000001,
        TransferBinary = 0x00000002,
        SecurityInternetMask = (IgnoreCertCnInvalid | IgnoreCertDateInvalid | IgnoreRedirectToHttps | IgnoreRedirectToHttp),
        SecurityIgnoreErrorMask = (IgnoreCertCnInvalid | IgnoreCertDateInvalid | 0x00000100 | 0x00000080),
    };

    enum class QueryInfo
    {
        Number = 0x20000000,

        MimeVersion = 0,
        ContentType = 1,
        ContentTransferEncoding = 2,
        ContentID = 3,
        ContentDescription = 4,
        ContentLength = 5,
        ContentLanguage = 6,
        Allow = 7,
        Public = 8,
        Date = 9,
        Expires = 10,
        LastModified = 11,
        MessageID = 12,
        Uri = 13,
        DerivedFrom = 14,
        Cost = 15,
        Link = 16,
        Pragma = 17,
        Version = 18,
        StatusCode = 19,
        StatusText = 20,
        RawHeaders = 21,
        RawHeadersCrlf = 22,
        Connection = 23,
        Accept = 24,
        AcceptCharset = 25,
        AcceptEncoding = 26,
        AcceptLanguage = 27,
        Authorization = 28,
        ContentEncoding = 29,
        Forwarded = 30,
        From = 31,
        IfModifiedSince = 32,
        Location = 33,
        OrigUri = 34,
        Referer = 35,
        RetryAfter = 36,
        Server = 37,
        Title = 38,
        UserAgent = 39,
        WwwAuthenticate = 40,
        ProxyAuthenticate = 41,
        AcceptRanges = 42,
        SetCookie = 43,
        Cookie = 44,
        RequestMethod = 45,
        Refresh = 46,
        ContentDisposition = 47,
    };

#endif  // SYSTEM_PLATFORM_WIN32

    ENUM_ORABLE_OPERATOR_DEFINE(QueryInfo);
}

#endif  // SYSTEM_NETWORK_WINDOWS_INTERNET_FLAGS_H
