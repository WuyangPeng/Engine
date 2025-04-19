/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.9 (2024/05/22 10:16)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_SUITE_BUFFER_SOURCE_TESTING_H
#define CORE_TOOLS_OBJECT_SYSTEMS_SUITE_BUFFER_SOURCE_TESTING_H

#include "Detail/BufferSourceTestingEnum.h"
#include "CoreTools/FileManager/FileManagerFwd.h"
#include "CoreTools/ObjectSystems/ConstObjectAssociated.h"
#include "CoreTools/ObjectSystems/ObjectSystemsFwd.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"
#include "Mathematics/Algebra/AlgebraFwd.h"
#include "Mathematics/Algebra/Vector4.h"
#include "Mathematics/Base/Math.h"

#include <array>
#include <list>
#include <set>

namespace CoreTools
{
    class BufferSourceTesting final : public UnitTest
    {
    public:
        using ClassType = BufferSourceTesting;
        using ParentType = UnitTest;

    public:
        explicit BufferSourceTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        static constexpr auto objectAssociatedSize0 = 5;
        static constexpr auto objectAssociatedSize1 = 6;
        static constexpr auto objectAssociatedSize2 = 7;
        static constexpr auto objectAssociatedSize3 = 4;
        static constexpr auto objectAssociatedSize4 = 2;
        static constexpr auto objectAssociatedSize5 = 3;
        static constexpr auto uniqueId0 = 1;
        static constexpr auto uniqueId1 = 2;
        static constexpr auto uniqueId2 = 123;
        static constexpr auto bufferSize = 512;
        static constexpr auto zeroTolerance = Mathematics::MathD::GetZeroTolerance();

        using ObjectAssociatedContainer0 = std::array<ConstObjectInterfaceAssociated, objectAssociatedSize0>;
        using ObjectAssociatedContainer1 = std::array<ConstObjectInterfaceAssociated, objectAssociatedSize1>;
        using ObjectAssociatedContainer2 = std::array<ConstObjectInterfaceAssociated, objectAssociatedSize2>;
        using ObjectAssociatedContainer3 = std::array<ConstObjectInterfaceAssociated, objectAssociatedSize3>;
        using ObjectAssociatedContainer4 = std::array<ConstObjectInterfaceAssociated, objectAssociatedSize4>;
        using ObjectAssociatedContainer5 = std::array<ConstObjectInterfaceAssociated, objectAssociatedSize5>;
        using Vector4D = Mathematics::Vector4<double>;
        using Vector4ToolsD = Mathematics::Vector4Tools<double>;
        using BoolContainer = std::vector<bool>;
        using StringContainer = std::vector<std::string>;
        using IntContainer = std::vector<int32_t>;
        using EnumContainer = std::vector<BufferSourceTestingEnum>;
        using AggregateContainer = std::vector<Vector4D>;
        using ObjectAssociatedContainer = std::vector<ConstObjectInterfaceAssociated>;
        using BoolContainer5 = std::array<bool, 7>;
        using BoolContainer6 = std::set<bool>;
        using StringContainer4 = std::set<std::string>;
        using StringContainer6 = std::array<std::string, 4>;
        using IntContainer4 = std::list<int32_t>;
        using IntContainer5 = std::set<int32_t>;
        using IntContainer8 = std::array<int32_t, 12>;
        using EnumContainer4 = std::list<BufferSourceTestingEnum>;
        using EnumContainer5 = std::set<BufferSourceTestingEnum>;
        using EnumContainer8 = std::array<BufferSourceTestingEnum, 3>;
        using VectorContainer0 = std::array<Vector4D, 5>;
        using VectorContainer3 = std::set<Vector4D>;

        static constexpr std::array boolContainer0{ true, false, true, false, true };
        static constexpr std::array boolContainer1{ false, false, true, false, true, true };
        static constexpr std::array boolContainer2{ true, false, true, false, false, true, true };
        static constexpr std::array boolContainer3{ true, false, true };
        static constexpr std::array boolContainer4{ false, false, true, false, false, true };
        static constexpr BoolContainer5 boolContainer5{ true, false, true, false, false, true, false };
        inline static const BoolContainer6 boolContainer6{ true, false };

