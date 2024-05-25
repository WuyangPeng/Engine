/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.9 (2024/05/21 19:55)

#include "BufferSourceTesting.h"
#include "Detail/BoolObject.h"
#include "Detail/BufferSourceTestingEnum.h"
#include "Detail/IntObject.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ConstObjectAssociated.h"
#include "CoreTools/ObjectSystems/ConstWeakObjectAssociated.h"
#include "CoreTools/ObjectSystems/StreamDetail.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Algebra/Vector4Detail.h"
#include "Mathematics/Algebra/Vector4ToolsDetail.h"
#include "Mathematics/Base/MathDetail.h"

CoreTools::BufferSourceTesting::BufferSourceTesting(const OStreamShared& stream)
    : ParentType{ stream },
      boolObjectAssociated{ CreateBoolObjectAssociated() },
      intObjectAssociated{ CreateIntObjectAssociated() },
      objectAssociatedContainer0{ intObjectAssociated, boolObjectAssociated, boolObjectAssociated, intObjectAssociated, boolObjectAssociated },
      objectAssociatedContainer1{ intObjectAssociated, boolObjectAssociated, boolObjectAssociated, intObjectAssociated, boolObjectAssociated, intObjectAssociated },
      objectAssociatedContainer2{ intObjectAssociated, boolObjectAssociated, boolObjectAssociated, intObjectAssociated, boolObjectAssociated, intObjectAssociated, boolObjectAssociated },
      objectAssociatedContainer3{ intObjectAssociated, boolObjectAssociated, intObjectAssociated, boolObjectAssociated },
      objectAssociatedContainer4{ intObjectAssociated, boolObjectAssociated },
      objectAssociatedContainer5{ intObjectAssociated, boolObjectAssociated, boolObjectAssociated }
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
    const auto fileBuffer = GetBoolFileBuffer();

    BufferSource bufferSource{ fileBuffer };
    ASSERT_EQUAL(bufferSource.GetBytesRead(), 0);
    ASSERT_EQUAL(bufferSource.GetBytesTotal(), fileBuffer->GetSize());

    ASSERT_NOT_THROW_EXCEPTION_1(ReadBool0Test, bufferSource);
    ASSERT_NOT_THROW_EXCEPTION_1(ReadBool1Test, bufferSource);
    ASSERT_NOT_THROW_EXCEPTION_1(ReadBool2Test, bufferSource);
    ASSERT_NOT_THROW_EXCEPTION_1(ReadBool3Test, bufferSource);
    ASSERT_NOT_THROW_EXCEPTION_1(ReadBool4Test, bufferSource);
    ASSERT_NOT_THROW_EXCEPTION_1(ReadBool5Test, bufferSource);
    ASSERT_NOT_THROW_EXCEPTION_1(ReadBool6Test, bufferSource);
    ASSERT_NOT_THROW_EXCEPTION_1(ReadBool7Test, bufferSource);

    ASSERT_LESS_EQUAL(bufferSource.GetBytesRead(), fileBuffer->GetSize());
    ASSERT_EQUAL(bufferSource.GetBytesTotal(), fileBuffer->GetSize());
}

CoreTools::ConstFileBufferSharedPtr CoreTools::BufferSourceTesting::GetBoolFileBuffer()
{
    const auto objectRegister = ObjectRegister::Create();

    BufferTarget bufferTarget{ bufferSize, objectRegister };

    bufferTarget.Write(true);
    bufferTarget.Write(false);

    bufferTarget.WriteBoolContainerWithNumber(boolContainer0);
    bufferTarget.WriteBoolContainerWithNumber(boolContainer1);
    bufferTarget.WriteContainer(boolContainer2);
    bufferTarget.WriteBoolContainerWithoutNumber(boolContainer3);
    bufferTarget.WriteBoolContainerWithNumber(boolContainer4);
    bufferTarget.WriteContainer(boolContainer5);
    bufferTarget.WriteBoolContainerWithoutNumber(boolContainer6);

    return bufferTarget.GetFileBuffer();
}

void CoreTools::BufferSourceTesting::ReadBool0Test(BufferSource& bufferSource)
{
    ASSERT_TRUE(bufferSource.ReadBool());
    auto result = true;
    bufferSource.Read(result);
    ASSERT_FALSE(result);
}

void CoreTools::BufferSourceTesting::ReadBool1Test(BufferSource& bufferSource)
{
    int32_t size{};
    bufferSource.Read(size);

    ASSERT_EQUAL(size, boost::numeric_cast<int32_t>(boolContainer0.size()));

    const auto result = bufferSource.ReadBoolContainerUseNumber<BoolContainer>(size);
    for (auto i = 0; i < size; ++i)
    {
        ASSERT_EQUAL(boolContainer0.at(i), result.at(i));
    }
}

void CoreTools::BufferSourceTesting::ReadBool2Test(BufferSource& bufferSource)
{
    const auto result = bufferSource.ReadBoolContainerNotUseNumber<BoolContainer>();
    ASSERT_EQUAL(result.size(), boolContainer1.size());
    for (auto i = 0u; i < result.size(); ++i)
    {
        ASSERT_EQUAL(boolContainer1.at(i), result.at(i));
    }
}

