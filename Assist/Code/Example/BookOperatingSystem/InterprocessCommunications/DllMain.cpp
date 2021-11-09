///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.3 (2021/09/08 21:14)

#include "Example/BookOperatingSystem/InterprocessCommunications/InterprocessCommunicationsExport.h"

#include "InterprocessCommunicationsFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_INTERPROCESS_COMMUNICATIONS_STATIC

DLL_MAIN_FUNCTION(InterprocessCommunications);

#else  // !BUILDING_INTERPROCESS_COMMUNICATIONS_STATIC

CORE_TOOLS_MUTEX_INIT(InterprocessCommunications);

#endif  // BUILDING_INTERPROCESS_COMMUNICATIONS_STATIC