        inline static const std::string stringTest0{ "test0" };
        inline static const std::string stringTest1{ "test1" };
        inline static const std::string stringTest2{ "test2" };
        inline static const std::string stringTest3{ "test3" };
        inline static const std::string stringTest4{ "test4" };
        inline static const std::string stringTest5{ "test5" };
        inline static const std::string stringTest6{ "test6" };
        inline static const std::string stringTest7{ "test7" };
        inline static const std::array stringContainer0{ stringTest0, stringTest1, stringTest2, stringTest3, stringTest4 };
        inline static const std::array stringContainer1{ stringTest0, stringTest1, stringTest2, stringTest3, stringTest4, stringTest5 };
        inline static const std::array stringContainer2{ stringTest0, stringTest1, stringTest2, stringTest3, stringTest4, stringTest5, stringTest6 };
        inline static const std::array stringContainer3{ stringTest0, stringTest1, stringTest2, stringTest3, stringTest4, stringTest5, stringTest6 };
        inline static const StringContainer4 stringContainer4{ stringTest0, stringTest1, stringTest2, stringTest3, stringTest4, stringTest5, stringTest6, stringTest7 };
        inline static const std::array stringContainer5{ stringTest0, stringTest1 };
        inline static const StringContainer6 stringContainer6{ stringTest0, stringTest1, stringTest2, stringTest3 };

        static constexpr std::array intContainer0{ 1, 2, 3, 4, 5 };
        static constexpr std::array intContainer1{ 6, 7, 8, 9, 1, 2 };
        static constexpr std::array intContainer2{ 3, 4, 5, 6, 7, 8, 9 };
        static constexpr std::array intContainer3{ 3, 4, 5 };
        static constexpr std::array intContainer4{ 3, 4, 3, 4, 5 };
        inline static const std::set intContainer5{ 1, 2, 3, 4, 5 };
        static constexpr std::array intContainer6{ 3, 4, 3, 4, 5, 4, 5, 4, 5 };
        static constexpr std::array intContainer7{ 3, 4, 3, 4, 5, 4, 5, 4, 5, 3, 4, 3 };
        static constexpr IntContainer8 intContainer8{ 3, 4, 3, 4, 5, 4, 5, 4, 5, 3, 4, 3 };
        static constexpr auto intValue0 = 51;
        static constexpr auto intValue1 = 511;

        static constexpr std::array enumContainer0{ BufferSourceTestingEnum::Nine, BufferSourceTestingEnum::Twenty, BufferSourceTestingEnum::Nine, BufferSourceTestingEnum::Twenty };
        static constexpr std::array enumContainer1{ BufferSourceTestingEnum::Nine, BufferSourceTestingEnum::Twenty, BufferSourceTestingEnum::Nine };
        static constexpr std::array enumContainer2{ BufferSourceTestingEnum::Nine, BufferSourceTestingEnum::Twenty, BufferSourceTestingEnum::Nine, BufferSourceTestingEnum::Twenty, BufferSourceTestingEnum::Twenty };
        static constexpr std::array enumContainer3{ BufferSourceTestingEnum::Nine, BufferSourceTestingEnum::Twenty, BufferSourceTestingEnum::Twenty };
        static constexpr std::array enumContainer4{ BufferSourceTestingEnum::Twenty, BufferSourceTestingEnum::Twenty };
        inline static const std::set enumContainer5{ BufferSourceTestingEnum::Nine, BufferSourceTestingEnum::Twenty };
        static constexpr std::array enumContainer6{ BufferSourceTestingEnum::Nine, BufferSourceTestingEnum::Twenty, BufferSourceTestingEnum::Twenty, BufferSourceTestingEnum::Nine, BufferSourceTestingEnum::Twenty };
        static constexpr std::array enumContainer7{ BufferSourceTestingEnum::Nine, BufferSourceTestingEnum::Twenty, BufferSourceTestingEnum::Nine, BufferSourceTestingEnum::Twenty };
        static constexpr EnumContainer8 enumContainer8{ BufferSourceTestingEnum::Nine, BufferSourceTestingEnum::Twenty, BufferSourceTestingEnum::Twenty };
        static constexpr auto enumValue0 = BufferSourceTestingEnum::Nine;
        static constexpr auto enumValue1 = BufferSourceTestingEnum::Twenty;

