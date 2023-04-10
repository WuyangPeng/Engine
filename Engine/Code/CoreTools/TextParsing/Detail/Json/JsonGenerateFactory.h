///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.5 (2023/04/03 20:05)

#ifndef CORE_TOOLS_TEXT_PARSING_JSON_GENERATE_FACTORY_H
#define CORE_TOOLS_TEXT_PARSING_JSON_GENERATE_FACTORY_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/TextParsing/TextParsingInternalFwd.h"

#include <memory>

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE JsonGenerateFactory final
    {
    public:
        using ClassType = JsonGenerateFactory;
        using JsonGenerateSharedPtr = std::shared_ptr<JsonGenerateImpl>;
        using String = System::String;

    public:
        NODISCARD static JsonGenerateSharedPtr Create(const JsonHead& jsonHead, JsonGenerateType csvGenerateType);
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_JSON_GENERATE_FACTORY_H