///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/12 14:27)

#ifndef CORE_TOOLS_BASE_FWD_H
#define CORE_TOOLS_BASE_FWD_H

#include "CoreTools/Threading/ThreadingFwd.h"

namespace CoreTools
{
    enum class UniqueIDSelect;

    template <typename T, MutexCreate mutexCreate>
    class Singleton;

    template <typename T, MutexCreate mutexCreate>
    class StaticSingleton;

    template <typename Iter>
    class SpanIterator;

    class UniqueIDManager;
    class Version;
    class LoadingLibrary;
}

#endif  // CORE_TOOLS_BASE_FWD_H