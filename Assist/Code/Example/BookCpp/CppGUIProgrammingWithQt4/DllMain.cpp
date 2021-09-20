///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.1 (2021/03/11 17:50)

#include "Example/BookCpp/CppGUIProgrammingWithQt4/CppGUIProgrammingWithQt4Export.h"

#include "CppGUIProgrammingWithQt4Fwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_CPP_GUI_PROGRAMMING_WITH_QT4_STATIC

DLL_MAIN_FUNCTION(CppGUIProgrammingWithQt4);

#else  // BUILDING_CPP_GUI_PROGRAMMING_WITH_QT4_STATIC

CORE_TOOLS_MUTEX_INIT(CppGUIProgrammingWithQt4);

#endif  // !BUILDING_CPP_GUI_PROGRAMMING_WITH_QT4_STATIC
