/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.9 (2024/05/22 10:20)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_SUITE_BUFFER_TARGET_TESTING_H
#define CORE_TOOLS_OBJECT_SYSTEMS_SUITE_BUFFER_TARGET_TESTING_H

#include "Detail/BufferTargetTestingEnum.h"
#include "CoreTools/FileManager/FileBuffer.h"
#include "CoreTools/ObjectSystems/ConstObjectAssociated.h"
#include "CoreTools/ObjectSystems/ObjectSystemsFwd.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"
#include "Mathematics/Algebra/Vector4.h"

#include <array>

namespace CoreTools
{
    class BufferTargetTesting final : public UnitTest
    {
    public:
        using ClassType = BufferTargetTesting;
        using ParentType = UnitTest;

    public:
        explicit BufferTargetTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        using Vector4D = Mathematics::Vector4D;
        using Vector4ToolsD = Mathematics::Vector4Tools<double>;

        static constexpr auto bufferSize = 512;
        static constexpr auto zeroTolerance = Mathematics::MathD::GetZeroTolerance();

        static constexpr auto boolSize0 = 5;
        static constexpr auto boolSize1 = 6;
        static constexpr auto boolSize2 = 7;

        static constexpr auto stringSize0 = 5;
        static constexpr auto stringSize1 = 6;
        static constexpr auto stringSize2 = 7;
        static constexpr auto stringSize3 = 7;

        static constexpr auto intSize0 = 5;
        static constexpr auto intSize1 = 6;
        static constexpr auto intSize2 = 7;

        static constexpr auto enumSize0 = 5;
        static constexpr auto enumSize1 = 3;
        static constexpr auto enumSize2 = 4;

        static constexpr auto aggregateSize0 = 5;
        static constexpr auto aggregateSize1 = 2;
        static constexpr auto aggregateSize2 = 3;

        static constexpr auto objectAssociatedSize0 = 5;
        static constexpr auto objectAssociatedSize1 = 6;
        static constexpr auto objectAssociatedSize2 = 7;

        static constexpr auto uniqueId0 = 1;
        static constexpr auto uniqueId1 = 2;

        using BoolContainer0 = std::array<bool, boolSize0>;
        using BoolContainer1 = std::array<bool, boolSize1>;
        using BoolContainer2 = std::array<bool, boolSize2>;

        using StringContainer0 = std::array<std::string, stringSize0>;
        using StringContainer1 = std::array<std::string, stringSize1>;
        using StringContainer2 = std::array<std::string, stringSize2>;
        using StringContainer3 = std::array<std::string, stringSize3>;

        using IntContainer0 = std::array<int32_t, intSize0>;
        using IntContainer1 = std::array<int32_t, intSize1>;
        using IntContainer2 = std::array<int32_t, intSize2>;

        using EnumContainer0 = std::array<BufferTargetTestingEnum, enumSize0>;
        using EnumContainer1 = std::array<BufferTargetTestingEnum, enumSize1>;
        using EnumContainer2 = std::array<BufferTargetTestingEnum, enumSize2>;

        using AggregateContainer0 = std::array<Vector4D, aggregateSize0>;
        using AggregateContainer1 = std::array<Vector4D, aggregateSize1>;
        using AggregateContainer2 = std::array<Vector4D, aggregateSize2>;

        using ObjectAssociatedContainer0 = std::array<ConstObjectInterfaceAssociated, objectAssociatedSize0>;
        using ObjectAssociatedContainer1 = std::array<ConstObjectInterfaceAssociated, objectAssociatedSize1>;
        using ObjectAssociatedContainer2 = std::array<ConstObjectInterfaceAssociated, objectAssociatedSize2>;

        using ObjectAssociatedInt64Container0 = std::array<int64_t, objectAssociatedSize0>;
        using ObjectAssociatedInt64Container1 = std::array<int64_t, objectAssociatedSize1>;
        using ObjectAssociatedInt64Container2 = std::array<int64_t, objectAssociatedSize2>;

        static constexpr BoolContainer0 boolContainer0{ true, false, true, false, true };
        static constexpr BoolContainer1 boolContainer1{ false, false, true, false, true, true };
        static constexpr BoolContainer2 boolContainer2{ true, false, true, false, false, true, true };

        inline static const std::string stringTest0{ "test0" };
        inline static const std::string stringTest1{ "test1" };
        inline static const std::string stringTest2{ "test2" };
        inline static const std::string stringTest3{ "test3" };
        inline static const std::string stringTest4{ "test4" };
        inline static const std::string stringTest5{ "test5" };
        inline static const std::string stringTest6{ "test6" };

        inline static const StringContainer0 stringContainer0{ stringTest0, stringTest1, stringTest2, stringTest3, stringTest4 };
        inline static const StringContainer1 stringContainer1{ stringTest0, stringTest1, stringTest2, stringTest3, stringTest4, stringTest5 };
        inline static const StringContainer2 stringContainer2{ stringTest0, stringTest1, stringTest2, stringTest3, stringTest4, stringTest5, stringTest6 };
        static constexpr std::array stringContainer3{ "test0", "test1", "test2", "test3", "test4", "test5", "test6" };

