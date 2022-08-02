///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���İ����汾��0.8.0.12 (2022/07/29 21:20)

#ifndef DATABASE_SERVER_MIDDLE_LAYER_GUI_MIDDLE_LAYER_GUI_H
#define DATABASE_SERVER_MIDDLE_LAYER_GUI_MIDDLE_LAYER_GUI_H

#include "DatabaseServer/DatabaseServerMiddleLayer/DatabaseServerMiddleLayerDll.h"

#include "DatabaseServer/DatabaseServerMiddleLayer/Macro/ExportMacro.h"
#include "Framework/MiddleLayer/GUIManagerInterface.h"

namespace DatabaseServerMiddleLayer
{
    class DATABASE_SERVER_MIDDLE_LAYER_DEFAULT_DECLARE GUIManager : public Framework::GUIManagerInterface
    {
    public:
        using ClassType = GUIManager;
        using ParentType = Framework::GUIManagerInterface;

    public:
        explicit GUIManager(Framework::MiddleLayerPlatform middleLayerPlatform);

        CLASS_INVARIANT_OVERRIDE_DECLARE;
    };
}

#endif  // DATABASE_SERVER_MIDDLE_LAYER_GUI_MIDDLE_LAYER_GUI_H
