///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.1.3 (2021/05/16 17:54)

#ifndef MICROSOFT_WINDOWS_INTERNALS_FOURTH_EDITION_PLACEHOLDER_H
#define MICROSOFT_WINDOWS_INTERNALS_FOURTH_EDITION_PLACEHOLDER_H

#include "Example/BookOperatingSystem/MicrosoftWindowsInternalsFourthEdition/MicrosoftWindowsInternalsFourthEditionDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace MicrosoftWindowsInternalsFourthEdition
{
    class MICROSOFT_WINDOWS_INTERNALS_FOURTH_EDITION_DEFAULT_DECLARE Placeholder
    {
    public:
        using ClassType = Placeholder;

    public:
        CLASS_INVARIANT_DECLARE;

    public:
        Placeholder() noexcept;
    };
}

#endif  // MICROSOFT_WINDOWS_INTERNALS_FOURTH_EDITION_PLACEHOLDER_H
