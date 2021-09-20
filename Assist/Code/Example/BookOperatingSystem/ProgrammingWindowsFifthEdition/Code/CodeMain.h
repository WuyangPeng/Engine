///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.1.3 (2021/05/01 19:07)

#ifndef PROGRAMMING_WINDOWS_FIFTH_EDITION_CODE_MAIN_H
#define PROGRAMMING_WINDOWS_FIFTH_EDITION_CODE_MAIN_H

#include "Example/BookOperatingSystem/ProgrammingWindowsFifthEdition/ProgrammingWindowsFifthEditionDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace ProgrammingWindowsFifthEdition
{
    class PROGRAMMING_WINDOWS_FIFTH_EDITION_DEFAULT_DECLARE CodeMain
    {
    public:
        using ClassType = CodeMain;

    public:
        CLASS_INVARIANT_DECLARE;

        bool Main() noexcept;

        bool ExecuteChapter1() noexcept;
    };
}

#endif  // PROGRAMMING_WINDOWS_FIFTH_EDITION_CODE_MAIN_H
