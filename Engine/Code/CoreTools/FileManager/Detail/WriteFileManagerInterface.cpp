///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/09 1:44)

#include "CoreTools/CoreToolsExport.h"

#include "FileManagerFactory.h"
#include "WriteFileManagerInterface.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CLASS_INVARIANT_STUB_DEFINE(CoreTools, WriteFileManagerInterface)

CoreTools::WriteFileManagerInterface::WriteFileManagerSharedPtr CoreTools::WriteFileManagerInterface::Create(const String& fileName, bool addition)
{
    return FileManagerFactory::CreateWriteFileManager(fileName, addition);
}
