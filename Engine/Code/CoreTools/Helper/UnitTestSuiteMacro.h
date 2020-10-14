//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.1 (2020/10/09 15:55)

#ifndef CORE_TOOLS_HELPER_UNIT_TEST_SUITE_MACRO_H
#define CORE_TOOLS_HELPER_UNIT_TEST_SUITE_MACRO_H

// 单元测试框架所需要的宏
#include "CoreTools/UnitTestSuite/Suite.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

#define ADD_TEST_BEGIN(suite, suiteName) \
    const auto printRun = IsPrintRun();  \
    Suite suite{ "【" SYSTEM_CONCATENATOR(suiteName) "组件】单元测试套件", GetStreamShared(), printRun };

#define ADD_TEST(suite, testing) \
    AddTest<testing>((suite), (#suite), (#testing))

#define ADD_TEST_USE_PARAMETER_1(suite, testing, parameter) \
    AddTest<testing>((suite), (#suite), (#testing), (parameter))

#define ADD_TEST_USE_PARAMETER_2(suite, testing, parameter1, parameter2) \
    AddTest<testing>((suite), (#suite), (#testing), (parameter1), (parameter2))

#define ADD_TEST_END(suite) \
    m_SuitePtr->AddSuite(suite)

#define CMAIN_FUNCTION_TESTING_HELPER_SUBCLASS_DECLARE(className) \
    using ClassType = className;                                  \
    using ParentType = CMainFunctionTestingHelper;                \
    using Suite = CoreTools::Suite;                               \
                                                                  \
public:                                                           \
    className(int argc, char** argv);

#define CMAIN_FUNCTION_TESTING_HELPER_SUBCLASS_COMPLETE_DECLARE(className) \
    CMAIN_FUNCTION_TESTING_HELPER_SUBCLASS_DECLARE(className);             \
    CLASS_INVARIANT_OVERRIDE_DECLARE

#define CMAIN_FUNCTION_HELPER_SUBCLASS_SUITE_PTR_DECLARE \
    using SuitePtr = std::shared_ptr<Suite>;             \
                                                         \
private:                                                 \
    SuitePtr m_SuitePtr

#define UNIT_TEST_DO_RUN_DEFINE(namespaceName, className, suiteName)                                                                 \
    int namespaceName::className::DoRun()                                                                                            \
    {                                                                                                                                \
        m_SuitePtr = std::make_shared<Suite>("【" SYSTEM_CONCATENATOR(suiteName) "】单元测试套件", GetStreamShared(), IsPrintRun()); \
        AddSuite();                                                                                                                  \
        m_SuitePtr->RunUnitTest();                                                                                                   \
        SystemPause();                                                                                                               \
        m_SuitePtr->PrintReport();                                                                                                   \
        SystemPause();                                                                                                               \
        return m_SuitePtr->GetFailedNumber();                                                                                        \
    }

#define CMAIN_FUNCTION_HELPER_SUBCLASS_DEFINE(namespaceName, className) \
    namespaceName::className::className(int argc, char** argv)          \
        : ParentType{ argc, argv }, m_SuitePtr{}                        \
    {                                                                   \
        SELF_CLASS_IS_VALID_0;                                          \
    }

#define CMAIN_FUNCTION_HELPER_SUBCLASS_COMPLETE_DEFINE(namespaceName, className, testName) \
    CMAIN_FUNCTION_HELPER_SUBCLASS_DEFINE(namespaceName, className)                        \
    CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(namespaceName, className)                       \
    UNIT_TEST_DO_RUN_DEFINE(namespaceName, className, testName)

#endif  // CORE_TOOLS_HELPER_UNIT_TEST_SUITE_MACRO_H
