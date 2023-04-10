///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.5 (2023/04/03 17:24)

#ifndef CORE_TOOLS_UNIT_TEST_SUITE_OSTREAM_SHARED_DETAIL_H
#define CORE_TOOLS_UNIT_TEST_SUITE_OSTREAM_SHARED_DETAIL_H

#include "OStreamShared.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

template <typename T>
CoreTools::OStreamShared& CoreTools::OStreamShared::operator<<(const T& value)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    GetStream() << value;

    return *this;
}

#endif  // CORE_TOOLS_UNIT_TEST_SUITE_OSTREAM_SHARED_DETAIL_H
