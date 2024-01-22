/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/10 20:05)

#ifndef CORE_TOOLS_BASE_FWD_H
#define CORE_TOOLS_BASE_FWD_H

#include "CoreTools/Threading/ThreadingFwd.h"

namespace CoreTools
{
    enum class UniqueIdSelect;

    template <typename T, MutexCreate MutexCreate>
    class Singleton;

    template <typename T, MutexCreate MutexCreate>
    class StaticSingleton;

    template <typename Iter>
    class SpanIterator;

    class UniqueIdManager;
    class Version;
    class LoadingLibrary;
}

#endif  // CORE_TOOLS_BASE_FWD_H