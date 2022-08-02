///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	最后的霸王版本：0.8.0.12 (2022/07/26 19:20)

#ifndef OFFLINE_SERVER_MIDDLE_LAYER_MACRO_EXPORT_MACRO_H
#define OFFLINE_SERVER_MIDDLE_LAYER_MACRO_EXPORT_MACRO_H

#include "CoreTools/Helper/ExportMacro.h"

#define OFFLINE_SERVER_MIDDLE_LAYER_EXPORT_SHARED_PTR(implClassName) \
    EXPORT_SHARED_PTR(OfflineServerMiddleLayer, implClassName, OFFLINE_SERVER_MIDDLE_LAYER_DEFAULT_DECLARE)

#endif  // OFFLINE_SERVER_MIDDLE_LAYER_MACRO_EXPORT_MACRO_H
