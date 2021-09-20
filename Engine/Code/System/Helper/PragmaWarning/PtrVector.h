///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.1.1 (2021/03/10 14:28)

#ifndef SYSTEM_HELPER_PRAGMA_WARNING_PTR_VECTOR_H
#define SYSTEM_HELPER_PRAGMA_WARNING_PTR_VECTOR_H

#include "System/Helper/PragmaWarning.h"

#include STSTEM_WARNING_PUSH

#include SYSTEM_WARNING_DISABLE(26432)
#include SYSTEM_WARNING_DISABLE(26433)
#include SYSTEM_WARNING_DISABLE(26434)
#include SYSTEM_WARNING_DISABLE(26440)
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26447)
#include SYSTEM_WARNING_DISABLE(26455)
#include SYSTEM_WARNING_DISABLE(26481)
#include SYSTEM_WARNING_DISABLE(26487)

#include <boost/ptr_container/ptr_vector.hpp>

#include STSTEM_WARNING_POP

#endif  // SYSTEM_HELPER_PRAGMA_WARNING_PTR_VECTOR_H