void CoreTools::BufferSourceTesting::ReadBool3Test(BufferSource& bufferSource)
{
    const auto result = bufferSource.ReadBoolContainer<boolContainer2.size()>();
    ASSERT_EQUAL(boolContainer2, result);
}

void CoreTools::BufferSourceTesting::ReadBool4Test(BufferSource& bufferSource)
{
    BoolContainer result{};
    bufferSource.ReadBoolContainer(boost::numeric_cast<int>(boolContainer3.size()), result);
    ASSERT_EQUAL(result.size(), boolContainer3.size());
    for (auto i = 0u; i < result.size(); ++i)
    {
        ASSERT_EQUAL(boolContainer3.at(i), result.at(i));
    }
}

void CoreTools::BufferSourceTesting::ReadBool5Test(BufferSource& bufferSource)
{
    BoolContainer result{};
    bufferSource.ReadBoolContainer(result);
    ASSERT_EQUAL(result.size(), boolContainer4.size());
    for (auto i = 0u; i < result.size(); ++i)
    {
        ASSERT_EQUAL(boolContainer4.at(i), result.at(i));
    }
}

void CoreTools::BufferSourceTesting::ReadBool6Test(BufferSource& bufferSource)
{
    BoolContainer5 result{};
    bufferSource.ReadContainer(result);
    ASSERT_EQUAL(boolContainer5, result);
}

void CoreTools::BufferSourceTesting::ReadBool7Test(BufferSource& bufferSource)
{
    BoolContainer6 result{};
    bufferSource.ReadBoolContainer(boost::numeric_cast<int>(boolContainer6.size()), result);
    ASSERT_EQUAL(result, boolContainer6);
}

void CoreTools::BufferSourceTesting::ReadStringTest()
{
    const auto fileBuffer = GetStringFileBuffer();

    BufferSource bufferSource{ fileBuffer };
    ASSERT_EQUAL(bufferSource.GetBytesRead(), 0);
    ASSERT_EQUAL(bufferSource.GetBytesTotal(), fileBuffer->GetSize());

    ASSERT_NOT_THROW_EXCEPTION_1(ReadString0Test, bufferSource);
    ASSERT_NOT_THROW_EXCEPTION_1(ReadString1Test, bufferSource);
    ASSERT_NOT_THROW_EXCEPTION_1(ReadString2Test, bufferSource);
    ASSERT_NOT_THROW_EXCEPTION_1(ReadString3Test, bufferSource);
    ASSERT_NOT_THROW_EXCEPTION_1(ReadString4Test, bufferSource);
    ASSERT_NOT_THROW_EXCEPTION_1(ReadString5Test, bufferSource);
    ASSERT_NOT_THROW_EXCEPTION_1(ReadString6Test, bufferSource);
    ASSERT_NOT_THROW_EXCEPTION_1(ReadString7Test, bufferSource);

    ASSERT_LESS_EQUAL(bufferSource.GetBytesRead(), fileBuffer->GetSize());
    ASSERT_EQUAL(bufferSource.GetBytesTotal(), fileBuffer->GetSize());
}

CoreTools::ConstFileBufferSharedPtr CoreTools::BufferSourceTesting::GetStringFileBuffer()
{
    const auto objectRegister = ObjectRegister::Create();

    BufferTarget bufferTarget{ bufferSize, objectRegister };

    bufferTarget.Write(stringTest0);
    bufferTarget.Write(stringTest1);

    bufferTarget.WriteStringContainerWithNumber(stringContainer0);
    bufferTarget.WriteStringContainerWithNumber(stringContainer1);
    bufferTarget.WriteContainer(stringContainer2);
    bufferTarget.WriteContainer(stringContainer3);
    bufferTarget.WriteStringContainerWithoutNumber(stringContainer4);
    bufferTarget.WriteStringContainerWithNumber(stringContainer5);
    bufferTarget.WriteStringContainerWithoutNumber(stringContainer6);

    return bufferTarget.GetFileBuffer();
}

void CoreTools::BufferSourceTesting::ReadString0Test(BufferSource& bufferSource)
{
    ASSERT_EQUAL(bufferSource.ReadString(), stringTest0);
    std::string result{};
    bufferSource.Read(result);
    ASSERT_EQUAL(result, stringTest1);
}

void CoreTools::BufferSourceTesting::ReadString1Test(BufferSource& bufferSource)
{
    int32_t size{};
    bufferSource.Read(size);

    ASSERT_EQUAL(size, boost::numeric_cast<int32_t>(stringContainer0.size()));

    const auto result = bufferSource.ReadStringContainerUseNumber<StringContainer>(size);
    ASSERT_EQUAL(result.size(), stringContainer0.size());
    for (auto i = 0u; i < result.size(); ++i)
    {
        ASSERT_EQUAL(result.at(i), stringContainer0.at(i));
    }
}

