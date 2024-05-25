/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.9 (2024/05/22 17:11)

#include "BufferTargetTesting.h"
#include "Detail/BoolObject.h"
#include "Detail/BufferTargetTestingEnum.h"
#include "Detail/IntObject.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/StreamMacro.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ConstObjectAssociated.h"
#include "CoreTools/ObjectSystems/ConstWeakObjectAssociated.h"
#include "CoreTools/ObjectSystems/ObjectRegisterDetail.h"
#include "CoreTools/ObjectSystems/StreamDetail.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Algebra/Vector4ToolsDetail.h"

CoreTools::BufferTargetTesting::BufferTargetTesting(const OStreamShared& stream)
    : ParentType{ stream },
      boolObjectAssociated{ CreateBoolObjectAssociated() },
      intObjectAssociated{ CreateIntObjectAssociated() },
      objectAssociatedContainer0{ intObjectAssociated, boolObjectAssociated, boolObjectAssociated, intObjectAssociated, boolObjectAssociated },
      objectAssociatedContainer1{ intObjectAssociated, boolObjectAssociated, boolObjectAssociated, intObjectAssociated, boolObjectAssociated, intObjectAssociated },
      objectAssociatedContainer2{ intObjectAssociated, boolObjectAssociated, boolObjectAssociated, intObjectAssociated, boolObjectAssociated, intObjectAssociated, boolObjectAssociated }
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
    const auto fileBuffer = GetBoolFileBuffer();

    BufferSource bufferSource{ fileBuffer };

    ASSERT_NOT_THROW_EXCEPTION_1(ReadBool0Test, bufferSource);
    ASSERT_NOT_THROW_EXCEPTION_1(ReadBool1Test, bufferSource);
    ASSERT_NOT_THROW_EXCEPTION_1(ReadBool2Test, bufferSource);
    ASSERT_NOT_THROW_EXCEPTION_1(ReadBool3Test, bufferSource);
}

CoreTools::ConstFileBufferSharedPtr CoreTools::BufferTargetTesting::GetBoolFileBuffer()
{
    const auto objectRegister = ObjectRegister::Create();

    BufferTarget bufferTarget{ bufferSize, objectRegister };

    bufferTarget.Write(true);

    ASSERT_EQUAL(bufferTarget.GetBytesWritten(), GetStreamSize(true));

    bufferTarget.WriteBoolContainerWithNumber(boolContainer0);
    bufferTarget.WriteBoolContainerWithoutNumber(boolContainer1);
    bufferTarget.WriteContainer(boolContainer2);

    return bufferTarget.GetFileBuffer();
}

void CoreTools::BufferTargetTesting::ReadBool0Test(BufferSource& bufferSource)
{
    ASSERT_TRUE(bufferSource.ReadBool());
}

void CoreTools::BufferTargetTesting::ReadBool1Test(BufferSource& bufferSource)
{
    int32_t size{};
    bufferSource.Read(size);

    ASSERT_EQUAL(size, boost::numeric_cast<int>(boolSize0));

    BoolContainer0 result{};
    bufferSource.ReadContainer(result);
    ASSERT_EQUAL(boolContainer0, result);
}

void CoreTools::BufferTargetTesting::ReadBool2Test(BufferSource& bufferSource)
{
    BoolContainer1 result{};
    bufferSource.ReadContainer(result);
    ASSERT_EQUAL(boolContainer1, result);
}

void CoreTools::BufferTargetTesting::ReadBool3Test(BufferSource& bufferSource)
{
    BoolContainer2 result{};
    bufferSource.ReadContainer(result);
    ASSERT_EQUAL(boolContainer2, result);
}

void CoreTools::BufferTargetTesting::WriteStringTest()
{
    const auto fileBuffer = GetStringFileBuffer();

    BufferSource bufferSource{ fileBuffer };

    ASSERT_NOT_THROW_EXCEPTION_1(ReadString0Test, bufferSource);
    ASSERT_NOT_THROW_EXCEPTION_1(ReadString1Test, bufferSource);
    ASSERT_NOT_THROW_EXCEPTION_1(ReadString2Test, bufferSource);
    ASSERT_NOT_THROW_EXCEPTION_1(ReadString3Test, bufferSource);
    ASSERT_NOT_THROW_EXCEPTION_1(ReadString4Test, bufferSource);
}

