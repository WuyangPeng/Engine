///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.3 (2021/09/22 21:06)

#include "Example/BookOperatingSystem/TCPIPProtocolSuite/TCPIPProtocolSuiteExport.h"

#include "TCPIPProtocolSuiteFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_TCP_IP_PROTOCOL_SUITE_STATIC

DLL_MAIN_FUNCTION(TCPIPProtocolSuite);

#else  // !BUILDING_TCP_IP_PROTOCOL_SUITE_STATIC

CORE_TOOLS_MUTEX_INIT(TCPIPProtocolSuite);

#endif  // BUILDING_TCP_IP_PROTOCOL_SUITE_STATIC
