/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.1 (2023/11/25 20:42)

#ifndef RECHARGE_SERVER_MIDDLE_LAYER_HELPER_EXPORT_MACRO_H
#define RECHARGE_SERVER_MIDDLE_LAYER_HELPER_EXPORT_MACRO_H

#include "CoreTools/Helper/ExportMacro.h"

#define RECHARGE_SERVER_MIDDLE_LAYER_EXPORT_SHARED_PTR(implClassName) \
    EXPORT_SHARED_PTR(RechargeServerMiddleLayer, implClassName, RECHARGE_SERVER_MIDDLE_LAYER_DEFAULT_DECLARE)

#endif  // RECHARGE_SERVER_MIDDLE_LAYER_HELPER_EXPORT_MACRO_H