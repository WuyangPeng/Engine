// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 13:29)

#ifndef SYSTEM_COM_IUNKNOWN_FLAGS_H
#define SYSTEM_COM_IUNKNOWN_FLAGS_H

#include "System/Helper/Platform.h"

#ifdef SYSTEM_PLATFORM_WIN32
	#include <objbase.h>
#endif // SYSTEM_PLATFORM_WIN32

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32

	enum class ClsContext
	{
		InprocServer = CLSCTX_INPROC_SERVER,
		InprocHandler = CLSCTX_INPROC_HANDLER,
		LocalServer = CLSCTX_LOCAL_SERVER,
		InprocServer16 = CLSCTX_INPROC_SERVER16,
		RemoteServer = CLSCTX_REMOTE_SERVER,
		InprocHandler16 = CLSCTX_INPROC_HANDLER16,
		Reserved1 = CLSCTX_RESERVED1,
		Reserved2 = CLSCTX_RESERVED2,
		Reserved3 = CLSCTX_RESERVED3,
		Reserved4 = CLSCTX_RESERVED4,
		NoCodeDownload = CLSCTX_NO_CODE_DOWNLOAD,
		Reserved5 = CLSCTX_RESERVED5,
		NoCustomMarshal = CLSCTX_NO_CUSTOM_MARSHAL,
		EnableCodeDownload = CLSCTX_ENABLE_CODE_DOWNLOAD,
		NoFailureLog = CLSCTX_NO_FAILURE_LOG,
		DisableAaa = CLSCTX_DISABLE_AAA,
		EnableAaa = CLSCTX_ENABLE_AAA,
		FromDefaultContext = CLSCTX_FROM_DEFAULT_CONTEXT,
		Activate32BitServer = CLSCTX_ACTIVATE_32_BIT_SERVER,
		Activate64BitServer = CLSCTX_ACTIVATE_64_BIT_SERVER,
		EnableCloaking = CLSCTX_ENABLE_CLOAKING,
		PsDll = CLSCTX_PS_DLL,
	};

	enum class RegCls
	{
		Singleuse = REGCLS_SINGLEUSE,
		Multipleuse = REGCLS_MULTIPLEUSE,
		MultiSeparate = REGCLS_MULTI_SEPARATE,
		Suspended = REGCLS_SUSPENDED,
		Surrogate = REGCLS_SURROGATE,
	};

#else // !SYSTEM_PLATFORM_WIN32

	enum class ClsContext
	{
		InprocServer = 0x1,
		InprocHandler = 0x2,
		LocalServer = 0x4,
		InprocServer16 = 0x8,
		RemoteServer = 0x10,
		InprocHandler16 = 0x20,
		Reserved1 = 0x40,
		Reserved2 = 0x80,
		Reserved3 = 0x100,
		Reserved4 = 0x200,
		NoCodeDownload = 0x400,
		Reserved5 = 0x800,
		NoCustomMarshal = 0x1000,
		EnableCodeDownload = 0x2000,
		NoFailureLog = 0x4000,
		DisableAaa = 0x8000,
		EnableAaa = 0x10000,
		FromDefaultContext = 0x20000,
		Activate32BitServer = 0x40000,
		Activate64BitServer = 0x80000,
		EnableCloaking = 0x100000,
		PsDll = 0x80000000,
	};

	enum class RegCls
	{
		Singleuse = 0,
		Multipleuse = 1,
		MultiSeparate = 2,
		Suspended = 4,
		Surrogate = 8
	};

#endif // SYSTEM_PLATFORM_WIN32
}

#endif // SYSTEM_COM_IUNKNOWN_FLAGS_H
