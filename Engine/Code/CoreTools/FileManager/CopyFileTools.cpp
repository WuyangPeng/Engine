/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/01 10:49)

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