CoreTools::ConstFileBufferSharedPtr CoreTools::BufferTargetTesting::GetStringFileBuffer()
{
    const auto objectRegister = ObjectRegister::Create();

    BufferTarget bufferTarget{ bufferSize, objectRegister };

    bufferTarget.Write(stringTest0.c_str());
    bufferTarget.Write(stringTest1);

    bufferTarget.WriteStringContainerWithNumber(stringContainer0);
    bufferTarget.WriteStringContainerWithoutNumber(stringContainer1);
    bufferTarget.WriteContainer(stringContainer2);
    bufferTarget.WriteContainer(stringContainer3);

    return bufferTarget.GetFileBuffer();
}

void CoreTools::BufferTargetTesting::ReadString0Test(BufferSource& bufferSource)
{
    ASSERT_EQUAL(bufferSource.ReadString(), stringTest0);
    ASSERT_EQUAL(bufferSource.ReadString(), stringTest1);
}

void CoreTools::BufferTargetTesting::ReadString1Test(BufferSource& bufferSource)
{
    int32_t size{};
    bufferSource.Read(size);

    ASSERT_EQUAL(size, boost::numeric_cast<int>(stringContainer0.size()));

    StringContainer0 result{};
    bufferSource.ReadContainer(result);
    ASSERT_EQUAL(stringContainer0, result);
}

void CoreTools::BufferTargetTesting::ReadString2Test(BufferSource& bufferSource)
{
    StringContainer1 result{};
    bufferSource.ReadContainer(result);
    ASSERT_EQUAL(stringContainer1, result);
}

void CoreTools::BufferTargetTesting::ReadString3Test(BufferSource& bufferSource)
{
    StringContainer2 result{};
    bufferSource.ReadContainer(result);
    ASSERT_EQUAL(stringContainer2, result);
}

void CoreTools::BufferTargetTesting::ReadString4Test(BufferSource& bufferSource)
{
    StringContainer3 result{};
    bufferSource.ReadContainer(result);

    for (auto i = 0u; i < stringContainer3.size(); ++i)
    {
        ASSERT_EQUAL(stringContainer3.at(i), result.at(i));
    }
}

void CoreTools::BufferTargetTesting::WriteIntTest()
{
    const auto fileBuffer = GetIntFileBuffer();

    BufferSource bufferSource{ fileBuffer };

    ASSERT_NOT_THROW_EXCEPTION_1(ReadInt0Test, bufferSource);
    ASSERT_NOT_THROW_EXCEPTION_1(ReadInt1Test, bufferSource);
    ASSERT_NOT_THROW_EXCEPTION_1(ReadInt2Test, bufferSource);
    ASSERT_NOT_THROW_EXCEPTION_1(ReadInt3Test, bufferSource);
}

CoreTools::ConstFileBufferSharedPtr CoreTools::BufferTargetTesting::GetIntFileBuffer()
{
    const auto objectRegister = ObjectRegister::Create();

    BufferTarget bufferTarget{ bufferSize, objectRegister };

    bufferTarget.Write(intValue);

    bufferTarget.WriteContainerWithNumber(intContainer0);
    bufferTarget.WriteContainerWithoutNumber(intContainer1);
    bufferTarget.WriteContainer(intContainer2);

    return bufferTarget.GetFileBuffer();
}

void CoreTools::BufferTargetTesting::ReadInt0Test(BufferSource& bufferSource)
{
    int32_t result{};
    bufferSource.Read(result);

    ASSERT_EQUAL(result, intValue);
}

void CoreTools::BufferTargetTesting::ReadInt1Test(BufferSource& bufferSource)
{
    int32_t size{};
    bufferSource.Read(size);

    ASSERT_EQUAL(size, boost::numeric_cast<int>(intContainer0.size()));

    IntContainer0 result{};
    bufferSource.ReadContainer(result);
    ASSERT_EQUAL(intContainer0, result);
}

void CoreTools::BufferTargetTesting::ReadInt2Test(BufferSource& bufferSource)
{
    IntContainer1 result{};
    bufferSource.ReadContainer(result);
    ASSERT_EQUAL(intContainer1, result);
}

void CoreTools::BufferTargetTesting::ReadInt3Test(BufferSource& bufferSource)
{
    IntContainer2 result{};
    bufferSource.ReadContainer(result);
    ASSERT_EQUAL(intContainer2, result);
}

void CoreTools::BufferTargetTesting::WriteEnumTest()
{
    const auto fileBuffer = GetEnumFileBuffer();

    BufferSource bufferSource{ fileBuffer };

    ASSERT_NOT_THROW_EXCEPTION_1(ReadEnum0Test, bufferSource);
    ASSERT_NOT_THROW_EXCEPTION_1(ReadEnum1Test, bufferSource);
    ASSERT_NOT_THROW_EXCEPTION_1(ReadEnum2Test, bufferSource);
    ASSERT_NOT_THROW_EXCEPTION_1(ReadEnum3Test, bufferSource);
}

