///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.4 (2023/03/09 11:08)

#ifndef CORE_TOOLS_TEXT_PARSING_CSV_TOTAL_GENERATE_IMPL_H
#define CORE_TOOLS_TEXT_PARSING_CSV_TOTAL_GENERATE_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/TextParsing/CSV/CSVHead.h"
#include "CoreTools/TextParsing/TextParsingInternalFwd.h"

#include <map>
#include <set>

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
        CSVTotalGenerateImpl(String nameSpace, CSVHeadContainer csvHeadContainer) noexcept;
        virtual ~CSVTotalGenerateImpl() noexcept = default;
        CSVTotalGenerateImpl(const CSVTotalGenerateImpl& rhs) = default;
        CSVTotalGenerateImpl& operator=(const CSVTotalGenerateImpl& rhs) = default;
        CSVTotalGenerateImpl(CSVTotalGenerateImpl&& rhs) noexcept = default;
        CSVTotalGenerateImpl& operator=(CSVTotalGenerateImpl&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        virtual void GenerateFile(const String& directory) const;

    protected:
        NODISCARD static String GenerateCopyright();
        NODISCARD static String GenerateNewLine();
        NODISCARD static String GenerateFwdHead();

        NODISCARD String GenerateHeaderGuard() const;
        NODISCARD String GenerateContainerHeaderGuard() const;
        NODISCARD String GenerateHeaderGuardEndif() const;

        NODISCARD String GenerateHead() const;   
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
        using EnumType = std::set<String>;
        using DataType = std::map<String, CSVHead>;

    private:
        NODISCARD static String GetOldContent(const String& fileName);

        NODISCARD static String GenerateEnumHead(const EnumType& enumType);
        NODISCARD static String GenerateDataHead(const DataType& dataType);

        NODISCARD static String GenerateEnumFwd(const EnumType& enumType);
        NODISCARD static String GenerateDataFwd(const DataType& dataType);

        NODISCARD virtual String GetFileSuffix() const = 0;
        NODISCARD virtual String GetContent() const = 0;

    private:
        String nameSpace;
        CSVHeadContainer csvHeadContainer;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_CSV_TOTAL_GENERATE_IMPL_H