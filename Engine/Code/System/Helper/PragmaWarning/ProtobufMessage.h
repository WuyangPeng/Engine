/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/04 20:01)

#ifndef SYSTEM_HELPER_PRAGMA_WARNING_TYPE_TRAITS_H
#define SYSTEM_HELPER_PRAGMA_WARNING_TYPE_TRAITS_H

#include "System/Helper/PragmaWarning.h"

#include SYSTEM_WARNING_PUSH

#include SYSTEM_WARNING_DISABLE(4018)
#include SYSTEM_WARNING_DISABLE(4100)
#include SYSTEM_WARNING_DISABLE(4127)
#include SYSTEM_WARNING_DISABLE(4251)
#include SYSTEM_WARNING_DISABLE(4267)
#include SYSTEM_WARNING_DISABLE(4458)

#include <google/protobuf/message.h>

#include SYSTEM_WARNING_POP

#endif  // SYSTEM_HELPER_PRAGMA_WARNING_TYPE_TRAITS_H
