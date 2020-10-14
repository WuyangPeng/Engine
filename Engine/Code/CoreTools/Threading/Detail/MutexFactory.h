//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.1 (2020/10/12 16:50)

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
        using MutexImplPtr = std::shared_ptr<MutexImpl>;

    public:
        [[nodiscard]] static MutexImplPtr GenerateMutex(MutexCreate mutexCreate);
    };
}

#endif  // CORE_TOOLS_THREADING_MUTEX_FACTORY_H
