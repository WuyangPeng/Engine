///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.1.1 (2021/03/08 11:11)

#include "System/SystemLib.h"
#include "CoreTools/CoreToolsLib.h"
#include "Toolset/CoreTools/ExportTest/ExportTestLib.h"

// NetworkMacroTesting��Ҫ
#if defined(TCRE_USE_MSVC)
    #pragma comment(lib, "Ws2_32.lib")
#endif  // TCRE_USE_MSVC