        static constexpr Vector4D color0{ 1.0, 2.0, 3.0, 4.0 };
        static constexpr Vector4D color1{ 1.0, 2.0, 3.0, 4.0 };

        static constexpr VectorContainer0 vectorContainer0{ Vector4D{ 1.0, 2.0, 3.0, 4.0 },
                                                            Vector4D{ 5.0, 6.0, 7.0, 8.0 },
                                                            Vector4D{ 9.0, 1.0, 2.0, 3.0 },
                                                            Vector4D{ 4.0, 5.0, 6.0, 7.0 },
                                                            Vector4D{ 1.0, 2.0, 3.0, 4.0 } };
        static constexpr std::array vectorContainer1{ Vector4D{ 1.0, 2.0, 3.0, 4.0 },
                                                      Vector4D{ 5.0, 6.0, 7.0, 8.0 } };
        static constexpr std::array vectorContainer2{ Vector4D{ 9.0, 1.0, 2.0, 3.0 },
                                                      Vector4D{ 4.0, 5.0, 6.0, 7.0 },
                                                      Vector4D{ 1.0, 2.0, 3.0, 4.0 } };
        inline static const VectorContainer3 vectorContainer3{ Vector4D{ 9.0, 1.0, 2.0, 3.0 },
                                                               Vector4D{ 4.0, 5.0, 6.0, 7.0 },
                                                               Vector4D{ 1.0, 2.0, 3.0, 4.0 } };
        static constexpr std::array vectorContainer4{ Vector4D{ 9.0, 1.0, 2.0, 3.0 },
                                                      Vector4D{ 4.0, 5.0, 6.0, 7.0 },
                                                      Vector4D{ 1.0, 2.0, 3.0, 4.0 },
                                                      Vector4D{ 1.0, 21.0, 3.0, 4.0 } };
        static constexpr std::array vectorContainer5{ Vector4D{ 9.0, 1.0, 2.0, 3.0 },
                                                      Vector4D{ 4.0, 5.0, 6.0, 7.0 },
                                                      Vector4D{ 1.0, 2.0, 3.0, 4.0 },
                                                      Vector4D{ 1.0, 21.0, 3.0, 4.0 },
                                                      Vector4D{ 1.0, 2.0, 3.0, 4.0 },
                                                      Vector4D{ 1.0, 21.0, 3.0, 4.0 } };
        static constexpr std::array vectorContainer6{ Vector4D{ 9.0, 1.0, 2.0, 3.0 },
                                                      Vector4D{ 4.0, 5.0, 6.0, 7.0 },
                                                      Vector4D{ 1.0, 2.0, 3.0, 4.0 },
                                                      Vector4D{ 4.0, 5.0, 6.0, 7.0 } };

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void ReadBoolTest();
        void ReadStringTest();
        void ReadIntTest();
        void ReadEnumTest();
        void ReadAggregateTest();
        void ReadObjectAssociatedTest();

        NODISCARD static ConstFileBufferSharedPtr GetBoolFileBuffer();
        NODISCARD static ConstFileBufferSharedPtr GetStringFileBuffer();
        NODISCARD static ConstFileBufferSharedPtr GetIntFileBuffer();
        NODISCARD static ConstFileBufferSharedPtr GetEnumFileBuffer();
        NODISCARD static ConstFileBufferSharedPtr GetAggregateFileBuffer();
        NODISCARD ConstFileBufferSharedPtr CreateObjectAssociatedFileBuffer() const;

        NODISCARD static ConstObjectInterfaceAssociated CreateBoolObjectAssociated();
        NODISCARD static ConstObjectInterfaceAssociated CreateIntObjectAssociated();

