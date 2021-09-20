///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.2.1 (2021/07/28 15:55)

#ifndef CORE_TOOLS_HELPER_UNIT_TEST_SUITE_MACRO_H
#define CORE_TOOLS_HELPER_UNIT_TEST_SUITE_MACRO_H

// 单元测试框架所需要的宏
#include "CoreTools/UnitTestSuite/Suite.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

#define ADD_TEST(suite, testing) \
    AddTest<testing>((suite), (#suite), (#testing))

#define ADD_TEST_USE_PARAMETER_1(suite, testing, parameter) \
    AddTest<testing>((suite), (#suite), (#testing), (parameter))

#define ADD_TEST_USE_PARAMETER_2(suite, testing, parameter1, parameter2) \
    AddTest<testing>((suite), (#suite), (#testing), (parameter1), (parameter2))

#define UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(className) \
    using ClassType = className;                       \
    using ParentType = UnitTest;                       \
                                                       \
public:                                                \
    explicit className(const OStreamShared& stream);   \
    CLASS_INVARIANT_OVERRIDE_DECLARE;

#define UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(namespaceName, testName) \
    namespaceName::testName::testName(const OStreamShared& stream)  \
        : ParentType{ stream }                                      \
    {                                                               \
        SELF_CLASS_IS_VALID_1;                                      \
    }                                                               \
    CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(namespaceName, testName) \
    void namespaceName::testName::DoRunUnitTest()                   \
    {                                                               \
        ASSERT_NOT_THROW_EXCEPTION_0(MainTest);                     \
    }

#define UNIT_TEST_SUBCLASS_COMPLETE_DEFINE_USE_TESTING_TYPE(namespaceName, className) \
    namespace namespaceName                                                           \
    {                                                                                 \
        using TestingType = className;                                                \
    }                                                                                 \
    UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(namespaceName, SYSTEM_CONCATENATOR(className, Testing))

#endif  // CORE_TOOLS_HELPER_UNIT_TEST_SUITE_MACRO_H
