///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���İ����汾��0.8.0.12 (2022/07/27 14:51)

#include "MailServer/MailServerMiddleLayer/MailServerMiddleLayerExport.h"

#include "AudioManager.h"
#include "MailServer/MailServerMiddleLayer/Macro/MailServerMiddleLayerClassInvariantMacro.h"

MailServerMiddleLayer::AudioManager::AudioManager(Framework::MiddleLayerPlatform middleLayerPlatform)
    : ParentType{ middleLayerPlatform }
{
    MAIL_SERVER_MIDDLE_LAYER_CLASS_IS_VALID_CONST_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(MailServerMiddleLayer, AudioManager)