CoreTools::ConstFileBufferSharedPtr CoreTools::BufferTargetTesting::GetEnumFileBuffer()
{
    const auto objectRegister = ObjectRegister::Create();

    BufferTarget bufferTarget{ bufferSize, objectRegister };

    bufferTarget.WriteEnum(enumValue);

    bufferTarget.WriteEnumContainerWithNumber(enumContainer0);
    bufferTarget.WriteEnumContainerWithoutNumber(enumContainer1);
    bufferTarget.WriteEnumContainer(enumContainer2);

    return bufferTarget.GetFileBuffer();
}

void CoreTools::BufferTargetTesting::ReadEnum0Test(BufferSource& bufferSource)
{
    BufferTargetTestingEnum result{};
    bufferSource.ReadEnum(result);

    ASSERT_EQUAL(result, enumValue);
}

void CoreTools::BufferTargetTesting::ReadEnum1Test(BufferSource& bufferSource)
{
    int32_t size{};
    bufferSource.Read(size);

    ASSERT_EQUAL(size, boost::numeric_cast<int>(enumContainer0.size()));

    EnumContainer0 result{};
    bufferSource.ReadEnumContainer(result);
    ASSERT_EQUAL(enumContainer0, result);
}

void CoreTools::BufferTargetTesting::ReadEnum2Test(BufferSource& bufferSource)
{
    EnumContainer1 result{};
    bufferSource.ReadEnumContainer(result);
    ASSERT_EQUAL(enumContainer1, result);
}

void CoreTools::BufferTargetTesting::ReadEnum3Test(BufferSource& bufferSource)
{
    EnumContainer2 result{};
    bufferSource.ReadEnumContainer(result);
    ASSERT_EQUAL(enumContainer2, result);
}

void CoreTools::BufferTargetTesting::WriteAggregateTest()
{
    const auto fileBuffer = GetAggregateFileBuffer();

    BufferSource bufferSource{ fileBuffer };

    ASSERT_NOT_THROW_EXCEPTION_1(ReadAggregate0Test, bufferSource);
    ASSERT_NOT_THROW_EXCEPTION_1(ReadAggregate1Test, bufferSource);
    ASSERT_NOT_THROW_EXCEPTION_1(ReadAggregate2Test, bufferSource);
    ASSERT_NOT_THROW_EXCEPTION_1(ReadAggregate3Test, bufferSource);
}

CoreTools::ConstFileBufferSharedPtr CoreTools::BufferTargetTesting::GetAggregateFileBuffer()
{
    const auto objectRegister = ObjectRegister::Create();

    BufferTarget bufferTarget{ bufferSize, objectRegister };

    bufferTarget.WriteAggregate(color);
    bufferTarget.WriteAggregateContainerWithNumber(aggregateContainer0);
    bufferTarget.WriteAggregateContainerWithoutNumber(aggregateContainer1);
    bufferTarget.WriteAggregateContainer(aggregateContainer2);

    return bufferTarget.GetFileBuffer();
}

void CoreTools::BufferTargetTesting::ReadAggregate0Test(BufferSource& bufferSource)
{
    Vector4D result{};
    bufferSource.ReadAggregate(result);

    ASSERT_APPROXIMATE_USE_FUNCTION(Vector4ToolsD::Approximate, result, color, zeroTolerance);
}

void CoreTools::BufferTargetTesting::ReadAggregate1Test(BufferSource& bufferSource)
{
    int32_t size{};
    bufferSource.Read(size);

    ASSERT_EQUAL(size, boost::numeric_cast<int>(aggregateContainer0.size()));

    AggregateContainer0 result{};
    bufferSource.ReadAggregateContainer(result);
    for (auto i = 0u; i < aggregateContainer0.size(); ++i)
    {
        ASSERT_APPROXIMATE_USE_FUNCTION(Vector4ToolsD::Approximate, aggregateContainer0.at(i), result.at(i), zeroTolerance);
    }
}

void CoreTools::BufferTargetTesting::ReadAggregate2Test(BufferSource& bufferSource)
{
    AggregateContainer1 result{};
    bufferSource.ReadAggregateContainer(result);
    for (auto i = 0u; i < aggregateContainer1.size(); ++i)
    {
        ASSERT_APPROXIMATE_USE_FUNCTION(Vector4ToolsD::Approximate, aggregateContainer1.at(i), result.at(i), zeroTolerance);
    }
}

