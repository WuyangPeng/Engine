///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���İ����汾��0.8.0.12 (2022/07/28 21:41)

#ifndef LOG_SERVER_MIDDLE_LAYER_GUI_MIDDLE_LAYER_GUI_H
#define LOG_SERVER_MIDDLE_LAYER_GUI_MIDDLE_LAYER_GUI_H

#include "LogServer/LogServerMiddleLayer/LogServerMiddleLayerDll.h"

#include "LogServer/LogServerMiddleLayer/Macro/ExportMacro.h"
#include "Framework/MiddleLayer/GUIManagerInterface.h"

namespace LogServerMiddleLayer
{
    class LOG_SERVER_MIDDLE_LAYER_DEFAULT_DECLARE GUIManager : public Framework::GUIManagerInterface
    {
    public:
        using ClassType = GUIManager;
        using ParentType = Framework::GUIManagerInterface;

    public:
        explicit GUIManager(Framework::MiddleLayerPlatform middleLayerPlatform);

        CLASS_INVARIANT_OVERRIDE_DECLARE;
    };
}

#endif  // LOG_SERVER_MIDDLE_LAYER_GUI_MIDDLE_LAYER_GUI_H
