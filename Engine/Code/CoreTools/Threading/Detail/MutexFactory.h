///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.2.3 (2021/08/31 22:51)

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
