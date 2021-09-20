///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.1.0 (2021/02/20 11:00)

#ifndef THREADING_CORE_RENDER_ENGINE_ASSIST_GUI_MIDDLE_LAYER_H
#define THREADING_CORE_RENDER_ENGINE_ASSIST_GUI_MIDDLE_LAYER_H

#include "ThreadingCoreRenderEngineAssist/Core/CoreFwd.h"
#include "System/Helper/UnicodeUsing.h"
#include "Framework/MiddleLayer/GUIManagerInterface.h"

namespace ThreadingCoreRenderEngineAssist
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

#endif  // THREADING_CORE_RENDER_ENGINE_ASSIST_GUI_MIDDLE_LAYER_H
