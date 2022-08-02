///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	最后的霸王版本：0.8.0.12 (2022/07/19 16:55)

#ifndef THE_LAST_OVERLORD_SYSTEM_MIDDLE_LAYER_H
#define THE_LAST_OVERLORD_SYSTEM_MIDDLE_LAYER_H

#include "Framework/MiddleLayer/SystemManagerInterface.h"

namespace TheLastOverlord
{
    class SystemMiddleLayer final : public Framework::SystemManagerInterface
    {
    public:
        using ClassType = SystemMiddleLayer;
        using ParentType = SystemManagerInterface;
        using MiddleLayerPlatform = Framework::MiddleLayerPlatform;

    public:
        explicit SystemMiddleLayer(MiddleLayerPlatform middleLayerPlatform);

        CLASS_INVARIANT_FINAL_DECLARE;

        void Execute(int select);
    };
}

#endif  // THE_LAST_OVERLORD_SYSTEM_MIDDLE_LAYER_H
