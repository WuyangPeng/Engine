///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.5 (2023/04/03 17:39)

#ifndef CORE_TOOLS_UNIT_TEST_SUITE_UNIT_TEST_H
#define CORE_TOOLS_UNIT_TEST_SUITE_UNIT_TEST_H

#include "CoreTools/CoreToolsDll.h"

#include "UnitTestComposite.h"
#include "UnitTestSuiteFwd.h"
#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Exception/ExceptionFwd.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/TextParsing/SimpleCSV/CellValue.h"

#include <string>
#include <type_traits>

EXPORT_SHARED_PTR(CoreTools, CpuTimerData, CORE_TOOLS_DEFAULT_DECLARE);
EXPORT_SHARED_PTR(CoreTools, UnitTestData, CORE_TOOLS_DEFAULT_DECLARE);

// 单元测试类。UnitTest为外部接口基类，子类要运行的测试在DoRunUnitTest函数中运行。
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
        ~UnitTest() = default;
        UnitTest(const UnitTest& rhs) = delete;
        UnitTest& operator=(const UnitTest& rhs) = delete;
        UnitTest(UnitTest&& rhs) noexcept;
        UnitTest& operator=(UnitTest&& rhs) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD std::string GetName() const override;
        NODISCARD int GetPassedNumber() const noexcept final;
        NODISCARD int GetFailedNumber() const noexcept final;
        NODISCARD int GetErrorNumber() const noexcept final;

        void PrintReport() final;
        void ResetTestData() final;
        void RunUnitTest() final;

        void PrintRunUnitTest() final;

    protected:
        // Assert用来测试对象的值是否符合预期。Error用来测试是否正确抛出异常。

        void AssertTest(bool condition,
                        const FunctionDescribed& functionDescribed,
                        const std::string& errorMessage = std::string{},
                        bool failureThrow = false);

        void AssertTrue() noexcept;

        void ErrorTest(bool condition, const FunctionDescribed& functionDescribed, const std::string& errorMessage = std::string{});
        void ErrorTest(bool condition, const FunctionDescribed& functionDescribed, const std::string_view& errorMessage);

        template <typename LhsType, typename RhsType>
        void AssertEqual(const LhsType& lhs,
                         const RhsType& rhs,
                         const FunctionDescribed& functionDescribed,
                         const std::string& errorMessage = std::string{},
                         bool failureThrow = false);

        template <typename LhsType, typename RhsType>
        void AssertEnumEqual(const LhsType& lhs,
                             const RhsType& rhs,
                             const FunctionDescribed& functionDescribed,
                             const std::string& errorMessage = std::string{},
                             bool failureThrow = false);

        template <typename LhsType, typename MhsType, typename RhsType>
        void AssertEqual(const LhsType& lhs,
                         const MhsType& mhs,
                         const RhsType& rhs,
                         const FunctionDescribed& functionDescribed,
                         const std::string& errorMessage = std::string{},
                         bool failureThrow = false);

        template <typename LhsType, typename RhsType>
        void AssertUnequal(const LhsType& lhs,
                           const RhsType& rhs,
                           const FunctionDescribed& functionDescribed,
                           const std::string& errorMessage = std::string{},
                           bool failureThrow = false);

        template <typename LhsType, typename RhsType>
        void AssertEnumUnequal(const LhsType& lhs,
                               const RhsType& rhs,
                               const FunctionDescribed& functionDescribed,
                               const std::string& errorMessage = std::string{},
                               bool failureThrow = false);

        template <typename LhsType, typename RhsType>
        void AssertApproximate(const LhsType& lhs,
                               const RhsType& rhs,
                               const std::common_type_t<LhsType, RhsType>& epsilon,
                               const FunctionDescribed& functionDescribed,
                               const std::string& errorMessage = std::string{},
                               bool failureThrow = false);

        template <typename Function, typename LhsType, typename RhsType, typename EpsilonType>
        void AssertApproximateUseFunction(Function function,
                                          const LhsType& lhs,
                                          const RhsType& rhs,
                                          const EpsilonType& epsilon,
                                          const FunctionDescribed& functionDescribed,
                                          const std::string& errorMessage = std::string{},
                                          bool failureThrow = false);

        // 测试是否在范围内。lhs <= test <= rhs。
        template <typename TestType, typename RangeType>
        void AssertRange(const TestType& test,
                         const RangeType& lhs,
                         const RangeType& rhs,
                         const FunctionDescribed& functionDescribed,
                         const std::string& errorMessage = std::string{},
                         bool failureThrow = false);

        template <typename LhsType, typename RhsType>
        void AssertEnumLess(const LhsType& lhs,
                            const RhsType& rhs,
                            const FunctionDescribed& functionDescribed,
                            const std::string& errorMessage = std::string{},
                            bool failureThrow = false);

        template <typename LhsType, typename RhsType>
        void AssertEnumLessEqual(const LhsType& lhs,
                                 const RhsType& rhs,
                                 const FunctionDescribed& functionDescribed,
                                 const std::string& errorMessage = std::string{},
                                 bool failureThrow = false);

        template <typename LhsType, typename RhsType>
        void AssertEnumGreater(const LhsType& lhs,
                               const RhsType& rhs,
                               const FunctionDescribed& functionDescribed,
                               const std::string& errorMessage = std::string{},
                               bool failureThrow = false);

        template <typename LhsType, typename RhsType>
        void AssertEnumGreaterEqual(const LhsType& lhs,
                                    const RhsType& rhs,
                                    const FunctionDescribed& functionDescribed,
                                    const std::string& errorMessage = std::string{},
                                    bool failureThrow = false);

        template <typename LhsType, typename RhsType>
        void AssertLess(const LhsType& lhs,
                        const RhsType& rhs,
                        const FunctionDescribed& functionDescribed,
                        const std::string& errorMessage = std::string{},
                        bool failureThrow = false);

        template <typename LhsType, typename RhsType>
        void AssertLessEqual(const LhsType& lhs,
                             const RhsType& rhs,
                             const FunctionDescribed& functionDescribed,
                             const std::string& errorMessage = std::string{},
                             bool failureThrow = false);

        template <typename LhsType, typename RhsType>
        void AssertGreater(const LhsType& lhs,
                           const RhsType& rhs,
                           const FunctionDescribed& functionDescribed,
                           const std::string& errorMessage = std::string{},
                           bool failureThrow = false);

        template <typename LhsType, typename RhsType>
        void AssertGreaterEqual(const LhsType& lhs,
                                const RhsType& rhs,
                                const FunctionDescribed& functionDescribed,
                                const std::string& errorMessage = std::string{},
                                bool failureThrow = false);

        template <typename PtrType>
        void AssertEqualNullPtr(const PtrType& ptr, const FunctionDescribed& functionDescribed, const std::string& errorMessage = std::string{}, bool failureThrow = false);

        template <typename PtrType>
        void AssertUnequalNullPtr(const PtrType& ptr, const FunctionDescribed& functionDescribed, const std::string& errorMessage = std::string{}, bool failureThrow = false);

        template <typename TestClass, typename Function, typename... Types>
        void AssertNotThrowException(TestClass* test, Function function, const FunctionDescribed& functionDescribed, const std::string& errorMessage, Types&&... args);

        template <typename TestClass, typename Function, typename... Types>
        void AssertThrowException(TestClass* test, Function function, const FunctionDescribed& functionDescribed, const std::string& errorMessage, Types&&... args);

        void AssertFloatingPointCompleteEqual(float lhs,
                                              float rhs,
                                              const FunctionDescribed& functionDescribed,
                                              const std::string& errorMessage = std::string{},
                                              bool failureThrow = false);

        void AssertFloatingPointCompleteUnequal(float lhs,
                                                float rhs,
                                                const FunctionDescribed& functionDescribed,
                                                const std::string& errorMessage = std::string{},
                                                bool failureThrow = false);

        void AssertFloatingPointCompleteEqual(double lhs,
                                              double rhs,
                                              const FunctionDescribed& functionDescribed,
                                              const std::string& errorMessage = std::string{},
                                              bool failureThrow = false);

        void AssertFloatingPointCompleteUnequal(double lhs,
                                                double rhs,
                                                const FunctionDescribed& functionDescribed,
                                                const std::string& errorMessage = std::string{},
                                                bool failureThrow = false);

        template <typename LhsType, typename RhsType>
        requires std::is_constructible_v<std::wstring, LhsType> && std::is_constructible_v<std::wstring, RhsType>
        void AssertEqual(const LhsType& lhs,
                         const RhsType& rhs,
                         const FunctionDescribed& functionDescribed,
                         const std::string& errorMessage = std::string{},
                         bool failureThrow = false);

        template <typename LhsType, typename RhsType>
        requires(std::is_constructible_v<std::string, LhsType> && std::is_constructible_v<std::string, RhsType>)
        void AssertEqual(const LhsType& lhs,
                         const RhsType& rhs,
                         const FunctionDescribed& functionDescribed,
                         const std::string& errorMessage = std::string{},
                         bool failureThrow = false);

        void AssertEqual(wchar_t lhs,
                         wchar_t rhs,
                         const FunctionDescribed& functionDescribed,
                         const std::string& errorMessage = std::string{},
                         bool failureThrow = false);

        void AssertEqual(const SimpleCSV::CellValue& lhs,
                         const SimpleCSV::CellValue& rhs,
                         const FunctionDescribed& functionDescribed,
                         const std::string& errorMessage = std::string{},
                         bool failureThrow = false);

        template <typename TestClass, typename Function>
        void ExecuteLoopTesting(TestClass* test, Function function);

        virtual void PrintTipsMessage();

    private:
        void PrintFailReport(const FunctionDescribed& functionDescribed, const std::string& errorMessage);

        void AssertExceptionInfoLog(const Error& error, const std::string& errorMessage);
        void AssertExceptionInfoLog(const std::exception& error, const FunctionDescribed& functionDescribed, const std::string& errorMessage);
        void AssertExceptionInfoLog(const FunctionDescribed& functionDescribed, const std::string& errorMessage);
        void AssertExceptionErrorLog(const Error& error, const std::string& errorMessage);
        void AssertExceptionErrorLog(const FunctionDescribed& functionDescribed, const std::string& errorMessage);
        void AssertExceptionFatalLog(const std::exception& error, const FunctionDescribed& functionDescribed, const std::string& errorMessage);
        void AssertExceptionFatalLog(const FunctionDescribed& functionDescribed, const std::string& errorMessage);

        NODISCARD virtual std::string GetTestModeDescribe() const;
        virtual void ResetOtherData();
        virtual void TestTimingBegins();
        virtual void TestTimingEnd();

        virtual void DoRunUnitTest() = 0;

    private:
        using CpuTimerDataSharedPtr = std::shared_ptr<CpuTimerData>;
        using UnitTestDataSharedPtr = std::shared_ptr<UnitTestData>;

    private:
        NODISCARD static constexpr std::string_view GetCorrectThrowExceptionDescribe()
        {
            using namespace std::literals;

            return "正确的抛出异常："sv;
        }

        NODISCARD static constexpr std::string_view GetErrorThrowExceptionDescribe()
        {
            using namespace std::literals;

            return "错误的抛出异常："sv;
        }

        NODISCARD static constexpr std::string_view GetCorrectNothrowExceptionDescribe()
        {
            using namespace std::literals;

            return "正确的未抛出异常："sv;
        }

        NODISCARD static constexpr std::string_view GetErrorNothrowExceptionDescribe()
        {
            using namespace std::literals;

            return "错误的未抛出异常："sv;
        }

        NODISCARD static std::string GetAssertDescribed(const std::string& assertMessage, const std::string& errorMessage);

    private:
        UnitTestDataSharedPtr unitTestData;
        CpuTimerDataSharedPtr cpuTimer;
    };
}

#endif  // CORE_TOOLS_UNIT_TEST_SUITE_UNIT_TEST_H