void CoreTools::BufferSourceTesting::ReadString2Test(BufferSource& bufferSource)
{
    const auto result = bufferSource.ReadStringContainerNotUseNumber<std::vector<std::string>>();
    ASSERT_EQUAL(result.size(), stringContainer1.size());
    for (auto i = 0u; i < result.size(); ++i)
    {
        ASSERT_EQUAL(result.at(i), stringContainer1.at(i));
    }
}

void CoreTools::BufferSourceTesting::ReadString3Test(BufferSource& bufferSource)
{
    const auto result = bufferSource.ReadStringContainer<stringContainer2.size()>();
    ASSERT_EQUAL(stringContainer2, result);
}

void CoreTools::BufferSourceTesting::ReadString4Test(BufferSource& bufferSource)
{
    StringContainer result{};
    bufferSource.ReadStringContainer(boost::numeric_cast<int>(stringContainer3.size()), result);
    ASSERT_EQUAL(result.size(), stringContainer3.size());

    for (auto i = 0u; i < stringContainer3.size(); ++i)
    {
        ASSERT_EQUAL(stringContainer3.at(i), result.at(i));
    }
}

void CoreTools::BufferSourceTesting::ReadString5Test(BufferSource& bufferSource)
{
    StringContainer4 result{};
    bufferSource.ReadStringContainer(boost::numeric_cast<int>(stringContainer4.size()), result);
    ASSERT_EQUAL(result, stringContainer4);
}

void CoreTools::BufferSourceTesting::ReadString6Test(BufferSource& bufferSource)
{
    StringContainer result{};
    bufferSource.ReadStringContainer(result);
    ASSERT_EQUAL(result.size(), stringContainer5.size());

    for (auto i = 0u; i < stringContainer5.size(); ++i)
    {
        ASSERT_EQUAL(stringContainer5.at(i), result.at(i));
    }
}

void CoreTools::BufferSourceTesting::ReadString7Test(BufferSource& bufferSource)
{
    StringContainer6 result6{};
    bufferSource.ReadContainer(result6);
    ASSERT_EQUAL(result6, stringContainer6);
}

void CoreTools::BufferSourceTesting::ReadIntTest()
{
    const auto fileBuffer = GetIntFileBuffer();

    BufferSource bufferSource{ fileBuffer };
    ASSERT_EQUAL(bufferSource.GetBytesRead(), 0);
    ASSERT_EQUAL(bufferSource.GetBytesTotal(), fileBuffer->GetSize());

    ASSERT_NOT_THROW_EXCEPTION_1(ReadInt0Test, bufferSource);
    ASSERT_NOT_THROW_EXCEPTION_1(ReadInt1Test, bufferSource);
    ASSERT_NOT_THROW_EXCEPTION_1(ReadInt2Test, bufferSource);
    ASSERT_NOT_THROW_EXCEPTION_1(ReadInt3Test, bufferSource);
    ASSERT_NOT_THROW_EXCEPTION_1(ReadInt4Test, bufferSource);
    ASSERT_NOT_THROW_EXCEPTION_1(ReadInt5Test, bufferSource);
    ASSERT_NOT_THROW_EXCEPTION_1(ReadInt6Test, bufferSource);
    ASSERT_NOT_THROW_EXCEPTION_1(ReadInt7Test, bufferSource);
    ASSERT_NOT_THROW_EXCEPTION_1(ReadInt8Test, bufferSource);
    ASSERT_NOT_THROW_EXCEPTION_1(ReadInt9Test, bufferSource);

    ASSERT_LESS_EQUAL(bufferSource.GetBytesRead(), fileBuffer->GetSize());
    ASSERT_EQUAL(bufferSource.GetBytesTotal(), fileBuffer->GetSize());
}

CoreTools::ConstFileBufferSharedPtr CoreTools::BufferSourceTesting::GetIntFileBuffer()
{
    const auto objectRegister = ObjectRegister::Create();

    BufferTarget bufferTarget{ bufferSize, objectRegister };

    bufferTarget.Write(intValue0);
    bufferTarget.Write(intValue1);

    bufferTarget.WriteContainerWithNumber(intContainer0);
    bufferTarget.WriteContainerWithoutNumber(intContainer1);
    bufferTarget.WriteContainerWithNumber(intContainer2);
    bufferTarget.WriteContainerWithNumber(intContainer3);
    bufferTarget.WriteContainerWithoutNumber(intContainer4);
    bufferTarget.WriteContainerWithoutNumber(intContainer5);
    bufferTarget.WriteContainerWithoutNumber(intContainer6);
    bufferTarget.WriteContainerWithNumber(intContainer7);
    bufferTarget.WriteContainerWithoutNumber(intContainer8);

    return bufferTarget.GetFileBuffer();
}

void CoreTools::BufferSourceTesting::ReadInt0Test(BufferSource& bufferSource)
{
    int32_t result{};
    bufferSource.Read(result);
    ASSERT_EQUAL(result, intValue0);

    result = bufferSource.Read<int32_t>();
    ASSERT_EQUAL(result, intValue1);
}

