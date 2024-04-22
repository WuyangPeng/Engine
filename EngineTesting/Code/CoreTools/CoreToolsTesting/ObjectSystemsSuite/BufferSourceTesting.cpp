///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/10/25 14:15)

#include "BufferSourceTesting.h"
#include "Detail/BoolObject.h"
#include "Detail/BufferSourceTestingEnum.h"
#include "Detail/IntObject.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ConstObjectAssociated.h"
#include "CoreTools/ObjectSystems/ConstWeakObjectAssociated.h"
#include "CoreTools/ObjectSystems/StreamDetail.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Algebra/Vector4Detail.h"
#include "Mathematics/Algebra/Vector4ToolsDetail.h"
#include "Mathematics/Base/MathDetail.h"

#include <vector>

using namespace std::literals;

CoreTools::BufferSourceTesting::BufferSourceTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, BufferSourceTesting)

void CoreTools::BufferSourceTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::BufferSourceTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ReadBoolTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ReadStringTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ReadIntTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ReadEnumTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ReadAggregateTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ReadObjectAssociatedTest);
}

void CoreTools::BufferSourceTesting::ReadBoolTest()
{
    const auto objectRegister = ObjectRegister::Create();

    BufferTarget bufferTarget{ 256, objectRegister };

    bufferTarget.Write(true);
    bufferTarget.Write(false);

    constexpr std::array container0{ true, false, true, false, true };
    constexpr std::array container1{ false, false, true, false, true, true };
    constexpr std::array container2{ true, false, true, false, false, true, true };
    constexpr std::array container3{ true, false, true };
    constexpr std::array container4{ false, false, true, false, false, true };
    constexpr std::array container5{ true, false, true, false, false, true, false };
    const std::set container6{ true, false };

    bufferTarget.WriteBoolContainerWithNumber(container0);
    bufferTarget.WriteBoolContainerWithNumber(container1);
    bufferTarget.WriteContainer(container2);
    bufferTarget.WriteBoolContainerWithoutNumber(container3);
    bufferTarget.WriteBoolContainerWithNumber(container4);
    bufferTarget.WriteContainer(container5);
    bufferTarget.WriteBoolContainerWithoutNumber(container6);

    const auto fileBuffer = bufferTarget.GetFileBuffer();

    BufferSource bufferSource{ fileBuffer };
    ASSERT_EQUAL(bufferSource.GetBytesRead(), 0);
    ASSERT_EQUAL(bufferSource.GetBytesTotal(), fileBuffer->GetSize());

    ASSERT_TRUE(bufferSource.ReadBool());
    auto result = true;
    bufferSource.Read(result);
    ASSERT_FALSE(result);

    int32_t size{};
    bufferSource.Read(size);

    ASSERT_EQUAL(size, 5);

    const auto result0 = bufferSource.ReadBoolContainerUseNumber<std::vector<bool>>(size);
    for (auto i = 0; i < size; ++i)
    {
        ASSERT_EQUAL(container0.at(i), result0.at(i));
    }

    const auto result1 = bufferSource.ReadBoolContainerNotUseNumber<std::vector<bool>>();
    ASSERT_EQUAL(result1.size(), container1.size());
    for (auto i = 0u; i < result1.size(); ++i)
    {
        ASSERT_EQUAL(container1.at(i), result1.at(i));
    }

    const auto result2 = bufferSource.ReadBoolContainer<container2.size()>();
    ASSERT_EQUAL(container2, result2);

    std::vector<bool> result3{};
    bufferSource.ReadBoolContainer(boost::numeric_cast<int>(container3.size()), result3);
    ASSERT_EQUAL(result3.size(), container3.size());
    for (auto i = 0u; i < result3.size(); ++i)
    {
        ASSERT_EQUAL(container3.at(i), result3.at(i));
    }

    std::vector<bool> result4{};
    bufferSource.ReadBoolContainer(result4);
    ASSERT_EQUAL(result4.size(), container4.size());
    for (auto i = 0u; i < result4.size(); ++i)
    {
        ASSERT_EQUAL(container4.at(i), result4.at(i));
    }

    std::array<bool, container5.size()> result5{};
    bufferSource.ReadContainer(result5);
    ASSERT_EQUAL(container5, result5);

    std::set<bool> result6{};
    bufferSource.ReadBoolContainer(boost::numeric_cast<int>(container6.size()), result6);
    ASSERT_EQUAL(result6, container6);

    ASSERT_LESS_EQUAL(bufferSource.GetBytesRead(), fileBuffer->GetSize());
    ASSERT_EQUAL(bufferSource.GetBytesTotal(), fileBuffer->GetSize());
}

