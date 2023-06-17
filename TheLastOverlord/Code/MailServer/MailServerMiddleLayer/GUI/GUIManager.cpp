///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���İ����汾��0.8.0.12 (2022/07/27 14:47)

#include "MailServer/MailServerMiddleLayer/MailServerMiddleLayerExport.h"

#include "GUIManager.h"
#include "MailServer/MailServerMiddleLayer/Macro/MailServerMiddleLayerClassInvariantMacro.h"

MailServerMiddleLayer::GUIManager::GUIManager(Framework::MiddleLayerPlatform middleLayerPlatform, const Framework::EnvironmentDirectory& environmentDirectory)
    : ParentType{ middleLayerPlatform,environmentDirectory }
{
    MAIL_SERVER_MIDDLE_LAYER_CLASS_IS_VALID_CONST_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(MailServerMiddleLayer, GUIManager)
