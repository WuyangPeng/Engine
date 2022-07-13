///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.8.0.10 (2022/07/05 10:43)

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
