///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.9.0.12 (2023/06/13 15:24)

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
