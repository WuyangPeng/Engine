///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/19 13:35)

#ifndef CORE_TOOLS_TEXT_PARSING_SHARED_PTR_USING_PARSING_H
#define CORE_TOOLS_TEXT_PARSING_SHARED_PTR_USING_PARSING_H

#include "CoreTools/CoreToolsDll.h"

#include "Parsing.h"
#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/TextParsing/TextParsingFwd.h"

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE SharedPtrUsingParsing : public Parsing
    {
    public:
        using ClassType = SharedPtrUsingParsing;
        using ParentType = Parsing;
        using StringView = System::StringView;
        using SharedPtrUsingParsingUniquePtr = std::unique_ptr<SharedPtrUsingParsing>;

    public:
        NODISCARD static SharedPtrUsingParsingUniquePtr Create(CSVFormatType csvFormatType, int indentationCount, const String& className, const String& keyTypeDescribe);

    protected:
        explicit SharedPtrUsingParsing(int indentationCount, const String& className);

    public:
        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD String GenerateSharedPtr(StringView suffix = StringView{}) const;
        NODISCARD String GenerateSharedPtrContainer(StringView suffix = StringView{}) const;
        NODISCARD String GenerateSharedPtrMappingContainer(const String& keyTypeDescribe, StringView mappingName) const;

        NODISCARD virtual String GenerateSharedPtrUsing() const = 0;

    private:
        String className;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_SHARED_PTR_USING_PARSING_H