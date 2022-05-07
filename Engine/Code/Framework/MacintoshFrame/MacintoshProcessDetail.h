///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.0.7 (2022/05/06 14:07)

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
