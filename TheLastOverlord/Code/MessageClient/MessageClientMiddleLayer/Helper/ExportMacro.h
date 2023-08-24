/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：0.9.1.3 (2023/08/21 10:42)

#ifndef MESSAGE_CLIENT_MIDDLE_LAYER_HELPER_EXPORT_MACRO_H
#define MESSAGE_CLIENT_MIDDLE_LAYER_HELPER_EXPORT_MACRO_H

#include "CoreTools/Helper/ExportMacro.h"

#define MESSAGE_CLIENT_MIDDLE_LAYER_EXPORT_SHARED_PTR(implClassName) \
    EXPORT_SHARED_PTR(MessageClientMiddleLayer, implClassName, MESSAGE_CLIENT_MIDDLE_LAYER_DEFAULT_DECLARE)

#endif  // MESSAGE_CLIENT_MIDDLE_LAYER_HELPER_EXPORT_MACRO_H