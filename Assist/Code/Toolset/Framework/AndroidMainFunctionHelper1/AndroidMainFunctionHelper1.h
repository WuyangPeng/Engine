///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.2 (2023/07/28 14:33)

#ifndef ANDROID_MAIN_FUNCTION_HELPER1_H
#define ANDROID_MAIN_FUNCTION_HELPER1_H

#include "Framework/AndroidFrame/AndroidFrameBuild.h"
#include "Framework/AndroidFrame/AndroidProcess.h"
#include "Framework/MainFunctionHelper/AndroidMainFunctionHelper.h"

namespace Framework
{
    using BaseType = AndroidMainFunctionHelper<AndroidFrameBuild, AndroidProcessInterface>;

    class AndroidMainFunctionHelper1 final : public BaseType
    {
    public:
        using ClassType = AndroidMainFunctionHelper1;
        using ParentType = BaseType;

    public:
        AndroidMainFunctionHelper1(AndroidApp* state, const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_FINAL_DECLARE;
    };
}

#endif  // ANDROID_MAIN_FUNCTION_HELPER1_H
