///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 11:38)

#ifndef RENDERING_RENDERERS_VIEWPORT_MANAGEMENT_H
#define RENDERING_RENDERERS_VIEWPORT_MANAGEMENT_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/Base/SingletonDetail.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/Helper/SingletonMacro.h"

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE ViewportManagement
    {
    public:
        using ClassType = ViewportManagement;
    };
}

#endif  // RENDERING_RENDERERS_VIEWPORT_MANAGEMENT_H
