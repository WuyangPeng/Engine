///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/19 19:44)

#ifndef CORE_TOOLS_TEXT_PARSING_ITERATOR_FLAGS_H
#define CORE_TOOLS_TEXT_PARSING_ITERATOR_FLAGS_H

namespace CoreTools
{
    namespace SimpleCSV
    {
        enum class IteratorDirection
        {
            Forward,
            Reverse
        };

        enum class IteratorLocation
        {
            Begin,
            End
        };
    }
}

#endif  // CORE_TOOLS_TEXT_PARSING_ITERATOR_FLAGS_H