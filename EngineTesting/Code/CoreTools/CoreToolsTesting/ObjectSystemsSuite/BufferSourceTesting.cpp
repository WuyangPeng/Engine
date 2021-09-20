// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/06 14:18)

#include "BufferSourceTesting.h"
#include "Detail/BufferSourceTestingEnum.h"
#include "Detail/NullObject.h"
#include "CoreTools/FileManager/FileBuffer.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/Helper/MemoryMacro.h"
#include "CoreTools/MemoryTools/SmartPointer1DArray.h"
#include "CoreTools/MemoryTools/SmartPointerManager.h"
#include "CoreTools/ObjectSystems/BufferOutStream.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/StreamDetail.h"
#include "CoreTools/ObjectSystems/StreamSize.h"

#include "System/Helper/PragmaWarning/NumericCast.h"
#include <vector>

using std::make_shared;
using std::string;
using std::vector;
using namespace std::literals;
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
#include SYSTEM_WARNING_DISABLE(26472)
namespace CoreTools
{
    constexpr size_t g_ArraySize{ 5 };

    constexpr bool g_FalseBoolValue{ false };
    constexpr bool g_TrueBoolValue{ true };

    const auto g_SingleBoolBufferSize = CORE_TOOLS_STREAM_SIZE(g_FalseBoolValue) + CORE_TOOLS_STREAM_SIZE(g_TrueBoolValue);
    const auto g_BoolBufferSize = static_cast<size_t>(g_SingleBoolBufferSize) * (g_ArraySize + 1u) + sizeof(int);

    const string g_FalseStringValue{ "false"s };
    const string g_TrueStringValue{ "true"s };

    const auto g_SingleStringBufferSize = CORE_TOOLS_STREAM_SIZE(g_FalseStringValue) + CORE_TOOLS_STREAM_SIZE(g_TrueStringValue);
    const auto g_StringBufferSize = static_cast<size_t>(g_SingleStringBufferSize) * (g_ArraySize + 1u) + sizeof(int);

    constexpr float g_FiveFloatValue{ 5.0f };
    constexpr float g_SixFloatValue{ 6.0f };

    const auto g_SingleFloatBufferSize = CORE_TOOLS_STREAM_SIZE(g_FiveFloatValue) + CORE_TOOLS_STREAM_SIZE(g_SixFloatValue);
    const auto g_FloatBufferSize = static_cast<size_t>(g_SingleFloatBufferSize) * (g_ArraySize + 1u) + sizeof(int);

    const auto g_SingleEnumbufferSize = CORE_TOOLS_STREAM_SIZE(BufferSourceTestingEnum::Nine) + CORE_TOOLS_STREAM_SIZE(BufferSourceTestingEnum::Twenty);
    const auto g_EnumbufferSize = static_cast<size_t>(g_SingleEnumbufferSize) * (g_ArraySize + 1u) + sizeof(int);
}
#include STSTEM_WARNING_POP
UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(CoreTools, BufferSourceTesting)

