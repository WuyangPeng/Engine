///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/08/31 15:34)

#include "System/SystemLib.h"
#include "CoreTools/CoreToolsLib.h"
#include "Mathematics/MathematicsLib.h"
#include "Toolset/CoreTools/ExportTest/ExportTestLib.h"

// NetworkMacroTesting 需要
#if defined(TCRE_USE_MSVC)

    #pragma comment(lib, "Ws2_32.lib")

#endif  // TCRE_USE_MSVC

// PragmaWarningTesting 需要
#if defined(TCRE_USE_MSVC)

    #pragma comment(lib, "libssl.lib")
    #pragma comment(lib, "libcrypto.lib")

#endif  // TCRE_USE_MSVC