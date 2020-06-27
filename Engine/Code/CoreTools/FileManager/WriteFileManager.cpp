// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.1 (2020/01/19 17:16)

#include "CoreTools/CoreToolsExport.h"

#include "WriteFileManager.h"
#include "Detail/FileManagerFactory.h"
#include "Detail/WriteFileManagerInterface.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

#include "System/Helper/PragmaWarning/NumericCast.h"
#include <array>

using std::string;
using std::array;

CoreTools::WriteFileManager
	::WriteFileManager(const String& fileName)
	:m_Impl{ FileManagerFactory::CreateWriteFileManage(fileName) }
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(CoreTools, WriteFileManager)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, WriteFileManager, GetFileByteSize, int)

void CoreTools::WriteFileManager
	::Write(size_t itemSize, const void* data)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->Write(itemSize, data);
}

void CoreTools::WriteFileManager
	::Write(size_t itemSize, size_t itemsNumber, const void* data)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->Write(itemSize, itemsNumber, data);
}

void CoreTools::WriteFileManager
	::SaveStdString(const string& name)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	constexpr auto alignedLength = 4;

	auto length = boost::numeric_cast<int>(name.size());
	Write(sizeof(int), &length);

	if (0 < length)
	{
		Write(sizeof(char), length, name.c_str());

		// 字符串被写入四个字节的倍数。	
		auto padding = (length % alignedLength);
		if (0 < padding)
		{
			constexpr array<char, alignedLength> zero{};
			padding = alignedLength - padding;

			Write(sizeof(char), padding, zero.data());
		}
	}
}
