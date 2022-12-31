///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.1.5 (2022/12/16 22:05)

#ifndef SYSTEM_HELPER_PRAGMA_WARNING_TYPE_TRAITS_H
#define SYSTEM_HELPER_PRAGMA_WARNING_TYPE_TRAITS_H

#include "System/Helper/PragmaWarning.h"

#include STSTEM_WARNING_PUSH

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
#include <boost/type_traits/is_const.hpp>
#include <boost/type_traits/is_volatile.hpp>
#include <boost/type_traits/remove_bounds.hpp>
#include <boost/type_traits/remove_const.hpp>
#include <boost/type_traits/remove_volatile.hpp>

#include STSTEM_WARNING_POP

#endif  // SYSTEM_HELPER_PRAGMA_WARNING_TYPE_TRAITS_H
