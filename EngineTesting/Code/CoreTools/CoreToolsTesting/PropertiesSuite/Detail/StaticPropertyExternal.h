/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.9 (2024/04/23 12:53)

#ifndef CORE_TOOLS_PROPERTIES_SUITE_STATIC_PROPERTY_EXTERNAL_H
#define CORE_TOOLS_PROPERTIES_SUITE_STATIC_PROPERTY_EXTERNAL_H

#include "CoreTools/Helper/UserMacro.h"
#include "CoreTools/Properties/StaticPropertyGetExternalDetail.h"
#include "CoreTools/Properties/StaticPropertyGetSetDetail.h"
#include "CoreTools/Properties/StaticPropertyGetSetExternalDetail.h"
#include "CoreTools/Properties/StaticPropertySetExternalDetail.h"

#include <string>

namespace CoreTools
{
    class StaticPropertyExternal
    {
    public:
        using ClassType = StaticPropertyExternal;

    public:
        StaticPropertyExternal() noexcept;

        CLASS_INVARIANT_DECLARE;

    private:
        static std::string value;

        NODISCARD static const std::string& GetValue() noexcept;
        static void SetValue(const std::string& aValue);

    public:
        using GetExternalType = StaticPropertyGetExternal<const std::string&, &GetValue>;
        using SetExternalType = StaticPropertySetExternal<const std::string&, &SetValue>;
        using GetSetExternalType = StaticPropertyGetSetExternal<const std::string&, const std::string&, &GetValue, &SetValue>;
        using GetSetType = StaticPropertyGetSet<std::string, const std::string&, const std::string&, ClassType, &GetValue, &SetValue>;

        GetExternalType getExternalType;
        SetExternalType setExternalType;
        GetSetExternalType getSetExternalType;
        GetSetType getSetType;
    };
}

#endif  // CORE_TOOLS_PROPERTIES_SUITE_STATIC_PROPERTY_EXTERNAL_H
