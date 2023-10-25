///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/10/25 14:41)

#ifndef CORE_TOOLS_PROPERTIES_SUITE_SIMPLE_PROPERTY_EXTERNAL_H
#define CORE_TOOLS_PROPERTIES_SUITE_SIMPLE_PROPERTY_EXTERNAL_H

#include "CoreTools/Helper/UserMacro.h"
#include "CoreTools/Properties/SimplePropertyGetExternalDetail.h"
#include "CoreTools/Properties/SimplePropertySetExternalDetail.h"

#include <string>

namespace CoreTools
{
    class SimplePropertyExternal
    {
    public:
        using ClassType = SimplePropertyExternal;
        using GetType = SimplePropertyGetExternal<std::string, const std::string&>;
        using SetType = SimplePropertySetExternal<std::string, std::string&>;

    public:
        SimplePropertyExternal() noexcept;

        CLASS_INVARIANT_DECLARE;

    private:
        std::string value;

    public:
        GetType getType{ value };
        SetType setType{ value };
    };
}

#endif  // CORE_TOOLS_PROPERTIES_SUITE_SIMPLE_PROPERTY_EXTERNAL_H