void CoreTools::BufferSourceTesting ::MainTest() noexcept
{
    // 	ASSERT_NOT_THROW_EXCEPTION_0(ReadBoolTest);
    // 	ASSERT_NOT_THROW_EXCEPTION_0(ReadStringTest);
    // 	ASSERT_NOT_THROW_EXCEPTION_0(ReadFloatTest);
    // 	ASSERT_NOT_THROW_EXCEPTION_0(ReadEnumTest);
    // 	ASSERT_NOT_THROW_EXCEPTION_0(ReadObjectPointerTest);
}
/*
void CoreTools::BufferSourceTesting
	::ReadBoolTest()
{
	auto fileBufferPtr = CreateBoolTarget();

	VerificationBoolSource(fileBufferPtr);
}

CoreTools::BufferSourceTesting::FileBufferPtr CoreTools::BufferSourceTesting
	::CreateBoolTarget()
{
	BufferTarget::FileBufferPtr	fileBufferPtr{ make_shared<FileBuffer>(g_BoolBufferSize) };

	auto currentWriteBufferSize = 0;

	ObjectRegister objectRegister{};
	BufferTarget target{ fileBufferPtr,objectRegister };

	ASSERT_EQUAL(target.GetBytesWritten(), currentWriteBufferSize);

	target.WriteBool(g_FalseBoolValue);
	currentWriteBufferSize += CORE_TOOLS_STREAM_SIZE(g_FalseBoolValue);

	ASSERT_EQUAL(target.GetBytesWritten(), currentWriteBufferSize);

	target.WriteBool(g_TrueBoolValue);
	currentWriteBufferSize += CORE_TOOLS_STREAM_SIZE(g_TrueBoolValue);

	ASSERT_EQUAL(currentWriteBufferSize, target.GetBytesWritten());

	SmartPointer1DArray<bool> boolArray{ NEW1<bool>(g_ArraySize) };

	for (auto i = 0; i < g_ArraySize; ++i)
	{
		boolArray[i] = g_FalseBoolValue;
	}

	target.WriteBoolWithNumber(g_ArraySize, boolArray);
	currentWriteBufferSize += (g_ArraySize * CORE_TOOLS_STREAM_SIZE(g_FalseBoolValue) + sizeof(int));

	ASSERT_EQUAL(currentWriteBufferSize, target.GetBytesWritten());

	for (auto i = 0; i < g_ArraySize; ++i)
	{
		boolArray[i] = g_TrueBoolValue;
	}

	target.WriteBoolWithoutNumber(g_ArraySize, boolArray);
	currentWriteBufferSize += (g_ArraySize * CORE_TOOLS_STREAM_SIZE(g_FalseBoolValue));

	ASSERT_EQUAL(currentWriteBufferSize, target.GetBytesWritten());
	ASSERT_EQUAL(currentWriteBufferSize, boost::numeric_cast<int>(g_BoolBufferSize));

	return fileBufferPtr;
}

void CoreTools::BufferSourceTesting
	::VerificationBoolSource(const FileBufferPtr& ptr)
{
	BufferSource source{ ptr };
	auto currentReadBufferSize = 0;

	ASSERT_EQUAL(source.GetBytesRead(), currentReadBufferSize);

	auto readBoolValue = source.ReadBool();
	ASSERT_EQUAL(readBoolValue, g_FalseBoolValue);

	currentReadBufferSize += CORE_TOOLS_STREAM_SIZE(readBoolValue);

	ASSERT_EQUAL(source.GetBytesRead(), currentReadBufferSize);

	readBoolValue = source.ReadBool();
	ASSERT_EQUAL(readBoolValue, g_TrueBoolValue);

	currentReadBufferSize += CORE_TOOLS_STREAM_SIZE(readBoolValue);

	ASSERT_EQUAL(source.GetBytesRead(), currentReadBufferSize);

	SmartPointer1DArray<bool> boolArray{ NEW1<bool>(g_ArraySize) };

	for (auto i = 0; i < g_ArraySize; ++i)
	{
		boolArray[i] = g_TrueBoolValue;
	}

	auto boolArraySize = 0;
	source.Read(boolArraySize);

	ASSERT_EQUAL(boost::numeric_cast<int>(g_ArraySize), boolArraySize);

	source.ReadBool(g_ArraySize, boolArray);
	currentReadBufferSize += (g_ArraySize * CORE_TOOLS_STREAM_SIZE(readBoolValue) + sizeof(int));

	for (auto i = 0; i < g_ArraySize; ++i)
	{
		ASSERT_EQUAL(boolArray[i], g_FalseBoolValue);
	}

	ASSERT_EQUAL(source.GetBytesRead(), currentReadBufferSize);

	source.ReadBool(g_ArraySize, boolArray);
	currentReadBufferSize += (g_ArraySize * CORE_TOOLS_STREAM_SIZE(g_FalseBoolValue));

	for (auto i = 0; i < g_ArraySize; ++i)
	{
		ASSERT_EQUAL(boolArray[i], g_TrueBoolValue);
	}

	ASSERT_EQUAL(source.GetBytesRead(), currentReadBufferSize);
	ASSERT_EQUAL(currentReadBufferSize, boost::numeric_cast<int>(g_BoolBufferSize));
}

void CoreTools::BufferSourceTesting
	::ReadStringTest()
{
	auto fileBufferPtr = CreateStringTarget();

	VerificationStringSource(fileBufferPtr);
}

CoreTools::BufferSourceTesting::FileBufferPtr CoreTools::BufferSourceTesting
	::CreateStringTarget()
{
	auto currentWriteBufferSize = 0;

	BufferTarget::FileBufferPtr	fileBufferPtr{ make_shared<FileBuffer>(g_StringBufferSize) };
	ObjectRegister objectRegister{};

	BufferTarget target{ fileBufferPtr,objectRegister };

	ASSERT_EQUAL(target.GetBytesWritten(), currentWriteBufferSize);

	target.WriteString(g_FalseStringValue);
	currentWriteBufferSize += CORE_TOOLS_STREAM_SIZE(g_FalseStringValue);

	ASSERT_EQUAL(target.GetBytesWritten(), currentWriteBufferSize);

	target.WriteString(g_TrueStringValue);
	currentWriteBufferSize += CORE_TOOLS_STREAM_SIZE(g_TrueStringValue);

	ASSERT_EQUAL(target.GetBytesWritten(), currentWriteBufferSize);

	vector<string> stringVector(g_ArraySize, g_FalseStringValue);
	target.WriteStringWithNumber(boost::numeric_cast<int>(stringVector.size()), &stringVector[0]);
	currentWriteBufferSize += CORE_TOOLS_STREAM_SIZE(g_FalseStringValue) * g_ArraySize + sizeof(int);

	ASSERT_EQUAL(target.GetBytesWritten(), currentWriteBufferSize);

	stringVector.assign(g_ArraySize, g_TrueStringValue);
	target.WriteStringWithoutNumber(boost::numeric_cast<int>(stringVector.size()), &stringVector[0]);
	currentWriteBufferSize += CORE_TOOLS_STREAM_SIZE(g_TrueStringValue) * g_ArraySize;

	ASSERT_EQUAL(target.GetBytesWritten(), currentWriteBufferSize);
	ASSERT_EQUAL(static_cast<int>(g_StringBufferSize), currentWriteBufferSize);

	return fileBufferPtr;
}

void CoreTools::BufferSourceTesting
	::VerificationStringSource(const FileBufferPtr& ptr)
{
	BufferSource source{ ptr };
	auto currentReadBufferSize = 0;

	ASSERT_EQUAL(source.GetBytesRead(), currentReadBufferSize);

	auto readStringValue = source.ReadString();
	currentReadBufferSize += CORE_TOOLS_STREAM_SIZE(readStringValue);

	ASSERT_EQUAL(readStringValue, g_FalseStringValue);
	ASSERT_EQUAL(source.GetBytesRead(), currentReadBufferSize);

	readStringValue = source.ReadString();
	currentReadBufferSize += CORE_TOOLS_STREAM_SIZE(readStringValue);

	ASSERT_EQUAL(readStringValue, g_TrueStringValue);
	ASSERT_EQUAL(source.GetBytesRead(), currentReadBufferSize);

	auto stringVectorSize = 0;
	source.Read(stringVectorSize);

	ASSERT_EQUAL(boost::numeric_cast<int>(g_ArraySize), stringVectorSize);

	vector<string> stringVector(g_ArraySize, g_TrueStringValue);

	source.ReadString(boost::numeric_cast<int>(stringVector.size()), &stringVector[0]);

	currentReadBufferSize += CORE_TOOLS_STREAM_SIZE(g_FalseStringValue) * g_ArraySize + sizeof(int);

	for (auto i = 0u; i < stringVector.size(); ++i)
	{
		ASSERT_EQUAL(stringVector[i], g_FalseStringValue);
	}
	ASSERT_EQUAL(source.GetBytesRead(), currentReadBufferSize);

	source.ReadString(boost::numeric_cast<int>(stringVector.size()), &stringVector[0]);

	currentReadBufferSize += CORE_TOOLS_STREAM_SIZE(g_TrueStringValue) * g_ArraySize;

	for (auto i = 0u; i < stringVector.size(); ++i)
	{
		ASSERT_EQUAL(stringVector[i], g_TrueStringValue);
	}

	ASSERT_EQUAL(source.GetBytesRead(), currentReadBufferSize);
	ASSERT_EQUAL(currentReadBufferSize, boost::numeric_cast<int>(g_StringBufferSize));
}

void CoreTools::BufferSourceTesting
	::ReadFloatTest()
{
	auto fileBufferPtr = CreateFloatTarget();

	VerificationFloatSource(fileBufferPtr);
}

CoreTools::BufferSourceTesting::FileBufferPtr CoreTools::BufferSourceTesting
	::CreateFloatTarget()
{
	int currentWriteBufferSize{ 0 };

	BufferTarget::FileBufferPtr	fileBufferPtr{ make_shared<FileBuffer>(g_FloatBufferSize) };
	ObjectRegister objectRegister{};

	BufferTarget target(fileBufferPtr, objectRegister);

	ASSERT_EQUAL(target.GetBytesWritten(), currentWriteBufferSize);

	target.Write(g_FiveFloatValue);
	currentWriteBufferSize += CORE_TOOLS_STREAM_SIZE(g_FiveFloatValue);

	ASSERT_EQUAL(target.GetBytesWritten(), currentWriteBufferSize);

	target.Write(g_SixFloatValue);
	currentWriteBufferSize += CORE_TOOLS_STREAM_SIZE(g_SixFloatValue);

	ASSERT_EQUAL(target.GetBytesWritten(), currentWriteBufferSize);

	vector<float> floatVector(g_ArraySize, g_FiveFloatValue);
	target.WriteWithNumber(boost::numeric_cast<int>(floatVector.size()), floatVector.data());
	currentWriteBufferSize += CORE_TOOLS_STREAM_SIZE(g_FiveFloatValue) * g_ArraySize + sizeof(int);

	ASSERT_EQUAL(target.GetBytesWritten(), currentWriteBufferSize);

	floatVector.assign(g_ArraySize, g_SixFloatValue);
	target.WriteWithoutNumber(boost::numeric_cast<int>(floatVector.size()), floatVector.data());
	currentWriteBufferSize += CORE_TOOLS_STREAM_SIZE(g_FiveFloatValue) * g_ArraySize;

	ASSERT_EQUAL(target.GetBytesWritten(), currentWriteBufferSize);
	ASSERT_EQUAL(boost::numeric_cast<int>(g_FloatBufferSize), currentWriteBufferSize);

	return fileBufferPtr;
}

void CoreTools::BufferSourceTesting
	::VerificationFloatSource(const FileBufferPtr& ptr)
{
	BufferSource source{ ptr };
	auto currentReadBufferSize = 0;

	ASSERT_EQUAL(source.GetBytesRead(), currentReadBufferSize);

	auto readFloatValue = g_SixFloatValue;

	source.Read(readFloatValue);
	currentReadBufferSize += CORE_TOOLS_STREAM_SIZE(readFloatValue);

	ASSERT_APPROXIMATE(readFloatValue, g_FiveFloatValue, 1e-8f);
	ASSERT_EQUAL(source.GetBytesRead(), currentReadBufferSize);

	source.Read(readFloatValue);
	currentReadBufferSize += CORE_TOOLS_STREAM_SIZE(readFloatValue);

	ASSERT_APPROXIMATE(readFloatValue, g_SixFloatValue, 1e-8f);
	ASSERT_EQUAL(source.GetBytesRead(), currentReadBufferSize);

	auto floatVectorSize = 0;
	source.Read(floatVectorSize);

	ASSERT_EQUAL(boost::numeric_cast<int>(g_ArraySize), floatVectorSize);

	vector<float> floatVector(g_ArraySize, g_SixFloatValue);
	source.Read(boost::numeric_cast<int>(floatVector.size()), &floatVector[0]);

	currentReadBufferSize += CORE_TOOLS_STREAM_SIZE(floatVectorSize) * g_ArraySize + sizeof(int);

	for (auto i = 0u; i < floatVector.size(); ++i)
	{
		ASSERT_APPROXIMATE(floatVector[i], g_FiveFloatValue, 1e-8f);
	}
	ASSERT_EQUAL(source.GetBytesRead(), currentReadBufferSize);

	source.Read(boost::numeric_cast<int>(floatVector.size()), &floatVector[0]);

	currentReadBufferSize += CORE_TOOLS_STREAM_SIZE(readFloatValue) * g_ArraySize;

	for (auto i = 0u; i < floatVector.size(); ++i)
	{
		ASSERT_APPROXIMATE(floatVector[i], g_SixFloatValue, 1e-8f);
	}

	ASSERT_EQUAL(source.GetBytesRead(), currentReadBufferSize);
	ASSERT_EQUAL(currentReadBufferSize, static_cast<int>(g_FloatBufferSize));
}

void CoreTools::BufferSourceTesting
	::ReadEnumTest()
{
	auto fileBufferPtr = CreateEnumTarget();

	VerificationEnumSource(fileBufferPtr);
}

CoreTools::BufferSourceTesting::FileBufferPtr CoreTools::BufferSourceTesting
	::CreateEnumTarget()
{
	auto currentWriteBufferSize = 0;

	BufferTarget::FileBufferPtr	fileBufferPtr{ make_shared<FileBuffer>(g_EnumbufferSize) };
	ObjectRegister objectRegister{};

	BufferTarget target(fileBufferPtr, objectRegister);

	ASSERT_EQUAL(target.GetBytesWritten(), currentWriteBufferSize);

	target.WriteEnum(BufferSourceTestingEnum::Nine);
	currentWriteBufferSize += CORE_TOOLS_STREAM_SIZE(BufferSourceTestingEnum::Nine);

	ASSERT_EQUAL(target.GetBytesWritten(), currentWriteBufferSize);

	target.WriteEnum(BufferSourceTestingEnum::Twenty);
	currentWriteBufferSize += CORE_TOOLS_STREAM_SIZE(BufferSourceTestingEnum::Twenty);

	ASSERT_EQUAL(target.GetBytesWritten(), currentWriteBufferSize);

	vector<BufferSourceTestingEnum> enumVector(g_ArraySize, BufferSourceTestingEnum::Nine);
	target.WriteEnumWithNumber(boost::numeric_cast<int>(enumVector.size()), &enumVector[0]);
	currentWriteBufferSize += CORE_TOOLS_STREAM_SIZE(BufferSourceTestingEnum::Nine) * g_ArraySize + sizeof(int);

	ASSERT_EQUAL(target.GetBytesWritten(), currentWriteBufferSize);

	enumVector.assign(g_ArraySize, BufferSourceTestingEnum::Twenty);
	target.WriteEnumWithoutNumber(boost::numeric_cast<int>(enumVector.size()), &enumVector[0]);
	currentWriteBufferSize += CORE_TOOLS_STREAM_SIZE(BufferSourceTestingEnum::Twenty) * g_ArraySize;

	ASSERT_EQUAL(target.GetBytesWritten(), currentWriteBufferSize);
	ASSERT_EQUAL(boost::numeric_cast<int>(g_EnumbufferSize), currentWriteBufferSize);

	return fileBufferPtr;
}

void CoreTools::BufferSourceTesting
	::VerificationEnumSource(const FileBufferPtr& ptr)
{
	BufferSource source{ ptr };
	auto currentReadBufferSize = 0;

	ASSERT_EQUAL(source.GetBytesRead(), currentReadBufferSize);

	auto readEnumValue = BufferSourceTestingEnum::Twenty;

	source.ReadEnum(readEnumValue);
	currentReadBufferSize += CORE_TOOLS_STREAM_SIZE(readEnumValue);

	ASSERT_ENUM_EQUAL(readEnumValue, BufferSourceTestingEnum::Nine);
	ASSERT_EQUAL(source.GetBytesRead(), currentReadBufferSize);

	source.ReadEnum(readEnumValue);
	currentReadBufferSize += CORE_TOOLS_STREAM_SIZE(readEnumValue);

	ASSERT_ENUM_EQUAL(readEnumValue, BufferSourceTestingEnum::Twenty);
	ASSERT_EQUAL(source.GetBytesRead(), currentReadBufferSize);

	auto enumVectorSize = 0;
	source.Read(enumVectorSize);

	ASSERT_EQUAL(boost::numeric_cast<int>(g_ArraySize), enumVectorSize);

	vector<BufferSourceTestingEnum> enumVector(g_ArraySize, BufferSourceTestingEnum::Twenty);
	source.ReadEnum(boost::numeric_cast<int>(enumVector.size()), &enumVector[0]);

	currentReadBufferSize += CORE_TOOLS_STREAM_SIZE(readEnumValue) * g_ArraySize + sizeof(int);

	for (auto i = 0u; i < enumVector.size(); ++i)
	{
		ASSERT_ENUM_EQUAL(enumVector[i], BufferSourceTestingEnum::Nine);
	}
	ASSERT_EQUAL(source.GetBytesRead(), currentReadBufferSize);

	source.ReadEnum(boost::numeric_cast<int>(enumVector.size()), &enumVector[0]);

	currentReadBufferSize += CORE_TOOLS_STREAM_SIZE(readEnumValue)  * g_ArraySize;

	for (auto i = 0u; i < enumVector.size(); ++i)
	{
		ASSERT_ENUM_EQUAL(enumVector[i], BufferSourceTestingEnum::Twenty);
	}

	ASSERT_EQUAL(source.GetBytesRead(), currentReadBufferSize);
	ASSERT_EQUAL(currentReadBufferSize, boost::numeric_cast<int>(g_EnumbufferSize));
}

void CoreTools::BufferSourceTesting
	::ReadObjectPointerTest()
{
	auto fileBufferPtr = CreateObjectPointerTarget();

	VerificationObjectPointerSource(fileBufferPtr);
}

CoreTools::BufferSourceTesting::FileBufferPtr CoreTools::BufferSourceTesting
	::CreateObjectPointerTarget()
{
	NullObjectSmartPointer nullObject{ NEW0 NullObject };
	vector<ObjectInterfaceSmartPointer> nullObjectVector1{};
	vector<ObjectInterfaceSmartPointer> nullObjectVector2{};
	vector<ObjectInterfaceSmartPointer> nullObjectVector3{};
	vector<ObjectInterfaceSmartPointer> nullObjectVector4{};
	vector<ObjectPtr> nullObjectVector5{};
	vector<ObjectPtr> nullObjectVector6{};

	for (auto i = 0; i < g_ArraySize; ++i)
	{
		nullObjectVector1.emplace_back(NEW0 NullObject);
		nullObjectVector2.emplace_back(NEW0 NullObject);
		nullObjectVector3.emplace_back(NEW0 NullObject);
		nullObjectVector4.emplace_back(NEW0 NullObject);
		nullObjectVector5.push_back(nullObjectVector1[i].GetData());
		nullObjectVector6.push_back(nullObjectVector2[i].GetData());
	}

	const auto bufferSize = static_cast<int>(8 * (4 * g_ArraySize + 1) + sizeof(int) * 2);
	auto currentWriteBufferSize = 0;

	BufferTarget::FileBufferPtr	fileBufferPtr{ make_shared<FileBuffer>(bufferSize) };

	ObjectRegister objectRegister{};
	objectRegister.RegisterRoot(ObjectInterfaceSmartPointer{});
	objectRegister.Register(nullObject.GetData());
	objectRegister.Register(boost::numeric_cast<int>(nullObjectVector5.size()), &nullObjectVector5[0]);
	objectRegister.Register(boost::numeric_cast<int>(nullObjectVector6.size()), &nullObjectVector6[0]);
	objectRegister.RegisterSmartPointer(boost::numeric_cast<int>(nullObjectVector3.size()), &nullObjectVector3[0]);
	objectRegister.RegisterSmartPointer(boost::numeric_cast<int>(nullObjectVector4.size()), &nullObjectVector4[0]);

	BufferTarget target{ fileBufferPtr,objectRegister };

	ASSERT_EQUAL(target.GetBytesWritten(), currentWriteBufferSize);

	target.WritePointer(nullObject.GetData());
	currentWriteBufferSize += CORE_TOOLS_STREAM_SIZE(&nullObject);
	ASSERT_EQUAL(target.GetBytesWritten(), currentWriteBufferSize);

	target.WritePointerWithNumber(boost::numeric_cast<int>(nullObjectVector1.size()), nullObjectVector5.data());
	currentWriteBufferSize += CORE_TOOLS_STREAM_SIZE(&nullObject) * g_ArraySize + sizeof(int);
	ASSERT_EQUAL(target.GetBytesWritten(), currentWriteBufferSize);

	target.WritePointerWithoutNumber(boost::numeric_cast<int>(nullObjectVector2.size()), nullObjectVector6.data());
	currentWriteBufferSize += CORE_TOOLS_STREAM_SIZE(&nullObject) * g_ArraySize;
	ASSERT_EQUAL(target.GetBytesWritten(), currentWriteBufferSize);

	target.WriteSmartPointerWithNumber(boost::numeric_cast<int>(nullObjectVector3.size()), nullObjectVector3.data());
	currentWriteBufferSize += CORE_TOOLS_STREAM_SIZE(&nullObject) * g_ArraySize + sizeof(int);
	ASSERT_EQUAL(target.GetBytesWritten(), currentWriteBufferSize);

	target.WriteSmartPointerWithoutNumber(boost::numeric_cast<int>(nullObjectVector4.size()), nullObjectVector4.data());
	currentWriteBufferSize += CORE_TOOLS_STREAM_SIZE(&nullObject) * g_ArraySize;
	ASSERT_EQUAL(target.GetBytesWritten(), currentWriteBufferSize);
	ASSERT_EQUAL(bufferSize, currentWriteBufferSize);

	return fileBufferPtr;
}

void CoreTools::BufferSourceTesting
	::VerificationObjectPointerSource(const FileBufferPtr& ptr)
{
	NullObjectSmartPointer nullObject{ NEW0 NullObject };

	const auto bufferSize = boost::numeric_cast<int>(CORE_TOOLS_STREAM_SIZE(nullObject) * (4 * g_ArraySize + 1) + sizeof(int) * 2);

	BufferSource source{ ptr };
	auto currentReadBufferSize = 0;

	ASSERT_EQUAL(source.GetBytesRead(), currentReadBufferSize);

	auto index = 0;
	NullObjectSmartPointer readNullObjectValue{ nullptr };

	source.ReadSmartPointer(readNullObjectValue);
	currentReadBufferSize += CORE_TOOLS_STREAM_SIZE(readNullObjectValue);

	ASSERT_EQUAL(boost::numeric_cast<int>(readNullObjectValue.GetAddress()), ++index);
	ASSERT_EQUAL(source.GetBytesRead(), currentReadBufferSize);

	auto nullObjectVectorSize = 0;
	source.Read(nullObjectVectorSize);

	ASSERT_EQUAL(boost::numeric_cast<int>(g_ArraySize), nullObjectVectorSize);

	vector<ObjectInterfaceSmartPointer> firstNullObjectVector(g_ArraySize);

	source.ReadSmartPointer(boost::numeric_cast<int>(firstNullObjectVector.size()), &firstNullObjectVector[0]);

	currentReadBufferSize += CORE_TOOLS_STREAM_SIZE(readNullObjectValue) *g_ArraySize + sizeof(int);

	for (auto i = 0u; i < firstNullObjectVector.size(); ++i)
	{
		ASSERT_EQUAL(boost::numeric_cast<int>(firstNullObjectVector[i].GetAddress()), ++index);
	}
	ASSERT_EQUAL(source.GetBytesRead(), currentReadBufferSize);

	source.ReadSmartPointer(boost::numeric_cast<int>(firstNullObjectVector.size()), &firstNullObjectVector[0]);

	currentReadBufferSize += CORE_TOOLS_STREAM_SIZE(readNullObjectValue) *g_ArraySize;

	for (auto i = 0u; i < firstNullObjectVector.size(); ++i)
	{
		ASSERT_EQUAL(boost::numeric_cast<int>(firstNullObjectVector[i].GetAddress()), ++index);
	}

	ASSERT_EQUAL(source.GetBytesRead(), currentReadBufferSize);

	source.Read(nullObjectVectorSize);

	ASSERT_EQUAL(boost::numeric_cast<int>(g_ArraySize), nullObjectVectorSize);

	vector<ObjectInterfaceSmartPointer> sixthNullObjectVector(g_ArraySize);

	source.ReadSmartPointer(boost::numeric_cast<int>(sixthNullObjectVector.size()), &sixthNullObjectVector[0]);

	currentReadBufferSize += CORE_TOOLS_STREAM_SIZE(readNullObjectValue) *g_ArraySize + sizeof(int);

	for (auto i = 0u; i < sixthNullObjectVector.size(); ++i)
	{
		ASSERT_EQUAL(boost::numeric_cast<int>(sixthNullObjectVector[i].GetAddress()), ++index);
	}
	ASSERT_EQUAL(source.GetBytesRead(), currentReadBufferSize);

	source.ReadSmartPointer(boost::numeric_cast<int>(sixthNullObjectVector.size()), &sixthNullObjectVector[0]);

	currentReadBufferSize += CORE_TOOLS_STREAM_SIZE(readNullObjectValue) * g_ArraySize;

	for (auto i = 0u; i < sixthNullObjectVector.size(); ++i)
	{
		ASSERT_EQUAL(boost::numeric_cast<int>(sixthNullObjectVector[i].GetAddress()), ++index);
	}

	ASSERT_EQUAL(source.GetBytesRead(), currentReadBufferSize);

	ASSERT_EQUAL(currentReadBufferSize, bufferSize);
}






*/