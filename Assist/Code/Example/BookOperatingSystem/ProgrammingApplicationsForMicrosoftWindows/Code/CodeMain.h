///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.3 (2021/05/08 21:53)

#ifndef PROGRAMMING_APPLICATIONS_FOR_MICROSOFT_WINDOWS_CODE_MAIN_H
#define PROGRAMMING_APPLICATIONS_FOR_MICROSOFT_WINDOWS_CODE_MAIN_H

#include "Example/BookOperatingSystem/ProgrammingApplicationsForMicrosoftWindows/ProgrammingApplicationsForMicrosoftWindowsDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace ProgrammingApplicationsForMicrosoftWindows
{
    class PROGRAMMING_APPLICATIONS_FOR_MICROSOFT_WINDOWS_DEFAULT_DECLARE CodeMain
    {
    public:
        using ClassType = CodeMain;

    public:
        CLASS_INVARIANT_DECLARE;

        bool Main() noexcept;

        bool ExecuteChapter1() noexcept;
    };
}

#endif  // PROGRAMMING_APPLICATIONS_FOR_MICROSOFT_WINDOWS_CODE_MAIN_H
