/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.9 (2024/05/18 20:24)

#ifndef CORE_TOOLS_DATA_TYPES_SUITE_SHARED_PTR_COMPARE_TESTING_H
#define CORE_TOOLS_DATA_TYPES_SUITE_SHARED_PTR_COMPARE_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class SharedPtrCompareTesting final : public UnitTest
    {
    public:
        using ClassType = SharedPtrCompareTesting;
        using ParentType = UnitTest;

    public:
        explicit SharedPtrCompareTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        using SharedPtr = std::shared_ptr<int>;

    private:
        void MainTest();
        void DoRunUnitTest() override;

        void SharedPtrCompareTest();

        void SharedPtrEqualTest(const SharedPtr& lhsSharedPtr, const SharedPtr& rhsSharedPtr);
        void SharedPtrUnequalTest(const SharedPtr& lhsSharedPtr, const SharedPtr& rhsSharedPtr);
        void SharedPtrLessTest(const SharedPtr& lhsSharedPtr, const SharedPtr& rhsSharedPtr);
        void SharedPtrLessEqualTest(const SharedPtr& lhsSharedPtr, const SharedPtr& rhsSharedPtr);
        void SharedPtrGreaterTest(const SharedPtr& lhsSharedPtr, const SharedPtr& rhsSharedPtr);
        void SharedPtrGreaterEqualTest(const SharedPtr& lhsSharedPtr, const SharedPtr& rhsSharedPtr);
    };
}

#endif  // CORE_TOOLS_DATA_TYPES_SUITE_SHARED_PTR_COMPARE_TESTING_H