// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 13:30)

#ifndef SYSTEM_COM_COM_OBJECT_BASE_H
#define SYSTEM_COM_COM_OBJECT_BASE_H

#include "System/SystemDll.h" 

#include "Fwd/ComFlagsFwd.h"
#include "Using/IUnknownUsing.h"
#include "System/Helper/UnicodeUsing.h"
#include "System/Window/Using/WindowUsing.h"

namespace System
{
	bool SYSTEM_DEFAULT_DECLARE ComRegisterClassObject(const SystemCLSID& rclsid, SystemIUnknown* unknown, ClsContext clsContext, RegCls flags, WindowDWord* registration) noexcept;
	bool SYSTEM_DEFAULT_DECLARE ComRevokeClassObject(WindowDWord registerMagicCookie) noexcept;

	bool SYSTEM_DEFAULT_DECLARE ConversionStringFromCLSID(const SystemCLSID& rclsid, TChar** result) noexcept;
	void SYSTEM_DEFAULT_DECLARE ComTaskMemFree(WindowVoidPtr pv) noexcept;
}

#endif // SYSTEM_COM_COM_OBJECT_BASE_H
