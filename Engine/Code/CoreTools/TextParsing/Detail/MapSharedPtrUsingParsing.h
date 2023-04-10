///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.5 (2023/04/03 20:10)

#ifndef CORE_TOOLS_TEXT_PARSING_MAP_SHARED_PTR_USING_PARSING_H
#define CORE_TOOLS_TEXT_PARSING_MAP_SHARED_PTR_USING_PARSING_H

#include "CoreTools/CoreToolsDll.h"

#include "SharedPtrUsingParsing.h"

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE MapSharedPtrUsingParsing final : public SharedPtrUsingParsing
    {
    public:
        using ClassType = MapSharedPtrUsingParsing;
        using ParentType = SharedPtrUsingParsing;

    public:
        explicit MapSharedPtrUsingParsing(int indentationCount, const String& className, const String& keyTypeDescribe, StringView mappingName);

        CLASS_INVARIANT_FINAL_DECLARE;

        NODISCARD String GenerateSharedPtrUsing() const override;

    private:
        String keyTypeDescribe;
        StringView mappingName;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_MAP_SHARED_PTR_USING_PARSING_H