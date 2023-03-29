///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.4 (2023/03/10 13:38)

#ifndef CORE_TOOLS_TEXT_PARSING_JSON_GENERATE_IMPL_H
#define CORE_TOOLS_TEXT_PARSING_JSON_GENERATE_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/TextParsing/Json/JsonHead.h"
#include "CoreTools/TextParsing/TextParsingInternalFwd.h"

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE JsonGenerateImpl
    {
    public:
        using ClassType = JsonGenerateImpl;
        using String = System::String;
        using FactoryType = JsonGenerateFactory;

    public:
        explicit JsonGenerateImpl(JsonHead jsonHead) noexcept;
        virtual ~JsonGenerateImpl() noexcept = default;
        JsonGenerateImpl(const JsonGenerateImpl& rhs) noexcept = default;
        JsonGenerateImpl& operator=(const JsonGenerateImpl& rhs) noexcept = default;
        JsonGenerateImpl(JsonGenerateImpl&& rhs) noexcept = default;
        JsonGenerateImpl& operator=(JsonGenerateImpl&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        virtual void GenerateFile(const String& directory) const;

    protected:
        NODISCARD String GetJsonClassName() const;
        NODISCARD static String GetOldContent(const String& fileName);
        NODISCARD JsonHead GetJsonHead() const noexcept;

        NODISCARD static String GenerateCopyright();
        NODISCARD String GenerateHeaderGuard() const;
        NODISCARD String GenerateNameSpace() const;
        NODISCARD String GenerateInnerNameSpaceBegin() const;
        NODISCARD static String GenerateInnerNameSpaceEnd();
        NODISCARD String GenerateHeaderGuardEndif() const;

    private:
        NODISCARD virtual String GetSuffix() const = 0;
        NODISCARD virtual String GetFilePrefix() const = 0;
        NODISCARD virtual String GetFileSuffix() const = 0;
        NODISCARD virtual String GetContent() const = 0;

    private:
        JsonHead jsonHead;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_JSON_GENERATE_IMPL_H