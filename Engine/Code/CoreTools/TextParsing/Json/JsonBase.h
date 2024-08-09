/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.1.0 (2024/08/09 16:11)

#ifndef CORE_TOOLS_TEXT_PARSING_JSON_JSON_BASE_H
#define CORE_TOOLS_TEXT_PARSING_JSON_JSON_BASE_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/PragmaWarning/PropertyTree.h"
#include "System/Helper/UnicodeUsing.h"

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE JsonBase
    {
    public:
        using ClassType = JsonBase;

        using String = System::String;
        using BasicTree = boost::property_tree::basic_ptree<String, String>;

    public:
        JsonBase() = default;
        virtual ~JsonBase() = default;
        JsonBase(const JsonBase& rhs) noexcept = default;
        JsonBase& operator=(const JsonBase& rhs) noexcept = default;
        JsonBase(JsonBase&& rhs) noexcept = default;
        JsonBase& operator=(JsonBase&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        virtual void Load(BasicTree& mainTree) = 0;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_JSON_JSON_BASE_H