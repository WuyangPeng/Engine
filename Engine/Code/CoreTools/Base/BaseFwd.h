//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.1 (2020/10/12 9:51)

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