///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.2 (2021/08/27 22:20)

#include "Example/BookOperatingSystem/EffectiveTCPIPProgramming/EffectiveTCPIPProgrammingExport.h"

#include "EffectiveTCPIPProgrammingFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_EFFECTIVE_TCP_IP_PROGRAMMING_STATIC

DLL_MAIN_FUNCTION(EffectiveTCPIPProgramming);

#else  // !BUILDING_EFFECTIVE_TCP_IP_PROGRAMMING_STATIC

CORE_TOOLS_MUTEX_INIT(EffectiveTCPIPProgramming);

#endif  // BUILDING_EFFECTIVE_TCP_IP_PROGRAMMING_STATIC
