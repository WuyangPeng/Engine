///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	千年史策版本：0.9.0.12 (2023/06/13 21:42)

#ifndef GAME_CLIENT_CORE_HELPER_EXPORT_MACRO_H
#define GAME_CLIENT_CORE_HELPER_EXPORT_MACRO_H

#include "CoreTools/Helper/ExportMacro.h"

#define GAME_CLIENT_CORE_EXPORT_SHARED_PTR(implClassName) \
    EXPORT_SHARED_PTR(GameClientCore, implClassName, GAME_CLIENT_CORE_DEFAULT_DECLARE)

#endif  // GAME_CLIENT_CORE_HELPER_EXPORT_MACRO_H