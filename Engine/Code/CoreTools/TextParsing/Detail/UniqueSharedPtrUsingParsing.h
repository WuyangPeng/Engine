///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.4 (2023/03/09 09:21)

#ifndef CORE_TOOLS_TEXT_PARSING_UNIQUE_SHARED_PTR_USING_PARSING_H
#define CORE_TOOLS_TEXT_PARSING_UNIQUE_SHARED_PTR_USING_PARSING_H

#include "CoreTools/CoreToolsDll.h"

#include "SharedPtrUsingParsing.h"

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE UniqueSharedPtrUsingParsing final : public SharedPtrUsingParsing
    {
    public:
        using ClassType = UniqueSharedPtrUsingParsing;
        using ParentType = SharedPtrUsingParsing;

    public:
        explicit UniqueSharedPtrUsingParsing(int indentationCount, const String& className);

        CLASS_INVARIANT_FINAL_DECLARE;

        NODISCARD String GenerateSharedPtrUsing() const override;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_UNIQUE_SHARED_PTR_USING_PARSING_H