///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/19 13:31)

#ifndef CORE_TOOLS_TEXT_PARSING_DEFAULT_SHARED_PTR_USING_PARSING_H
#define CORE_TOOLS_TEXT_PARSING_DEFAULT_SHARED_PTR_USING_PARSING_H

#include "CoreTools/CoreToolsDll.h"

#include "SharedPtrUsingParsing.h"

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE DefaultSharedPtrUsingParsing final : public SharedPtrUsingParsing
    {
    public:
        using ClassType = DefaultSharedPtrUsingParsing;
        using ParentType = SharedPtrUsingParsing;

    public:
        explicit DefaultSharedPtrUsingParsing(int indentationCount, const String& className);

        CLASS_INVARIANT_FINAL_DECLARE;

        NODISCARD String GenerateSharedPtrUsing() const final;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_DEFAULT_SHARED_PTR_USING_PARSING_H