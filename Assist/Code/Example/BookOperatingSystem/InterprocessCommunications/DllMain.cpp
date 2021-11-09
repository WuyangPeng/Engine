///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.3 (2021/09/08 21:14)

#include "Example/BookOperatingSystem/InterprocessCommunications/InterprocessCommunicationsExport.h"

#include "InterprocessCommunicationsFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_INTERPROCESS_COMMUNICATIONS_STATIC

DLL_MAIN_FUNCTION(InterprocessCommunications);

#else  // !BUILDING_INTERPROCESS_COMMUNICATIONS_STATIC

CORE_TOOLS_MUTEX_INIT(InterprocessCommunications);

#endif  // BUILDING_INTERPROCESS_COMMUNICATIONS_STATIC
