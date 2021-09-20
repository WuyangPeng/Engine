///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.1 (2021/03/11 17:50)

#include "Example/BookCpp/DesigningAndCodingReusableCpp/DesigningAndCodingReusableCppExport.h"

#include "DesigningAndCodingReusableCppFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_DESIGNING_AND_CODING_REUSABLE_CPP_STATIC

DLL_MAIN_FUNCTION(DesigningAndCodingReusableCpp);

#else  // BUILDING_DESIGNING_AND_CODING_REUSABLE_CPP_STATIC

CORE_TOOLS_MUTEX_INIT(DesigningAndCodingReusableCpp);

#endif  // !BUILDING_DESIGNING_AND_CODING_REUSABLE_CPP_STATIC
