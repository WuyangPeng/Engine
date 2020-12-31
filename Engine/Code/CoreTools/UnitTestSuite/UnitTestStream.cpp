//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.0 (2020/10/23 14:59)

#include "CoreTools/CoreToolsExport.h"

#include "UnitTestStream.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::UnitTestStream::UnitTestStream(const OStreamShared& streamShared) noexcept
    : m_StreamShared{ streamShared }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, UnitTestStream)

CoreTools::OStreamShared& CoreTools::UnitTestStream::GetStream() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    return m_StreamShared;
}

bool CoreTools::UnitTestStream::IsStreamSharedFile() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    return m_StreamShared.IsFile();
}
