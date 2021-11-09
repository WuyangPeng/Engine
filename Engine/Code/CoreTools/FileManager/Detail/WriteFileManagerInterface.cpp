///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.7.2.3 (2021/09/03 14:28)

#include "CoreTools/CoreToolsExport.h"

#include "FileManagerFactory.h"
#include "WriteFileManagerInterface.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CLASS_INVARIANT_STUB_DEFINE(CoreTools, WriteFileManagerInterface)

CoreTools::WriteFileManagerInterface::WriteFileManagerSharedPtr CoreTools::WriteFileManagerInterface::Create(const String& fileName, bool addition)
{
    return FileManagerFactory::CreateWriteFileManager(fileName, addition);
}
