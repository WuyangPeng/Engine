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

#include SYSTEM_WARNING_DISABLE(26429)
#include SYSTEM_WARNING_DISABLE(26440)
#include SYSTEM_WARNING_DISABLE(26471)
#include SYSTEM_WARNING_DISABLE(26485)
#include SYSTEM_WARNING_DISABLE(26496)

#include <boost/type_traits/has_equal_to.hpp>
#include <boost/type_traits/has_greater.hpp>
#include <boost/type_traits/has_greater_equal.hpp>
#include <boost/type_traits/has_left_shift.hpp>
#include <boost/type_traits/has_less.hpp>
#include <boost/type_traits/has_less_equal.hpp>
#include <boost/type_traits/has_minus.hpp>
#include <boost/type_traits/has_not_equal_to.hpp>
#include <boost/type_traits/has_plus.hpp>
#include <boost/type_traits/is_const.hpp>
#include <boost/type_traits/is_volatile.hpp>
#include <boost/type_traits/remove_bounds.hpp>
#include <boost/type_traits/remove_const.hpp>
#include <boost/type_traits/remove_volatile.hpp>

#include SYSTEM_WARNING_POP

#endif  // SYSTEM_HELPER_PRAGMA_WARNING_TYPE_TRAITS_H
