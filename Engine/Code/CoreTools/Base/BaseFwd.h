/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/10 20:05)

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