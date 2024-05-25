/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.9 (2024/04/28 21:51)

#include "BufferIOTesting.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

const std::string CoreTools::BufferIOTesting::bufferIOContent = "BufferIO Testing Text";

CoreTools::BufferIOTesting::BufferIOTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, BufferIOTesting)

std::string CoreTools::BufferIOTesting::GetBufferIOContent()
{
    return bufferIOContent;
}

size_t CoreTools::BufferIOTesting::GetBufferIOContentSize() noexcept
{
    return bufferIOContent.size();
}

int CoreTools::BufferIOTesting::GetBufferSize()
{
    return boost::numeric_cast<int>(bufferIOContent.size() + sizeof(decltype(bufferIOContent.size())));
}
