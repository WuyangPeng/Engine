///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.2 (2023/07/25 15:47)

#include "Instance/InstanceExport.h"

#include "InstanceFwd.h"
#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_INSTANCE_STATIC

DLL_MAIN_FUNCTION(Instance);

#else  // !BUILDING_INSTANCE_STATIC

CORE_TOOLS_MUTEX_INIT(Instance);

#endif  // BUILDING_INSTANCE_STATIC