void CoreTools::BufferSourceTesting::ReadInt1Test(BufferSource& bufferSource)
{
    int32_t size{};
    bufferSource.Read(size);

    ASSERT_EQUAL(size, boost::numeric_cast<int>(intContainer0.size()));

    const auto result = bufferSource.ReadContainerUseNumber<IntContainer>(size);
    for (auto i = 0u; i < result.size(); ++i)
    {
        ASSERT_EQUAL(result.at(i), intContainer0.at(i));
    }
}

void CoreTools::BufferSourceTesting::ReadInt2Test(BufferSource& bufferSource)
{
    const auto result = bufferSource.ReadVectorUseNumber<int32_t>(boost::numeric_cast<int>(intContainer1.size()));
    for (auto i = 0u; i < result.size(); ++i)
    {
        ASSERT_EQUAL(result.at(i), intContainer1.at(i));
    }
}

void CoreTools::BufferSourceTesting::ReadInt3Test(BufferSource& bufferSource)
{
    const auto result = bufferSource.ReadContainerNotUseNumber<IntContainer>();
    for (auto i = 0u; i < result.size(); ++i)
    {
        ASSERT_EQUAL(result.at(i), intContainer2.at(i));
    }
}

void CoreTools::BufferSourceTesting::ReadInt4Test(BufferSource& bufferSource)
{
    const auto result = bufferSource.ReadVectorNotUseNumber<int32_t>();
    for (auto i = 0u; i < result.size(); ++i)
    {
        ASSERT_EQUAL(result.at(i), intContainer3.at(i));
    }
}

void CoreTools::BufferSourceTesting::ReadInt5Test(BufferSource& bufferSource)
{
    IntContainer4 result{};
    bufferSource.ReadContainer(boost::numeric_cast<int>(intContainer4.size()), result);
    ASSERT_EQUAL(result.size(), intContainer4.size());

    auto index = 0;
    for (auto element : result)
    {
        ASSERT_EQUAL(intContainer4.at(index), element);
        ++index;
    }
}

void CoreTools::BufferSourceTesting::ReadInt6Test(BufferSource& bufferSource)
{
    IntContainer5 result{};
    bufferSource.ReadContainer(boost::numeric_cast<int>(intContainer5.size()), result);
    ASSERT_EQUAL(result, intContainer5);
}

void CoreTools::BufferSourceTesting::ReadInt7Test(BufferSource& bufferSource)
{
    IntContainer result{};
    bufferSource.ReadContainer(boost::numeric_cast<int>(intContainer6.size()), result);
    ASSERT_EQUAL(result.size(), intContainer6.size());
    for (auto i = 0u; i < result.size(); ++i)
    {
        ASSERT_EQUAL(result.at(i), intContainer6.at(i));
    }
}

void CoreTools::BufferSourceTesting::ReadInt8Test(BufferSource& bufferSource)
{
    IntContainer result{};
    bufferSource.ReadContainer(result);
    ASSERT_EQUAL(result.size(), intContainer7.size());
    for (auto i = 0u; i < result.size(); ++i)
    {
        ASSERT_EQUAL(result.at(i), intContainer7.at(i));
    }
}

void CoreTools::BufferSourceTesting::ReadInt9Test(BufferSource& bufferSource)
{
    IntContainer8 result{};
    bufferSource.ReadContainer(result);
    ASSERT_EQUAL(result, intContainer8);
}

void CoreTools::BufferSourceTesting::ReadEnumTest()
{
    const auto fileBuffer = GetEnumFileBuffer();

    BufferSource bufferSource{ fileBuffer };
    ASSERT_EQUAL(bufferSource.GetBytesRead(), 0);
    ASSERT_EQUAL(bufferSource.GetBytesTotal(), fileBuffer->GetSize());

    ASSERT_NOT_THROW_EXCEPTION_1(ReadEnum0Test, bufferSource);
    ASSERT_NOT_THROW_EXCEPTION_1(ReadEnum1Test, bufferSource);
    ASSERT_NOT_THROW_EXCEPTION_1(ReadEnum2Test, bufferSource);
    ASSERT_NOT_THROW_EXCEPTION_1(ReadEnum3Test, bufferSource);
    ASSERT_NOT_THROW_EXCEPTION_1(ReadEnum4Test, bufferSource);
    ASSERT_NOT_THROW_EXCEPTION_1(ReadEnum5Test, bufferSource);
    ASSERT_NOT_THROW_EXCEPTION_1(ReadEnum6Test, bufferSource);
    ASSERT_NOT_THROW_EXCEPTION_1(ReadEnum7Test, bufferSource);
    ASSERT_NOT_THROW_EXCEPTION_1(ReadEnum8Test, bufferSource);
    ASSERT_NOT_THROW_EXCEPTION_1(ReadEnum9Test, bufferSource);

    ASSERT_LESS_EQUAL(bufferSource.GetBytesRead(), fileBuffer->GetSize());
    ASSERT_EQUAL(bufferSource.GetBytesTotal(), fileBuffer->GetSize());
}

