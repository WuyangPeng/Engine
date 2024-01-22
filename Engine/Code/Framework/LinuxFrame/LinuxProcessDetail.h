/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/11 15:17)

#ifndef FRAMEWORK_LINUX_LINUX_PROCESS_DETAIL_H
#define FRAMEWORK_LINUX_LINUX_PROCESS_DETAIL_H

#include "LinuxProcess.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

#ifdef OPEN_CLASS_INVARIANT

template <typename LinuxCallBack>
bool Framework::LinuxProcess<LinuxCallBack>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

#endif  // FRAMEWORK_LINUX_LINUX_PROCESS_DETAIL_H