void CoreTools::BufferSourceTesting::ReadStringTest()
{
    const auto objectRegister = ObjectRegister::Create();

    BufferTarget bufferTarget{ 512, objectRegister };

    bufferTarget.Write("test1"s);
    bufferTarget.Write("test2"s);

    const std::array container0{ "test1"s, "test2"s, "test3"s, "test4"s, "test5"s };
    const std::array container1{ "test1"s, "test2"s, "test3"s, "test4"s, "test5"s, "test6"s };
    const std::array container2{ "test1"s, "test2"s, "test3"s, "test4"s, "test5"s, "test6"s, "test7"s };
    const std::array container3{ "test1"s, "test2"s, "test3"s, "test4"s, "test5"s, "test6"s, "test7"s };
    const std::set container4{ "test1"s, "test2"s, "test3"s, "test4"s, "test5"s, "test6"s, "test7"s, "test8"s };
    const std::array container5{ "test1"s, "test2"s };
    const std::array container6{ "test1"s, "test2"s, "test3"s, "test4"s };

    bufferTarget.WriteStringContainerWithNumber(container0);
    bufferTarget.WriteStringContainerWithNumber(container1);
    bufferTarget.WriteContainer(container2);
    bufferTarget.WriteContainer(container3);
    bufferTarget.WriteStringContainerWithoutNumber(container4);
    bufferTarget.WriteStringContainerWithNumber(container5);

    const auto fileBuffer = bufferTarget.GetFileBuffer();

    BufferSource bufferSource{ fileBuffer };
    ASSERT_EQUAL(bufferSource.GetBytesRead(), 0);
    ASSERT_EQUAL(bufferSource.GetBytesTotal(), fileBuffer->GetSize());

    ASSERT_EQUAL(bufferSource.ReadString(), "test1");
    std::string result{};
    bufferSource.Read(result);
    ASSERT_EQUAL(result, "test2");

    int32_t size{};
    bufferSource.Read(size);

    ASSERT_EQUAL(size, 5);

    const auto result0 = bufferSource.ReadStringContainerUseNumber<std::vector<std::string>>(size);
    ASSERT_EQUAL(result0.size(), container0.size());
    for (auto i = 0u; i < result0.size(); ++i)
    {
        ASSERT_EQUAL(result0.at(i), container0.at(i));
    }

    const auto result1 = bufferSource.ReadStringContainerNotUseNumber<std::vector<std::string>>();
    ASSERT_EQUAL(result1.size(), container1.size());
    for (auto i = 0u; i < result1.size(); ++i)
    {
        ASSERT_EQUAL(result1.at(i), container1.at(i));
    }

    const auto result2 = bufferSource.ReadStringContainer<container2.size()>();
    ASSERT_EQUAL(container2, result2);

    std::vector<std::string> result3{};
    bufferSource.ReadStringContainer(boost::numeric_cast<int>(container3.size()), result3);
    ASSERT_EQUAL(result3.size(), container3.size());

    for (auto i = 0u; i < container3.size(); ++i)
    {
        ASSERT_EQUAL(container3.at(i), result3.at(i));
    }

    std::set<std::string> result4{};
    bufferSource.ReadStringContainer(boost::numeric_cast<int>(container4.size()), result4);
    ASSERT_EQUAL(result4, container4);

    std::vector<std::string> result5{};
    bufferSource.ReadStringContainer(result5);
    ASSERT_EQUAL(result5.size(), container5.size());

    for (auto i = 0u; i < container5.size(); ++i)
    {
        ASSERT_EQUAL(container5.at(i), result5.at(i));
    }

    std::array<std::string, container6.size()> result6{};
    bufferSource.ReadContainer(result6);
    ASSERT_EQUAL(result6.size(), container6.size());

    ASSERT_LESS_EQUAL(bufferSource.GetBytesRead(), fileBuffer->GetSize());
    ASSERT_EQUAL(bufferSource.GetBytesTotal(), fileBuffer->GetSize());
}

