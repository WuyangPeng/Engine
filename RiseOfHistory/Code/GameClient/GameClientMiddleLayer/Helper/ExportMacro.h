///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.0 (2023/06/19 15:21)

#ifndef GAME_CLIENT_MIDDLE_LAYER_HELPER_EXPORT_MACRO_H
#define GAME_CLIENT_MIDDLE_LAYER_HELPER_EXPORT_MACRO_H

#include "CoreTools/Helper/ExportMacro.h"

#define GAME_CLIENT_MIDDLE_LAYER_EXPORT_SHARED_PTR(implClassName) \
    EXPORT_SHARED_PTR(GameClientMiddleLayer, implClassName, GAME_CLIENT_MIDDLE_LAYER_DEFAULT_DECLARE)

#endif  // GAME_CLIENT_MIDDLE_LAYER_HELPER_EXPORT_MACRO_H