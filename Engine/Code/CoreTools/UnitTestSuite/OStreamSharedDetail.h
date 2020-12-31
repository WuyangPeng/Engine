//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.0 (2020/10/23 14:01)

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
