///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.4 (2022/11/18 23:37)

#ifndef SYSTEM_HELPER_PRAGMA_WARNING_CALL_TRAITS_H
#define SYSTEM_HELPER_PRAGMA_WARNING_CALL_TRAITS_H

#include "System/Helper/PragmaWarning.h"

#include STSTEM_WARNING_PUSH

#include SYSTEM_WARNING_DISABLE(26440)
#include SYSTEM_WARNING_DISABLE(26471)
#include SYSTEM_WARNING_DISABLE(26485)

#include <boost/call_traits.hpp>

#include STSTEM_WARNING_POP

#endif  // SYSTEM_HELPER_PRAGMA_WARNING_CALL_TRAITS_H
