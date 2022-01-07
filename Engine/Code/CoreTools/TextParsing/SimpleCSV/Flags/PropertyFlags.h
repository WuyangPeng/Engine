///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/19 19:44)

#ifndef CORE_TOOLS_TEXT_PARSING_PROPERTY_FLAGS_H
#define CORE_TOOLS_TEXT_PARSING_PROPERTY_FLAGS_H

#include "System/Helper/ConfigMacro.h"

namespace CoreTools
{
    namespace SimpleCSV
    {
        enum class Property
        {
            Title,
            Subject,
            Creator,
            Keywords,
            Description,
            LastModifiedBy,
            LastPrinted,
            CreationDate,
            ModificationDate,
            Category,
            Application,
            DocSecurity,
            ScaleCrop,
            Manager,
            Company,
            LinksUpToDate,
            SharedDoc,
            HyperlinkBase,
            HyperlinksChanged,
            AppVersion
        };
    }
}

#endif  // CORE_TOOLS_TEXT_PARSING_PROPERTY_FLAGS_H