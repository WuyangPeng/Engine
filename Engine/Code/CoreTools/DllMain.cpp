///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.5 (2023/09/20 11:21)

#include "CoreToolsExport.h"

#include "CoreToolsFwd.h"
#include "Helper/MainFunctionMacro.h"

#if !defined(BUILDING_CORE_TOOLS_STATIC)

DLL_MAIN_FUNCTION(CoreTools);

#else  // defined(BUILDING_CORE_TOOLS_STATIC)

CORE_TOOLS_MUTEX_INIT(CoreTools);

#endif  // !defined(BUILDING_CORE_TOOLS_STATIC)