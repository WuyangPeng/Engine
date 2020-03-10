// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.1 (2020/01/19 17:03)

#include "CoreTools/CoreToolsExport.h"

#include "WriteFileHandleImpl.h"
#include "System/Helper/UnusedMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

#include <boost/numeric/conversion/cast.hpp>

using boost::numeric_cast;

CoreTools::WriteFileHandleImpl
	::WriteFileHandleImpl(const String& fileName, FileHandleCreationDisposition creation)
	:ParentType{ fileName, FileHandleDesiredAccess::Write, FileHandleShareMode::Prevents,creation }
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CoreTools::WriteFileHandleImpl
	::~WriteFileHandleImpl()
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
bool CoreTools::WriteFileHandleImpl
	::IsValid() const noexcept
{
	if (ParentType::IsValid() && InterfaceType::IsValid())
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

int CoreTools::WriteFileHandleImpl
	::GetFileByteSize() const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	return numeric_cast<int>(ParentType::GetFileLength());
}

void CoreTools::WriteFileHandleImpl
	::Write(size_t itemSize, const void* data)
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	CORE_TOOLS_ASSERTION_2(itemSize == 1 || itemSize == 2 || itemSize == 4 || itemSize == 8, "大小必须为1，2，4或8\n");
	CORE_TOOLS_ASSERTION_0(data != nullptr, "数据无效");

	Write(itemSize, 1, data);
}

void CoreTools::WriteFileHandleImpl
	::Write(size_t itemSize, size_t itemsNumber, const void* data)
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	CORE_TOOLS_ASSERTION_2(itemSize == 1 || itemSize == 2 || itemSize == 4 || itemSize == 8, "大小必须为1，2，4或8\n");
	CORE_TOOLS_ASSERTION_0(0 < itemsNumber && data != nullptr, "数据无效");

	WriteToFile(itemSize, itemsNumber, data);
}

void CoreTools::WriteFileHandleImpl
	::ReadFromFile(size_t itemSize, size_t itemsNumber, void* data)
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	CORE_TOOLS_ASSERTION_0(false, "WriteFileHandleImpl禁止调用ReadFromFile！");

	SYSTEM_UNUSED_ARG(itemSize);
	SYSTEM_UNUSED_ARG(itemsNumber);
	SYSTEM_UNUSED_ARG(data);
}





