///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.7.2.2 (2021/08/26 18:54)

#ifndef CORE_TOOLS_BASE_FWD_H
#define CORE_TOOLS_BASE_FWD_H

namespace CoreTools
{
    enum class UniqueIDSelect;

    template <typename T>
    class Singleton;

    template <typename T>
    class StaticSingleton;

    template <typename Iter>
    class SpanIterator;

    class UniqueIDManager;
    class Version;
    class LoadingLibrary;
}

#endif  // CORE_TOOLS_BASE_FWD_H