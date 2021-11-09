///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.5 (2021/10/28 22:19)

#include "Example/BookOperatingSystem/ObjectOrientedMultithreadingUsingCpp/ObjectOrientedMultithreadingUsingCppExport.h"

#include "ObjectOrientedMultithreadingUsingCppFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_OBJECT_ORIENTED_MULTITHREADING_USING_CPP_STATIC

DLL_MAIN_FUNCTION(ObjectOrientedMultithreadingUsingCpp);

#else  // !BUILDING_OBJECT_ORIENTED_MULTITHREADING_USING_CPP_STATIC

CORE_TOOLS_MUTEX_INIT(ObjectOrientedMultithreadingUsingCpp);

#endif  // BUILDING_OBJECT_ORIENTED_MULTITHREADING_USING_CPP_STATIC
