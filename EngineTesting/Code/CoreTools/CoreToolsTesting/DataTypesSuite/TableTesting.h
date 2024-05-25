/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/19 10:27)

#ifndef CORE_TOOLS_DATA_TYPES_SUITE_TABLE_TESTING_H
#define CORE_TOOLS_DATA_TYPES_SUITE_TABLE_TESTING_H

#include "CoreTools/DataTypes/Table.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class TableTesting final : public UnitTest
    {
    public:
        using ClassType = TableTesting;
        using ParentType = UnitTest;

    public:
        explicit TableTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        using TestingType2 = Table<2, 2, int>;
        using TestingType3 = Table<3, 3, int>;
        using TestingType4 = Table<4, 4, int>;
        using StringTestingType = Table<2, 2, std::string>;
        using StringTuple = Tuple<2, std::string>;
        using IntegerTestingType = Table<3, 2, int>;
        using IntegerTuple2 = Tuple<2, int>;
        using IntegerTuple3 = Tuple<3, int>;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void IntegerTest();
        void StringTest();
        void OperatorTest();
        void ConstructorTest();
        void CompileErrorTest() noexcept;
        void ForEachTest();
        void GetCoordinateTest();

        NODISCARD IntegerTestingType IntegerRowTest(IntegerTestingType& table);
        void IntegerColumnTest(IntegerTestingType& lhs, IntegerTestingType& rhs);
        void IntegerSquareBracketsTest(const IntegerTestingType& table);
        void DoIntegerRowTest(const IntegerTestingType& table, const IntegerTuple2& rowTuple0, const IntegerTuple2& rowTuple1, const IntegerTuple2& rowTuple2);
        void DoIntegerColumnTest(const IntegerTestingType& table, const IntegerTuple3& columnTuple0, const IntegerTuple3& columnTuple1);

        NODISCARD StringTestingType StringRowTest(StringTestingType& table);
        void StringColumnTest(StringTestingType& lhs, StringTestingType& rhs);
        void StringSquareBracketsTest(const StringTestingType& table);
        void DoStringRowTest(const StringTestingType& table, const StringTuple& rowTuple0, const StringTuple& rowTuple1);
        void DoStringColumnTest(const StringTestingType& table, const StringTuple& columnTuple0, const StringTuple& columnTuple1);

        void Constructor2Test();
        void Constructor3Test();
        void Constructor4Test();

        NODISCARD static TestingType2 CreateTestingType2();
    };
}

#endif  // CORE_TOOLS_DATA_TYPES_SUITE_TABLE_TESTING_H