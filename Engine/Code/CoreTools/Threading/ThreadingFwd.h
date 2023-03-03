///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.3 (2023/03/01 15:59)

#ifndef CORE_TOOLS_THREADING_FWD_H
#define CORE_TOOLS_THREADING_FWD_H

namespace CoreTools
{
    enum class MutexCreate;

    class DllMutex;
    class Mutex;
    class ScopedMutex;
    class TryScopedMutex;
    class Event;
    class Semaphore;
    class Thread;
    class ThreadManager;
    class ThreadGuard;
    class ThreadGroup;
}

#endif  // CORE_TOOLS_THREADING_FWD_H