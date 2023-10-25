///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/10/25 14:16)

#include "BufferTargetTesting.h"
#include "Detail/BoolObject.h"
#include "Detail/BufferTargetTestingEnum.h"
#include "Detail/IntObject.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/Helper/StreamMacro.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ConstObjectAssociated.h"
#include "CoreTools/ObjectSystems/ConstWeakObjectAssociated.h"
#include "CoreTools/ObjectSystems/ObjectRegisterDetail.h"
#include "CoreTools/ObjectSystems/StreamDetail.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Algebra/Vector4ToolsDetail.h"

using namespace std::literals;

CoreTools::BufferTargetTesting::BufferTargetTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, BufferTargetTesting)

void CoreTools::BufferTargetTesting::DoRunUnitTest()
{
    InitTerm::ExecuteInitializer();

    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);

    InitTerm::ExecuteTerminator();
}

void CoreTools::BufferTargetTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(WriteBoolTest);
    ASSERT_NOT_THROW_EXCEPTION_0(WriteStringTest);
    ASSERT_NOT_THROW_EXCEPTION_0(WriteIntTest);
    ASSERT_NOT_THROW_EXCEPTION_0(WriteEnumTest);
    ASSERT_NOT_THROW_EXCEPTION_0(WriteAggregateTest);
    ASSERT_NOT_THROW_EXCEPTION_0(WriteObjectAssociatedTest);
}

void CoreTools::BufferTargetTesting::WriteBoolTest()
{
    const auto objectRegister = ObjectRegister::Create();

    BufferTarget bufferTarget{ 256, objectRegister };

    bufferTarget.Write(true);

    ASSERT_EQUAL(bufferTarget.GetBytesWritten(), GetStreamSize(true));

    constexpr std::array container0{ true, false, true, false, true };
    constexpr std::array container1{ false, false, true, false, true, true };
    constexpr std::array container2{ true, false, true, false, false, true, true };

    bufferTarget.WriteBoolContainerWithNumber(container0);
    bufferTarget.WriteBoolContainerWithoutNumber(container1);
    bufferTarget.WriteContainer(container2);

    const auto fileBuffer = bufferTarget.GetFileBuffer();

    BufferSource bufferSource{ fileBuffer };

    ASSERT_TRUE(bufferSource.ReadBool());

    int32_t size{};
    bufferSource.Read(size);

    ASSERT_EQUAL(size, 5);

    std::array<bool, container0.size()> result0{};
    bufferSource.ReadContainer(result0);
    ASSERT_EQUAL(container0, result0);

    std::array<bool, container1.size()> result1{};
    bufferSource.ReadContainer(result1);
    ASSERT_EQUAL(container1, result1);

    std::array<bool, container2.size()> result2{};
    bufferSource.ReadContainer(result2);
    ASSERT_EQUAL(container2, result2);
}

void CoreTools::BufferTargetTesting::WriteStringTest()
{
    const auto objectRegister = ObjectRegister::Create();

    BufferTarget bufferTarget{ 512, objectRegister };

    bufferTarget.Write("test1");
    bufferTarget.Write("test2"s);

    const std::array container0{ "test1"s, "test2"s, "test3"s, "test4"s, "test5"s };
    const std::array container1{ "test1"s, "test2"s, "test3"s, "test4"s, "test5"s, "test6"s };
    const std::array container2{ "test1"s, "test2"s, "test3"s, "test4"s, "test5"s, "test6"s, "test7"s };
    constexpr std::array container3{ "test1", "test2", "test3", "test4", "test5", "test6", "test7" };

    bufferTarget.WriteStringContainerWithNumber(container0);
    bufferTarget.WriteStringContainerWithoutNumber(container1);
    bufferTarget.WriteContainer(container2);
    bufferTarget.WriteContainer(container3);

    const auto fileBuffer = bufferTarget.GetFileBuffer();

    BufferSource bufferSource{ fileBuffer };

    ASSERT_EQUAL(bufferSource.ReadString(), "test1");
    ASSERT_EQUAL(bufferSource.ReadString(), "test2");

    int32_t size{};
    bufferSource.Read(size);

    ASSERT_EQUAL(size, 5);

    std::array<std::string, container0.size()> result0{};
    bufferSource.ReadContainer(result0);
    ASSERT_EQUAL(container0, result0);

    std::array<std::string, container1.size()> result1{};
    bufferSource.ReadContainer(result1);
    ASSERT_EQUAL(container1, result1);

    std::array<std::string, container2.size()> result2{};
    bufferSource.ReadContainer(result2);
    ASSERT_EQUAL(container2, result2);

    std::array<std::string, container3.size()> result3{};
    bufferSource.ReadContainer(result3);

    for (auto i = 0u; i < container3.size(); ++i)
    {
        ASSERT_EQUAL(container3.at(i), result3.at(i));
    }
}

