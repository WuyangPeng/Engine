/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.3 (2023/12/26 22:54)

#ifndef DATABASE_GENERATE_MIDDLE_LAYER_NETWORK_MIDDLE_LAYER_NETWORK_H
#define DATABASE_GENERATE_MIDDLE_LAYER_NETWORK_MIDDLE_LAYER_NETWORK_H

#include "DatabaseGenerate/DatabaseGenerateMiddleLayer/DatabaseGenerateMiddleLayerDll.h"

#include "DatabaseGenerate/DatabaseGenerateMiddleLayer/Helper/ExportMacro.h"
#include "Framework/MiddleLayer/NetworkManagerInterface.h"

namespace DatabaseGenerateMiddleLayer
{
    class DATABASE_GENERATE_MIDDLE_LAYER_DEFAULT_DECLARE NetworkManager final : public Framework::NetworkManagerInterface
    {
    public:
        using ClassType = NetworkManager;
        using ParentType = NetworkManagerInterface;

    public:
        NetworkManager(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_OVERRIDE_DECLARE;
    };
}

#endif  // DATABASE_GENERATE_MIDDLE_LAYER_NETWORK_MIDDLE_LAYER_NETWORK_H
