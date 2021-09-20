///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨�����԰汾��0.7.0.0 (2021/01/24 16:55)

#include "CppFootprintAndPerformanceOptimizationPlaceholderTesting.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "Example/BookCpp/CppFootprintAndPerformanceOptimization/Helper/CppFootprintAndPerformanceOptimizationClassInvariantMacro.h"

BookIntermediate::CppFootprintAndPerformanceOptimization::CppFootprintAndPerformanceOptimizationPlaceholderTesting::CppFootprintAndPerformanceOptimizationPlaceholderTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CPP_FOOTPRINT_AND_PERFORMANCE_OPTIMIZATION_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BookIntermediate::CppFootprintAndPerformanceOptimization, CppFootprintAndPerformanceOptimizationPlaceholderTesting)

void BookIntermediate::CppFootprintAndPerformanceOptimization::CppFootprintAndPerformanceOptimizationPlaceholderTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void BookIntermediate::CppFootprintAndPerformanceOptimization::CppFootprintAndPerformanceOptimizationPlaceholderTesting::MainTest() noexcept
{
}