        void ReadBool0Test(BufferSource& bufferSource);
        void ReadBool1Test(BufferSource& bufferSource);
        void ReadBool2Test(BufferSource& bufferSource);
        void ReadBool3Test(BufferSource& bufferSource);
        void ReadBool4Test(BufferSource& bufferSource);
        void ReadBool5Test(BufferSource& bufferSource);
        void ReadBool6Test(BufferSource& bufferSource);
        void ReadBool7Test(BufferSource& bufferSource);

        void ReadString0Test(BufferSource& bufferSource);
        void ReadString1Test(BufferSource& bufferSource);
        void ReadString2Test(BufferSource& bufferSource);
        void ReadString3Test(BufferSource& bufferSource);
        void ReadString4Test(BufferSource& bufferSource);
        void ReadString5Test(BufferSource& bufferSource);
        void ReadString6Test(BufferSource& bufferSource);
        void ReadString7Test(BufferSource& bufferSource);

        void ReadInt0Test(BufferSource& bufferSource);
        void ReadInt1Test(BufferSource& bufferSource);
        void ReadInt2Test(BufferSource& bufferSource);
        void ReadInt3Test(BufferSource& bufferSource);
        void ReadInt4Test(BufferSource& bufferSource);
        void ReadInt5Test(BufferSource& bufferSource);
        void ReadInt6Test(BufferSource& bufferSource);
        void ReadInt7Test(BufferSource& bufferSource);
        void ReadInt8Test(BufferSource& bufferSource);
        void ReadInt9Test(BufferSource& bufferSource);

        void ReadEnum0Test(BufferSource& bufferSource);
        void ReadEnum1Test(BufferSource& bufferSource);
        void ReadEnum2Test(BufferSource& bufferSource);
        void ReadEnum3Test(BufferSource& bufferSource);
        void ReadEnum4Test(BufferSource& bufferSource);
        void ReadEnum5Test(BufferSource& bufferSource);
        void ReadEnum6Test(BufferSource& bufferSource);
        void ReadEnum7Test(BufferSource& bufferSource);
        void ReadEnum8Test(BufferSource& bufferSource);
        void ReadEnum9Test(BufferSource& bufferSource);

        void ReadAggregate0Test(BufferSource& bufferSource);
        void ReadAggregate1Test(BufferSource& bufferSource);
        void ReadAggregate2Test(BufferSource& bufferSource);
        void ReadAggregate3Test(BufferSource& bufferSource);
        void ReadAggregate4Test(BufferSource& bufferSource);
        void ReadAggregate5Test(BufferSource& bufferSource);
        void ReadAggregate6Test(BufferSource& bufferSource);
        void ReadAggregate7Test(BufferSource& bufferSource);

        void ReadObjectAssociated0Test(BufferSource& bufferSource);
        void ReadObjectAssociated1Test(BufferSource& bufferSource);
        void ReadObjectAssociated2Test(BufferSource& bufferSource);
        void ReadObjectAssociated3Test(BufferSource& bufferSource);
        void ReadObjectAssociated4Test(BufferSource& bufferSource);
        void ReadObjectAssociated5Test(BufferSource& bufferSource);
        void ReadObjectAssociated6Test(BufferSource& bufferSource);
        void ReadObjectAssociated7Test(BufferSource& bufferSource);
        void IncrementBytesProcessedTest(BufferSource& bufferSource);

    private:
        ConstObjectInterfaceAssociated boolObjectAssociated;
        ConstObjectInterfaceAssociated intObjectAssociated;

        ObjectAssociatedContainer0 objectAssociatedContainer0;
        ObjectAssociatedContainer1 objectAssociatedContainer1;
        ObjectAssociatedContainer2 objectAssociatedContainer2;
        ObjectAssociatedContainer3 objectAssociatedContainer3;
        ObjectAssociatedContainer4 objectAssociatedContainer4;
        ObjectAssociatedContainer5 objectAssociatedContainer5;
    };
}

#endif  // CORE_TOOLS_OBJECT_SYSTEMS_SUITE_BUFFER_SOURCE_TESTING_H