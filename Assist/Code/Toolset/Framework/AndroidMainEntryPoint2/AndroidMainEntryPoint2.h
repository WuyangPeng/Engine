///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.2 (2023/07/28 14:35)

#ifndef ANDROID_MAIN_ENTRY_POINT2_H
#define ANDROID_MAIN_ENTRY_POINT2_H

#include "Framework/AndroidFrame/AndroidFrameBuild.h"
#include "Framework/AndroidFrame/AndroidProcess.h"
#include "Framework/MainFunctionHelper/AndroidMainFunctionHelper.h"

namespace Framework
{
    using BaseType = AndroidMainFunctionHelper<AndroidFrameBuild, AndroidProcessInterface>;

    class AndroidMainEntryPoint2 : public BaseType
    {
    public:
        using ClassType = AndroidMainEntryPoint2;
        using ParentType = BaseType;

    public:
        AndroidMainEntryPoint2(AndroidApp* state, const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_FINAL_DECLARE;
    };
}

#endif  // ANDROID_MAIN_ENTRY_POINT2_H
