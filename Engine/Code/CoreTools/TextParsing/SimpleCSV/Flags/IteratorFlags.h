///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/19 19:44)

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
