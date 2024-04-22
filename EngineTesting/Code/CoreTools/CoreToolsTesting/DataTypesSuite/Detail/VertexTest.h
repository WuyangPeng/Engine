/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/19 14:38)

#ifndef CORE_TOOLS_DATA_TYPES_SUITE_VERTEX_TEST_H
#define CORE_TOOLS_DATA_TYPES_SUITE_VERTEX_TEST_H

#include "CoreTools/Helper/UserMacro.h"

namespace CoreTools
{
    class VertexTest
    {
    public:
        using ClassType = VertexTest;

    public:
        VertexTest() noexcept;
        VertexTest(int previous, int current, int next) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetPrevious() const noexcept;
        NODISCARD int GetCurrent() const noexcept;
        NODISCARD int GetNext() const noexcept;

        void SetPrevious(int aPrevious) noexcept;
        void SetCurrent(int aCurrent) noexcept;
        void SetNext(int aNext) noexcept;

        NODISCARD double GetWeight() const noexcept;

    private:
        int previous;
        int current;
        int next;
    };
}

#endif  // CORE_TOOLS_DATA_TYPES_SUITE_VERTEX_TEST_H