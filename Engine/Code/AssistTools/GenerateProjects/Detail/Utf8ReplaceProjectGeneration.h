///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/24 13:34)

#ifndef AssistTools_XX_Utf8ReplaceProjectGeneration_H
#define AssistTools_XX_Utf8ReplaceProjectGeneration_H

#include "AssistTools/AssistToolsDll.h"

#include "ReplaceProjectGeneration.h"

namespace AssistTools
{
    class ASSIST_TOOLS_HIDDEN_DECLARE Utf8ReplaceProjectGeneration : public ReplaceProjectGeneration
    {
    public:
        using ClassType = Utf8ReplaceProjectGeneration;
        using ParentType = ReplaceProjectGeneration;

        using ReplaceType = std::map<String, String>;

    public:
        Utf8ReplaceProjectGeneration(const String& fileName, const GameParameterAnalysis& gameParameterAnalysis, const CodeMappingAnalysis& codeMappingAnalysis);
        Utf8ReplaceProjectGeneration(const String& fileName, const GameParameterAnalysis& gameParameterAnalysis, const CodeMappingAnalysis& codeMappingAnalysis, const ReplaceType& replace);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD String GetTemplateContent() const override;
    };
}

#endif  // AssistTools_XX_Utf8ReplaceProjectGeneration_H
