///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	最后的霸王版本：0.8.0.12 (2022/07/27 14:36)

#ifndef MAIL_SERVER_MIDDLE_LAYER_RENDERING_MIDDLE_LAYER_RENDERING_H
#define MAIL_SERVER_MIDDLE_LAYER_RENDERING_MIDDLE_LAYER_RENDERING_H

#include "MailServer/MailServerMiddleLayer/MailServerMiddleLayerDll.h"

#include "MailServer/MailServerMiddleLayer/Macro/ExportMacro.h"
#include "Framework/MiddleLayer/RenderingManagerInterface.h"

namespace MailServerMiddleLayer
{
    class MAIL_SERVER_MIDDLE_LAYER_DEFAULT_DECLARE RenderingManager : public Framework::RenderingManagerInterface
    {
    public:
        using ClassType = RenderingManager;
        using ParentType = Framework::RenderingManagerInterface;

    public:
        explicit RenderingManager(Framework::MiddleLayerPlatform middleLayerPlatform);

        CLASS_INVARIANT_OVERRIDE_DECLARE;
    };
}

#endif  // MAIL_SERVER_MIDDLE_LAYER_RENDERING_MIDDLE_LAYER_RENDERING_H
