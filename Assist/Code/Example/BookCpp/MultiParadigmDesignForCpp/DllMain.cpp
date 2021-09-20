///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.1 (2021/03/11 17:50)

#include "Example/BookCpp/MultiParadigmDesignForCpp/MultiParadigmDesignForCppExport.h"

#include "MultiParadigmDesignForCppFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_MULTI_PARADIGM_DESIGN_FOR_CPP_STATIC

DLL_MAIN_FUNCTION(MultiParadigmDesignForCpp);

#else  // BUILDING_MULTI_PARADIGM_DESIGN_FOR_CPP_STATIC

CORE_TOOLS_MUTEX_INIT(MultiParadigmDesignForCpp);

#endif  // !BUILDING_MULTI_PARADIGM_DESIGN_FOR_CPP_STATIC
