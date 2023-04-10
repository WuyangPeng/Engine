///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.5 (2023/04/03 20:08)

#ifndef CORE_TOOLS_TEXT_PARSING_CONTAINER_MEMBER_PARSING_H
#define CORE_TOOLS_TEXT_PARSING_CONTAINER_MEMBER_PARSING_H

#include "CoreTools/CoreToolsDll.h"

#include "Parsing.h"
#include "CoreTools/TextParsing/CSV/CSVHead.h"

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE ContainerMemberParsing : public Parsing
    {
    public:
        using ClassType = ContainerMemberParsing;
        using ParentType = Parsing;
        using ContainerMemberParsingSharedPtr = std::shared_ptr<ContainerMemberParsing>;

    public:
        NODISCARD static ContainerMemberParsingSharedPtr Create(const CSVHead& csvHead);

    protected:
        explicit ContainerMemberParsing(CSVHead csvHead) noexcept;

    public:
        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD virtual String GenerateMember() const = 0;

    protected:
        NODISCARD CSVHead GetCSVHead() const noexcept;
        NODISCARD String GetCSVClassName() const;

    private:
        CSVHead head;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_CONTAINER_MEMBER_PARSING_H