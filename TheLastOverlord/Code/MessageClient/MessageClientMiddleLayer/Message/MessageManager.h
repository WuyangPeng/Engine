/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.0 (2023/11/18 17:09)

#ifndef MESSAGE_CLIENT_MIDDLE_LAYER_MESSAGE_MIDDLE_LAYER_MESSAGE_H
#define MESSAGE_CLIENT_MIDDLE_LAYER_MESSAGE_MIDDLE_LAYER_MESSAGE_H

#include "MessageClient/MessageClientMiddleLayer/MessageClientMiddleLayerDll.h"

#include "MessageClient/MessageClientMiddleLayer/Helper/ExportMacro.h"
#include "Framework/MiddleLayer/MessageManagerInterface.h"

namespace MessageClientMiddleLayer
{
    class MESSAGE_CLIENT_MIDDLE_LAYER_DEFAULT_DECLARE MessageManager final : public Framework::MessageManagerInterface
    {
    public:
        using ClassType = MessageManager;
        using ParentType = MessageManagerInterface;

    public:
        MessageManager(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_OVERRIDE_DECLARE;
    };
}

#endif  // MESSAGE_CLIENT_MIDDLE_LAYER_MESSAGE_MIDDLE_LAYER_MESSAGE_H