CoreTools::ConstFileBufferSharedPtr CoreTools::BufferSourceTesting::GetEnumFileBuffer()
{
    const auto objectRegister = ObjectRegister::Create();

    BufferTarget bufferTarget{ bufferSize, objectRegister };

    bufferTarget.WriteEnum(enumValue0);
    bufferTarget.WriteEnum(enumValue1);

    bufferTarget.WriteEnumContainerWithNumber(enumContainer0);
    bufferTarget.WriteEnumContainerWithoutNumber(enumContainer1);
    bufferTarget.WriteEnumContainerWithNumber(enumContainer2);
    bufferTarget.WriteEnumContainerWithNumber(enumContainer3);
    bufferTarget.WriteEnumContainerWithoutNumber(enumContainer4);
    bufferTarget.WriteEnumContainerWithoutNumber(enumContainer5);
    bufferTarget.WriteEnumContainerWithoutNumber(enumContainer6);
    bufferTarget.WriteEnumContainerWithNumber(enumContainer7);
    bufferTarget.WriteEnumContainerWithoutNumber(enumContainer8);

    return bufferTarget.GetFileBuffer();
}

void CoreTools::BufferSourceTesting::ReadEnum0Test(BufferSource& bufferSource)
{
    BufferSourceTestingEnum result{};
    bufferSource.ReadEnum(result);
    ASSERT_EQUAL(result, enumValue0);

    result = bufferSource.ReadEnum<BufferSourceTestingEnum>();
    ASSERT_EQUAL(result, enumValue1);
}

void CoreTools::BufferSourceTesting::ReadEnum1Test(BufferSource& bufferSource)
{
    int32_t size{};
    bufferSource.Read(size);

    ASSERT_EQUAL(size, boost::numeric_cast<int>(enumContainer0.size()));

    const auto result = bufferSource.ReadEnumContainerUseNumber<EnumContainer>(size);
    for (auto i = 0u; i < result.size(); ++i)
    {
        ASSERT_EQUAL(result.at(i), enumContainer0.at(i));
    }
}

void CoreTools::BufferSourceTesting::ReadEnum2Test(BufferSource& bufferSource)
{
    const auto result = bufferSource.ReadEnumVectorUseNumber<BufferSourceTestingEnum>(boost::numeric_cast<int>(enumContainer1.size()));
    for (auto i = 0u; i < result.size(); ++i)
    {
        ASSERT_EQUAL(result.at(i), enumContainer1.at(i));
    }
}

void CoreTools::BufferSourceTesting::ReadEnum3Test(BufferSource& bufferSource)
{
    const auto result = bufferSource.ReadEnumContainerNotUseNumber<EnumContainer>();
    for (auto i = 0u; i < result.size(); ++i)
    {
        ASSERT_EQUAL(result.at(i), enumContainer2.at(i));
    }
}

void CoreTools::BufferSourceTesting::ReadEnum4Test(BufferSource& bufferSource)
{
    const auto result = bufferSource.ReadEnumVectorNotUseNumber<BufferSourceTestingEnum>();
    for (auto i = 0u; i < result.size(); ++i)
    {
        ASSERT_EQUAL(result.at(i), enumContainer3.at(i));
    }
}

void CoreTools::BufferSourceTesting::ReadEnum5Test(BufferSource& bufferSource)
{
    EnumContainer4 result{};
    bufferSource.ReadEnumContainer(boost::numeric_cast<int>(enumContainer4.size()), result);
    ASSERT_EQUAL(result.size(), enumContainer4.size());

    auto index = 0;
    for (auto value : result)
    {
        ASSERT_EQUAL(enumContainer4.at(index), value);
        ++index;
    }
}

void CoreTools::BufferSourceTesting::ReadEnum6Test(BufferSource& bufferSource)
{
    EnumContainer5 result{};
    bufferSource.ReadEnumContainer(boost::numeric_cast<int>(enumContainer5.size()), result);
    ASSERT_EQUAL(result, enumContainer5);
}

void CoreTools::BufferSourceTesting::ReadEnum7Test(BufferSource& bufferSource)
{
    EnumContainer result{};
    bufferSource.ReadEnumContainer(boost::numeric_cast<int>(enumContainer6.size()), result);
    ASSERT_EQUAL(result.size(), enumContainer6.size());
    for (auto i = 0u; i < result.size(); ++i)
    {
        ASSERT_EQUAL(result.at(i), enumContainer6.at(i));
    }
}

void CoreTools::BufferSourceTesting::ReadEnum8Test(BufferSource& bufferSource)
{
    EnumContainer result{};
    bufferSource.ReadEnumContainer(result);
    ASSERT_EQUAL(result.size(), enumContainer7.size());
    for (auto i = 0u; i < result.size(); ++i)
    {
        ASSERT_EQUAL(result.at(i), enumContainer7.at(i));
    }
}

void CoreTools::BufferSourceTesting::ReadEnum9Test(BufferSource& bufferSource)
{
    EnumContainer8 result8{};
    bufferSource.ReadEnumContainer(result8);
    ASSERT_EQUAL(result8, enumContainer8);
}

