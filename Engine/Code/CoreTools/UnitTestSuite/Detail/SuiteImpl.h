//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.2.0 (2020/10/23 11:23)

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
        explicit SuiteImpl(const std::string& name, const OStreamShared& osPtr, bool printRunUnitTest);

#ifdef OPEN_CLASS_INVARIANT
        CLASS_INVARIANT_FINAL_DECLARE;
        [[nodiscard]] bool IsUnitTestValid() const noexcept;
#endif  // OPEN_CLASS_INVARIANT

        void PrintReport() final;
        void ResetTestData() final;

        [[nodiscard]] int GetPassedNumber() const noexcept final;
        [[nodiscard]] int GetFailedNumber() const noexcept final;
        [[nodiscard]] int GetErrorNumber() const noexcept final;
        [[nodiscard]] const std::string GetName() const final;

        void ClearUnitTestCollection() noexcept final;
        void AddUnitTest(const UnitTestCompositeSharedPtr& unitTest) final;
        void RunUnitTest() final;

        void PrintRunUnitTest() final;

    private:
        using UnitTestContainer = std::vector<UnitTestCompositeSharedPtr>;

    private:
        std::string m_SuiteName;
        UnitTestContainer m_UnitTestCollection;
        bool m_PrintRunUnitTest;
    };
}

#endif  // CORE_TOOLS_UNIT_TEST_SUITE_SUITE_IMPL_H
