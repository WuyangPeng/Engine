///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.5 (2023/04/03 20:10)

#ifndef CORE_TOOLS_TEXT_PARSING_PARSING_H
#define CORE_TOOLS_TEXT_PARSING_PARSING_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE Parsing
    {
    public:
        using ClassType = Parsing;
        using String = System::String;
        using StringView = System::StringView;
        using SplitType = std::vector<String>;

    public:
        explicit Parsing(int indentationCount = 0) noexcept;
        virtual ~Parsing() noexcept = default;

        Parsing(const Parsing& rhs) noexcept = default;
        Parsing& operator=(const Parsing& rhs) noexcept = default;
        Parsing(Parsing&& rhs) noexcept = default;
        Parsing& operator=(Parsing&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

    public:
        NODISCARD String GenerateFunctionBeginBrackets(int addIndentationCount = 0) const;
        NODISCARD String GenerateFunctionEndBrackets(int addIndentationCount = 0) const;
        NODISCARD String GeneratePublic() const;

        NODISCARD static SplitType GetSplitComma(const String& column);

    protected:
        NODISCARD String GenerateUserSelfClassIsValid9(int addIndentationCount = 0) const;
        NODISCARD String GenerateUserSelfClassIsValid1(int addIndentationCount = 0) const;
        NODISCARD String GenerateUserClassIsValidConst9(int addIndentationCount = 0) const;
        NODISCARD String GenerateUserClassIsValidConst1(int addIndentationCount = 0) const;
        NODISCARD String GenerateOpenClassInvariant() const;
        NODISCARD String GenerateOpenClassInvariantEndif() const;
        NODISCARD String GenerateParentTypeIsValid(int addIndentationCount = 0) const;
        NODISCARD String GenerateReturnTrue(int addIndentationCount = 0) const;
        NODISCARD String GenerateReturnFalse(int addIndentationCount = 0) const;
        NODISCARD String GenerateElse(int addIndentationCount = 0) const;
        NODISCARD String GenerateClassEndBrackets(int addIndentationCount = 0) const;
        NODISCARD String GenerateReturnIterSecond() const;
        NODISCARD String GenerateIndentation(int addIndentationCount = 0) const;

    private:
        int indentationCount;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_PARSING_H