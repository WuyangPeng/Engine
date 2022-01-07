///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.2.1 (2021/08/18 13:52)

#ifndef CORE_TOOLS_HELPER_SUITE_MEMORY_MACRO_TESTING_H
#define CORE_TOOLS_HELPER_SUITE_MEMORY_MACRO_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class MemoryMacroTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = MemoryMacroTesting;
        using ParentType = UnitTest;

    public:
        explicit MemoryMacroTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest() noexcept; 

        NODISCARD static void* Allocator(size_t bytesNumber, MAYBE_UNUSED const FunctionDescribed& functionDescribed);
        static void Deallocator(const void* memBlock, MAYBE_UNUSED const FunctionDescribed& functionDescribed) noexcept;
    };
}

#endif  // CORE_TOOLS_HELPER_SUITE_MEMORY_MACRO_TESTING_H