        static constexpr auto intValue = 51;
        static constexpr IntContainer0 intContainer0{ 1, 2, 3, 4, 5 };
        static constexpr IntContainer1 intContainer1{ 6, 7, 8, 9, 1, 2 };
        static constexpr IntContainer2 intContainer2{ 3, 4, 5, 6, 7, 8, 9 };

        static constexpr auto enumValue = BufferTargetTestingEnum::Fifteen;
        static constexpr EnumContainer0 enumContainer0{ BufferTargetTestingEnum::Fifteen, BufferTargetTestingEnum::Ten, BufferTargetTestingEnum::Fifteen, BufferTargetTestingEnum::Ten, BufferTargetTestingEnum::Fifteen };
        static constexpr EnumContainer1 enumContainer1{ BufferTargetTestingEnum::Fifteen, BufferTargetTestingEnum::Ten, BufferTargetTestingEnum::Fifteen };
        static constexpr EnumContainer2 enumContainer2{ BufferTargetTestingEnum::Fifteen, BufferTargetTestingEnum::Ten, BufferTargetTestingEnum::Ten, BufferTargetTestingEnum::Ten };

        static constexpr Vector4D color{ 1.0, 2.0, 3.0, 4.0 };
        static constexpr AggregateContainer0 aggregateContainer0{ Vector4D{ 1.0, 2.0, 3.0, 4.0 },
                                                                  Vector4D{ 5.0, 6.0, 7.0, 8.0 },
                                                                  Vector4D{ 9.0, 1.0, 2.0, 3.0 },
                                                                  Vector4D{ 4.0, 5.0, 6.0, 7.0 },
                                                                  Vector4D{ 1.0, 2.0, 3.0, 4.0 } };
        static constexpr AggregateContainer1 aggregateContainer1{ Vector4D{ 1.0, 2.0, 3.0, 4.0 },
                                                                  Vector4D{ 5.0, 6.0, 7.0, 8.0 } };
        static constexpr AggregateContainer2 aggregateContainer2{ Vector4D{ 9.0, 1.0, 2.0, 3.0 },
                                                                  Vector4D{ 4.0, 5.0, 6.0, 7.0 },
                                                                  Vector4D{ 1.0, 2.0, 3.0, 4.0 } };

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void WriteBoolTest();
        void WriteStringTest();
        void WriteIntTest();
        void WriteEnumTest();
        void WriteAggregateTest();
        void WriteObjectAssociatedTest();

        NODISCARD ConstFileBufferSharedPtr GetBoolFileBuffer();
        NODISCARD static ConstFileBufferSharedPtr GetStringFileBuffer();
        NODISCARD static ConstFileBufferSharedPtr GetIntFileBuffer();
        NODISCARD static ConstFileBufferSharedPtr GetEnumFileBuffer();
        NODISCARD static ConstFileBufferSharedPtr GetAggregateFileBuffer();
        NODISCARD ConstFileBufferSharedPtr GetObjectAssociatedFileBuffer() const;

        NODISCARD static ConstObjectInterfaceAssociated CreateBoolObjectAssociated();
        NODISCARD static ConstObjectInterfaceAssociated CreateIntObjectAssociated();

        void ReadBool0Test(BufferSource& bufferSource);
        void ReadBool1Test(BufferSource& bufferSource);
        void ReadBool2Test(BufferSource& bufferSource);
        void ReadBool3Test(BufferSource& bufferSource);

        void ReadString0Test(BufferSource& bufferSource);
        void ReadString1Test(BufferSource& bufferSource);
        void ReadString2Test(BufferSource& bufferSource);
        void ReadString3Test(BufferSource& bufferSource);
        void ReadString4Test(BufferSource& bufferSource);

        void ReadInt0Test(BufferSource& bufferSource);
        void ReadInt1Test(BufferSource& bufferSource);
        void ReadInt2Test(BufferSource& bufferSource);
        void ReadInt3Test(BufferSource& bufferSource);

        void ReadEnum0Test(BufferSource& bufferSource);
        void ReadEnum1Test(BufferSource& bufferSource);
        void ReadEnum2Test(BufferSource& bufferSource);
        void ReadEnum3Test(BufferSource& bufferSource);

        void ReadAggregate0Test(BufferSource& bufferSource);
        void ReadAggregate1Test(BufferSource& bufferSource);
        void ReadAggregate2Test(BufferSource& bufferSource);
        void ReadAggregate3Test(BufferSource& bufferSource);

        void ReadObjectAssociated0Test(BufferSource& bufferSource);
        void ReadObjectAssociated1Test(BufferSource& bufferSource);
        void ReadObjectAssociated2Test(BufferSource& bufferSource);
        void ReadObjectAssociated3Test(BufferSource& bufferSource);

    private:
        ConstObjectInterfaceAssociated boolObjectAssociated;
        ConstObjectInterfaceAssociated intObjectAssociated;

        ObjectAssociatedContainer0 objectAssociatedContainer0;
        ObjectAssociatedContainer1 objectAssociatedContainer1;
        ObjectAssociatedContainer2 objectAssociatedContainer2;
    };
}

#endif  // CORE_TOOLS_OBJECT_SYSTEMS_SUITE_BUFFER_TARGET_TESTING_H