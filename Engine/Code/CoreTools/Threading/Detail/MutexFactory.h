/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/03/30 18:00)

#ifndef CORE_TOOLS_THREADING_MUTEX_FACTORY_H
#define CORE_TOOLS_THREADING_MUTEX_FACTORY_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Threading/ThreadingInternalFwd.h"

#include <memory>

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE MutexFactory final
    {
    public:
        using ClassType = MutexFactory;

        using MutexImplSharedPtr = std::shared_ptr<MutexImpl>;

    public:
        NODISCARD static MutexImplSharedPtr Create(MutexCreate mutexCreate);
    };
}

#endif  // CORE_TOOLS_THREADING_MUTEX_FACTORY_H
