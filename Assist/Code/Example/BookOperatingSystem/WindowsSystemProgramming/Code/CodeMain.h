///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.3 (2021/05/12 16:56)

#ifndef WINDOWS_SYSTEM_PROGRAMMING_CODE_MAIN_H
#define WINDOWS_SYSTEM_PROGRAMMING_CODE_MAIN_H

#include "Example/BookOperatingSystem/WindowsSystemProgramming/WindowsSystemProgrammingDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace WindowsSystemProgramming
{
    class WINDOWS_SYSTEM_PROGRAMMING_DEFAULT_DECLARE CodeMain
    {
    public:
        using ClassType = CodeMain;

    public:
        CLASS_INVARIANT_DECLARE;

        bool Main() noexcept;

        bool ExecuteChapter1() noexcept;
    };
}

#endif  // WINDOWS_SYSTEM_PROGRAMMING_CODE_MAIN_H
