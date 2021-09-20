//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.1 (2020/10/14 13:52)

#include "CoreTools/CoreToolsExport.h"

#include "ReadFileManagerInterface.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "FileManagerFactory.h"

CLASS_INVARIANT_STUB_DEFINE(CoreTools, ReadFileManagerInterface)

CoreTools::ReadFileManagerInterface::ReadFileManageInterfacePtr CoreTools::ReadFileManagerInterface::Create(const String& fileName)
{
    return FileManagerFactory::CreateReadFileManage(fileName);
}
