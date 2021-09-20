///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.3 (2021/05/03 15:40)

#ifndef PROGRAMMING_WINDOWS_SIXTH_EDITION_CODE_MAIN_H
#define PROGRAMMING_WINDOWS_SIXTH_EDITION_CODE_MAIN_H

#include "Example/BookOperatingSystem/ProgrammingWindowsSixthEdition/ProgrammingWindowsSixthEditionDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace ProgrammingWindowsSixthEdition
{
    class PROGRAMMING_WINDOWS_SIXTH_EDITION_DEFAULT_DECLARE CodeMain
    {
    public:
        using ClassType = CodeMain;

    public:
        CLASS_INVARIANT_DECLARE;

        bool Main() noexcept;

        bool ExecuteChapter1() noexcept;
    };
}

#endif  // PROGRAMMING_WINDOWS_SIXTH_EDITION_CODE_MAIN_H
