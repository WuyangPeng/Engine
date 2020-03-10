// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.1 (2020/01/19 14:52)

#include "CoreTools/CoreToolsExport.h"

#include "CReadFileManagerImpl.h"
#include "System/Helper/UnusedMacro.h"
#include "CoreTools/FileManager/Endian.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

using std::string;

CoreTools::CReadFileManagerImpl
	::CReadFileManagerImpl(const String& fileName)
	:ParentType{ fileName,SYSTEM_TEXT("rbS") }
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CoreTools::CReadFileManagerImpl
	::~CReadFileManagerImpl()
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
bool CoreTools::CReadFileManagerImpl
	::IsValid() const noexcept
{
	if (ParentType::IsValid() && InterfaceType::IsValid())
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

int CoreTools::CReadFileManagerImpl
	::GetFileByteSize() const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	return ParentType::GetFileLength();
}

void CoreTools::CReadFileManagerImpl
	::Read(size_t itemSize, void* data)
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	CORE_TOOLS_ASSERTION_2(itemSize == 1 || itemSize == 2 || itemSize == 4 || itemSize == 8, "��С����Ϊ1��2��4��8\n");
	CORE_TOOLS_ASSERTION_0(data != nullptr, "������Ч");

	Read(itemSize, 1, data);
}

void CoreTools::CReadFileManagerImpl
	::Read(size_t itemSize, size_t itemsNumber, void* data)
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	CORE_TOOLS_ASSERTION_2(itemSize == 1 || itemSize == 2 || itemSize == 4 || itemSize == 8, "��С����Ϊ1��2��4��8\n");
	CORE_TOOLS_ASSERTION_0(0 < itemsNumber && data != nullptr, "������Ч");

	auto readNumber = ReadFromFile(itemSize, itemsNumber, data);

	if (readNumber != itemsNumber)
	{
		THROW_EXCEPTION(SYSTEM_TEXT("�����ļ����ݴ���"));
	}

#ifdef SYSTEM_BIG_ENDIAN
	if (1 < itemSize)
	{
		Endian::SwapByteOrder(itemSize, itemsNumber, data);
	}
#endif // SYSTEM_BIG_ENDIAN
}

size_t CoreTools::CReadFileManagerImpl
	::WriteToFile(size_t itemSize, size_t itemsNumber, const void* data) noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	CORE_TOOLS_ASSERTION_4(false, "CReadFileManageImpl��ֹ����WriteToFile��");

	SYSTEM_UNUSED_ARG(itemSize);
	SYSTEM_UNUSED_ARG(itemsNumber);
	SYSTEM_UNUSED_ARG(data);

	return 0;
}

bool CoreTools::CReadFileManagerImpl
	::PutCharacter(int character) noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	CORE_TOOLS_ASSERTION_4(false, "CReadFileManageImpl��ֹ����PutCharacter��");

	SYSTEM_UNUSED_ARG(character);

	return false;
}

bool CoreTools::CReadFileManagerImpl
	::PutString(const string& str) noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	CORE_TOOLS_ASSERTION_4(false, "CReadFileManageImpl��ֹ����PutString��");

	SYSTEM_UNUSED_ARG(str);

	return false;
}


