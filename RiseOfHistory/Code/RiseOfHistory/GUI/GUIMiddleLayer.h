///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	��ʷ������汾��0.8.1.0 (2022/08/03 11:01)

#ifndef RISE_OF_HISTORY_GUI_MIDDLE_LAYER_H
#define RISE_OF_HISTORY_GUI_MIDDLE_LAYER_H

#include "RiseOfHistory/Core/CoreFwd.h"
#include "System/Helper/UnicodeUsing.h"
#include "Framework/MiddleLayer/GUIManagerInterface.h"

namespace RiseOfHistory
{
    class GUIMiddleLayer final : public Framework::GUIManagerInterface
    {
    public:
        using ClassType = GUIMiddleLayer;
        using ParentType = GUIManagerInterface;

        using String = System::String;
        using MiddleLayerPlatform = Framework::MiddleLayerPlatform;
        using EnvironmentDirectory = Framework::EnvironmentDirectory;

    public:
        GUIMiddleLayer(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_FINAL_DECLARE;

        void PrintSelect(const ProjectName& projectName);
        void PrintEngineering(const String& engineeringName);
    };
}

#endif  // RISE_OF_HISTORY_GUI_MIDDLE_LAYER_H