// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.1 (2020/01/19 15:18)

#include "CoreTools/CoreToolsExport.h"

#include "CWriteFileManagerImpl.h"
#include "System/Helper/UnusedMacro.h"
#include "CoreTools/FileManager/Endian.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

#include "System/Helper/PragmaWarning/NumericCast.h"
#include <vector>

using std::vector;
using std::string;

CoreTools::CWriteFileManagerImpl
	::CWriteFileManagerImpl(const String& fileName)
	:ParentType{ fileName,SYSTEM_TEXT("wbS") }
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CoreTools::CWriteFileManagerImpl
	::~CWriteFileManagerImpl()
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
bool CoreTools::CWriteFileManagerImpl
	::IsValid() const noexcept
{
	if (ParentType::IsValid() && InterfaceType::IsValid())
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

int CoreTools::CWriteFileManagerImpl
	::GetFileByteSize() const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	return ParentType::GetFileLength();
}

void CoreTools::CWriteFileManagerImpl
	::Write(size_t itemSize, const void* data)
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	CORE_TOOLS_ASSERTION_2(itemSize == 1 || itemSize == 2 || itemSize == 4 || itemSize == 8, "��С����Ϊ1��2��4��8\n");
	CORE_TOOLS_ASSERTION_0(data != nullptr, "������Ч");

	Write(itemSize, 1, data);
}

void CoreTools::CWriteFileManagerImpl
	::Write(size_t itemSize, size_t itemsNumber, const void* data)
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	CORE_TOOLS_ASSERTION_2(itemSize == 1 || itemSize == 2 || itemSize == 4 || itemSize == 8, "��С����Ϊ1��2��4��8\n");
	CORE_TOOLS_ASSERTION_0(0 < itemsNumber && data != nullptr, "������Ч");

#ifdef SYSTEM_BIG_ENDIAN
	auto writeNumber = WriteToFileWithBigEndian(itemSize, itemsNumber, data);
#else // !SYSTEM_BIG_ENDIAN
	auto writeNumber = WriteToFile(itemSize, itemsNumber, data);
#endif // SYSTEM_BIG_ENDIAN

	if (writeNumber != itemsNumber)
	{
		THROW_EXCEPTION(SYSTEM_TEXT("�����ļ����ݴ���"));
	}
}

#ifdef SYSTEM_BIG_ENDIAN
// private
size_t CoreTools::CWriteFileManagerImpl
	::WriteToFileWithBigEndian(size_t itemSize, size_t itemsNumber, const void* data) noexcept
{
	switch (itemSize)
	{
		case 2:
			return WriteToFileSwap2ByteOrder(itemsNumber, data);
		case 4:
			return WriteToFileSwap4ByteOrder(itemsNumber, data);
		case 8:
			return WriteToFileSwap8ByteOrder(itemsNumber, data);
		default:
			return WriteToFile(itemSize, itemsNumber, data);
	}
}

// private
size_t CoreTools::CWriteFileManagerImpl
	::WriteToFileSwap2ByteOrder(size_t itemsNumber, const void* data) noexcept
{
	vector<uint16_t> target(itemsNumber);
	auto bytes = reinterpret_cast<const uint16_t*>(data);

	Endian::Swap2ByteOrderToTarget(boost::numeric_cast<int>(itemsNumber), bytes, target.data());

	return WriteToFile(sizeof(uint16_t), itemsNumber, target.data());
}

// private
size_t CoreTools::CWriteFileManagerImpl
	::WriteToFileSwap4ByteOrder(size_t itemsNumber, const void* data) noexcept
{
	vector<uint32_t> target(itemsNumber);
	auto bytes = reinterpret_cast<const uint32_t*>(data);

	Endian::Swap4ByteOrderToTarget(boost::numeric_cast<int>(itemsNumber), bytes, target.data());

	return WriteToFile(sizeof(uint32_t), itemsNumber, target.data());
}

// private
size_t CoreTools::CWriteFileManagerImpl
	::WriteToFileSwap8ByteOrder(size_t itemsNumber, const void* data) noexcept
{
	vector<uint64_t> target(itemsNumber);
	auto bytes = reinterpret_cast<const uint64_t*>(data);

	Endian::Swap8ByteOrderToTarget(boost::numeric_cast<int>(itemsNumber), bytes, target.data());

	return WriteToFile(sizeof(uint64_t), itemsNumber, target.data());
}

#endif // SYSTEM_BIG_ENDIAN

size_t CoreTools::CWriteFileManagerImpl
	::ReadFromFile(size_t itemSize, size_t itemsNumber, void* data) noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	CORE_TOOLS_ASSERTION_4(false, "CWriteFileManageImpl��ֹ����ReadFromFile��");

	SYSTEM_UNUSED_ARG(itemSize);
	SYSTEM_UNUSED_ARG(itemsNumber);
	SYSTEM_UNUSED_ARG(data);

	return 0;
}

int CoreTools::CWriteFileManagerImpl
	::GetCharacter() noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	CORE_TOOLS_ASSERTION_4(false, "CWriteFileManageImpl��ֹ����GetCharacter��");

	return System::g_CFileError;
}

bool CoreTools::CWriteFileManagerImpl
	::UnGetCharacter(int character) noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	CORE_TOOLS_ASSERTION_4(false, "CWriteFileManageImpl��ֹ����UnGetCharacter��");

	SYSTEM_UNUSED_ARG(character);

	return false;
}

string CoreTools::CWriteFileManagerImpl
	::GetString(int count)
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	CORE_TOOLS_ASSERTION_4(false, "CWriteFileManageImpl��ֹ����GetString��");

	SYSTEM_UNUSED_ARG(count);

	return "";
}


