/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.2 (2023/12/17 19:26)

#ifndef BACKGROUND_CLIENT_MIDDLE_LAYER_GUI_MIDDLE_LAYER_GUI_H
#define BACKGROUND_CLIENT_MIDDLE_LAYER_GUI_MIDDLE_LAYER_GUI_H

#include "BackgroundClient/BackgroundClientMiddleLayer/BackgroundClientMiddleLayerDll.h"

#include "BackgroundClient/BackgroundClientMiddleLayer/Helper/ExportMacro.h"
#include "Framework/MiddleLayer/GUIManagerInterface.h"

namespace BackgroundClientMiddleLayer
{
    class BACKGROUND_CLIENT_MIDDLE_LAYER_DEFAULT_DECLARE GUIManager final : public Framework::GUIManagerInterface
    {
    public:
        using ClassType = GUIManager;
        using ParentType = GUIManagerInterface;

    public:
        GUIManager(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_OVERRIDE_DECLARE;
    };
}

#endif  // BACKGROUND_CLIENT_MIDDLE_LAYER_GUI_MIDDLE_LAYER_GUI_H
