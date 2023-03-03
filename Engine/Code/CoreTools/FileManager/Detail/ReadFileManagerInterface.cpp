///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.3 (2023/03/02 10:54)

#include "CoreTools/CoreToolsExport.h"

#include "FileManagerFactory.h"
#include "ReadFileManagerInterface.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CLASS_INVARIANT_STUB_DEFINE(CoreTools, ReadFileManagerInterface)

CoreTools::ReadFileManagerInterface::ReadFileManagerSharedPtr CoreTools::ReadFileManagerInterface::Create(const String& fileName)
{
    return FileManagerFactory::CreateReadFileManager(fileName);
}
