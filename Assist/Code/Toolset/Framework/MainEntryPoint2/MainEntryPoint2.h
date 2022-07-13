///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.0.10 (2022/07/05 10:43)

#ifndef MAIN_ENTRY_POINT2_H
#define MAIN_ENTRY_POINT2_H

#include "Framework/MainFunctionHelper/ConsoleMainFunctionHelperBase.h"

namespace Framework
{
    class MainEntryPoint2 final : public ConsoleMainFunctionHelperBase
    {
    public:
        using ClassType = MainEntryPoint2;
        using ParentType = ConsoleMainFunctionHelperBase;

    public:
        MainEntryPoint2(int argc, char** argv, const String& consoleTitle, const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_FINAL_DECLARE;

        NODISCARD int DoRun() override;
    };
}

#endif  // MAIN_ENTRY_POINT2_H
