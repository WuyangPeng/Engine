///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.8.0.10 (2022/06/30 16:40)

#ifndef C_MAIN_FUNCTION_HELPER_HELPER_H
#define C_MAIN_FUNCTION_HELPER_HELPER_H

#include "CoreTools/MainFunctionHelper/CMainFunctionHelper.h"

namespace CMainFunctionHelper
{
    class Helper : public CoreTools::CMainFunctionHelper
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