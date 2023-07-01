///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.0 (2023/06/20 09:30)
///	版本：0.9.1.0 (2023/06/19 15:16)

#ifndef DISTANCE_ALIGNED_BOXES_DISTANCE_ALIGNED_BOXES_HELPER_H
#define DISTANCE_ALIGNED_BOXES_DISTANCE_ALIGNED_BOXES_HELPER_H

#include "DistanceAlignedBoxesMiddleLayerMessage.h"
#include "Framework/MainFunctionHelper/WindowMainFunctionHelper.h"
#include "Framework/WindowsAPIFrame/WindowsAPIFrameBuild.h"

namespace DistanceAlignedBoxes
{
    using HelperBase = Framework::WindowMainFunctionHelper<Framework::WindowsAPIFrameBuild, DistanceAlignedBoxesProcess>;

    class DistanceAlignedBoxesHelper final : public HelperBase
    {
    public:
        using ClassType = DistanceAlignedBoxesHelper;
        using ParentType = HelperBase;

        using EnvironmentDirectory = Framework::EnvironmentDirectory;
        using WindowApplicationInformation = Framework::WindowApplicationInformation;

    public:
        DistanceAlignedBoxesHelper(WindowsHInstance instance, const char* commandLine, const WindowApplicationInformation& information, const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_FINAL_DECLARE;
    };
}

#endif  // DISTANCE_ALIGNED_BOXES_DISTANCE_ALIGNED_BOXES_HELPER_H