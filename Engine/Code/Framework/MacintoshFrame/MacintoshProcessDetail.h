/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 15:16)

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
