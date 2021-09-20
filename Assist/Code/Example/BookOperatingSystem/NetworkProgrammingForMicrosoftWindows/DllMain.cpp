///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.1 (2021/08/01 21:07)

#include "Example/BookOperatingSystem/NetworkProgrammingForMicrosoftWindows/NetworkProgrammingForMicrosoftWindowsExport.h"

#include "NetworkProgrammingForMicrosoftWindowsFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_NETWORK_PROGRAMMING_FOR_MICROSOFT_WINDOWS_STATIC

DLL_MAIN_FUNCTION(NetworkProgrammingForMicrosoftWindows);

#else  // !BUILDING_NETWORK_PROGRAMMING_FOR_MICROSOFT_WINDOWS_STATIC

CORE_TOOLS_MUTEX_INIT(NetworkProgrammingForMicrosoftWindows);

#endif  // BUILDING_NETWORK_PROGRAMMING_FOR_MICROSOFT_WINDOWS_STATIC
