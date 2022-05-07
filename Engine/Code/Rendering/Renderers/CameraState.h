///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/21 18:48)

#ifndef RENDERING_RENDERERS_CAMERA_STATE_H
#define RENDERING_RENDERERS_CAMERA_STATE_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/Base/SingletonDetail.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/Helper/SingletonMacro.h"

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE CameraState
    {
    public:
        using ClassType = CameraState;
    };
}

#endif  // RENDERING_RENDERERS_CAMERA_STATE_H
