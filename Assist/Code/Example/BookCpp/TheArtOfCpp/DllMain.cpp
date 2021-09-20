///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.1 (2021/03/11 17:50)

#include "Example/BookCpp/TheArtOfCpp/TheArtOfCppExport.h"

#include "TheArtOfCppFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_THE_ART_OF_CPP_STATIC

DLL_MAIN_FUNCTION(TheArtOfCpp);

#else  // BUILDING_THE_ART_OF_CPP_STATIC

CORE_TOOLS_MUTEX_INIT(TheArtOfCpp);

#endif  // !BUILDING_THE_ART_OF_CPP_STATIC
