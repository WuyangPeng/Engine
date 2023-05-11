///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���İ����汾��0.8.0.12 (2022/07/27 14:34)

#ifndef MAIL_SERVER_MIDDLE_LAYER_RESOURCE_MIDDLE_LAYER_RESOURCE_H
#define MAIL_SERVER_MIDDLE_LAYER_RESOURCE_MIDDLE_LAYER_RESOURCE_H

#include "MailServer/MailServerMiddleLayer/MailServerMiddleLayerDll.h"

#include "MailServer/MailServerMiddleLayer/Macro/ExportMacro.h"
#include "Framework/MiddleLayer/ResourceManagerInterface.h"

namespace MailServerMiddleLayer
{
    class MAIL_SERVER_MIDDLE_LAYER_DEFAULT_DECLARE ResourceManager : public Framework::ResourceManagerInterface
    {
    public:
        using ClassType = ResourceManager;
        using ParentType = Framework::ResourceManagerInterface;

    public:
        explicit ResourceManager(Framework::MiddleLayerPlatform middleLayerPlatform);

        CLASS_INVARIANT_OVERRIDE_DECLARE;
    };
}

#endif  // MAIL_SERVER_MIDDLE_LAYER_RESOURCE_MIDDLE_LAYER_RESOURCE_H