void CoreTools::BufferTargetTesting::WriteIntTest()
{
    const auto objectRegister = ObjectRegister::Create();

    BufferTarget bufferTarget{ 256, objectRegister };

    bufferTarget.Write(51);

    constexpr std::array container0{ 1, 2, 3, 4, 5 };
    constexpr std::array container1{ 6, 7, 8, 9, 1, 2 };
    constexpr std::array container2{ 3, 4, 5, 6, 7, 8, 9 };

    bufferTarget.WriteContainerWithNumber(container0);
    bufferTarget.WriteContainerWithoutNumber(container1);
    bufferTarget.WriteContainer(container2);

    const auto fileBuffer = bufferTarget.GetFileBuffer();

    BufferSource bufferSource{ fileBuffer };

    int32_t result{};
    bufferSource.Read(result);

    ASSERT_EQUAL(result, 51);

    int32_t size{};
    bufferSource.Read(size);

    ASSERT_EQUAL(size, 5);

    std::array<int, container0.size()> result0{};
    bufferSource.ReadContainer(result0);
    ASSERT_EQUAL(container0, result0);

    std::array<int, container1.size()> result1{};
    bufferSource.ReadContainer(result1);
    ASSERT_EQUAL(container1, result1);

    std::array<int, container2.size()> result2{};
    bufferSource.ReadContainer(result2);
    ASSERT_EQUAL(container2, result2);
}

void CoreTools::BufferTargetTesting::WriteEnumTest()
{
    const auto objectRegister = ObjectRegister::Create();

    BufferTarget bufferTarget{ 256, objectRegister };

    bufferTarget.WriteEnum(BufferTargetTestingEnum::Fifteen);

    constexpr std::array container0{ BufferTargetTestingEnum::Fifteen, BufferTargetTestingEnum::Ten, BufferTargetTestingEnum::Fifteen, BufferTargetTestingEnum::Ten, BufferTargetTestingEnum::Fifteen };
    constexpr std::array container1{ BufferTargetTestingEnum::Fifteen, BufferTargetTestingEnum::Ten, BufferTargetTestingEnum::Fifteen };
    constexpr std::array container2{ BufferTargetTestingEnum::Fifteen, BufferTargetTestingEnum::Ten, BufferTargetTestingEnum::Ten, BufferTargetTestingEnum::Ten };

    bufferTarget.WriteEnumContainerWithNumber(container0);
    bufferTarget.WriteEnumContainerWithoutNumber(container1);
    bufferTarget.WriteEnumContainer(container2);

    const auto fileBuffer = bufferTarget.GetFileBuffer();

    BufferSource bufferSource{ fileBuffer };

    BufferTargetTestingEnum result{};
    bufferSource.ReadEnum(result);

    ASSERT_EQUAL(result, BufferTargetTestingEnum::Fifteen);

    int32_t size{};
    bufferSource.Read(size);

    ASSERT_EQUAL(size, 5);

    std::array<BufferTargetTestingEnum, container0.size()> result0{};
    bufferSource.ReadEnumContainer(result0);
    ASSERT_EQUAL(container0, result0);

    std::array<BufferTargetTestingEnum, container1.size()> result1{};
    bufferSource.ReadEnumContainer(result1);
    ASSERT_EQUAL(container1, result1);

    std::array<BufferTargetTestingEnum, container2.size()> result2{};
    bufferSource.ReadEnumContainer(result2);
    ASSERT_EQUAL(container2, result2);
}

