/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��0.9.1.3 (2023/08/21 10:43)

#ifndef LOG_SERVER_MIDDLE_LAYER_ARTIFICIAL_INTELLIGENCE_MIDDLE_LAYER_ARTIFICIAL_INTELLIGENCE_H
#define LOG_SERVER_MIDDLE_LAYER_ARTIFICIAL_INTELLIGENCE_MIDDLE_LAYER_ARTIFICIAL_INTELLIGENCE_H

#include "LogServer/LogServerMiddleLayer/LogServerMiddleLayerDll.h"

#include "LogServer/LogServerMiddleLayer/Helper/ExportMacro.h"
#include "Framework/MiddleLayer/ArtificialIntelligenceInterface.h"

namespace LogServerMiddleLayer
{
    class LOG_SERVER_MIDDLE_LAYER_DEFAULT_DECLARE ArtificialIntelligenceManager : public Framework::ArtificialIntelligenceInterface
    {
    public:
        using ClassType = ArtificialIntelligenceManager;
        using ParentType = ArtificialIntelligenceInterface;

    public:
        ArtificialIntelligenceManager(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_OVERRIDE_DECLARE;
    };
}

#endif  // LOG_SERVER_MIDDLE_LAYER_ARTIFICIAL_INTELLIGENCE_MIDDLE_LAYER_ARTIFICIAL_INTELLIGENCE_H