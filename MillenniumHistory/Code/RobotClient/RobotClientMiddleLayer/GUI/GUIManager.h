/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.1 (2023/11/25 20:42)

#ifndef ROBOT_CLIENT_MIDDLE_LAYER_GUI_MIDDLE_LAYER_GUI_H
#define ROBOT_CLIENT_MIDDLE_LAYER_GUI_MIDDLE_LAYER_GUI_H

#include "RobotClient/RobotClientMiddleLayer/RobotClientMiddleLayerDll.h"

#include "RobotClient/RobotClientMiddleLayer/Helper/ExportMacro.h"
#include "Framework/MiddleLayer/GUIManagerInterface.h"

namespace RobotClientMiddleLayer
{
    class ROBOT_CLIENT_MIDDLE_LAYER_DEFAULT_DECLARE GUIManager final : public Framework::GUIManagerInterface
    {
    public:
        using ClassType = GUIManager;
        using ParentType = GUIManagerInterface;

    public:
        GUIManager(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_OVERRIDE_DECLARE;
    };
}

#endif  // ROBOT_CLIENT_MIDDLE_LAYER_GUI_MIDDLE_LAYER_GUI_H
