///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.0.10 (2022/07/05 10:26)

#ifndef MACINTOSH_MAIN_FUNCTION_HELPER1_H
#define MACINTOSH_MAIN_FUNCTION_HELPER1_H

#include "Framework/MacintoshFrame/MacintoshFrameBuild.h"
#include "Framework/MacintoshFrame/MacintoshProcess.h"
#include "Framework/MainFunctionHelper/MacintoshMainFunctionHelper.h"

namespace Framework
{
    using BaseType = MacintoshMainFunctionHelper<MacintoshFrameBuild, MacintoshProcessInterface>;

    class MacintoshMainFunctionHelper1 final : public BaseType
    {
    public:
        using ClassType = MacintoshMainFunctionHelper1;
        using ParentType = BaseType;

    public:
        MacintoshMainFunctionHelper1(const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_FINAL_DECLARE;
    };
}

#endif  // MACINTOSH_MAIN_FUNCTION_HELPER1_H
