///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.4 (2023/03/09 11:07)

#ifndef CORE_TOOLS_TEXT_PARSING_JSON_TOTAL_GENERATE_FACTORY_H
#define CORE_TOOLS_TEXT_PARSING_JSON_TOTAL_GENERATE_FACTORY_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/TextParsing/Json/JsonHead.h"

#include <memory>
#include <vector>

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE JsonTotalGenerateFactory final
    {
    public:
        using ClassType = JsonTotalGenerateFactory;
        using JsonTotalGenerateSharedPtr = std::shared_ptr<JsonTotalGenerateImpl>;
        using String = System::String;
        using JsonHeadContainer = std::vector<JsonHead>;

    public:
        NODISCARD static JsonTotalGenerateSharedPtr Create(const String& nameSpace, const JsonHeadContainer& jsonHeadContainer, JsonTotalGenerateType jsonTotalGenerateType);
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_JSON_TOTAL_GENERATE_FACTORY_H