///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.9.0.12 (2023/06/13 15:02)

#ifndef ANDROID_MAIN_ENTRY_POINT1_H
#define ANDROID_MAIN_ENTRY_POINT1_H

#include "Framework/AndroidFrame/AndroidFrameBuild.h"
#include "Framework/AndroidFrame/AndroidProcess.h"
#include "Framework/MainFunctionHelper/AndroidMainFunctionHelper.h"

namespace Framework
{
    using BaseType = AndroidMainFunctionHelper<AndroidFrameBuild, AndroidProcessInterface>;

    class AndroidMainEntryPoint1 final : public BaseType
    {
    public:
        using ClassType = AndroidMainEntryPoint1;
        using ParentType = BaseType;

    public:
        AndroidMainEntryPoint1(AndroidApp* state, const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_FINAL_DECLARE;
    };
}

#endif  // ANDROID_MAIN_ENTRY_POINT1_H
