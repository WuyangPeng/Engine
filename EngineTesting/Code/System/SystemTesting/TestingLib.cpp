/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/06 16:43)

#include "System/SystemLib.h"
#include "CoreTools/CoreToolsLib.h"
#include "Mathematics/MathematicsLib.h"
#include "Toolset/CoreTools/ExportTest/ExportTestLib.h"

/// NetworkMacroTesting ��Ҫ
#if defined(TCRE_USE_MSVC)

    #pragma comment(lib, "Ws2_32.lib")

#endif  // TCRE_USE_MSVC

/// PragmaWarningTesting ��Ҫ
#if defined(TCRE_USE_MSVC)

    #pragma comment(lib, "libssl.lib")
    #pragma comment(lib, "libcrypto.lib")

#endif  // TCRE_USE_MSVC