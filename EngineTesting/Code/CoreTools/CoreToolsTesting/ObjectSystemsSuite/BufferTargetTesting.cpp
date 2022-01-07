// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎测试版本：0.0.2.3 (2020/03/06 14:24)

#include "BufferTargetTesting.h"
#include "Detail/NullObject.h"
#include "Detail/BufferTargetTestingEnum.h"
#include "CoreTools/Helper/StreamMacro.h"

#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/FileManager/FileBuffer.h"

#include "CoreTools/ObjectSystems/StreamSize.h"
#include "CoreTools/ObjectSystems/StreamDetail.h"
#include "CoreTools/ObjectSystems/BufferOutStream.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectRegisterDetail.h"

#include "System/Helper/PragmaWarning/NumericCast.h"
#include <vector>

using std::string;
using std::vector;
using std::make_shared;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(CoreTools, BufferTargetTesting)

void CoreTools::BufferTargetTesting ::MainTest() noexcept
{
    // 	ASSERT_NOT_THROW_EXCEPTION_0(WriteBoolTest);
// 	ASSERT_NOT_THROW_EXCEPTION_0(WriteStringTest);
// 	ASSERT_NOT_THROW_EXCEPTION_0(WriteIntTest);
// 	ASSERT_NOT_THROW_EXCEPTION_0(WriteEnumTest);
// 	ASSERT_NOT_THROW_EXCEPTION_0(WriteNullObjectTest);
// 	ASSERT_NOT_THROW_EXCEPTION_0(WriteObjectPointerTest);
}
/*
void CoreTools::BufferTargetTesting
	::WriteBoolTest()
{
	constexpr auto arraySize = 5;

	bool falseValue{ false };
	bool trueValue{ true };

	// 测试写入缓冲区的总大小
	const auto bufferSize = static_cast<int>(arraySize * 2 * CORE_TOOLS_STREAM_SIZE(falseValue) + CORE_TOOLS_STREAM_SIZE(falseValue) * 2 + sizeof(int));
	auto currentBufferSize = 0;

	BufferTarget::FileBufferPtr fileBufferPtr{ make_shared<FileBuffer>(bufferSize) };
	ObjectRegister objectRegister{};

	BufferTarget target{ fileBufferPtr,objectRegister };

	ASSERT_EQUAL(target.GetBytesWritten(), currentBufferSize);

	target.WriteBool(falseValue);
	currentBufferSize += CORE_TOOLS_STREAM_SIZE(falseValue);

	ASSERT_EQUAL(target.GetBytesWritten(), currentBufferSize);

	target.WriteBool(trueValue);
	currentBufferSize += CORE_TOOLS_STREAM_SIZE(trueValue);

	ASSERT_EQUAL(currentBufferSize, target.GetBytesWritten());

	SmartPointer1DArray<bool> boolArray{ NEW1<bool>(arraySize) };

	for (auto i = 0; i < arraySize; ++i)
	{
		boolArray[i] = falseValue;
	}

	target.WriteBoolWithNumber(arraySize, &boolArray[0]);
	auto addSize = arraySize * CORE_TOOLS_STREAM_SIZE(falseValue);
	currentBufferSize += (addSize + sizeof(int));

	ASSERT_EQUAL(currentBufferSize, target.GetBytesWritten());

	for (auto i = 0; i < arraySize; ++i)
	{
		boolArray[i] = trueValue;
	}

	target.WriteBoolWithoutNumber(arraySize, &boolArray[0]);
	currentBufferSize += (arraySize * CORE_TOOLS_STREAM_SIZE(falseValue));

	ASSERT_EQUAL(currentBufferSize, target.GetBytesWritten());
	ASSERT_EQUAL(currentBufferSize, bufferSize);

	// 测试写入的值是否正确
	auto ptr = reinterpret_cast<int*>(fileBufferPtr->GetBufferBegin());

	for (auto i = 0u; i < fileBufferPtr->GetSize() / sizeof(int); ++i)
	{
		if (i == 0 || (3 <= i && i < 3 + arraySize))
			ASSERT_EQUAL(ptr[i], 0);
		else if (i == 2)
			ASSERT_EQUAL(ptr[i], arraySize);
		else
			ASSERT_UNEQUAL(ptr[i], 0);
	}
}

void CoreTools::BufferTargetTesting
	::WriteStringTest()
{
	constexpr auto arraySize = 5;

	string falseValue{ "false" };
	string trueValue{ "true" };

	// 测试写入缓冲区的总大小
	const auto bufferSize = static_cast<int>((CORE_TOOLS_STREAM_SIZE(falseValue) + CORE_TOOLS_STREAM_SIZE(trueValue)) * (arraySize + 1) + sizeof(int));
	int currentBufferSize{ 0 };

	BufferTarget::FileBufferPtr fileBufferPtr{ make_shared<FileBuffer>(bufferSize) };
	ObjectRegister objectRegister{};

	BufferTarget target{ fileBufferPtr,objectRegister };

	ASSERT_EQUAL(target.GetBytesWritten(), currentBufferSize);

	target.WriteString(falseValue);
	currentBufferSize += CORE_TOOLS_STREAM_SIZE(falseValue);

	ASSERT_EQUAL(target.GetBytesWritten(), currentBufferSize);

	target.WriteString(trueValue);
	currentBufferSize += CORE_TOOLS_STREAM_SIZE(trueValue);

	ASSERT_EQUAL(target.GetBytesWritten(), currentBufferSize);

	vector<string> stringVector(arraySize, falseValue);
	target.WriteStringWithNumber(boost::numeric_cast<int>(stringVector.size()), &stringVector[0]);
	auto addSize = CORE_TOOLS_STREAM_SIZE(falseValue) * arraySize;
	currentBufferSize += (addSize + sizeof(int));

	ASSERT_EQUAL(target.GetBytesWritten(), currentBufferSize);

	stringVector.assign(arraySize, trueValue);
	target.WriteStringWithoutNumber(boost::numeric_cast<int>(stringVector.size()), &stringVector[0]);
	currentBufferSize += CORE_TOOLS_STREAM_SIZE(trueValue) * arraySize;

	ASSERT_EQUAL(target.GetBytesWritten(), currentBufferSize);
	ASSERT_EQUAL(bufferSize, currentBufferSize);

	// 测试写入的值是否正确
	auto ptr = fileBufferPtr->GetBufferBegin();

	string buffer{ ptr,ptr + fileBufferPtr->GetSize() };

	string fiveSizeString(4, '\0');
	string fourSizeString(4, '\0');
	string zeroSuffix(3, '\0');
	fiveSizeString[0] = '\5';
	fourSizeString[0] = '\4';

	string arraySizeString(fiveSizeString);

	string correctBuffer{ fiveSizeString + falseValue + zeroSuffix +
						  fourSizeString + trueValue +
						  arraySizeString +
						  fiveSizeString + falseValue + zeroSuffix +
						  fiveSizeString + falseValue + zeroSuffix +
						  fiveSizeString + falseValue + zeroSuffix +
						  fiveSizeString + falseValue + zeroSuffix +
						  fiveSizeString + falseValue + zeroSuffix +
						  fourSizeString + trueValue +
						  fourSizeString + trueValue +
						  fourSizeString + trueValue +
						  fourSizeString + trueValue +
						  fourSizeString + trueValue };

	ASSERT_EQUAL(correctBuffer, buffer);
}

void CoreTools::BufferTargetTesting
	::WriteIntTest()
{
	constexpr auto arraySize = 5;

	int fiveValue{ 5 };
	int sixValue{ 6 };

	// 测试写入缓冲区的总大小
	const auto bufferSize = static_cast<int>((sizeof(fiveValue) + sizeof(sixValue)) * (arraySize + 1) + sizeof(int));
	int currentBufferSize{ 0 };

	BufferTarget::FileBufferPtr fileBufferPtr{ make_shared<FileBuffer>(bufferSize) };
	ObjectRegister objectRegister{};

	BufferTarget target{ fileBufferPtr,objectRegister };

	ASSERT_EQUAL(target.GetBytesWritten(), currentBufferSize);

	target.Write(fiveValue);
	currentBufferSize += sizeof(fiveValue);

	ASSERT_EQUAL(target.GetBytesWritten(), currentBufferSize);

	target.Write(sixValue);
	currentBufferSize += sizeof(sixValue);

	ASSERT_EQUAL(target.GetBytesWritten(), currentBufferSize);

	vector<int> intVector(arraySize, fiveValue);
	target.WriteWithNumber(boost::numeric_cast<int>(intVector.size()), &intVector[0]);
	currentBufferSize += sizeof(fiveValue) * arraySize + sizeof(int);

	ASSERT_EQUAL(target.GetBytesWritten(), currentBufferSize);

	intVector.assign(arraySize, sixValue);
	target.WriteWithoutNumber(boost::numeric_cast<int>(intVector.size()), &intVector[0]);
	currentBufferSize += sizeof(fiveValue) * arraySize;

	ASSERT_EQUAL(target.GetBytesWritten(), currentBufferSize);
	ASSERT_EQUAL(bufferSize, currentBufferSize);

	// 测试写入的值是否正确
	auto ptr = reinterpret_cast<int*>(fileBufferPtr->GetBufferBegin());

	for (auto i = 0u; i < fileBufferPtr->GetSize() / sizeof(int); ++i)
	{
		if (i == 0 || (3 <= i && i < 3 + arraySize))
			ASSERT_EQUAL(ptr[i], fiveValue);
		else if (i == 2)
			ASSERT_EQUAL(ptr[i], arraySize);
		else
			ASSERT_EQUAL(ptr[i], sixValue);
	}
}

void CoreTools::BufferTargetTesting
	::WriteEnumTest()
{
	constexpr auto arraySize = 5;

	const auto singleBufferSize = CORE_TOOLS_STREAM_SIZE(BufferTargetTestingEnum::Ten) + CORE_TOOLS_STREAM_SIZE(BufferTargetTestingEnum::Fifteen);

	// 测试写入缓冲区的总大小
	const auto bufferSize = singleBufferSize * (arraySize + 1) + boost::numeric_cast<int>(sizeof(int));
	auto currentBufferSize = 0;

	BufferTarget::FileBufferPtr fileBufferPtr(make_shared<FileBuffer>(bufferSize));
	ObjectRegister objectRegister{};

	BufferTarget target{ fileBufferPtr,objectRegister };

	ASSERT_EQUAL(target.GetBytesWritten(), currentBufferSize);

	target.WriteEnum(BufferTargetTestingEnum::Ten);
	currentBufferSize += CORE_TOOLS_STREAM_SIZE(BufferTargetTestingEnum::Ten);

	ASSERT_EQUAL(target.GetBytesWritten(), currentBufferSize);

	target.WriteEnum(BufferTargetTestingEnum::Fifteen);
	currentBufferSize += CORE_TOOLS_STREAM_SIZE(BufferTargetTestingEnum::Fifteen);

	ASSERT_EQUAL(target.GetBytesWritten(), currentBufferSize);

	vector<BufferTargetTestingEnum> enumVector(arraySize, BufferTargetTestingEnum::Ten);
	target.WriteEnumWithNumber(boost::numeric_cast<int>(enumVector.size()), &enumVector[0]);
	auto addSize = CORE_TOOLS_STREAM_SIZE(BufferTargetTestingEnum::Ten) * arraySize;
	currentBufferSize += addSize + sizeof(int);

	ASSERT_EQUAL(target.GetBytesWritten(), currentBufferSize);

	enumVector.assign(arraySize, BufferTargetTestingEnum::Fifteen);
	target.WriteEnumWithoutNumber(boost::numeric_cast<int>(enumVector.size()), &enumVector[0]);
	currentBufferSize += CORE_TOOLS_STREAM_SIZE(BufferTargetTestingEnum::Fifteen) * arraySize;

	ASSERT_EQUAL(target.GetBytesWritten(), currentBufferSize);
	ASSERT_EQUAL(bufferSize, currentBufferSize);

	// 测试写入的值是否正确
	auto ptr = reinterpret_cast<BufferTargetTestingEnum*>(fileBufferPtr->GetBufferBegin());

	for (auto i = 0u; i < fileBufferPtr->GetSize() / sizeof(BufferTargetTestingEnum); ++i)
	{
		if (i == 0 || (3 <= i && i < 3 + arraySize))
		{
			ASSERT_ENUM_EQUAL(ptr[i], BufferTargetTestingEnum::Ten);
		}
		else if (i == 2)
		{
			auto sizePtr = reinterpret_cast<int*>(ptr + i);
			ASSERT_EQUAL(*sizePtr, arraySize);
		}
		else
		{
			ASSERT_ENUM_EQUAL(ptr[i], BufferTargetTestingEnum::Fifteen);
		}
	}
}

void CoreTools::BufferTargetTesting
	::WriteNullObjectTest()
{
	NullObjectSmartPointer nullObject(NEW0 NullObject);

	const auto bufferSize = nullObject->GetStreamingSize();

	BufferTarget::FileBufferPtr fileBufferPtr(make_shared<FileBuffer>(bufferSize));
	ObjectRegister objectRegister{};
	objectRegister.RegisterSmartPointer(nullObject);

	BufferTarget target{ fileBufferPtr,objectRegister };

	ASSERT_EQUAL(target.GetBytesWritten(), 0);

	nullObject->Save(target);
	ASSERT_EQUAL(target.GetBytesWritten(), bufferSize);
}

void CoreTools::BufferTargetTesting
	::WriteObjectPointerTest()
{
	constexpr auto arraySize = 5;
	NullObjectSmartPointer nullObject{ NEW0 NullObject };
	vector<ObjectInterfaceSmartPointer> nullObjectVector1;
	vector<ObjectInterfaceSmartPointer> nullObjectVector2;
	vector<ObjectInterfaceSmartPointer> nullObjectVector3;
	vector<ObjectInterfaceSmartPointer> nullObjectVector4;
	vector<ObjectPtr> nullObjectVector5;
	vector<ObjectPtr> nullObjectVector6;

	for (int i = 0; i < arraySize; ++i)
	{
		nullObjectVector1.emplace_back(NEW0 NullObject);
		nullObjectVector2.emplace_back(NEW0 NullObject);
		nullObjectVector3.emplace_back(NEW0 NullObject);
		nullObjectVector4.emplace_back(NEW0 NullObject);
		nullObjectVector5.push_back(nullObjectVector1[i].GetData());
		nullObjectVector6.push_back(nullObjectVector2[i].GetData());
	}

	// 测试写入缓冲区的总大小
	const auto bufferSize = static_cast<int>(CORE_TOOLS_STREAM_SIZE(nullObject) * (4 * arraySize + 1) + sizeof(int) * 2);
	int currentBufferSize{ 0 };

	BufferTarget::FileBufferPtr fileBufferPtr(make_shared<FileBuffer>(bufferSize));
	ObjectRegister objectRegister{};
	objectRegister.RegisterRoot(ConstObjectInterfaceSmartPointer{});
	objectRegister.RegisterSmartPointer(nullObject);
	objectRegister.Register(boost::numeric_cast<int>(nullObjectVector5.size()), &nullObjectVector5[0]);
	objectRegister.Register(boost::numeric_cast<int>(nullObjectVector6.size()), &nullObjectVector6[0]);
	objectRegister.RegisterSmartPointer(boost::numeric_cast<int>(nullObjectVector3.size()), &nullObjectVector3[0]);
	objectRegister.RegisterSmartPointer(boost::numeric_cast<int>(nullObjectVector4.size()), &nullObjectVector4[0]);

	BufferTarget target{ fileBufferPtr,objectRegister };

	ASSERT_EQUAL(target.GetBytesWritten(), currentBufferSize);

	target.WriteSmartPointer(nullObject);
	currentBufferSize += CORE_TOOLS_STREAM_SIZE(nullObject);
	ASSERT_EQUAL(target.GetBytesWritten(), currentBufferSize);

	target.WritePointerWithNumber(boost::numeric_cast<int>(nullObjectVector1.size()), &nullObjectVector5[0]);
	auto addSize = CORE_TOOLS_STREAM_SIZE(nullObject) * arraySize;
	currentBufferSize += addSize + sizeof(int);
	ASSERT_EQUAL(target.GetBytesWritten(), currentBufferSize);

	target.WritePointerWithoutNumber(boost::numeric_cast<int>(nullObjectVector2.size()), &nullObjectVector6[0]);
	currentBufferSize += CORE_TOOLS_STREAM_SIZE(nullObject) * arraySize;
	ASSERT_EQUAL(target.GetBytesWritten(), currentBufferSize);

	target.WriteSmartPointerWithNumber(boost::numeric_cast<int>(nullObjectVector3.size()), &nullObjectVector3[0]);
	addSize = CORE_TOOLS_STREAM_SIZE(nullObject) * arraySize;
	currentBufferSize += addSize + sizeof(int);
	ASSERT_EQUAL(target.GetBytesWritten(), currentBufferSize);

	target.WriteSmartPointerWithoutNumber(boost::numeric_cast<int>(nullObjectVector4.size()), &nullObjectVector4[0]);
	currentBufferSize += CORE_TOOLS_STREAM_SIZE(nullObject) * arraySize;
	ASSERT_EQUAL(target.GetBytesWritten(), currentBufferSize);
	ASSERT_EQUAL(bufferSize, currentBufferSize);
}

*/