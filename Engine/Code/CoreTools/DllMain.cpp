///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.7.2.0 (2021/07/18 11:26)

#include "CoreToolsExport.h"

#include "CoreToolsFwd.h"
#include "Helper/MainFunctionMacro.h"

#if !defined(BUILDING_CORE_TOOLS_STATIC)

DLL_MAIN_FUNCTION(CoreTools);

#else  // defined(BUILDING_CORE_TOOLS_STATIC)

CORE_TOOLS_MUTEX_INIT(CoreTools);

#endif  // !defined(BUILDING_CORE_TOOLS_STATIC)