void CoreTools::BufferSourceTesting::ReadAggregateTest()
{
    const auto fileBuffer = GetAggregateFileBuffer();

    BufferSource bufferSource{ fileBuffer };
    ASSERT_EQUAL(bufferSource.GetBytesRead(), 0);
    ASSERT_EQUAL(bufferSource.GetBytesTotal(), fileBuffer->GetSize());

    ASSERT_NOT_THROW_EXCEPTION_1(ReadAggregate0Test, bufferSource);
    ASSERT_NOT_THROW_EXCEPTION_1(ReadAggregate1Test, bufferSource);
    ASSERT_NOT_THROW_EXCEPTION_1(ReadAggregate2Test, bufferSource);
    ASSERT_NOT_THROW_EXCEPTION_1(ReadAggregate3Test, bufferSource);
    ASSERT_NOT_THROW_EXCEPTION_1(ReadAggregate4Test, bufferSource);
    ASSERT_NOT_THROW_EXCEPTION_1(ReadAggregate5Test, bufferSource);
    ASSERT_NOT_THROW_EXCEPTION_1(ReadAggregate6Test, bufferSource);
    ASSERT_NOT_THROW_EXCEPTION_1(ReadAggregate7Test, bufferSource);

    ASSERT_LESS_EQUAL(bufferSource.GetBytesRead(), fileBuffer->GetSize());
    ASSERT_EQUAL(bufferSource.GetBytesTotal(), fileBuffer->GetSize());
}

CoreTools::ConstFileBufferSharedPtr CoreTools::BufferSourceTesting::GetAggregateFileBuffer()
{
    const auto objectRegister = ObjectRegister::Create();

    BufferTarget bufferTarget{ bufferSize * 2, objectRegister };

    bufferTarget.WriteAggregate(color0);
    bufferTarget.WriteAggregate(color1);

    bufferTarget.WriteAggregateContainerWithNumber(vectorContainer0);
    bufferTarget.WriteAggregateContainerWithNumber(vectorContainer1);
    bufferTarget.WriteAggregateContainer(vectorContainer2);
    bufferTarget.WriteAggregateContainerWithoutNumber(vectorContainer3);
    bufferTarget.WriteAggregateContainerWithoutNumber(vectorContainer4);
    bufferTarget.WriteAggregateContainerWithNumber(vectorContainer5);
    bufferTarget.WriteAggregateContainer(vectorContainer6);

    return bufferTarget.GetFileBuffer();
}

void CoreTools::BufferSourceTesting::ReadAggregate0Test(BufferSource& bufferSource)
{
    Vector4D result{};
    bufferSource.ReadAggregate(result);

    ASSERT_APPROXIMATE_USE_FUNCTION(Vector4ToolsD::Approximate, result, color0, zeroTolerance);

    result = bufferSource.ReadAggregate<Vector4D>();
    ASSERT_APPROXIMATE_USE_FUNCTION(Vector4ToolsD::Approximate, result, color1, zeroTolerance);
}

void CoreTools::BufferSourceTesting::ReadAggregate1Test(BufferSource& bufferSource)
{
    int32_t size{};
    bufferSource.Read(size);

    ASSERT_EQUAL(size, boost::numeric_cast<int>(vectorContainer0.size()));

    VectorContainer0 result{};
    bufferSource.ReadAggregateContainer(result);
    for (auto i = 0u; i < vectorContainer0.size(); ++i)
    {
        ASSERT_APPROXIMATE_USE_FUNCTION(Vector4ToolsD::Approximate, vectorContainer0.at(i), result.at(i), zeroTolerance);
    }
}

void CoreTools::BufferSourceTesting::ReadAggregate2Test(BufferSource& bufferSource)
{
    AggregateContainer result{};
    bufferSource.ReadAggregateContainer(result);
    ASSERT_EQUAL(result.size(), vectorContainer1.size());
    for (auto i = 0u; i < vectorContainer1.size(); ++i)
    {
        ASSERT_APPROXIMATE_USE_FUNCTION(Vector4ToolsD::Approximate, vectorContainer1.at(i), result.at(i), zeroTolerance);
    }
}

void CoreTools::BufferSourceTesting::ReadAggregate3Test(BufferSource& bufferSource)
{
    AggregateContainer result{};
    bufferSource.ReadAggregateContainer(boost::numeric_cast<int>(vectorContainer2.size()), result);
    ASSERT_EQUAL(result.size(), vectorContainer2.size());
    for (auto i = 0u; i < vectorContainer2.size(); ++i)
    {
        ASSERT_APPROXIMATE_USE_FUNCTION(Vector4ToolsD::Approximate, vectorContainer2.at(i), result.at(i), zeroTolerance);
    }
}

void CoreTools::BufferSourceTesting::ReadAggregate4Test(BufferSource& bufferSource)
{
    VectorContainer3 result{};
    bufferSource.ReadAggregateContainer(boost::numeric_cast<int>(vectorContainer3.size()), result);
    ASSERT_EQUAL(result.size(), vectorContainer3.size());
    auto iter = vectorContainer3.cbegin();
    for (const auto& element : result)
    {
        if (iter == vectorContainer3.cend())
        {
            break;
        }

        ASSERT_APPROXIMATE_USE_FUNCTION(Vector4ToolsD::Approximate, *iter, element, zeroTolerance);
        ++iter;
    }
}

