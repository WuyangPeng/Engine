///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/19 13:20)

#ifndef CORE_TOOLS_TEXT_PARSING_DEFAULT_CONTAINER_MEMBER_PARSING_H
#define CORE_TOOLS_TEXT_PARSING_DEFAULT_CONTAINER_MEMBER_PARSING_H

#include "CoreTools/CoreToolsDll.h"

#include "ContainerMemberParsing.h"

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE DefaultContainerMemberParsing : public ContainerMemberParsing
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