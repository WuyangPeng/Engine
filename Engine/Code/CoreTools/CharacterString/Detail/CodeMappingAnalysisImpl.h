///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：1.0.0.0 (2023/11/08 10:13)

#ifndef CORE_TOOLS_CHARACTER_STRING_CODE_MAPPING_ANALYSIS_IMPL_H
#define CORE_TOOLS_CHARACTER_STRING_CODE_MAPPING_ANALYSIS_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/PragmaWarning/PropertyTree.h"
#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/CharacterString/CodeMapping.h"
#include "CoreTools/Exception/ExceptionFwd.h"

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE CodeMappingAnalysisImpl final
    {
    public:
        using ClassType = CodeMappingAnalysisImpl;

        using String = System::String;

    public:
        explicit CodeMappingAnalysisImpl(const std::wstring& fileName);
        explicit CodeMappingAnalysisImpl(std::string fileName);

        CLASS_INVARIANT_DECLARE;

        NODISCARD String GetElement(const String& codeKey) const;

    private:
        using BasicTree = boost::property_tree::basic_ptree<std::string, std::string>;

    private:
        void Analysis();
        void AnalysisJson();
        void AnalysisMain();
        void AnalysisMain(const std::string& codeKey, const BasicTree& element);
        void InsertElement(const std::string& codeKey, const BasicTree& element);
        static void PrintErrorLog(const std::string& codeKey, const Error& error) noexcept;

    private:
        std::string fileName;
        CodeMapping codeMapping;
        BasicTree mainTree;
    };
}

#endif  // CORE_TOOLS_CHARACTER_STRING_CODE_MAPPING_ANALYSIS_IMPL_H
