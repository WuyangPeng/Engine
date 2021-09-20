///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.1 (2021/03/11 17:50)

#include "Example/BookCpp/InsideTheCppObjectModel/InsideTheCppObjectModelExport.h"

#include "InsideTheCppObjectModelFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_INSIDE_THE_CPP_OBJECT_MODEL_STATIC

DLL_MAIN_FUNCTION(InsideTheCppObjectModel);

#else  // BUILDING_INSIDE_THE_CPP_OBJECT_MODEL_STATIC

CORE_TOOLS_MUTEX_INIT(InsideTheCppObjectModel);

#endif  // !BUILDING_INSIDE_THE_CPP_OBJECT_MODEL_STATIC
