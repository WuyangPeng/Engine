// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.1 (2020/01/21 15:52)

#include "CoreTools/CoreToolsExport.h"

#include "FileOutStream.h"
#include "OutTopLevel.h"
#include "CoreTools/FileManager/FileBuffer.h"
#include "CoreTools/FileManager/CFileManagerHelper.h"
#include "CoreTools/Base/Version.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

#include "System/Helper/PragmaWarning/NumericCast.h"

using std::string;

#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26486)

CoreTools::FileOutStream
	::FileOutStream(const OutTopLevel& topLevel)
	:m_BufferOutStream{ topLevel }
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, FileOutStream)

void CoreTools::FileOutStream
	::Save(const String& fileName)
{
	CORE_TOOLS_CLASS_IS_VALID_9;

	auto version = Version::GetVersion();

	// 保存该文件的版本号到磁盘。
	CFileManagerHelper::SaveIntoFile(fileName, true, boost::numeric_cast<int>(version.size()), version.c_str());

	auto fileBufferPtr = m_BufferOutStream.GetBufferOutStreamInformation();

	// 保存场景图从内存到磁盘。
	CFileManagerHelper::AppendToFile(fileName, true, boost::numeric_cast<int>(fileBufferPtr->GetSize()), fileBufferPtr->GetBufferBegin());
}



#include STSTEM_WARNING_POP