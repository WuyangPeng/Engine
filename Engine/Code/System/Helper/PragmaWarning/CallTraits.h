/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.3 (2023/12/21 18:07)

#ifndef SYSTEM_HELPER_PRAGMA_WARNING_CALL_TRAITS_H
#define SYSTEM_HELPER_PRAGMA_WARNING_CALL_TRAITS_H

#include "System/Helper/PragmaWarning.h"

#include SYSTEM_WARNING_PUSH

#include SYSTEM_WARNING_DISABLE(26440)
#include SYSTEM_WARNING_DISABLE(26471)
#include SYSTEM_WARNING_DISABLE(26485)
#include SYSTEM_WARNING_DISABLE(26819)
#include SYSTEM_WARNING_DISABLE(26826)

#include <boost/call_traits.hpp>

#include SYSTEM_WARNING_POP

#endif  // SYSTEM_HELPER_PRAGMA_WARNING_CALL_TRAITS_H
