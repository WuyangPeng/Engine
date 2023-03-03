///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.3 (2023/03/02 10:54)

#include "CoreTools/CoreToolsExport.h"

#include "FileManagerFactory.h"
#include "ReadFileManagerInterface.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CLASS_INVARIANT_STUB_DEFINE(CoreTools, ReadFileManagerInterface)

CoreTools::ReadFileManagerInterface::ReadFileManagerSharedPtr CoreTools::ReadFileManagerInterface::Create(const String& fileName)
{
    return FileManagerFactory::CreateReadFileManager(fileName);
}
