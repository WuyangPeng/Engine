///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.1 (2021/03/11 17:50)

#include "Example/BookCpp/BoostCppApplicationDevelopmentCookbook/BoostCppApplicationDevelopmentCookbookExport.h"

#include "BoostCppApplicationDevelopmentCookbookFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_BOOST_CPP_APPLICATION_DEVELOPMENT_COOKBOOK_STATIC

DLL_MAIN_FUNCTION(BoostCppApplicationDevelopmentCookbook);

#else  // BUILDING_BOOST_CPP_APPLICATION_DEVELOPMENT_COOKBOOK_STATIC

CORE_TOOLS_MUTEX_INIT(BoostCppApplicationDevelopmentCookbook);

#endif  // !BUILDING_BOOST_CPP_APPLICATION_DEVELOPMENT_COOKBOOK_STATIC
