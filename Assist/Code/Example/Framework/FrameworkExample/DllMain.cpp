///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.2 (2023/07/31 13:46)

#include "Example/Framework/FrameworkExample/FrameworkExampleExport.h"

#include "CoreTools/Helper/MainFunctionMacro.h"
#include "Example/Framework/FrameworkExample/FrameworkExampleFwd.h"

#ifndef BUILDING_FRAMEWORK_EXAMPLE_STATIC

DLL_MAIN_FUNCTION(FrameworkExample);

#else  // !BUILDING_FRAMEWORK_EXAMPLE_STATIC

CORE_TOOLS_MUTEX_INIT(FrameworkExample);

#endif  // !BUILDING_FRAMEWORK_EXAMPLE_STATIC
