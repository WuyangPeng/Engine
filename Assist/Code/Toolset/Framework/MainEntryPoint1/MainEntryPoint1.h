///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.2 (2023/07/28 14:05)

#ifndef MAIN_ENTRY_POINT1_H
#define MAIN_ENTRY_POINT1_H

#include "Framework/MainFunctionHelper/ConsoleMainFunctionHelperBase.h"

namespace Framework
{
    class MainEntryPoint1 final : public ConsoleMainFunctionHelperBase
    {
    public:
        using ClassType = MainEntryPoint1;
        using ParentType = ConsoleMainFunctionHelperBase;

    public:
        MainEntryPoint1(int argc, char** argv, const String& consoleTitle, const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_FINAL_DECLARE;

        NODISCARD int DoRun() override;
    };
}

#endif  // MAIN_ENTRY_POINT1_H
