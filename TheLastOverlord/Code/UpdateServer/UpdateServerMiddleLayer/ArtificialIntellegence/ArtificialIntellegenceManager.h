///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���İ����汾��0.8.0.12 (2022/07/29 17:21)

#ifndef UPDATE_SERVER_MIDDLE_LAYER_ARTIFICIAL_INTELLEGENCE_MIDDLE_LAYER_ARTIFICIAL_INTELLEGENCE_H
#define UPDATE_SERVER_MIDDLE_LAYER_ARTIFICIAL_INTELLEGENCE_MIDDLE_LAYER_ARTIFICIAL_INTELLEGENCE_H

#include "UpdateServer/UpdateServerMiddleLayer/UpdateServerMiddleLayerDll.h"

#include "UpdateServer/UpdateServerMiddleLayer/Macro/ExportMacro.h"
#include "Framework/MiddleLayer/ArtificialIntellegenceInterface.h"

namespace UpdateServerMiddleLayer
{
    class UPDATE_SERVER_MIDDLE_LAYER_DEFAULT_DECLARE ArtificialIntellegenceManager : public Framework::ArtificialIntellegenceInterface
    {
    public:
        using ClassType = ArtificialIntellegenceManager;
        using ParentType = Framework::ArtificialIntellegenceInterface;

    public:
        explicit ArtificialIntellegenceManager(Framework::MiddleLayerPlatform middleLayerPlatform, const Framework::EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_OVERRIDE_DECLARE;
    };
}

#endif  // UPDATE_SERVER_MIDDLE_LAYER_ARTIFICIAL_INTELLEGENCE_MIDDLE_LAYER_ARTIFICIAL_INTELLEGENCE_H
