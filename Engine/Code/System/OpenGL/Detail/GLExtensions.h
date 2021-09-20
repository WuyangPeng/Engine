///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.7.1.5 (2021/06/12 18:04)

#ifndef SYSTEM_GL_EXTENSIONS_H
#define SYSTEM_GL_EXTENSIONS_H

#include "System/SystemDll.h"

namespace System
{
    SYSTEM_HIDDEN_DECLARE NODISCARD const char* GetVendorString() noexcept;
    SYSTEM_HIDDEN_DECLARE NODISCARD const char* GetRendererString() noexcept;
    SYSTEM_HIDDEN_DECLARE NODISCARD const char* GetVersionString() noexcept;
    SYSTEM_HIDDEN_DECLARE NODISCARD const char* GetShadingLanguageVersion() noexcept;
    SYSTEM_HIDDEN_DECLARE NODISCARD bool InitGL() noexcept;
}

#endif  // SYSTEM_GL_EXTENSIONS_H
