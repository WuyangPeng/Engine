// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 13:30)

#include "System/SystemExport.h"

#include "ComObjectBase.h"
#include "System/Helper/UnusedMacro.h"
#include "System/Helper/WindowsMacro.h"
#include "System/EnumOperator/EnumCastDetail.h"

bool System
	::ComRegisterClassObject(const SystemCLSID& rclsid, SystemIUnknown* unknown, ClsContext clsContext, RegCls flags, WindowDWord* registration) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (IsFailed(::CoRegisterClassObject(rclsid, unknown, EnumCastUnderlying(clsContext), EnumCastUnderlying(flags), registration)))
		return false;
	else
		return true;;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(rclsid);
	SYSTEM_UNUSED_ARG(unknown);
	SYSTEM_UNUSED_ARG(clsContext);
	SYSTEM_UNUSED_ARG(flags);
	SYSTEM_UNUSED_ARG(registration);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::ComRevokeClassObject(WindowDWord registerMagicCookie) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (IsFailed(::CoRevokeClassObject(registerMagicCookie)))
		return false;
	else
		return true;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(registerMagicCookie);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::ConversionStringFromCLSID(const SystemCLSID& rclsid, TChar** result) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32	 
	if (IsFailed(::StringFromCLSID(rclsid, result)))
		return false;
	else
		return true;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(rclsid);
	SYSTEM_UNUSED_ARG(result);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

void System
	::ComTaskMemFree(WindowVoidPtr pv) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32	 
	return ::CoTaskMemFree(pv);
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(pv);
#endif // SYSTEM_PLATFORM_WIN32
}