void CoreTools::BufferSourceTesting::ReadIntTest()
{
    const auto objectRegister = ObjectRegister::Create();

    BufferTarget bufferTarget{ 512, objectRegister };

    bufferTarget.Write(51);
    bufferTarget.Write(511);

    constexpr std::array container0{ 1, 2, 3, 4, 5 };
    constexpr std::array container1{ 6, 7, 8, 9, 1, 2 };
    constexpr std::array container2{ 3, 4, 5, 6, 7, 8, 9 };
    constexpr std::array container3{ 3, 4, 5 };
    constexpr std::array container4{ 3, 4, 3, 4, 5 };
    const std::set container5{ 1, 2, 3, 4, 5 };
    constexpr std::array container6{ 3, 4, 3, 4, 5, 4, 5, 4, 5 };
    constexpr std::array container7{ 3, 4, 3, 4, 5, 4, 5, 4, 5, 3, 4, 3 };
    constexpr std::array container8{ 3, 4, 3, 4, 5, 4, 5, 4, 5, 3, 4, 3 };

    bufferTarget.WriteContainerWithNumber(container0);
    bufferTarget.WriteContainerWithoutNumber(container1);
    bufferTarget.WriteContainerWithNumber(container2);
    bufferTarget.WriteContainerWithNumber(container3);
    bufferTarget.WriteContainerWithoutNumber(container4);
    bufferTarget.WriteContainerWithoutNumber(container5);
    bufferTarget.WriteContainerWithoutNumber(container6);
    bufferTarget.WriteContainerWithNumber(container7);
    bufferTarget.WriteContainerWithoutNumber(container8);

    const auto fileBuffer = bufferTarget.GetFileBuffer();

    BufferSource bufferSource{ fileBuffer };
    ASSERT_EQUAL(bufferSource.GetBytesRead(), 0);
    ASSERT_EQUAL(bufferSource.GetBytesTotal(), fileBuffer->GetSize());

    int32_t result{};
    bufferSource.Read(result);
    ASSERT_EQUAL(result, 51);

    result = bufferSource.Read<int32_t>();
    ASSERT_EQUAL(result, 511);

    int32_t size{};
    bufferSource.Read(size);

    ASSERT_EQUAL(size, 5);

    const auto result0 = bufferSource.ReadContainerUseNumber<std::vector<int32_t>>(size);
    for (auto i = 0u; i < result0.size(); ++i)
    {
        ASSERT_EQUAL(result0.at(i), container0.at(i));
    }

    const auto result1 = bufferSource.ReadVectorUseNumber<int32_t>(boost::numeric_cast<int>(container1.size()));
    for (auto i = 0u; i < result1.size(); ++i)
    {
        ASSERT_EQUAL(result1.at(i), container1.at(i));
    }

    const auto result2 = bufferSource.ReadContainerNotUseNumber<std::vector<int32_t>>();
    for (auto i = 0u; i < result2.size(); ++i)
    {
        ASSERT_EQUAL(result2.at(i), container2.at(i));
    }

    const auto result3 = bufferSource.ReadVectorNotUseNumber<int32_t>();
    for (auto i = 0u; i < result3.size(); ++i)
    {
        ASSERT_EQUAL(result3.at(i), container3.at(i));
    }

    std::list<int32_t> result4{};
    bufferSource.ReadContainer(boost::numeric_cast<int>(container4.size()), result4);
    ASSERT_EQUAL(result4.size(), container4.size());

    auto index = 0;
    for (auto value : result4)
    {
        ASSERT_EQUAL(container4.at(index), value);
        ++index;
    }

    std::set<int32_t> result5{};
    bufferSource.ReadContainer(boost::numeric_cast<int>(container5.size()), result5);
    ASSERT_EQUAL(result5, container5);

    std::vector<int32_t> result6{};
    bufferSource.ReadContainer(boost::numeric_cast<int>(container6.size()), result6);
    ASSERT_EQUAL(result6.size(), container6.size());
    for (auto i = 0u; i < result6.size(); ++i)
    {
        ASSERT_EQUAL(result6.at(i), container6.at(i));
    }

    std::vector<int32_t> result7{};
    bufferSource.ReadContainer(result7);
    ASSERT_EQUAL(result7.size(), container7.size());
    for (auto i = 0u; i < result7.size(); ++i)
    {
        ASSERT_EQUAL(result7.at(i), container7.at(i));
    }

    std::array<int32_t, container8.size()> result8{};
    bufferSource.ReadContainer(result8);
    ASSERT_EQUAL(result8, container8);

    ASSERT_LESS_EQUAL(bufferSource.GetBytesRead(), fileBuffer->GetSize());
    ASSERT_EQUAL(bufferSource.GetBytesTotal(), fileBuffer->GetSize());
}

