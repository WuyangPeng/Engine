///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.7 (2021/12/05 10:34)

#include "Example/BookOperatingSystem/BookComputer/BookComputerExport.h"

#include "BookComputerFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_BOOK_COMPUTER_STATIC

DLL_MAIN_FUNCTION(BookComputer);

#else  // !BUILDING_BOOK_COMPUTER_STATIC

CORE_TOOLS_MUTEX_INIT(BookComputer);

#endif  // BUILDING_BOOK_COMPUTER_STATIC
