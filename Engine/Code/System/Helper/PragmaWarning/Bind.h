///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/13 18:10)

#ifndef SYSTEM_HELPER_PRAGMA_WARNING_BIND_H
#define SYSTEM_HELPER_PRAGMA_WARNING_BIND_H

#include "System/Helper/PragmaWarning.h"

#include STSTEM_WARNING_PUSH

#include SYSTEM_WARNING_DISABLE(26434)
#include SYSTEM_WARNING_DISABLE(26440)
#include SYSTEM_WARNING_DISABLE(26455)

#include <boost/bind/bind.hpp>

#include STSTEM_WARNING_POP

#endif  // SYSTEM_HELPER_PRAGMA_WARNING_BIND_H
