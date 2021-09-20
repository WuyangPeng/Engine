///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.1.3 (2021/05/01 19:02)

#include "Example/BookOperatingSystem/MicrosoftWindowsInternalsSixthEdition/MicrosoftWindowsInternalsSixthEditionExport.h"

#include "MicrosoftWindowsInternalsSixthEdition.h"

#ifndef BUILDING_MICROSOFT_WINDOWS_INTERNALS_SIXTH_EDITION_STATIC

    #include "DllLib.h"

#else  // !BUILDING_MICROSOFT_WINDOWS_INTERNALS_SIXTH_EDITION_STATIC

namespace MicrosoftWindowsInternalsSixthEdition
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_MICROSOFT_WINDOWS_INTERNALS_SIXTH_EDITION_STATIC
