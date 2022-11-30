///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.1.4 (2022/11/05 18:45)

#ifndef SYSTEM_VULKAN_SUITE_VULKAN_TESTING_H
#define SYSTEM_VULKAN_SUITE_VULKAN_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class VulkanTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = VulkanTesting;
        using ParentType = UnitTest;

    public:
        explicit VulkanTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest() noexcept;
    };
}

#endif  // SYSTEM_VULKAN_SUITE_VULKAN_TESTING_H