/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/02 22:51)

#ifndef CORE_TOOLS_TEXT_PARSING_CSV_CSV_GENERATE_CONTAINER_SOURCE_FILE_H
#define CORE_TOOLS_TEXT_PARSING_CSV_CSV_GENERATE_CONTAINER_SOURCE_FILE_H

#include "CoreTools/CoreToolsDll.h"

#include "CSVGenerateImpl.h"

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE CSVGenerateContainerSourceFile final : public CSVGenerateImpl
    {
    public:
        using ClassType = CSVGenerateContainerSourceFile;
        using ParentType = CSVGenerateImpl;

    public:
        CSVGenerateContainerSourceFile(const CSVHead& csvHead, const CodeMappingAnalysis& codeMappingAnalysis) noexcept;

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        NODISCARD String GetSuffix() const override;
        NODISCARD String GetFilePrefix() const override;
        NODISCARD String GetFileSuffix() const override;
        NODISCARD String GetContent(const String& codeDirectory) const override;

        NODISCARD String GetFirstContainerDefineReplace() const;
        NODISCARD String GetEntityContainerIncludeReplace() const;
        NODISCARD String GetCallUniqueReplace() const;
        NODISCARD String GetUniqueFunctionDefineReplace() const;
        NODISCARD String GetLoadFunctionDefineReplace() const;
        NODISCARD String GetShrinkToFitCallReplace() const;
        NODISCARD String GetFirstContainerReturnReplace() const;
        NODISCARD String GetSharedPtrDefineReplace() const;
        NODISCARD String GetContainerByKeyDefineReplace() const;
        NODISCARD String GetOriginalContainerDefineReplace() const;
        NODISCARD String GetContainerSizeDefineReplace() const;
        NODISCARD String GetUniqueDefineReplace() const;
        NODISCARD String GetIsVectorReplace() const;
        NODISCARD String GetIsMapReplace() const;
        NODISCARD String GetSharedPtrDefineReturnReplace() const;

    private:
        String templateName;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_CSV_CSV_GENERATE_CONTAINER_SOURCE_FILE_H