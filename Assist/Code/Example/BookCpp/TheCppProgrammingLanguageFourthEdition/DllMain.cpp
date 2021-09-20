///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.6.0.1 (2021/01/08 21:28)

#include "Example/BookCpp/TheCppProgrammingLanguageFourthEdition/TheCppProgrammingLanguageFourthEditionExport.h"

#include "TheCppProgrammingLanguageFourthEditionFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_THE_CPP_PROGRAMMING_LANGUAGE_FOURTH_EDITION_STATIC

DLL_MAIN_FUNCTION(TheCppProgrammingLanguageFourthEdition);

#else  // BUILDING_THE_CPP_PROGRAMMING_LANGUAGE_FOURTH_EDITION_STATIC

CORE_TOOLS_MUTEX_INIT(TheCppProgrammingLanguageFourthEdition);

#endif  // !BUILDING_THE_CPP_PROGRAMMING_LANGUAGE_FOURTH_EDITION_STATIC
