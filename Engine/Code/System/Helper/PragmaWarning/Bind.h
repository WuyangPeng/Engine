/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/21 18:07)

#ifndef SYSTEM_HELPER_PRAGMA_WARNING_BIND_H
#define SYSTEM_HELPER_PRAGMA_WARNING_BIND_H

#include "System/Helper/PragmaWarning.h"

#include SYSTEM_WARNING_PUSH

#include SYSTEM_WARNING_DISABLE(26434)
#include SYSTEM_WARNING_DISABLE(26437)
#include SYSTEM_WARNING_DISABLE(26440)
#include SYSTEM_WARNING_DISABLE(26455)
#include SYSTEM_WARNING_DISABLE(26819)
#include SYSTEM_WARNING_DISABLE(26826)

#include <boost/bind/bind.hpp>

#include SYSTEM_WARNING_POP

#endif  // SYSTEM_HELPER_PRAGMA_WARNING_BIND_H
