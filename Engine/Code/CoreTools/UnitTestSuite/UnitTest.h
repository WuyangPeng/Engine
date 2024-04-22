/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/12 11:21)

#ifndef CORE_TOOLS_UNIT_TEST_SUITE_UNIT_TEST_H
#define CORE_TOOLS_UNIT_TEST_SUITE_UNIT_TEST_H

#include "CoreTools/CoreToolsDll.h"

#include "UnitTestComposite.h"
#include "System/Helper/PragmaWarning/TypeTraits.h"
#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Exception/ExceptionFwd.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/LogManager/LogManagerFwd.h"
#include "CoreTools/TextParsing/SimpleCSV/CellValue.h"

#include <string>
#include <type_traits>

EXPORT_SHARED_PTR(CoreTools, CpuTimerData, CORE_TOOLS_DEFAULT_DECLARE);
EXPORT_SHARED_PTR(CoreTools, UnitTestData, CORE_TOOLS_DEFAULT_DECLARE);

/// ��Ԫ�����ࡣ
/// UnitTestΪ�ⲿ�ӿڻ��࣬����Ҫ���еĲ�����DoRunUnitTest���������С�
namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE UnitTest : public UnitTestComposite
    {
    public:
        using ClassType = UnitTest;
        using ParentType = UnitTestComposite;

        /// ���������ֱ��ʹ��OStreamShared
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
        /// Assert�������Զ����ֵ�Ƿ����Ԥ�ڡ�
        /// Error���������Ƿ���ȷ�׳��쳣��

        void AssertTest(bool condition,
                        const FunctionDescribed& functionDescribed,
                        const std::string& errorMessage = std::string{},
                        bool failureThrow = false);

        void AssertTrue() noexcept;

        void ErrorTest(bool condition, const FunctionDescribed& functionDescribed, const std::string& errorMessage = std::string{});
        void ErrorTest(bool condition, const FunctionDescribed& functionDescribed, const std::string_view& errorMessage);

        template <typename LhsType, typename RhsType>
        requires(!(std::is_same_v<std::remove_all_extents_t<LhsType>, char> && std::is_same_v<std::remove_all_extents_t<RhsType>, char>) &&
                 !(std::is_same_v<std::remove_all_extents_t<LhsType>, wchar_t> && std::is_same_v<std::remove_all_extents_t<RhsType>, wchar_t>) &&
                 !(std::is_constructible_v<std::string, LhsType> && std::is_constructible_v<std::string, RhsType>) &&
                 !(std::is_constructible_v<std::wstring, LhsType> && std::is_constructible_v<std::wstring, RhsType>) &&
                 boost::has_equal_to<LhsType, RhsType, bool>::value &&
                 !(std::is_enum_v<LhsType> && std::is_enum_v<RhsType>))
        void AssertEqual(const LhsType& lhs,
                         const RhsType& rhs,
                         const FunctionDescribed& functionDescribed,
                         const std::string& errorMessage = std::string{},
                         bool failureThrow = false);

        template <typename LhsType, typename RhsType>
        requires(std::is_enum_v<LhsType> && std::is_enum_v<RhsType>)
        void AssertEqual(const LhsType& lhs,
                         const RhsType& rhs,
                         const FunctionDescribed& functionDescribed,
                         const std::string& errorMessage = std::string{},
                         bool failureThrow = false);

        template <typename LhsType, typename MhsType, typename RhsType>
        requires(boost::has_equal_to<LhsType, MhsType, bool>::value && boost::has_equal_to<RhsType, MhsType, bool>::value)
        void AssertEqual(const LhsType& lhs,
                         const MhsType& mhs,
                         const RhsType& rhs,
                         const FunctionDescribed& functionDescribed,
                         const std::string& errorMessage = std::string{},
                         bool failureThrow = false);

        template <typename LhsType, typename RhsType>
        requires((std::is_same_v<std::remove_all_extents_t<LhsType>, wchar_t> && std::is_same_v<std::remove_all_extents_t<RhsType>, wchar_t>) ||
                 (std::is_constructible_v<std::wstring, LhsType> && std::is_constructible_v<std::wstring, RhsType>))
        void AssertEqual(const LhsType& lhs,
                         const RhsType& rhs,
                         const FunctionDescribed& functionDescribed,
                         const std::string& errorMessage = std::string{},
                         bool failureThrow = false);

        template <typename LhsType, typename RhsType>
        requires((std::is_same_v<std::remove_all_extents_t<LhsType>, char> && std::is_same_v<std::remove_all_extents_t<RhsType>, char>) ||
                 (std::is_constructible_v<std::string, LhsType> && std::is_constructible_v<std::string, RhsType>))
        void AssertEqual(const LhsType& lhs,
                         const RhsType& rhs,
                         const FunctionDescribed& functionDescribed,
                         const std::string& errorMessage = std::string{},
                         bool failureThrow = false);

        void AssertEqual(const SimpleCSV::CellValue& lhs,
                         const SimpleCSV::CellValue& rhs,
                         const FunctionDescribed& functionDescribed,
                         const std::string& errorMessage = std::string{},
                         bool failureThrow = false);

        template <typename LhsType, typename RhsType>
        requires(boost::has_not_equal_to<LhsType, RhsType, bool>::value &&
                 !(std::is_enum_v<LhsType> && std::is_enum_v<RhsType>))
        void AssertUnequal(const LhsType& lhs,
                           const RhsType& rhs,
                           const FunctionDescribed& functionDescribed,
                           const std::string& errorMessage = std::string{},
                           bool failureThrow = false);

        template <typename LhsType, typename RhsType>
        requires(std::is_enum_v<LhsType> && std::is_enum_v<RhsType>)
        void AssertUnequal(const LhsType& lhs,
                           const RhsType& rhs,
                           const FunctionDescribed& functionDescribed,
                           const std::string& errorMessage = std::string{},
                           bool failureThrow = false);

        template <typename LhsType, typename RhsType>
        requires(boost::has_minus<LhsType, RhsType>::value && boost::has_less_equal<std::common_type_t<LhsType, RhsType>, double, bool>::value)
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

        /// �����Ƿ��ڷ�Χ�ڡ�lhs <= test <= rhs��
        template <typename TestType, typename RangeType>
        requires(boost::has_less_equal<RangeType, TestType, bool>::value && boost::has_less_equal<TestType, RangeType, bool>::value)
        void AssertRange(const TestType& test,
                         const RangeType& lhs,
                         const RangeType& rhs,
                         const FunctionDescribed& functionDescribed,
                         const std::string& errorMessage = std::string{},
                         bool failureThrow = false);

        template <typename LhsType, typename RhsType>
        requires(std::is_enum_v<LhsType> && std::is_enum_v<RhsType>)
        void AssertLess(const LhsType& lhs,
                        const RhsType& rhs,
                        const FunctionDescribed& functionDescribed,
                        const std::string& errorMessage = std::string{},
                        bool failureThrow = false);

        template <typename LhsType, typename RhsType>
        requires(std::is_enum_v<LhsType> && std::is_enum_v<RhsType>)
        void AssertLessEqual(const LhsType& lhs,
                             const RhsType& rhs,
                             const FunctionDescribed& functionDescribed,
                             const std::string& errorMessage = std::string{},
                             bool failureThrow = false);

        template <typename LhsType, typename RhsType>
        requires(std::is_enum_v<LhsType> && std::is_enum_v<RhsType>)
        void AssertGreater(const LhsType& lhs,
                           const RhsType& rhs,
                           const FunctionDescribed& functionDescribed,
                           const std::string& errorMessage = std::string{},
                           bool failureThrow = false);

        template <typename LhsType, typename RhsType>
        requires(std::is_enum_v<LhsType> && std::is_enum_v<RhsType>)
        void AssertGreaterEqual(const LhsType& lhs,
                                const RhsType& rhs,
                                const FunctionDescribed& functionDescribed,
                                const std::string& errorMessage = std::string{},
                                bool failureThrow = false);

        template <typename LhsType, typename RhsType>
        requires(boost::has_less<LhsType, RhsType, bool>::value &&
                 !(std::is_enum_v<LhsType> && std::is_enum_v<RhsType>))
        void AssertLess(const LhsType& lhs,
                        const RhsType& rhs,
                        const FunctionDescribed& functionDescribed,
                        const std::string& errorMessage = std::string{},
                        bool failureThrow = false);

        template <typename LhsType, typename RhsType>
        requires(boost::has_less_equal<LhsType, RhsType, bool>::value &&
                 !(std::is_enum_v<LhsType> && std::is_enum_v<RhsType>))
        void AssertLessEqual(const LhsType& lhs,
                             const RhsType& rhs,
                             const FunctionDescribed& functionDescribed,
                             const std::string& errorMessage = std::string{},
                             bool failureThrow = false);

        template <typename LhsType, typename RhsType>
        requires(boost::has_greater<LhsType, RhsType, bool>::value &&
                 !(std::is_enum_v<LhsType> && std::is_enum_v<RhsType>))
        void AssertGreater(const LhsType& lhs,
                           const RhsType& rhs,
                           const FunctionDescribed& functionDescribed,
                           const std::string& errorMessage = std::string{},
                           bool failureThrow = false);

        template <typename LhsType, typename RhsType>
        requires(boost::has_greater_equal<LhsType, RhsType, bool>::value &&
                 !(std::is_enum_v<LhsType> && std::is_enum_v<RhsType>))
        void AssertGreaterEqual(const LhsType& lhs,
                                const RhsType& rhs,
                                const FunctionDescribed& functionDescribed,
                                const std::string& errorMessage = std::string{},
                                bool failureThrow = false);

        template <typename PtrType>
        void AssertEqualNullPtr(const PtrType& ptr,
                                const FunctionDescribed& functionDescribed,
                                const std::string& errorMessage = std::string{},
                                bool failureThrow = false);

        template <typename PtrType>
        void AssertUnequalNullPtr(const PtrType& ptr,
                                  const FunctionDescribed& functionDescribed,
                                  const std::string& errorMessage = std::string{},
                                  bool failureThrow = false);

        template <typename TestClass, typename Function, typename... Types>
        requires(std::is_member_function_pointer_v<Function> && std::is_base_of_v<CoreTools::UnitTest, TestClass>)
        void AssertNotThrowException(TestClass* test, Function function, const FunctionDescribed& functionDescribed, const std::string& errorMessage, Types&&... args);

        template <typename TestClass, typename Function, typename... Types>
        requires(std::is_member_function_pointer_v<Function> && std::is_base_of_v<CoreTools::UnitTest, TestClass>)
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

        template <typename TestClass, typename Function>
        requires(std::is_member_function_pointer_v<Function> && std::is_base_of_v<CoreTools::UnitTest, TestClass>)
        void ExecuteLoopTesting(TestClass* test, Function function);

        virtual void PrintTipsMessage();

    private:
        void PrintFailReport(const FunctionDescribed& functionDescribed, const std::string& errorMessage, LogLevel logLevel);

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

            return "��ȷ���׳��쳣��"sv;
        }

        NODISCARD static constexpr std::string_view GetErrorThrowExceptionDescribe()
        {
            using namespace std::literals;

            return "������׳��쳣��"sv;
        }

        NODISCARD static constexpr std::string_view GetCorrectNothrowExceptionDescribe()
        {
            using namespace std::literals;

            return "��ȷ��δ�׳��쳣��"sv;
        }

        NODISCARD static constexpr std::string_view GetErrorNothrowExceptionDescribe()
        {
            using namespace std::literals;

            return "�����δ�׳��쳣��"sv;
        }

        NODISCARD static std::string GetAssertDescribed(const std::string& assertMessage, const std::string& errorMessage);

    private:
        UnitTestDataSharedPtr unitTestData;
        CpuTimerDataSharedPtr cpuTimer;
    };
}

#endif  // CORE_TOOLS_UNIT_TEST_SUITE_UNIT_TEST_H
