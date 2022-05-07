///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.0.7 (2022/05/05 16:09)

#include "Framework/FrameworkExport.h"

#include "CoreTools/Helper/MainFunctionMacro.h"
#include "Framework/FrameworkFwd.h"

#ifndef BUILDING_FRAMEWORK_STATIC

DLL_MAIN_FUNCTION(Framework);

#else  // !BUILDING_FRAMEWORK_STATIC

CORE_TOOLS_MUTEX_INIT(Framework);

#endif  // !BUILDING_FRAMEWORK_STATIC
