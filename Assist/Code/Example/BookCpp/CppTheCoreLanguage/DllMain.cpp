///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.6.0.1 (2021/01/01 14:26)

#include "Example/BookCpp/CppTheCoreLanguage/CppTheCoreLanguageExport.h"

#include "CppTheCoreLanguageFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_CPP_THE_CORE_LANGUAGE_STATIC

DLL_MAIN_FUNCTION(CppTheCoreLanguage);

#else  // BUILDING_CPP_THE_CORE_LANGUAGE_STATIC

CORE_TOOLS_MUTEX_INIT(CppTheCoreLanguage);

#endif  // !BUILDING_CPP_THE_CORE_LANGUAGE_STATIC
