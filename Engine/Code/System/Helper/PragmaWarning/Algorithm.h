// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.3 (2020/03/02 10:41)

#ifndef SYSTEM_HELPER_PRAGMA_WARNING_ALGORITHM_H
#define SYSTEM_HELPER_PRAGMA_WARNING_ALGORITHM_H 

#include "System/Helper/PragmaWarning.h"

#include STSTEM_WARNING_PUSH

#include SYSTEM_WARNING_DISABLE(26495)

	#include <boost/algorithm/string/trim.hpp>
	#include <boost/algorithm/string/split.hpp>
	#include <boost/algorithm/string/predicate.hpp>
	#include <boost/algorithm/string/classification.hpp>

#include STSTEM_WARNING_POP

#endif // SYSTEM_HELPER_PRAGMA_WARNING_ALGORITHM_H