///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/22 13:52)

#include "CoreTools/CoreToolsExport.h"

#include "CopyFileTools.h"
#include "Detail/CopyFileToolsFactory.h"
#include "Detail/CopyFileToolsImpl.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::CopyFileTools::CopyFileTools(const String& inFileName, const String& outFileName)
    : impl{ ImplCreateUseFactory::Default, inFileName, outFileName }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, CopyFileTools)
