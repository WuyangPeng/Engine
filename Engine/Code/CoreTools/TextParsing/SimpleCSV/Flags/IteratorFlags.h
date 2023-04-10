///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.5 (2023/04/03 20:15)

#ifndef CORE_TOOLS_TEXT_PARSING_ITERATOR_FLAGS_H
#define CORE_TOOLS_TEXT_PARSING_ITERATOR_FLAGS_H

namespace CoreTools::SimpleCSV
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

#endif  // CORE_TOOLS_TEXT_PARSING_ITERATOR_FLAGS_H