void CoreTools::BufferTargetTesting::ReadAggregate3Test(BufferSource& bufferSource)
{
    AggregateContainer2 result{};
    bufferSource.ReadAggregateContainer(result);
    for (auto i = 0u; i < aggregateContainer2.size(); ++i)
    {
        ASSERT_APPROXIMATE_USE_FUNCTION(Vector4ToolsD::Approximate, aggregateContainer2.at(i), result.at(i), zeroTolerance);
    }
}

void CoreTools::BufferTargetTesting::WriteObjectAssociatedTest()
{
    const auto fileBuffer = GetObjectAssociatedFileBuffer();

    BufferSource bufferSource{ fileBuffer };

    ASSERT_NOT_THROW_EXCEPTION_1(ReadObjectAssociated0Test, bufferSource);
    ASSERT_NOT_THROW_EXCEPTION_1(ReadObjectAssociated1Test, bufferSource);
    ASSERT_NOT_THROW_EXCEPTION_1(ReadObjectAssociated2Test, bufferSource);
    ASSERT_NOT_THROW_EXCEPTION_1(ReadObjectAssociated3Test, bufferSource);
}

CoreTools::ConstObjectInterfaceAssociated CoreTools::BufferTargetTesting::CreateBoolObjectAssociated()
{
    const auto boolObject = std::make_shared<BoolObject>(DisableNotThrow::Disable);
    boolObject->SetUniqueId(uniqueId0);

    return ConstObjectInterfaceAssociated{ boolObject };
}

CoreTools::ConstObjectInterfaceAssociated CoreTools::BufferTargetTesting::CreateIntObjectAssociated()
{
    const auto intObject = std::make_shared<IntObject>(DisableNotThrow::Disable);
    intObject->SetUniqueId(uniqueId1);

    return ConstObjectInterfaceAssociated{ intObject };
}

CoreTools::ConstFileBufferSharedPtr CoreTools::BufferTargetTesting::GetObjectAssociatedFileBuffer() const
{
    const auto objectRegister = ObjectRegister::Create();

    BufferTarget bufferTarget{ bufferSize, objectRegister };

    const ConstWeakObjectAssociated<ObjectInterface> intWeakObjectAssociated{ intObjectAssociated.object };

    objectRegister->Register(boolObjectAssociated);
    objectRegister->Register(intObjectAssociated);

    bufferTarget.WriteUniqueId(intObjectAssociated.object);
    bufferTarget.WriteObjectAssociated(boolObjectAssociated);
    bufferTarget.WriteWeakObjectAssociated(intWeakObjectAssociated);

    bufferTarget.WriteObjectAssociatedContainerWithNumber(objectAssociatedContainer0);
    bufferTarget.WriteObjectAssociatedContainerWithoutNumber(objectAssociatedContainer1);
    bufferTarget.WriteObjectAssociatedContainer(objectAssociatedContainer2);

    return bufferTarget.GetFileBuffer();
}

void CoreTools::BufferTargetTesting::ReadObjectAssociated0Test(BufferSource& bufferSource)
{
    int64_t result{};

    bufferSource.Read(result);
    ASSERT_EQUAL(result, uniqueId1);

    bufferSource.Read(result);
    ASSERT_EQUAL(result, uniqueId0);

    bufferSource.Read(result);
    ASSERT_EQUAL(result, uniqueId1);
}

void CoreTools::BufferTargetTesting::ReadObjectAssociated1Test(BufferSource& bufferSource)
{
    int32_t size{};
    bufferSource.Read(size);

    ASSERT_EQUAL(size, boost::numeric_cast<int>(objectAssociatedContainer0.size()));

    ObjectAssociatedInt64Container0 result{};
    bufferSource.ReadContainer(result);
    for (auto i = 0u; i < objectAssociatedContainer0.size(); ++i)
    {
        ASSERT_EQUAL(objectAssociatedContainer0.at(i).object->GetUniqueId(), result.at(i));
    }
}

void CoreTools::BufferTargetTesting::ReadObjectAssociated2Test(BufferSource& bufferSource)
{
    ObjectAssociatedInt64Container1 result{};
    bufferSource.ReadContainer(result);
    for (auto i = 0u; i < objectAssociatedContainer1.size(); ++i)
    {
        ASSERT_EQUAL(objectAssociatedContainer1.at(i).object->GetUniqueId(), result.at(i));
    }
}

void CoreTools::BufferTargetTesting::ReadObjectAssociated3Test(BufferSource& bufferSource)
{
    ObjectAssociatedInt64Container2 result{};
    bufferSource.ReadContainer(result);
    for (auto i = 0u; i < objectAssociatedContainer2.size(); ++i)
    {
        ASSERT_EQUAL(objectAssociatedContainer2.at(i).object->GetUniqueId(), result.at(i));
    }
}