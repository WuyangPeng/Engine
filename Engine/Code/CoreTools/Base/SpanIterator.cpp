//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.0.0 (2020/08/18 13:25)

#include "CoreTools/CoreToolsExport.h"

#include "SpanIteratorDetail.h"

#include <string>
#include <vector>

using std::string;
using std::vector;

#ifdef CORE_TOOLS_TEMPLATE_TEST

namespace CoreTools
{
    void SpanIteratorTemplateTest()
    {
        using Container = vector<string>;
        using ContainerIter = Container::iterator;
        using ContainerConstIter = Container::const_iterator;

        Container container{ "1", "3", "5", "7" };

        SpanIterator<ContainerIter> spanIterator{ container.begin(), container.end(), container.begin() };

        [[maybe_unused]] const auto value = *spanIterator;
        [[maybe_unused]] const auto size = spanIterator->size();

        ++spanIterator;
        auto previous = spanIterator++;
        --spanIterator;
        previous = spanIterator--;
        spanIterator += 2;
        spanIterator -= 2;

        [[maybe_unused]] const auto current = spanIterator.GetCurrent();
        [[maybe_unused]] const auto begin = spanIterator.GetBegin();
        [[maybe_unused]] const auto end = spanIterator.GetEnd();
        [[maybe_unused]] const auto difference = spanIterator - spanIterator;
        [[maybe_unused]] const auto remainingCount = spanIterator.GetRemainingCount();

        using Uint16Container = vector<uint16_t>;
        using Uint16ContainerIter = Uint16Container::iterator;

        Uint16Container uint16Container{ 1, 2, 3, 4, 5, 6 };

        SpanIterator<Uint16ContainerIter> uint16SpanIterator{ uint16Container.begin(), uint16Container.end(), uint16Container.begin() };

        [[maybe_unused]] const auto increase = uint16SpanIterator.Increase<uint32_t>();
        uint16SpanIterator.Increase(4u);
    }
}

#else  // !CORE_TOOLS_TEMPLATE_TEST

namespace CoreTools
{
    void SpanIteratorTemplateTest() noexcept
    {
    }
}

#endif  // CORE_TOOLS_TEMPLATE_TEST