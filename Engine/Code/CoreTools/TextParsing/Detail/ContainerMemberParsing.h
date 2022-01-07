///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/19 13:17)

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
        explicit ContainerMemberParsing(const CSVHead& csvHead) noexcept;

    public:
        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD virtual String GenerateMember() const = 0;

    protected:
        NODISCARD CSVHead GetCSVHead() const noexcept;
        NODISCARD String GetCSVClassName() const;

    private:
        CSVHead m_CSVHead;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_CONTAINER_MEMBER_PARSING_H