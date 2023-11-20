/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.0 (2023/11/18 17:09)

#ifndef LOGIN_SERVER_MIDDLE_LAYER_HELPER_EXPORT_MACRO_H
#define LOGIN_SERVER_MIDDLE_LAYER_HELPER_EXPORT_MACRO_H

#include "CoreTools/Helper/ExportMacro.h"

#define LOGIN_SERVER_MIDDLE_LAYER_EXPORT_SHARED_PTR(implClassName) \
    EXPORT_SHARED_PTR(LoginServerMiddleLayer, implClassName, LOGIN_SERVER_MIDDLE_LAYER_DEFAULT_DECLARE)

#endif  // LOGIN_SERVER_MIDDLE_LAYER_HELPER_EXPORT_MACRO_H