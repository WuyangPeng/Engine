///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.5 (2023/09/20 13:49)

#ifndef CORE_TOOLS_UNIT_TEST_SUITE_SUITE_IMPL_H
#define CORE_TOOLS_UNIT_TEST_SUITE_SUITE_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/UnitTestSuite/UnitTestComposite.h"

#include <string>
#include <vector>

// ��Ԫ�����׼��ࡣSuiteImplΪ�ڲ��ӿ��࣬�����ӻ�ɾ����Ԫ���ԣ�����ȡ���ԵĽ����
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

        void PrintReport() override;
        void ResetTestData() override;

        NODISCARD int GetPassedNumber() const noexcept override;
        NODISCARD int GetFailedNumber() const noexcept override;
        NODISCARD int GetErrorNumber() const noexcept override;
        NODISCARD std::string GetName() const override;

        void ClearUnitTestCollection() noexcept override;
        void AddUnitTest(const UnitTestCompositeSharedPtr& unitTest) override;
        void RunUnitTest() override;

        void PrintRunUnitTest() override;

    private:
        using UnitTestContainer = std::vector<UnitTestCompositeSharedPtr>;

    private:
        std::string suiteName;
        UnitTestContainer unitTestCollection;
        bool printRunUnitTest;
    };
}

#endif  // CORE_TOOLS_UNIT_TEST_SUITE_SUITE_IMPL_H
