//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.7.1.1 (2020/10/23 13:18)

// 单元测试类。UnitTest为外部接口基类，子类要运行的测试在DoRunUnitTest函数中运行。
#ifndef CORE_TOOLS_UNIT_TEST_SUITE_UNIT_TEST_H
#define CORE_TOOLS_UNIT_TEST_SUITE_UNIT_TEST_H

#include "CoreTools/CoreToolsDll.h"

#include "UnitTestComposite.h"
#include "UnitTestSuiteFwd.h"
#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Exception/ExceptionFwd.h"
#include "CoreTools/Helper/ExportMacro.h"

#include <iostream>
#include <string>
#include <type_traits>

namespace boost
{
    namespace timer
    {
        class cpu_timer;
    }
}

namespace std
{
    class exception;
}

 
EXPORT_SHARED_PTR(CoreTools, CpuTimerData, CORE_TOOLS_DEFAULT_DECLARE);
EXPORT_SHARED_PTR(CoreTools, UnitTestData, CORE_TOOLS_DEFAULT_DECLARE);
namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE UnitTest : public UnitTestComposite
    {
    public:
        using ClassType = UnitTest;
        using ParentType = UnitTestComposite;
        using ClassShareType = NonCopyClasses;
        using OStreamShared = CoreTools::OStreamShared;

    public:
        explicit UnitTest(const OStreamShared& streamShared);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        [[nodiscard]] const std::string GetName() const override;
        [[nodiscard]] int GetPassedNumber() const noexcept final;
        [[nodiscard]] int GetFailedNumber() const noexcept final;
        [[nodiscard]] int GetErrorNumber() const noexcept final;

        void PrintReport() final;
        void ResetTestData() final;
        void RunUnitTest() final;

        void PrintRunUnitTest() final;

    protected:
        // Assert用来测试对象的值是否符合预期。Error用来测试是否正确抛出异常。

        void AssertTest(bool condition, const FunctionDescribed& functionDescribed,
                        const std::string& errorMessage = std::string{}, bool failureThrow = false);

        void ErrorTest(bool condition, const FunctionDescribed& functionDescribed, const std::string& errorMessage = std::string{});

        template <typename LhsType, typename RhsType>
        void AssertEqual(const LhsType& lhs, const RhsType& rhs, const FunctionDescribed& functionDescribed,
                         const std::string& errorMessage = std::string{}, bool failureThrow = false);

        template <typename LhsType, typename RhsType>
        void AssertEnumEqual(const LhsType& lhs, const RhsType& rhs, const FunctionDescribed& functionDescribed,
                             const std::string& errorMessage = std::string{}, bool failureThrow = false);

        template <typename LhsType, typename RhsType>
        void AssertEqualDoNotUseMessage(const LhsType& lhs, const RhsType& rhs, const FunctionDescribed& functionDescribed, bool failureThrow = false);

        template <typename LhsType, typename MhsType, typename RhsType>
        void AssertEqual(const LhsType& lhs, const MhsType& mhs, const RhsType& rhs, const FunctionDescribed& functionDescribed,
                         const std::string& errorMessage = std::string{}, bool failureThrow = false);

        template <typename LhsType, typename RhsType>
        void AssertUnequal(const LhsType& lhs, const RhsType& rhs, const FunctionDescribed& functionDescribed,
                           const std::string& errorMessage = std::string{}, bool failureThrow = false);

        template <typename LhsType, typename RhsType>
        void AssertUnequalDoNotUseMessage(const LhsType& lhs, const RhsType& rhs, const FunctionDescribed& functionDescribed, bool failureThrow = false);

        template <typename LhsType, typename RhsType>
        void AssertEnumUnequal(const LhsType& lhs, const RhsType& rhs, const FunctionDescribed& functionDescribed,
                               const std::string& errorMessage = std::string{}, bool failureThrow = false);

        template <typename LhsType, typename RhsType>
        void AssertApproximate(const LhsType& lhs, const RhsType& rhs, const std::common_type_t<LhsType, RhsType>& epsilon,
                               const FunctionDescribed& functionDescribed, const std::string& errorMessage = std::string{}, bool failureThrow = false);

        template <typename Function, typename LhsType, typename RhsType, typename EpsilonType>
        void AssertApproximateUseFunction(Function function, const LhsType& lhs, const RhsType& rhs, const EpsilonType& epsilon,
                                          const FunctionDescribed& functionDescribed, const std::string& errorMessage = std::string{}, bool failureThrow = false);

        // 测试是否在范围内。lhs <= test <= rhs。
        template <typename TestType, typename RangeType>
        void AssertRange(const TestType& test, const RangeType& lhs, const RangeType& rhs, const FunctionDescribed& functionDescribed,
                         const std::string& errorMessage = std::string{}, bool failureThrow = false);

        template <typename LhsType, typename RhsType>
        void AssertEnumLess(const LhsType& lhs, const RhsType& rhs, const FunctionDescribed& functionDescribed,
                            const std::string& errorMessage = std::string{}, bool failureThrow = false);

        template <typename LhsType, typename RhsType>
        void AssertEnumLessEqual(const LhsType& lhs, const RhsType& rhs, const FunctionDescribed& functionDescribed,
                                 const std::string& errorMessage = std::string{}, bool failureThrow = false);

        template <typename LhsType, typename RhsType>
        void AssertEnumGreater(const LhsType& lhs, const RhsType& rhs, const FunctionDescribed& functionDescribed,
                               const std::string& errorMessage = std::string{}, bool failureThrow = false);

        template <typename LhsType, typename RhsType>
        void AssertEnumGreaterEqual(const LhsType& lhs, const RhsType& rhs, const FunctionDescribed& functionDescribed,
                                    const std::string& errorMessage = std::string{}, bool failureThrow = false);

        template <typename LhsType, typename RhsType>
        void AssertLess(const LhsType& lhs, const RhsType& rhs, const FunctionDescribed& functionDescribed,
                        const std::string& errorMessage = std::string{}, bool failureThrow = false);

        template <typename LhsType, typename RhsType>
        void AssertLessEqual(const LhsType& lhs, const RhsType& rhs, const FunctionDescribed& functionDescribed,
                             const std::string& errorMessage = std::string{}, bool failureThrow = false);

        template <typename LhsType, typename RhsType>
        void AssertGreater(const LhsType& lhs, const RhsType& rhs, const FunctionDescribed& functionDescribed,
                           const std::string& errorMessage = std::string{}, bool failureThrow = false);

        template <typename LhsType, typename RhsType>
        void AssertGreaterEqual(const LhsType& lhs, const RhsType& rhs, const FunctionDescribed& functionDescribed,
                                const std::string& errorMessage = std::string{}, bool failureThrow = false);

        template <typename PtrType>
        void AssertEqualNullPtr(const PtrType& ptr, const FunctionDescribed& functionDescribed, const std::string& errorMessage = std::string{}, bool failureThrow = false);

        template <typename PtrType>
        void AssertUnequalNullPtr(const PtrType& ptr, const FunctionDescribed& functionDescribed, const std::string& errorMessage = std::string{}, bool failureThrow = false);

        template <typename TestClass, typename Function>
        void AssertNotThrowException(TestClass* test, Function function, const FunctionDescribed& functionDescribed, const std::string& errorMessage = std::string{});

        template <typename TestClass, typename Function, typename Parameter>
        void AssertNotThrowException(TestClass* test, Function function, const Parameter& parameter,
                                     const FunctionDescribed& functionDescribed, const std::string& errorMessage = std::string{});

        template <typename TestClass, typename Function, typename FirstParameter, typename SecondParameter>
        void AssertNotThrowException(TestClass* test, Function function, const FirstParameter& firstParameter,
                                     const SecondParameter& secondParameter, const FunctionDescribed& functionDescribed, const std::string& errorMessage = std::string{});

        template <typename TestClass, typename Function>
        void AssertThrowException(TestClass* test, Function function, const FunctionDescribed& functionDescribed, const std::string& errorMessage = std::string{});

        template <typename TestClass, typename Function, typename Parameter>
        void AssertThrowException(TestClass* test, Function function, const Parameter& parameter,
                                  const FunctionDescribed& functionDescribed, const std::string& errorMessage = std::string{});

        template <typename TestClass, typename Function, typename FirstParameter, typename SecondParameter>
        void AssertThrowException(TestClass* test, Function function, const FirstParameter& firstParameter,
                                  const SecondParameter& secondParameter, const FunctionDescribed& functionDescribed, const std::string& errorMessage = std::string{});

        void AssertFloatingPointCompleteEqual(float lhs, float rhs, const FunctionDescribed& functionDescribed,
                                              const std::string& errorMessage = std::string{}, bool failureThrow = false);

        void AssertFloatingPointCompleteUnequal(float lhs, float rhs, const FunctionDescribed& functionDescribed,
                                                const std::string& errorMessage = std::string{}, bool failureThrow = false);

        void AssertFloatingPointCompleteEqual(double lhs, double rhs, const FunctionDescribed& functionDescribed,
                                              const std::string& errorMessage = std::string{}, bool failureThrow = false);

        void AssertFloatingPointCompleteUnequal(double lhs, double rhs, const FunctionDescribed& functionDescribed,
                                                const std::string& errorMessage = std::string{}, bool failureThrow = false);

        void AssertEqual(const std::wstring& lhs, const std::wstring& rhs, const FunctionDescribed& functionDescribed,
                         const std::string& errorMessage = std::string{}, bool failureThrow = false);
        void AssertEqual(const char* lhs, const char* rhs, const FunctionDescribed& functionDescribed,
                         const std::string& errorMessage = std::string{}, bool failureThrow = false);
        void AssertEqual(const wchar_t* lhs, const wchar_t* rhs, const FunctionDescribed& functionDescribed,
                         const std::string& errorMessage = std::string{}, bool failureThrow = false);

        template <typename TestClass, typename Function>
        void ExecuteLoopTesting(TestClass* test, Function function);

    private:
        void PrintFailReport(const FunctionDescribed& functionDescribed, const std::string& errorMessage);

        void AssertExceptionInfoLog(const Error& error, const std::string& errorMessage);
        void AssertExceptionInfoLog(const std::exception& error, const FunctionDescribed& functionDescribed, const std::string& errorMessage);
        void AssertExceptionInfoLog(const FunctionDescribed& functionDescribed, const std::string& errorMessage);
        void AssertExceptionErrorLog(const Error& error, const std::string& errorMessage);
        void AssertExceptionErrorLog(const FunctionDescribed& functionDescribed, const std::string& errorMessage);
        void AssertExceptionFatalLog(const std::exception& error, const FunctionDescribed& functionDescribed, const std::string& errorMessage);
        void AssertExceptionFatalLog(const FunctionDescribed& functionDescribed, const std::string& errorMessage);

        [[nodiscard]] virtual std::string GetTestModeDescribe() const;
        virtual void ResetOtherData();
        virtual void TestTimingBegins();
        virtual void TestTimingEnd();

        virtual void DoRunUnitTest() = 0;

    private:
        using CpuTimerDataSharedPtr = std::shared_ptr<CpuTimerData>;
        using UnitTestDataSharedPtr = std::shared_ptr<UnitTestData>;

    private:
        [[nodiscard]] static const std::string GetCorrectThrowExceptionDescribe();
        [[nodiscard]] static const std::string GetErrorThrowExceptionDescribe();
        [[nodiscard]] static const std::string GetCorrectNothrowExceptionDescribe();
        [[nodiscard]] static const std::string GetErrorNothrowExceptionDescribe();

    private:
        UnitTestDataSharedPtr m_Data;
        CpuTimerDataSharedPtr m_CpuTimer;
    };
}
#endif  // CORE_TOOLS_UNIT_TEST_SUITE_UNIT_TEST_H
