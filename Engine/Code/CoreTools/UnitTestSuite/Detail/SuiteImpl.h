///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/14 18:49)

// ��Ԫ�����׼��ࡣSuiteImplΪ�ڲ��ӿ��࣬�����ӻ�ɾ����Ԫ���ԣ�����ȡ���ԵĽ����
#ifndef CORE_TOOLS_UNIT_TEST_SUITE_SUITE_IMPL_H
#define CORE_TOOLS_UNIT_TEST_SUITE_SUITE_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/UnitTestSuite/UnitTestComposite.h"

#include <iostream>
#include <string>
#include <vector>

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE SuiteImpl final : public UnitTestComposite
    {
    public:
        using ClassType = SuiteImpl;
        using ParentType = UnitTestComposite;

    public:
        explicit SuiteImpl(const std::string& name, const OStreamShared& streamShared, bool printRunUnitTest);

        CLASS_INVARIANT_FINAL_DECLARE;

#ifdef OPEN_CLASS_INVARIANT
        NODISCARD bool IsUnitTestValid() const noexcept;
#endif  // OPEN_CLASS_INVARIANT

        void PrintReport() final;
        void ResetTestData() final;

        NODISCARD int GetPassedNumber() const noexcept final;
        NODISCARD int GetFailedNumber() const noexcept final;
        NODISCARD int GetErrorNumber() const noexcept final;
        NODISCARD std::string GetName() const final;

        void ClearUnitTestCollection() noexcept final;
        void AddUnitTest(const UnitTestCompositeSharedPtr& unitTest) final;
        void RunUnitTest() final;

        void PrintRunUnitTest() final;

    private:
        using UnitTestContainer = std::vector<UnitTestCompositeSharedPtr>;

    private:
        std::string suiteName;
        UnitTestContainer unitTestCollection;
        bool printRunUnitTest;
    };
}

#endif  // CORE_TOOLS_UNIT_TEST_SUITE_SUITE_IMPL_H
