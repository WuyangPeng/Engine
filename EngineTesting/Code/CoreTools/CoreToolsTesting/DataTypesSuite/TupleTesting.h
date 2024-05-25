/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/19 10:08)

#ifndef CORE_TOOLS_DATA_TYPES_SUITE_TUPLE_TESTING_H
#define CORE_TOOLS_DATA_TYPES_SUITE_TUPLE_TESTING_H

#include "CoreTools/DataTypes/Tuple.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class TupleTesting final : public UnitTest
    {
    public:
        using ClassType = TupleTesting;
        using ParentType = UnitTest;

    public:
        explicit TupleTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        using Tuple1 = Tuple<1, int>;
        using Tuple2 = Tuple<2, int>;
        using Tuple3 = Tuple<3, int>;
        using Tuple4 = Tuple<4, int>;
        using StringTuple2 = Tuple<2, std::string>;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void IntegerTest();
        void StringTest();
        void OperatorTest();
        void ConstructorTest();
        void CompileErrorTest() noexcept;
        void ForEachTest();
        void SumTest();

        void IntegerZeroTest(const Tuple4& tuple);
        void IntegerAssignment(Tuple4& tuple, int value);
        void IntegerOriginalTest(const Tuple4& tuple, int value);

        void StringZeroTest(const StringTuple2& tuple);
        void StringAssignment(StringTuple2& tuple, int value);
        void StringOriginalTest(const StringTuple2& tuple, int value);

        void Constructor0Test();
        void Constructor1Test();
        void Constructor2Test();
        void Constructor3Test();

        NODISCARD static Tuple4 CreateTuple4();
    };
}

#endif  // CORE_TOOLS_DATA_TYPES_SUITE_TUPLE_TESTING_H