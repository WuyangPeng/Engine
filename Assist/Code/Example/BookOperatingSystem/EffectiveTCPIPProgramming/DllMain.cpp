///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.2 (2021/08/27 22:20)

#include "Example/BookOperatingSystem/EffectiveTCPIPProgramming/EffectiveTCPIPProgrammingExport.h"

#include "EffectiveTCPIPProgrammingFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_EFFECTIVE_TCP_IP_PROGRAMMING_STATIC

DLL_MAIN_FUNCTION(EffectiveTCPIPProgramming);

#else  // !BUILDING_EFFECTIVE_TCP_IP_PROGRAMMING_STATIC

CORE_TOOLS_MUTEX_INIT(EffectiveTCPIPProgramming);

#endif  // BUILDING_EFFECTIVE_TCP_IP_PROGRAMMING_STATIC