void CoreTools::BufferSourceTesting::ReadAggregate5Test(BufferSource& bufferSource)
{
    const auto result = bufferSource.ReadAggregateContainerUseNumber<AggregateContainer>(boost::numeric_cast<int>(vectorContainer4.size()));
    ASSERT_EQUAL(result.size(), vectorContainer4.size());
    for (auto i = 0u; i < vectorContainer4.size(); ++i)
    {
        ASSERT_APPROXIMATE_USE_FUNCTION(Vector4ToolsD::Approximate, vectorContainer4.at(i), result.at(i), zeroTolerance);
    }
}

void CoreTools::BufferSourceTesting::ReadAggregate6Test(BufferSource& bufferSource)
{
    const auto result = bufferSource.ReadAggregateContainerNotUseNumber<AggregateContainer>();
    ASSERT_EQUAL(result.size(), vectorContainer5.size());
    for (auto i = 0u; i < vectorContainer5.size(); ++i)
    {
        ASSERT_APPROXIMATE_USE_FUNCTION(Vector4ToolsD::Approximate, vectorContainer5.at(i), result.at(i), zeroTolerance);
    }
}

void CoreTools::BufferSourceTesting::ReadAggregate7Test(BufferSource& bufferSource)
{
    const auto result = bufferSource.ReadAggregateContainer<Mathematics::Vector4D, vectorContainer6.size()>();
    ASSERT_EQUAL(result.size(), vectorContainer6.size());
    for (auto i = 0u; i < vectorContainer6.size(); ++i)
    {
        ASSERT_APPROXIMATE_USE_FUNCTION(Vector4ToolsD::Approximate, vectorContainer6.at(i), result.at(i), zeroTolerance);
    }
}

void CoreTools::BufferSourceTesting::ReadObjectAssociatedTest()
{
    const auto fileBuffer = CreateObjectAssociatedFileBuffer();

    BufferSource bufferSource{ fileBuffer };
    ASSERT_EQUAL(bufferSource.GetBytesRead(), 0);
    ASSERT_EQUAL(bufferSource.GetBytesTotal(), fileBuffer->GetSize());

    ASSERT_NOT_THROW_EXCEPTION_1(ReadObjectAssociated0Test, bufferSource);
    ASSERT_NOT_THROW_EXCEPTION_1(ReadObjectAssociated1Test, bufferSource);
    ASSERT_NOT_THROW_EXCEPTION_1(ReadObjectAssociated2Test, bufferSource);
    ASSERT_NOT_THROW_EXCEPTION_1(ReadObjectAssociated3Test, bufferSource);
    ASSERT_NOT_THROW_EXCEPTION_1(ReadObjectAssociated4Test, bufferSource);
    ASSERT_NOT_THROW_EXCEPTION_1(ReadObjectAssociated5Test, bufferSource);
    ASSERT_NOT_THROW_EXCEPTION_1(ReadObjectAssociated6Test, bufferSource);
    ASSERT_NOT_THROW_EXCEPTION_1(ReadObjectAssociated7Test, bufferSource);
    ASSERT_NOT_THROW_EXCEPTION_1(IncrementBytesProcessedTest, bufferSource);

    ASSERT_LESS_EQUAL(bufferSource.GetBytesRead(), fileBuffer->GetSize());
    ASSERT_EQUAL(bufferSource.GetBytesTotal(), fileBuffer->GetSize());
}

CoreTools::ConstObjectInterfaceAssociated CoreTools::BufferSourceTesting::CreateBoolObjectAssociated()
{
    const auto boolObject = std::make_shared<BoolObject>(DisableNotThrow::Disable);
    boolObject->SetUniqueId(uniqueId0);

    return ConstObjectInterfaceAssociated{ boolObject };
}

CoreTools::ConstObjectInterfaceAssociated CoreTools::BufferSourceTesting::CreateIntObjectAssociated()
{
    const auto intObject = std::make_shared<IntObject>(DisableNotThrow::Disable);
    intObject->SetUniqueId(uniqueId1);

    return ConstObjectInterfaceAssociated{ intObject };
}

CoreTools::ConstFileBufferSharedPtr CoreTools::BufferSourceTesting::CreateObjectAssociatedFileBuffer() const
{
    const auto objectRegister = ObjectRegister::Create();

    BufferTarget bufferTarget{ bufferSize, objectRegister };

    const ConstWeakObjectAssociated<ObjectInterface> intWeakObjectAssociated{ intObjectAssociated.object };

    objectRegister->Register(boolObjectAssociated);
    objectRegister->Register(intObjectAssociated);

    bufferTarget.WriteObjectAssociated(boolObjectAssociated);
    bufferTarget.WriteWeakObjectAssociated(intWeakObjectAssociated);

    bufferTarget.WriteObjectAssociatedContainerWithNumber(objectAssociatedContainer0);
    bufferTarget.WriteObjectAssociatedContainerWithoutNumber(objectAssociatedContainer1);
    bufferTarget.WriteObjectAssociatedContainerWithNumber(objectAssociatedContainer2);
    bufferTarget.WriteObjectAssociatedContainer(objectAssociatedContainer3);
    bufferTarget.WriteObjectAssociatedContainer(objectAssociatedContainer4);
    bufferTarget.WriteObjectAssociatedContainerWithNumber(objectAssociatedContainer5);
    bufferTarget.Write(uniqueId2);

    return bufferTarget.GetFileBuffer();
}

