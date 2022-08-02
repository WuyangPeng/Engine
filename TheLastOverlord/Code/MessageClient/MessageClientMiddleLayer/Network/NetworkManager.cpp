///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���İ����汾��0.8.0.12 (2022/07/22 21:17)

#include "MessageClient/MessageClientMiddleLayer/MessageClientMiddleLayerExport.h"

#include "MessageClient/MessageClientMiddleLayer/Macro/MessageClientMiddleLayerClassInvariantMacro.h"
#include "NetworkManager.h"

MessageClientMiddleLayer::NetworkManager::NetworkManager(Framework::MiddleLayerPlatform middleLayerPlatform)
    : ParentType{ middleLayerPlatform }
{
    MESSAGE_CLIENT_MIDDLE_LAYER_CLASS_IS_VALID_CONST_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(MessageClientMiddleLayer, NetworkManager)
