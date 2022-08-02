///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	最后的霸王版本：0.8.0.12 (2022/07/24 0:22)

#include "LoginServerMiddleLayerExport.h"

#include "DllLib.h"
#include "LoginServerMiddleLayer.h"

#ifdef BUILDING_LOGIN_SERVER_MIDDLE_LAYER_STATIC

namespace LoginServerMiddleLayer
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_LOGIN_SERVER_MIDDLE_LAYER_STATIC
