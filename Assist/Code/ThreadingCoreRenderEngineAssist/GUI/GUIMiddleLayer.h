///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.0.10 (2022/06/30 14:10)

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
