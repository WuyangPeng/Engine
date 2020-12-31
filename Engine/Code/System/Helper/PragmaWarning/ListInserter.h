//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/21 18:35)

#ifndef SYSTEM_HELPER_PRAGMA_WARNING_LIST_INSERTER_H
#define SYSTEM_HELPER_PRAGMA_WARNING_LIST_INSERTER_H

#include "System/Helper/PragmaWarning.h"

#include STSTEM_WARNING_PUSH

#include SYSTEM_WARNING_DISABLE(26440)
#include SYSTEM_WARNING_DISABLE(26477)
#include SYSTEM_WARNING_DISABLE(26481)

#include <boost/assign/list_inserter.hpp>

#include STSTEM_WARNING_POP

#endif  // SYSTEM_HELPER_PRAGMA_WARNING_LIST_INSERTER_H