void CoreTools::BufferSourceTesting::ReadEnumTest()
{
    const auto objectRegister = ObjectRegister::Create();

    BufferTarget bufferTarget{ 512, objectRegister };

    bufferTarget.WriteEnum(BufferSourceTestingEnum::Nine);
    bufferTarget.WriteEnum(BufferSourceTestingEnum::Twenty);

    constexpr std::array container0{ BufferSourceTestingEnum::Nine, BufferSourceTestingEnum::Twenty, BufferSourceTestingEnum::Nine, BufferSourceTestingEnum::Twenty };
    constexpr std::array container1{ BufferSourceTestingEnum::Nine, BufferSourceTestingEnum::Twenty, BufferSourceTestingEnum::Nine };
    constexpr std::array container2{ BufferSourceTestingEnum::Nine, BufferSourceTestingEnum::Twenty, BufferSourceTestingEnum::Nine, BufferSourceTestingEnum::Twenty, BufferSourceTestingEnum::Twenty };
    constexpr std::array container3{ BufferSourceTestingEnum::Nine, BufferSourceTestingEnum::Twenty, BufferSourceTestingEnum::Twenty };
    constexpr std::array container4{ BufferSourceTestingEnum::Twenty, BufferSourceTestingEnum::Twenty };
    const std::set container5{ BufferSourceTestingEnum::Nine, BufferSourceTestingEnum::Twenty };
    constexpr std::array container6{ BufferSourceTestingEnum::Nine, BufferSourceTestingEnum::Twenty, BufferSourceTestingEnum::Twenty, BufferSourceTestingEnum::Nine, BufferSourceTestingEnum::Twenty };
    constexpr std::array container7{ BufferSourceTestingEnum::Nine, BufferSourceTestingEnum::Twenty, BufferSourceTestingEnum::Nine, BufferSourceTestingEnum::Twenty };
    constexpr std::array container8{ BufferSourceTestingEnum::Nine, BufferSourceTestingEnum::Twenty, BufferSourceTestingEnum::Twenty };

    bufferTarget.WriteEnumContainerWithNumber(container0);
    bufferTarget.WriteEnumContainerWithoutNumber(container1);
    bufferTarget.WriteEnumContainerWithNumber(container2);
    bufferTarget.WriteEnumContainerWithNumber(container3);
    bufferTarget.WriteEnumContainerWithoutNumber(container4);
    bufferTarget.WriteEnumContainerWithoutNumber(container5);
    bufferTarget.WriteEnumContainerWithoutNumber(container6);
    bufferTarget.WriteEnumContainerWithNumber(container7);
    bufferTarget.WriteEnumContainerWithoutNumber(container8);

    const auto fileBuffer = bufferTarget.GetFileBuffer();

    BufferSource bufferSource{ fileBuffer };
    ASSERT_EQUAL(bufferSource.GetBytesRead(), 0);
    ASSERT_EQUAL(bufferSource.GetBytesTotal(), fileBuffer->GetSize());

    BufferSourceTestingEnum result{};
    bufferSource.ReadEnum(result);
    ASSERT_EQUAL(result, BufferSourceTestingEnum::Nine);

    result = bufferSource.ReadEnum<BufferSourceTestingEnum>();
    ASSERT_EQUAL(result, BufferSourceTestingEnum::Twenty);

    int32_t size{};
    bufferSource.Read(size);

    ASSERT_EQUAL(size, 4);

    const auto result0 = bufferSource.ReadEnumContainerUseNumber<std::vector<BufferSourceTestingEnum>>(size);
    for (auto i = 0u; i < result0.size(); ++i)
    {
        ASSERT_EQUAL(result0.at(i), container0.at(i));
    }

    const auto result1 = bufferSource.ReadEnumVectorUseNumber<BufferSourceTestingEnum>(boost::numeric_cast<int>(container1.size()));
    for (auto i = 0u; i < result1.size(); ++i)
    {
        ASSERT_EQUAL(result1.at(i), container1.at(i));
    }

    const auto result2 = bufferSource.ReadEnumContainerNotUseNumber<std::vector<BufferSourceTestingEnum>>();
    for (auto i = 0u; i < result2.size(); ++i)
    {
        ASSERT_EQUAL(result2.at(i), container2.at(i));
    }

    const auto result3 = bufferSource.ReadEnumVectorNotUseNumber<BufferSourceTestingEnum>();
    for (auto i = 0u; i < result3.size(); ++i)
    {
        ASSERT_EQUAL(result3.at(i), container3.at(i));
    }

    std::list<BufferSourceTestingEnum> result4{};
    bufferSource.ReadEnumContainer(boost::numeric_cast<int>(container4.size()), result4);
    ASSERT_EQUAL(result4.size(), container4.size());

    auto index = 0;
    for (auto value : result4)
    {
        ASSERT_EQUAL(container4.at(index), value);
        ++index;
    }

    std::set<BufferSourceTestingEnum> result5{};
    bufferSource.ReadEnumContainer(boost::numeric_cast<int>(container5.size()), result5);
    ASSERT_EQUAL(result5, container5);

    std::vector<BufferSourceTestingEnum> result6{};
    bufferSource.ReadEnumContainer(boost::numeric_cast<int>(container6.size()), result6);
    ASSERT_EQUAL(result6.size(), container6.size());
    for (auto i = 0u; i < result6.size(); ++i)
    {
        ASSERT_EQUAL(result6.at(i), container6.at(i));
    }

    std::vector<BufferSourceTestingEnum> result7{};
    bufferSource.ReadEnumContainer(result7);
    ASSERT_EQUAL(result7.size(), container7.size());
    for (auto i = 0u; i < result7.size(); ++i)
    {
        ASSERT_EQUAL(result7.at(i), container7.at(i));
    }

    std::array<BufferSourceTestingEnum, container8.size()> result8{};
    bufferSource.ReadEnumContainer(result8);
    ASSERT_EQUAL(result8, container8);

    ASSERT_LESS_EQUAL(bufferSource.GetBytesRead(), fileBuffer->GetSize());
    ASSERT_EQUAL(bufferSource.GetBytesTotal(), fileBuffer->GetSize());
}

