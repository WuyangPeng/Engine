///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.5 (2021/10/28 22:19)

#include "Example/BookOperatingSystem/ObjectOrientedMultithreadingUsingCpp/ObjectOrientedMultithreadingUsingCppExport.h"

#include "ObjectOrientedMultithreadingUsingCppFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_OBJECT_ORIENTED_MULTITHREADING_USING_CPP_STATIC

DLL_MAIN_FUNCTION(ObjectOrientedMultithreadingUsingCpp);

#else  // !BUILDING_OBJECT_ORIENTED_MULTITHREADING_USING_CPP_STATIC

CORE_TOOLS_MUTEX_INIT(ObjectOrientedMultithreadingUsingCpp);

#endif  // BUILDING_OBJECT_ORIENTED_MULTITHREADING_USING_CPP_STATIC
