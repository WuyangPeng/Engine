/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/11 18:23)

#ifndef SYSTEM_CONSOLE_SUITE_CONSOLE_STANDARD_HANDLES_TESTING_H
#define SYSTEM_CONSOLE_SUITE_CONSOLE_STANDARD_HANDLES_TESTING_H

#include "ConsoleColourTesting.h"

#include <random>

namespace System
{
    class ConsoleStandardHandlesTesting : public ConsoleColourTesting
    {
    public:
        using ClassType = ConsoleStandardHandlesTesting;
        using ParentType = ConsoleColourTesting;

    public:
        explicit ConsoleStandardHandlesTesting(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    protected:
        using StandardHandleContainer = std::vector<StandardHandle>;
        using StandardHandleContainerConstIter = StandardHandleContainer::const_iterator;

    protected:
        void RandomShuffleStandardHandle(std::default_random_engine& randomEngine);
        NODISCARD StandardHandle GetConsoleStandardHandle(size_t index) const;
        void SetDefaultTextAttribute();

        NODISCARD StandardHandleContainerConstIter begin() const noexcept;
        NODISCARD StandardHandleContainerConstIter end() const noexcept;
        NODISCARD size_t GetStandardHandleSize() const noexcept;

    private:
        StandardHandleContainer standardHandles;
    };
}

#endif  // SYSTEM_CONSOLE_SUITE_CONSOLE_STANDARD_HANDLES_TESTING_H