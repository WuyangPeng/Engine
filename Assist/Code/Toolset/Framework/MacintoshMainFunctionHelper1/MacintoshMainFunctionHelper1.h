///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/28 14:06)

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

        using MacintoshMainFunctionHelper1SharedPtr = std::shared_ptr<ClassType>;

    public:
        NODISCARD static MacintoshMainFunctionHelper1SharedPtr Create(const EnvironmentDirectory& environmentDirectory);

        explicit MacintoshMainFunctionHelper1(const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_FINAL_DECLARE;
    };
}

#endif  // MACINTOSH_MAIN_FUNCTION_HELPER1_H
