///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.5 (2023/09/22 13:52)

#include "CoreTools/CoreToolsExport.h"

#include "FileManagerFactory.h"
#include "WriteFileManagerInterface.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CLASS_INVARIANT_STUB_DEFINE(CoreTools, WriteFileManagerInterface)

CoreTools::WriteFileManagerInterface::WriteFileManagerSharedPtr CoreTools::WriteFileManagerInterface::Create(const String& fileName, bool addition)
{
    return FileManagerFactory::CreateWriteFileManager(fileName, addition);
}
