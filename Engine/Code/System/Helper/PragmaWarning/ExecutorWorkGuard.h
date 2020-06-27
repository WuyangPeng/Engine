// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.2.0.0 (2020/05/08 19:25)

#ifndef SYSTEM_HELPER_PRAGMA_WARNING_EXECUTOR_WORK_GUARD_H
#define SYSTEM_HELPER_PRAGMA_WARNING_EXECUTOR_WORK_GUARD_H 

#include "System/Helper/PragmaWarning.h"

#include STSTEM_WARNING_PUSH

	#include SYSTEM_WARNING_DISABLE(4996)   

	#include <boost/asio/executor_work_guard.hpp>

#include STSTEM_WARNING_POP

#endif // SYSTEM_HELPER_PRAGMA_WARNING_EXECUTOR_WORK_GUARD_H
