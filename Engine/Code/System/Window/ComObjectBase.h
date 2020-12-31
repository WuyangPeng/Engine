//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.0 (2020/09/27 10:53)

#ifndef SYSTEM_WINDOW_COM_OBJECT_BASE_H
#define SYSTEM_WINDOW_COM_OBJECT_BASE_H

#include "System/SystemDll.h"

#include "Fwd/WindowFlagsFwd.h"
#include "Using/IUnknownUsing.h"
#include "System/Helper/UnicodeUsing.h"
#include "System/Window/Using/WindowUsing.h"

namespace System
{
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE ComRegisterClassObject(const SystemCLSID& rclsid, SystemIUnknown* unknown, ClsContext clsContext, RegCls flags, WindowDWord* registration) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE ComRevokeClassObject(WindowDWord registerMagicCookie) noexcept;

    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE ConversionStringFromCLSID(const SystemCLSID& rclsid, TChar** result) noexcept;
    void SYSTEM_DEFAULT_DECLARE ComTaskMemFree(WindowVoidPtr pv) noexcept;
}

#endif  // SYSTEM_WINDOW_COM_OBJECT_BASE_H
