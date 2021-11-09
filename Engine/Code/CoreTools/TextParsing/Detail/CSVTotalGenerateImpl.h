///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.2.5 (2021/10/23 22:11)

#ifndef CORE_TOOLS_TEXT_PARSING_CSV_TOTAL_GENERATE_IMPL_H
#define CORE_TOOLS_TEXT_PARSING_CSV_TOTAL_GENERATE_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/TextParsing/CSVHead.h"
#include "CoreTools/TextParsing/TextParsingInternalFwd.h"

#include <vector>

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE CSVTotalGenerateImpl
    {
    public:
        using ClassType = CSVTotalGenerateImpl;
        using String = System::String;
        using FactoryType = CSVTotalGenerateFactory;
        using CSVHeadContainer = std::vector<CSVHead>;

    public:
        explicit CSVTotalGenerateImpl(const String& nameSpace, const CSVHeadContainer& csvHeadContainer);
        virtual ~CSVTotalGenerateImpl() noexcept = default;
        CSVTotalGenerateImpl(const CSVTotalGenerateImpl& rhs) = default;
        CSVTotalGenerateImpl& operator=(const CSVTotalGenerateImpl& rhs) = default;
        CSVTotalGenerateImpl(CSVTotalGenerateImpl&& rhs) noexcept = default;
        CSVTotalGenerateImpl& operator=(CSVTotalGenerateImpl&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        virtual void GenerateFile(const String& directory) const;

    protected:
        NODISCARD String GenerateCopyright() const;
        NODISCARD String GenerateNewLine() const;
        NODISCARD String GenerateHeaderGuard() const;
        NODISCARD String GenerateContainerHeaderGuard() const;
        NODISCARD String GenerateHeaderGuardEndif() const;

        NODISCARD String GenerateHead() const;
        NODISCARD String GenerateFwdHead() const;
        NODISCARD String GenerateContainerHead() const;
        NODISCARD String GenerateContainerSourceHead() const;
        NODISCARD String GenerateNameSpace() const;
        NODISCARD String GenerateFwd() const;
        NODISCARD String GenerateContainerClassName() const;
        NODISCARD String GenerateContainerDefaultFunction() const;
        NODISCARD String GenerateContainerDefaultFunctionDefinition() const;
        NODISCARD String GenerateContainerFunction() const;
        NODISCARD String GenerateContainerFunctionDefinition() const;
        NODISCARD String GenerateContainerMember() const;


    private:
        NODISCARD String GetOldContent(const String& fileName) const;

        NODISCARD virtual String GetFileSuffix() const = 0;
        NODISCARD virtual String GetContent() const = 0;

    private:
        String nameSpace;
        CSVHeadContainer csvHeadContainer;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_CSV_TOTAL_GENERATE_IMPL_H