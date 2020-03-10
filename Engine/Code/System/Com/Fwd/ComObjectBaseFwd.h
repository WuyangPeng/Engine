// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 13:29)

#ifndef SYSTEM_COM_COM_OBJECT_BASE_FWD_H
#define SYSTEM_COM_COM_OBJECT_BASE_FWD_H 

#include "ComFlagsFwd.h"
#include "System/Helper/UnicodeUsing.h"
#include "System/Com/Using/IUnknownUsing.h"

namespace System
{
	bool ComRegisterClassObject(const SystemCLSID& rclsid, SystemIUnknown* unknown, ClsContext clsContext, RegCls flags, WindowDWord* registration) noexcept;
	bool ComRevokeClassObject(WindowDWord registerMagicCookie) noexcept;
	bool ConversionStringFromCLSID(const SystemCLSID& rclsid, TChar** result) noexcept;
	void ComTaskMemFree(WindowVoidPtr pv) noexcept;
}

#endif // SYSTEM_COM_COM_OBJECT_BASE_FWD_H