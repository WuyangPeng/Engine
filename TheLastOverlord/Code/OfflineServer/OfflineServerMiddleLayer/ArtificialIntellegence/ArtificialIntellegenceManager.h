///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���İ����汾��0.8.0.12 (2022/07/26 19:22)

#ifndef OFFLINE_SERVER_MIDDLE_LAYER_ARTIFICIAL_INTELLEGENCE_MIDDLE_LAYER_ARTIFICIAL_INTELLEGENCE_H
#define OFFLINE_SERVER_MIDDLE_LAYER_ARTIFICIAL_INTELLEGENCE_MIDDLE_LAYER_ARTIFICIAL_INTELLEGENCE_H

#include "OfflineServer/OfflineServerMiddleLayer/OfflineServerMiddleLayerDll.h"

#include "OfflineServer/OfflineServerMiddleLayer/Macro/ExportMacro.h"
#include "Framework/MiddleLayer/ArtificialIntellegenceInterface.h"

namespace OfflineServerMiddleLayer
{
    class OFFLINE_SERVER_MIDDLE_LAYER_DEFAULT_DECLARE ArtificialIntellegenceManager : public Framework::ArtificialIntellegenceInterface
    {
    public:
        using ClassType = ArtificialIntellegenceManager;
        using ParentType = Framework::ArtificialIntellegenceInterface;

    public:
        explicit ArtificialIntellegenceManager(Framework::MiddleLayerPlatform middleLayerPlatform, const Framework::EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_OVERRIDE_DECLARE;
    };
}

#endif  // OFFLINE_SERVER_MIDDLE_LAYER_ARTIFICIAL_INTELLEGENCE_MIDDLE_LAYER_ARTIFICIAL_INTELLEGENCE_H
