//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/27 10:52)

#ifndef SYSTEM_COM_IUNKNOWN_USING_H
#define SYSTEM_COM_IUNKNOWN_USING_H

#include "System/Helper/Platform.h"

#ifdef SYSTEM_PLATFORM_WIN32
    #include <objbase.h>
#endif  // SYSTEM_PLATFORM_WIN32

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32

    using SystemHResult = HRESULT;
    using SystemIID = IID;
    using SystemCLSID = CLSID;
    using SystemGUID = GUID;
    using SystemIUnknown = IUnknown;
    using SystemIClassFactory = IClassFactory;

    constexpr SystemHResult g_ResultOK{ S_OK };
    constexpr SystemHResult g_ResultNoInterface{ E_NOINTERFACE };
    constexpr SystemHResult g_ResultClassNoaggregation{ CLASS_E_NOAGGREGATION };
    constexpr SystemHResult g_NoError{ NOERROR };
    const SystemIID g_UnknownIID{ IID_IUnknown };
    const SystemIID g_ClassFactoryIID{ IID_IClassFactory };

#else  // !SYSTEM_PLATFORM_WIN32

    using SystemHResult = long;

    struct SystemIID
    {
        unsigned long Data1;
        unsigned short Data2;
        unsigned short Data3;
        unsigned char Data4[8];
    };

    using SystemCLSID = SystemIID;
    using SystemGUID = SystemIID;

    struct SystemIUnknown
    {
    };

    struct SystemIClassFactory
    {
    };

    constexpr SystemHResult g_ResultOK{ 0 };
    constexpr SystemHResult g_ResultNoInterface{ 0x80004002L };
    constexpr SystemHResult g_ResultClassNoaggregation{ 0x80040110L };
    constexpr SystemHResult g_NoError{ 0 };
    const SystemIID g_UnknownIID{ 0 };
    const SystemIID g_ClassFactoryIID{ 1 };

#endif  // SYSTEM_PLATFORM_WIN32
}

#endif  // SYSTEM_COM_IUNKNOWN_USING_H
