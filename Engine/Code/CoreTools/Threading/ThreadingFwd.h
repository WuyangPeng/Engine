///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/18 1:22)

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