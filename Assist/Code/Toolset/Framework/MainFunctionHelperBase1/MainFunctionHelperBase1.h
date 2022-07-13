///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.0.10 (2022/07/05 10:50)

#ifndef MAIN_FUNCTION_HELPER_BASE1_H
#define MAIN_FUNCTION_HELPER_BASE1_H

#include "Framework/MainFunctionHelper/MainFunctionHelperBase.h"

namespace Framework
{
    class MainFunctionHelperBase1 final : public MainFunctionHelperBase
    {
    public:
        using ClassType = MainFunctionHelperBase1;
        using ParentType = MainFunctionHelperBase;

    public:
        MainFunctionHelperBase1(int argc, char** argv, const String& consoleTitle, const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_FINAL_DECLARE;

        NODISCARD int DoRun() final;
    };
}

#endif  // MAIN_FUNCTION_HELPER_BASE1_H