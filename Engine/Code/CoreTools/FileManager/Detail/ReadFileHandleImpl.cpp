// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.1 (2020/01/19 17:02)

#include "CoreTools/CoreToolsExport.h"

#include "ReadFileHandleImpl.h"
#include "System/Helper/UnusedMacro.h"
#include "System/FileManager/Flags/FileFlags.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/ClassInvariant/Noexcept.h"

using boost::numeric_cast;

CoreTools::ReadFileHandleImpl
	::ReadFileHandleImpl(const String& fileName)
	:ParentType{ fileName, FileHandleDesiredAccess::Read,FileHandleShareMode::ShareRead,FileHandleCreationDisposition::OpenExisting }
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

 

#ifdef OPEN_CLASS_INVARIANT
bool CoreTools::ReadFileHandleImpl
	::IsValid() const noexcept
{
	if (ParentType::IsValid() && InterfaceType::IsValid())
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

int CoreTools::ReadFileHandleImpl
 	::GetFileByteSize() const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	return numeric_cast<int>(ParentType::GetFileLength());
}

void CoreTools::ReadFileHandleImpl
	::Read(size_t itemSize, void* data)
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	CORE_TOOLS_ASSERTION_2(itemSize == 1 || itemSize == 2 || itemSize == 4 || itemSize == 8, "��С����Ϊ1��2��4��8\n");
	CORE_TOOLS_ASSERTION_0(data != nullptr, "������Ч");

	Read(itemSize, 1, data);
}

void CoreTools::ReadFileHandleImpl
	::Read(size_t itemSize, size_t itemsNumber, void* data)
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	CORE_TOOLS_ASSERTION_2(itemSize == 1 || itemSize == 2 || itemSize == 4 || itemSize == 8, "��С����Ϊ1��2��4��8\n");
	CORE_TOOLS_ASSERTION_0(0 < itemsNumber && data != nullptr, "������Ч");

	ReadFromFile(itemSize, itemsNumber, data);
}

void CoreTools::ReadFileHandleImpl
	::WriteToFile(size_t itemSize, size_t itemsNumber, const void* data)
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	CORE_TOOLS_ASSERTION_4(false, "ReadFileHandleImpl��ֹ����WriteToFile��");

	CoreTools::DoNothing();

	SYSTEM_UNUSED_ARG(itemSize);
	SYSTEM_UNUSED_ARG(itemsNumber);
	SYSTEM_UNUSED_ARG(data);
}

void CoreTools::ReadFileHandleImpl
	::AppendToFile(size_t itemSize, size_t itemsNumber, const void* data)
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	CORE_TOOLS_ASSERTION_4(false, "ReadFileHandleImpl��ֹ����AppendToFile��");
	CoreTools::DoNothing();

	SYSTEM_UNUSED_ARG(itemSize);
	SYSTEM_UNUSED_ARG(itemsNumber);
	SYSTEM_UNUSED_ARG(data);
}


