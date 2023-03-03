///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.3 (2023/03/01 16:19)

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
