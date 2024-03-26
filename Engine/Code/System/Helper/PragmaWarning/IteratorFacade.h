/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/04 19:58)

#ifndef SYSTEM_HELPER_PRAGMA_WARNING_ITERATOR_FACADE_H
#define SYSTEM_HELPER_PRAGMA_WARNING_ITERATOR_FACADE_H

#include "System/Helper/PragmaWarning.h"

#include SYSTEM_WARNING_PUSH

#include SYSTEM_WARNING_DISABLE(26429)
#include SYSTEM_WARNING_DISABLE(26440)
#include SYSTEM_WARNING_DISABLE(26471)
#include SYSTEM_WARNING_DISABLE(26485)
#include SYSTEM_WARNING_DISABLE(26487)
#include SYSTEM_WARNING_DISABLE(26491)
#include SYSTEM_WARNING_DISABLE(26496)
#include SYSTEM_WARNING_DISABLE(26819)

#include <boost/iterator/iterator_facade.hpp>

#include SYSTEM_WARNING_POP

#endif  // SYSTEM_HELPER_PRAGMA_WARNING_ITERATOR_FACADE_H
