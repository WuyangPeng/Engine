///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.3 (2023/08/08 19:51)

#ifndef FRAMEWORK_MACINTOSH_MACINTOSH_PROCESS_DETAIL_H
#define FRAMEWORK_MACINTOSH_MACINTOSH_PROCESS_DETAIL_H

#include "MacintoshProcess.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

#ifdef OPEN_CLASS_INVARIANT

template <typename MacintoshCallBack>
bool Framework::MacintoshProcess<MacintoshCallBack>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

#endif  // FRAMEWORK_MACINTOSH_MACINTOSH_PROCESS_DETAIL_H
