/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.1 (2023/11/25 20:42)

#ifndef DATABASE_GENERATE_MIDDLE_LAYER_OBJECT_LOGIC_MIDDLE_LAYER_OBJECT_LOGIC_H
#define DATABASE_GENERATE_MIDDLE_LAYER_OBJECT_LOGIC_MIDDLE_LAYER_OBJECT_LOGIC_H

#include "DatabaseGenerate/DatabaseGenerateMiddleLayer/DatabaseGenerateMiddleLayerDll.h"

#include "DatabaseGenerate/DatabaseGenerateMiddleLayer/Helper/ExportMacro.h"
#include "Framework/MiddleLayer/ObjectLogicInterface.h"

namespace DatabaseGenerateMiddleLayer
{
    class DATABASE_GENERATE_MIDDLE_LAYER_DEFAULT_DECLARE ObjectLogicManager final : public Framework::ObjectLogicInterface
    {
    public:
        using ClassType = ObjectLogicManager;
        using ParentType = ObjectLogicInterface;

    public:
        ObjectLogicManager(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_OVERRIDE_DECLARE;
    };
}

#endif  // DATABASE_GENERATE_MIDDLE_LAYER_OBJECT_LOGIC_MIDDLE_LAYER_OBJECT_LOGIC_H
