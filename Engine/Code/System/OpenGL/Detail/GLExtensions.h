///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/08/29 23:19)

#ifndef SYSTEM_GL_EXTENSIONS_H
#define SYSTEM_GL_EXTENSIONS_H

#include "System/SystemDll.h"

namespace System
{
    SYSTEM_HIDDEN_DECLARE MAYBE_NULLPTR const char* GetVendorString() noexcept;
    SYSTEM_HIDDEN_DECLARE MAYBE_NULLPTR const char* GetRendererString() noexcept;
    SYSTEM_HIDDEN_DECLARE MAYBE_NULLPTR const char* GetVersionString() noexcept;
    SYSTEM_HIDDEN_DECLARE MAYBE_NULLPTR const char* GetShadingLanguageVersion() noexcept;
    SYSTEM_HIDDEN_DECLARE NODISCARD bool InitGL() noexcept;
}

#endif  // SYSTEM_GL_EXTENSIONS_H
