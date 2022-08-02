///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	最后的霸王版本：0.8.0.12 (2022/07/27 21:29)

#include "ChatServer/ChatServerMiddleLayer/ChatServerMiddleLayerExport.h"

#include "ChatServer/ChatServerMiddleLayer/Macro/ChatServerMiddleLayerClassInvariantMacro.h"
#include "GUIManager.h"

ChatServerMiddleLayer::GUIManager::GUIManager(Framework::MiddleLayerPlatform middleLayerPlatform)
    : ParentType{ middleLayerPlatform }
{
    CHAT_SERVER_MIDDLE_LAYER_CLASS_IS_VALID_CONST_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(ChatServerMiddleLayer, GUIManager)
