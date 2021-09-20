///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.0 (2021/02/27 12:43)

#include "Example/BookCpp/TheCppStandardLibrary/TheCppStandardLibraryExport.h"

#include "TheCppStandardLibraryFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_THE_CPP_STANDARD_LIBRARY_STATIC

DLL_MAIN_FUNCTION(TheCppStandardLibrary);

#else  // BUILDING_THE_CPP_STANDARD_LIBRARY_STATIC

CORE_TOOLS_MUTEX_INIT(TheCppStandardLibrary);

#endif  // !BUILDING_THE_CPP_STANDARD_LIBRARY_STATIC
