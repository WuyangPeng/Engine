///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/28 14:04)

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