void CoreTools::BufferSourceTesting::ReadObjectAssociated0Test(BufferSource& bufferSource)
{
    auto result = bufferSource.ReadObjectAssociated<ConstObjectInterfaceAssociated>();
    ASSERT_EQUAL(result.associated, uniqueId0);

    bufferSource.ReadObjectAssociated(result);
    ASSERT_EQUAL(result.associated, uniqueId1);
}

void CoreTools::BufferSourceTesting::ReadObjectAssociated1Test(BufferSource& bufferSource)
{
    int32_t size{};
    bufferSource.Read(size);

    ASSERT_EQUAL(size, boost::numeric_cast<int>(objectAssociatedContainer0.size()));

    ObjectAssociatedContainer0 result{};
    bufferSource.ReadObjectAssociatedContainer(result);
    for (auto i = 0u; i < objectAssociatedContainer0.size(); ++i)
    {
        ASSERT_EQUAL(objectAssociatedContainer0.at(i).object->GetUniqueId(), result.at(i).associated);
    }
}

void CoreTools::BufferSourceTesting::ReadObjectAssociated2Test(BufferSource& bufferSource)
{
    const auto result = bufferSource.ReadObjectAssociatedContainerUseNumber<ObjectAssociatedContainer>(boost::numeric_cast<int>(objectAssociatedContainer1.size()));
    ASSERT_EQUAL(result.size(), objectAssociatedContainer1.size());
    for (auto i = 0u; i < objectAssociatedContainer1.size(); ++i)
    {
        ASSERT_EQUAL(objectAssociatedContainer1.at(i).object->GetUniqueId(), result.at(i).associated);
    }
}

void CoreTools::BufferSourceTesting::ReadObjectAssociated3Test(BufferSource& bufferSource)
{
    const auto result = bufferSource.ReadObjectAssociatedContainerNotUseNumber<ObjectAssociatedContainer>();
    ASSERT_EQUAL(result.size(), objectAssociatedContainer2.size());
    for (auto i = 0u; i < objectAssociatedContainer2.size(); ++i)
    {
        ASSERT_EQUAL(objectAssociatedContainer2.at(i).object->GetUniqueId(), result.at(i).associated);
    }
}

void CoreTools::BufferSourceTesting::ReadObjectAssociated4Test(BufferSource& bufferSource)
{
    const auto result = bufferSource.ReadObjectAssociatedContainer<ConstObjectInterfaceAssociated, objectAssociatedSize3>();
    ASSERT_EQUAL(result.size(), objectAssociatedContainer3.size());
    for (auto i = 0u; i < objectAssociatedContainer3.size(); ++i)
    {
        ASSERT_EQUAL(objectAssociatedContainer3.at(i).object->GetUniqueId(), result.at(i).associated);
    }
}

void CoreTools::BufferSourceTesting::ReadObjectAssociated5Test(BufferSource& bufferSource)
{
    ObjectAssociatedContainer result{};
    bufferSource.ReadObjectAssociatedContainer(boost::numeric_cast<int>(objectAssociatedContainer4.size()), result);
    ASSERT_EQUAL(result.size(), objectAssociatedContainer4.size());
    for (auto i = 0u; i < objectAssociatedContainer4.size(); ++i)
    {
        ASSERT_EQUAL(objectAssociatedContainer4.at(i).object->GetUniqueId(), result.at(i).associated);
    }
}

void CoreTools::BufferSourceTesting::ReadObjectAssociated6Test(BufferSource& bufferSource)
{
    ObjectAssociatedContainer result{};
    bufferSource.ReadObjectAssociatedContainer(result);
    ASSERT_EQUAL(result.size(), objectAssociatedContainer5.size());
    for (auto i = 0u; i < objectAssociatedContainer5.size(); ++i)
    {
        ASSERT_EQUAL(objectAssociatedContainer5.at(i).object->GetUniqueId(), result.at(i).associated);
    }
}

void CoreTools::BufferSourceTesting::ReadObjectAssociated7Test(BufferSource& bufferSource)
{
    const auto objectInterface = BoolObject::Create();

    bufferSource.ReadUniqueId(*objectInterface);

    ASSERT_EQUAL(objectInterface->GetUniqueId(), uniqueId2);
}

void CoreTools::BufferSourceTesting::IncrementBytesProcessedTest(BufferSource& bufferSource)
{
    bufferSource.IncrementBytesProcessed(20);
}