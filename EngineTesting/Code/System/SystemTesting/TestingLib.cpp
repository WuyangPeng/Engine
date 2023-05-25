///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.9 (2023/05/23 16:51)

#include "System/SystemLib.h"
#include "CoreTools/CoreToolsLib.h"
#include "Mathematics/MathematicsLib.h"
#include "Toolset/CoreTools/ExportTest/ExportTestLib.h"

// NetworkMacroTesting ��Ҫ
#if defined(TCRE_USE_MSVC)

    #pragma comment(lib, "Ws2_32.lib")

#endif  // TCRE_USE_MSVC

// PragmaWarningTesting ��Ҫ
#if defined(TCRE_USE_MSVC)

    #pragma comment(lib, "libssl.lib")
    #pragma comment(lib, "libcrypto.lib")

#endif  // TCRE_USE_MSVC