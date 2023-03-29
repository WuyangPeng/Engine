///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.4 (2023/03/09 09:11)

#ifndef CORE_TOOLS_TEXT_PARSING_DEFAULT_CONTAINER_MEMBER_PARSING_H
#define CORE_TOOLS_TEXT_PARSING_DEFAULT_CONTAINER_MEMBER_PARSING_H

#include "CoreTools/CoreToolsDll.h"

#include "ContainerMemberParsing.h"

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE DefaultContainerMemberParsing final : public ContainerMemberParsing
    {
    public:
        using ClassType = DefaultContainerMemberParsing;
        using ParentType = ContainerMemberParsing;

    public:
        explicit DefaultContainerMemberParsing(const CSVHead& csvHead) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD String GenerateMember() const override;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_DEFAULT_CONTAINER_MEMBER_PARSING_H