///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.3 (2021/05/01 19:07)

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
