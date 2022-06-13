///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/19 13:44)

#ifndef CORE_TOOLS_DATA_TYPES_SUITE_TUPLE_TESTING_H
#define CORE_TOOLS_DATA_TYPES_SUITE_TUPLE_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace CoreTools
{
    class TupleTesting : public UnitTest
    {
    public:
        UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(TupleTesting);

    private:
        void MainTest();
        void IntegerTest();
        void StringTest();
        void OperatorTest();
        void ConstructorTest();
        void CompileErrorTest() noexcept;

        void DoRunUnitTest() override;
    };
}

#endif  // CORE_TOOLS_DATA_TYPES_SUITE_TUPLE_TESTING_H