///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.3 (2021/09/08 21:14)

#include "Example/BookOperatingSystem/InterprocessCommunications/InterprocessCommunicationsExport.h"

#include "InterprocessCommunications.h"

#ifndef BUILDING_INTERPROCESS_COMMUNICATIONS_STATIC

    #include "DllLib.h"

#else  // !BUILDING_INTERPROCESS_COMMUNICATIONS_STATIC

namespace InterprocessCommunications
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_INTERPROCESS_COMMUNICATIONS_STATIC