void CoreTools::BufferTargetTesting::WriteAggregateTest()
{
    const auto objectRegister = ObjectRegister::Create();

    BufferTarget bufferTarget{ 512, objectRegister };

    constexpr Mathematics::Vector4D color{ 1.0, 2.0, 3.0, 4.0 };

    bufferTarget.WriteAggregate(color);

    constexpr std::array container0{ Mathematics::Vector4D{ 1.0, 2.0, 3.0, 4.0 },
                                     Mathematics::Vector4D{ 5.0, 6.0, 7.0, 8.0 },
                                     Mathematics::Vector4D{ 9.0, 1.0, 2.0, 3.0 },
                                     Mathematics::Vector4D{ 4.0, 5.0, 6.0, 7.0 },
                                     Mathematics::Vector4D{ 1.0, 2.0, 3.0, 4.0 } };
    constexpr std::array container1{ Mathematics::Vector4D{ 1.0, 2.0, 3.0, 4.0 },
                                     Mathematics::Vector4D{ 5.0, 6.0, 7.0, 8.0 } };
    constexpr std::array container2{ Mathematics::Vector4D{ 9.0, 1.0, 2.0, 3.0 },
                                     Mathematics::Vector4D{ 4.0, 5.0, 6.0, 7.0 },
                                     Mathematics::Vector4D{ 1.0, 2.0, 3.0, 4.0 } };

    bufferTarget.WriteAggregateContainerWithNumber(container0);
    bufferTarget.WriteAggregateContainerWithoutNumber(container1);
    bufferTarget.WriteAggregateContainer(container2);

    const auto fileBuffer = bufferTarget.GetFileBuffer();

    BufferSource bufferSource{ fileBuffer };

    Mathematics::Vector4D result{};
    bufferSource.ReadAggregate(result);

    ASSERT_APPROXIMATE_USE_FUNCTION(Mathematics::Vector4ToolsD::Approximate, result, color, Mathematics::MathD::GetZeroTolerance());

    int32_t size{};
    bufferSource.Read(size);

    ASSERT_EQUAL(size, 5);

    std::array<Mathematics::Vector4D, container0.size()> result0{};
    bufferSource.ReadAggregateContainer(result0);
    for (auto i = 0u; i < container0.size(); ++i)
    {
        ASSERT_APPROXIMATE_USE_FUNCTION(Mathematics::Vector4ToolsD::Approximate, container0.at(i), result0.at(i), Mathematics::MathD::GetZeroTolerance());
    }

    std::array<Mathematics::Vector4D, container1.size()> result1{};
    bufferSource.ReadAggregateContainer(result1);
    for (auto i = 0u; i < container1.size(); ++i)
    {
        ASSERT_APPROXIMATE_USE_FUNCTION(Mathematics::Vector4ToolsD::Approximate, container1.at(i), result1.at(i), Mathematics::MathD::GetZeroTolerance());
    }

    std::array<Mathematics::Vector4D, container2.size()> result2{};
    bufferSource.ReadAggregateContainer(result2);
    for (auto i = 0u; i < container2.size(); ++i)
    {
        ASSERT_APPROXIMATE_USE_FUNCTION(Mathematics::Vector4ToolsD::Approximate, container2.at(i), result2.at(i), Mathematics::MathD::GetZeroTolerance());
    }
}

void CoreTools::BufferTargetTesting::WriteObjectAssociatedTest()
{
    const auto objectRegister = ObjectRegister::Create();

    BufferTarget bufferTarget{ 256, objectRegister };

    const auto boolObject = std::make_shared<BoolObject>(DisableNotThrow::Disable);
    boolObject->SetUniqueId(1);
    const ConstObjectInterfaceAssociated boolObjectAssociated{ boolObject };

    const auto intObject = std::make_shared<IntObject>(DisableNotThrow::Disable);
    intObject->SetUniqueId(2);
    const ConstObjectInterfaceAssociated intObjectAssociated{ intObject };
    const ConstWeakObjectAssociated<ObjectInterface> intWeakObjectAssociated{ intObject };

    objectRegister->Register(boolObjectAssociated);
    objectRegister->Register(intObjectAssociated);

    bufferTarget.WriteUniqueId(intObject);
    bufferTarget.WriteObjectAssociated(boolObjectAssociated);
    bufferTarget.WriteWeakObjectAssociated(intWeakObjectAssociated);

    const std::array container0{ intObjectAssociated, boolObjectAssociated, boolObjectAssociated, intObjectAssociated, boolObjectAssociated };
    const std::array container1{ intObjectAssociated, boolObjectAssociated, boolObjectAssociated, intObjectAssociated, boolObjectAssociated, intObjectAssociated };
    const std::array container2{ intObjectAssociated, boolObjectAssociated, boolObjectAssociated, intObjectAssociated, boolObjectAssociated, intObjectAssociated, boolObjectAssociated };

    bufferTarget.WriteObjectAssociatedContainerWithNumber(container0);
    bufferTarget.WriteObjectAssociatedContainerWithoutNumber(container1);
    bufferTarget.WriteObjectAssociatedContainer(container2);

    const auto fileBuffer = bufferTarget.GetFileBuffer();

    BufferSource bufferSource{ fileBuffer };

    int64_t result{};

    bufferSource.Read(result);
    ASSERT_EQUAL(result, 2);

    bufferSource.Read(result);
    ASSERT_EQUAL(result, 1);

    bufferSource.Read(result);
    ASSERT_EQUAL(result, 2);

    int32_t size{};
    bufferSource.Read(size);

    ASSERT_EQUAL(size, 5);

    std::array<int64_t, container0.size()> result0{};
    bufferSource.ReadContainer(result0);
    for (auto i = 0u; i < container0.size(); ++i)
    {
        ASSERT_EQUAL(container0.at(i).object->GetUniqueId(), result0.at(i));
    }

    std::array<int64_t, container1.size()> result1{};
    bufferSource.ReadContainer(result1);
    for (auto i = 0u; i < container1.size(); ++i)
    {
        ASSERT_EQUAL(container1.at(i).object->GetUniqueId(), result1.at(i));
    }

    std::array<int64_t, container2.size()> result2{};
    bufferSource.ReadContainer(result2);
    for (auto i = 0u; i < container2.size(); ++i)
    {
        ASSERT_EQUAL(container2.at(i).object->GetUniqueId(), result2.at(i));
    }
}
