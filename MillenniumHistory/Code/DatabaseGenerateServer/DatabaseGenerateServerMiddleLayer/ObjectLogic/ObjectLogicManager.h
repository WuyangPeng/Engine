///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.0 (2023/06/19 21:49)

#ifndef DATABASE_GENERATE_SERVER_MIDDLE_LAYER_OBJECT_LOGIC_OBJECT_LOGIC_MANAGER_H
#define DATABASE_GENERATE_SERVER_MIDDLE_LAYER_OBJECT_LOGIC_OBJECT_LOGIC_MANAGER_H

#include "DatabaseGenerateServer/DatabaseGenerateServerMiddleLayer/DatabaseGenerateServerMiddleLayerDll.h"

#include "DatabaseGenerateServer/DatabaseGenerateServerMiddleLayer/Helper/ExportMacro.h"
#include "Framework/MiddleLayer/ObjectLogicInterface.h"

namespace DatabaseGenerateServerMiddleLayer
{
    class DATABASE_GENERATE_SERVER_MIDDLE_LAYER_DEFAULT_DECLARE ObjectLogicManager : public Framework::ObjectLogicInterface
    {
    public:
        using ClassType = ObjectLogicManager;
        using ParentType = Framework::ObjectLogicInterface;

        using MiddleLayerPlatform = Framework::MiddleLayerPlatform;
        using EnvironmentDirectory = Framework::EnvironmentDirectory;

    public:
        ObjectLogicManager(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_OVERRIDE_DECLARE;
    };
}

#endif  // DATABASE_GENERATE_SERVER_MIDDLE_LAYER_OBJECT_LOGIC_OBJECT_LOGIC_MANAGER_H
