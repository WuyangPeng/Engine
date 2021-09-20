///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.1 (2021/08/01 21:07)

#include "Example/BookOperatingSystem/NetworkProgrammingForMicrosoftWindows/NetworkProgrammingForMicrosoftWindowsExport.h"

#include "NetworkProgrammingForMicrosoftWindowsFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_NETWORK_PROGRAMMING_FOR_MICROSOFT_WINDOWS_STATIC

DLL_MAIN_FUNCTION(NetworkProgrammingForMicrosoftWindows);

#else  // !BUILDING_NETWORK_PROGRAMMING_FOR_MICROSOFT_WINDOWS_STATIC

CORE_TOOLS_MUTEX_INIT(NetworkProgrammingForMicrosoftWindows);

#endif  // BUILDING_NETWORK_PROGRAMMING_FOR_MICROSOFT_WINDOWS_STATIC
