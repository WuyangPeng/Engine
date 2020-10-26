//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.0 (2020/10/22 15:07)

#include "CoreTools/CoreToolsExport.h"

#include "FileOutStream.h"
#include "OutTopLevel.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Base/Version.h"
#include "CoreTools/FileManager/CFileManagerHelper.h"
#include "CoreTools/FileManager/FileBuffer.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

using std::string;

CoreTools::FileOutStream::FileOutStream(const OutTopLevel& topLevel)
    : m_BufferOutStream{ topLevel }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, FileOutStream)

void CoreTools::FileOutStream::Save(const String& fileName)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    const auto version = Version::GetVersion();

    // 保存该文件的版本号到磁盘。
    CFileManagerHelper::SaveIntoFile(fileName, true, boost::numeric_cast<int>(version.size()), version.c_str());

    auto fileBufferPtr = m_BufferOutStream.GetBufferOutStreamInformation();

    // 保存场景图从内存到磁盘。
    CFileManagerHelper::AppendToFile(fileName, true, boost::numeric_cast<int>(fileBufferPtr->GetSize()), fileBufferPtr->GetBufferBegin());
}