void CoreTools::BufferSourceTesting::ReadAggregateTest()
{
    const auto objectRegister = ObjectRegister::Create();

    BufferTarget bufferTarget{ 1024, objectRegister };

    constexpr Mathematics::Vector4D color0{ 1.0, 2.0, 3.0, 4.0 };
    bufferTarget.WriteAggregate(color0);

    constexpr Mathematics::Vector4D color1{ 1.0, 2.0, 3.0, 4.0 };
    bufferTarget.WriteAggregate(color1);

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
    const std::set container3{ Mathematics::Vector4D{ 9.0, 1.0, 2.0, 3.0 },
                               Mathematics::Vector4D{ 4.0, 5.0, 6.0, 7.0 },
                               Mathematics::Vector4D{ 1.0, 2.0, 3.0, 4.0 } };
    constexpr std::array container4{ Mathematics::Vector4D{ 9.0, 1.0, 2.0, 3.0 },
                                     Mathematics::Vector4D{ 4.0, 5.0, 6.0, 7.0 },
                                     Mathematics::Vector4D{ 1.0, 2.0, 3.0, 4.0 },
                                     Mathematics::Vector4D{ 1.0, 21.0, 3.0, 4.0 } };
    constexpr std::array container5{ Mathematics::Vector4D{ 9.0, 1.0, 2.0, 3.0 },
                                     Mathematics::Vector4D{ 4.0, 5.0, 6.0, 7.0 },
                                     Mathematics::Vector4D{ 1.0, 2.0, 3.0, 4.0 },
                                     Mathematics::Vector4D{ 1.0, 21.0, 3.0, 4.0 },
                                     Mathematics::Vector4D{ 1.0, 2.0, 3.0, 4.0 },
                                     Mathematics::Vector4D{ 1.0, 21.0, 3.0, 4.0 } };
    constexpr std::array container6{ Mathematics::Vector4D{ 9.0, 1.0, 2.0, 3.0 },
                                     Mathematics::Vector4D{ 4.0, 5.0, 6.0, 7.0 },
                                     Mathematics::Vector4D{ 1.0, 2.0, 3.0, 4.0 },
                                     Mathematics::Vector4D{ 4.0, 5.0, 6.0, 7.0 } };

    bufferTarget.WriteAggregateContainerWithNumber(container0);
    bufferTarget.WriteAggregateContainerWithNumber(container1);
    bufferTarget.WriteAggregateContainer(container2);
    bufferTarget.WriteAggregateContainerWithoutNumber(container3);
    bufferTarget.WriteAggregateContainerWithoutNumber(container4);
    bufferTarget.WriteAggregateContainerWithNumber(container5);
    bufferTarget.WriteAggregateContainer(container6);

    const auto fileBuffer = bufferTarget.GetFileBuffer();

    BufferSource bufferSource{ fileBuffer };
    ASSERT_EQUAL(bufferSource.GetBytesRead(), 0);
    ASSERT_EQUAL(bufferSource.GetBytesTotal(), fileBuffer->GetSize());

    Mathematics::Vector4D result{};
    bufferSource.ReadAggregate(result);

    ASSERT_APPROXIMATE_USE_FUNCTION(Mathematics::Vector4ToolsD::Approximate, result, color0, Mathematics::MathD::GetZeroTolerance());

    result = bufferSource.ReadAggregate<Mathematics::Vector4D>();
    ASSERT_APPROXIMATE_USE_FUNCTION(Mathematics::Vector4ToolsD::Approximate, result, color1, Mathematics::MathD::GetZeroTolerance());

    int32_t size{};
    bufferSource.Read(size);

    ASSERT_EQUAL(size, 5);

    std::array<Mathematics::Vector4D, container0.size()> result0{};
    bufferSource.ReadAggregateContainer(result0);
    for (auto i = 0u; i < container0.size(); ++i)
    {
        ASSERT_APPROXIMATE_USE_FUNCTION(Mathematics::Vector4ToolsD::Approximate, container0.at(i), result0.at(i), Mathematics::MathD::GetZeroTolerance());
    }

    std::vector<Mathematics::Vector4D> result1{};
    bufferSource.ReadAggregateContainer(result1);
    ASSERT_EQUAL(result1.size(), container1.size());
    for (auto i = 0u; i < container1.size(); ++i)
    {
        ASSERT_APPROXIMATE_USE_FUNCTION(Mathematics::Vector4ToolsD::Approximate, container1.at(i), result1.at(i), Mathematics::MathD::GetZeroTolerance());
    }

    std::vector<Mathematics::Vector4D> result2{};
    bufferSource.ReadAggregateContainer(boost::numeric_cast<int>(container2.size()), result2);
    ASSERT_EQUAL(result2.size(), container2.size());
    for (auto i = 0u; i < container2.size(); ++i)
    {
        ASSERT_APPROXIMATE_USE_FUNCTION(Mathematics::Vector4ToolsD::Approximate, container2.at(i), result2.at(i), Mathematics::MathD::GetZeroTolerance());
    }

    std::set<Mathematics::Vector4D> result3{};
    bufferSource.ReadAggregateContainer(boost::numeric_cast<int>(container3.size()), result3);
    ASSERT_EQUAL(result3.size(), container3.size());
    auto iter = container3.cbegin();
    for (const auto& value : result3)
    {
        if (iter == container3.cend())
        {
            break;
        }

        ASSERT_APPROXIMATE_USE_FUNCTION(Mathematics::Vector4ToolsD::Approximate, *iter, value, Mathematics::MathD::GetZeroTolerance());
        ++iter;
    }

    const auto result4 = bufferSource.ReadAggregateContainerUseNumber<std::vector<Mathematics::Vector4D>>(boost::numeric_cast<int>(container4.size()));
    ASSERT_EQUAL(result4.size(), container4.size());
    for (auto i = 0u; i < container4.size(); ++i)
    {
        ASSERT_APPROXIMATE_USE_FUNCTION(Mathematics::Vector4ToolsD::Approximate, container4.at(i), result4.at(i), Mathematics::MathD::GetZeroTolerance());
    }

    const auto result5 = bufferSource.ReadAggregateContainerNotUseNumber<std::vector<Mathematics::Vector4D>>();
    ASSERT_EQUAL(result5.size(), container5.size());
    for (auto i = 0u; i < container5.size(); ++i)
    {
        ASSERT_APPROXIMATE_USE_FUNCTION(Mathematics::Vector4ToolsD::Approximate, container5.at(i), result5.at(i), Mathematics::MathD::GetZeroTolerance());
    }

    const auto result6 = bufferSource.ReadAggregateContainer<Mathematics::Vector4D, container6.size()>();
    ASSERT_EQUAL(result6.size(), container6.size());
    for (auto i = 0u; i < container6.size(); ++i)
    {
        ASSERT_APPROXIMATE_USE_FUNCTION(Mathematics::Vector4ToolsD::Approximate, container6.at(i), result6.at(i), Mathematics::MathD::GetZeroTolerance());
    }

    ASSERT_LESS_EQUAL(bufferSource.GetBytesRead(), fileBuffer->GetSize());
    ASSERT_EQUAL(bufferSource.GetBytesTotal(), fileBuffer->GetSize());
}

