/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/21 14:45)

#ifndef USER_INTERFACE_DLL_LIB_H
#define USER_INTERFACE_DLL_LIB_H

#include "Helper/UserMacro.h"

#include "System/SystemLib.h"
#include "CoreTools/CoreToolsLib.h"
#include "Mathematics/MathematicsLib.h"
#include "Rendering/RenderingLib.h"

#if defined(TCRE_USE_MSVC)

    #ifdef USER_INTERFACE_USE_WX_WIDGETS

    #endif  // USER_INTERFACE_USE_WX_WIDGETS

#endif  // TCRE_USE_MSVC

#endif  // USER_INTERFACE_DLL_LIB_H