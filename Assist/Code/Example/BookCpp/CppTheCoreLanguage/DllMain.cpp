///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.6.0.1 (2021/01/01 14:26)

#include "Example/BookCpp/CppTheCoreLanguage/CppTheCoreLanguageExport.h"

#include "CppTheCoreLanguageFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_CPP_THE_CORE_LANGUAGE_STATIC

DLL_MAIN_FUNCTION(CppTheCoreLanguage);

#else  // BUILDING_CPP_THE_CORE_LANGUAGE_STATIC

CORE_TOOLS_MUTEX_INIT(CppTheCoreLanguage);

#endif  // !BUILDING_CPP_THE_CORE_LANGUAGE_STATIC