void CoreTools::BufferSourceTesting::ReadObjectAssociatedTest()
{
    const auto objectRegister = ObjectRegister::Create();

    BufferTarget bufferTarget{ 512, objectRegister };

    const auto boolObject = std::make_shared<BoolObject>(DisableNotThrow::Disable);
    boolObject->SetUniqueId(1);
    const ConstObjectInterfaceAssociated boolObjectAssociated{ boolObject };

    const auto intObject = std::make_shared<IntObject>(DisableNotThrow::Disable);
    intObject->SetUniqueId(2);
    const ConstObjectInterfaceAssociated intObjectAssociated{ intObject };
    const ConstWeakObjectAssociated<ObjectInterface> intWeakObjectAssociated{ intObject };

    objectRegister->Register(boolObjectAssociated);
    objectRegister->Register(intObjectAssociated);

    bufferTarget.WriteObjectAssociated(boolObjectAssociated);
    bufferTarget.WriteWeakObjectAssociated(intWeakObjectAssociated);

    const std::array container0{ intObjectAssociated, boolObjectAssociated, boolObjectAssociated, intObjectAssociated, boolObjectAssociated };
    const std::array container1{ intObjectAssociated, boolObjectAssociated, boolObjectAssociated, intObjectAssociated, boolObjectAssociated, intObjectAssociated };
    const std::array container2{ intObjectAssociated, boolObjectAssociated, boolObjectAssociated, intObjectAssociated, boolObjectAssociated, intObjectAssociated, boolObjectAssociated };
    const std::array container3{ intObjectAssociated, boolObjectAssociated, intObjectAssociated, boolObjectAssociated };
    const std::array container4{ intObjectAssociated, boolObjectAssociated };
    const std::array container5{ intObjectAssociated, boolObjectAssociated, boolObjectAssociated };

    bufferTarget.WriteObjectAssociatedContainerWithNumber(container0);
    bufferTarget.WriteObjectAssociatedContainerWithoutNumber(container1);
    bufferTarget.WriteObjectAssociatedContainerWithNumber(container2);
    bufferTarget.WriteObjectAssociatedContainer(container3);
    bufferTarget.WriteObjectAssociatedContainer(container4);
    bufferTarget.WriteObjectAssociatedContainerWithNumber(container5);
    bufferTarget.Write(int64_t{ 123 });

    const auto fileBuffer = bufferTarget.GetFileBuffer();

    BufferSource bufferSource{ fileBuffer };
    ASSERT_EQUAL(bufferSource.GetBytesRead(), 0);
    ASSERT_EQUAL(bufferSource.GetBytesTotal(), fileBuffer->GetSize());

    auto result = bufferSource.ReadObjectAssociated<ConstObjectInterfaceAssociated>();
    ASSERT_EQUAL(result.associated, 1);

    bufferSource.ReadObjectAssociated(result);
    ASSERT_EQUAL(result.associated, 2);

    int32_t size{};
    bufferSource.Read(size);

    ASSERT_EQUAL(size, 5);

    std::array<ConstObjectInterfaceAssociated, container0.size()> result0{};
    bufferSource.ReadObjectAssociatedContainer(result0);
    for (auto i = 0u; i < container0.size(); ++i)
    {
        ASSERT_EQUAL(container0.at(i).object->GetUniqueId(), result0.at(i).associated);
    }

    const auto result1 = bufferSource.ReadObjectAssociatedContainerUseNumber<std::vector<ConstObjectInterfaceAssociated>>(boost::numeric_cast<int>(container1.size()));
    ASSERT_EQUAL(result1.size(), container1.size());
    for (auto i = 0u; i < container1.size(); ++i)
    {
        ASSERT_EQUAL(container1.at(i).object->GetUniqueId(), result1.at(i).associated);
    }

    const auto result2 = bufferSource.ReadObjectAssociatedContainerNotUseNumber<std::vector<ConstObjectInterfaceAssociated>>();
    ASSERT_EQUAL(result2.size(), container2.size());
    for (auto i = 0u; i < container2.size(); ++i)
    {
        ASSERT_EQUAL(container2.at(i).object->GetUniqueId(), result2.at(i).associated);
    }

    const auto result3 = bufferSource.ReadObjectAssociatedContainer<ConstObjectInterfaceAssociated, container3.size()>();
    ASSERT_EQUAL(result3.size(), container3.size());
    for (auto i = 0u; i < container3.size(); ++i)
    {
        ASSERT_EQUAL(container3.at(i).object->GetUniqueId(), result3.at(i).associated);
    }

    std::vector<ConstObjectInterfaceAssociated> result4{};
    bufferSource.ReadObjectAssociatedContainer(boost::numeric_cast<int>(container4.size()), result4);
    ASSERT_EQUAL(result4.size(), container4.size());
    for (auto i = 0u; i < container4.size(); ++i)
    {
        ASSERT_EQUAL(container4.at(i).object->GetUniqueId(), result4.at(i).associated);
    }

    std::vector<ConstObjectInterfaceAssociated> result5{};
    bufferSource.ReadObjectAssociatedContainer(result5);
    ASSERT_EQUAL(result5.size(), container5.size());
    for (auto i = 0u; i < container5.size(); ++i)
    {
        ASSERT_EQUAL(container5.at(i).object->GetUniqueId(), result5.at(i).associated);
    }

    const auto objectInterface = BoolObject::Create();

    bufferSource.ReadUniqueId(*objectInterface);

    ASSERT_EQUAL(objectInterface->GetUniqueId(), 123);

    bufferSource.IncrementBytesProcessed(20);

    ASSERT_LESS_EQUAL(bufferSource.GetBytesRead(), fileBuffer->GetSize());
    ASSERT_EQUAL(bufferSource.GetBytesTotal(), fileBuffer->GetSize());
}
