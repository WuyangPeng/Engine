///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.2 (2023/07/28 14:51)

#ifndef C_MAIN_FUNCTION_HELPER_HELPER_H
#define C_MAIN_FUNCTION_HELPER_HELPER_H

#include "CoreTools/MainFunctionHelper/CMainFunctionHelper.h"

namespace CMainFunctionHelper
{
    class Helper final : public CoreTools::CMainFunctionHelper
    {
    public:
        using ClassType = Helper;
        using ParentType = CMainFunctionHelper;

    public:
        Helper(int argc, char** argv);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        NODISCARD int DoRun() override;
    };
}

#endif  // C_MAIN_FUNCTION_HELPER_HELPER_H