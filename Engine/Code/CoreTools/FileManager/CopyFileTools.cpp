//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.1 (2020/10/14 14:18)

#include "CoreTools/CoreToolsExport.h"

#include "../Contract/Flags/ImplFlags.h"
#include "CopyFileTools.h"
#include "Detail/CopyFileToolsImpl.h"
#include "Detail/CopyFileToolsFactory.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::CopyFileTools::CopyFileTools(const String& inFileName, const String& outFileName)
    : impl{ ImplCreateUseFactory::Default, inFileName, outFileName }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, CopyFileTools)
