///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.4 (2023/03/09 09:21)

#ifndef CORE_TOOLS_TEXT_PARSING_UNIQUE_CONTAINER_MEMBER_PARSING_H
#define CORE_TOOLS_TEXT_PARSING_UNIQUE_CONTAINER_MEMBER_PARSING_H

#include "CoreTools/CoreToolsDll.h"

#include "ContainerMemberParsing.h"

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE UniqueContainerMemberParsing : public ContainerMemberParsing
    {
    public:
        using ClassType = UniqueContainerMemberParsing;
        using ParentType = ContainerMemberParsing;

    public:
        explicit UniqueContainerMemberParsing(const CSVHead& csvHead) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD String GenerateMember() const override;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_UNIQUE_CONTAINER_MEMBER_PARSING_H