///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.3 (2021/05/01 19:02)

#include "Example/BookOperatingSystem/MicrosoftWindowsInternalsFourthEdition/MicrosoftWindowsInternalsFourthEditionExport.h"

#include "MicrosoftWindowsInternalsFourthEdition.h"

#ifndef BUILDING_MICROSOFT_WINDOWS_INTERNALS_FOURTH_EDITION_STATIC

    #include "DllLib.h"

#else  // !BUILDING_MICROSOFT_WINDOWS_INTERNALS_FOURTH_EDITION_STATIC

namespace MicrosoftWindowsInternalsFourthEdition
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_MICROSOFT_WINDOWS_INTERNALS_FOURTH_EDITION_STATIC
