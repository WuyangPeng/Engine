///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/18 1:22)

#ifndef CORE_TOOLS_THREADING_FWD_H
#define CORE_TOOLS_THREADING_FWD_H

namespace CoreTools
{
    enum class MutexCreate;

    class DllMutex;
    class Mutex;
    class ScopedMutex;
    class TryScopedMutex;
    class AtomicInteger;
    class Event;
    class Semaphore;
    class Thread;
    class ThreadManager;

    class ThreadGuard;
}

#endif  // CORE_TOOLS_THREADING_FWD_H