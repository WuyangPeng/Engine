///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.0.0 (2021/01/30 11:02)

#include "Example/BookCpp/TheArtOfComputerProgramming/TheArtOfComputerProgrammingExport.h"

#include "TheArtOfComputerProgrammingFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_THE_ART_OF_COMPUTER_PROGRAMMING_STATIC

DLL_MAIN_FUNCTION(TheArtOfComputerProgramming);

#else  // BUILDING_THE_ART_OF_COMPUTER_PROGRAMMING_STATIC

CORE_TOOLS_MUTEX_INIT(TheArtOfComputerProgramming);

#endif  // !BUILDING_THE_ART_OF_COMPUTER_PROGRAMMING_STATIC