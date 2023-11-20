/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.0 (2023/11/19 00:20)

#ifndef GATEWAY_SERVER_MIDDLE_LAYER_HELPER_EXPORT_MACRO_H
#define GATEWAY_SERVER_MIDDLE_LAYER_HELPER_EXPORT_MACRO_H

#include "CoreTools/Helper/ExportMacro.h"

#define GATEWAY_SERVER_MIDDLE_LAYER_EXPORT_SHARED_PTR(implClassName) \
    EXPORT_SHARED_PTR(GatewayServerMiddleLayer, implClassName, GATEWAY_SERVER_MIDDLE_LAYER_DEFAULT_DECLARE)

#endif  // GATEWAY_SERVER_MIDDLE_LAYER_HELPER_EXPORT_MACRO_H