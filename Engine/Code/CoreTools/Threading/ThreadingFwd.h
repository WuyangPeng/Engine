//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.1 (2020/10/12 16:47)

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
}

#endif  // CORE_TOOLS_THREADING_FWD_H