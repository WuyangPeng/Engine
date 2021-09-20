///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���İ����汾��0.7.0.1 (2021/02/18 15:14)

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
