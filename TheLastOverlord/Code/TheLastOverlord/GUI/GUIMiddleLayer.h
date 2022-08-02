///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	最后的霸王版本：0.8.0.12 (2022/07/19 16:57)

#ifndef THE_LAST_OVERLORD_GUI_MIDDLE_LAYER_H
#define THE_LAST_OVERLORD_GUI_MIDDLE_LAYER_H

#include "TheLastOverlord/Core/CoreFwd.h"
#include "System/Helper/UnicodeUsing.h"
#include "Framework/MiddleLayer/GUIManagerInterface.h"

namespace TheLastOverlord
{
    class GUIMiddleLayer final : public Framework::GUIManagerInterface
    {
    public:
        using ClassType = GUIMiddleLayer;
        using ParentType = GUIManagerInterface;
        using String = System::String;
        using MiddleLayerPlatform = Framework::MiddleLayerPlatform;

    public:
        explicit GUIMiddleLayer(MiddleLayerPlatform middleLayerPlatform);

        CLASS_INVARIANT_FINAL_DECLARE;

        void PrintSelect(const ProjectName& projectName);
        void PrintEngineering(const String& engineeringName);
    };
}

#endif  // THE_LAST_OVERLORD_GUI_MIDDLE_LAYER_H
