///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.6.0.0 (2020/12/24 22:45)

#include "Example/BookCpp/CppPrimerFifthEdition/CppPrimerFifthEditionExport.h"

#include "CppPrimerFifthEditionFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_CPP_PRIMER_FIFTH_EDITION_STATIC

DLL_MAIN_FUNCTION(CppPrimerFifthEdition);

#else  // BUILDING_CPP_PRIMER_FIFTH_EDITION_STATIC

CORE_TOOLS_MUTEX_INIT(CppPrimerFifthEdition);

#endif  // !BUILDING_CPP_PRIMER_FIFTH_EDITION_STATIC
