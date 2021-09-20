///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	最后的霸王版本：0.7.0.1 (2021/02/18 15:01)

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
