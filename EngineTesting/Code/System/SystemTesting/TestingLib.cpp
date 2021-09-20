///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.1.1 (2021/03/08 11:11)

#include "System/SystemLib.h"
#include "CoreTools/CoreToolsLib.h"
#include "Toolset/CoreTools/ExportTest/ExportTestLib.h"

// NetworkMacroTesting需要
#if defined(TCRE_USE_MSVC)
    #pragma comment(lib, "Ws2_32.lib")
#endif  // TCRE_USE_MSVC