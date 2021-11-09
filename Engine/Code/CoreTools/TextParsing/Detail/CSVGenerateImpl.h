///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.2.5 (2021/10/20 13:42)

#ifndef CORE_TOOLS_TEXT_PARSING_CSV_GENERATE_IMPL_H
#define CORE_TOOLS_TEXT_PARSING_CSV_GENERATE_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/TextParsing/CSVHead.h"
#include "CoreTools/TextParsing/TextParsingInternalFwd.h"

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE CSVGenerateImpl
    {
    public:
        using ClassType = CSVGenerateImpl;
        using String = System::String;
        using FactoryType = CSVGenerateFactory;

    public:
        explicit CSVGenerateImpl(const CSVHead& csvHead) noexcept;
        virtual ~CSVGenerateImpl() noexcept = default;
        CSVGenerateImpl(const CSVGenerateImpl& rhs) = default;
        CSVGenerateImpl& operator=(const CSVGenerateImpl& rhs) = default;
        CSVGenerateImpl(CSVGenerateImpl&& rhs) noexcept = default;
        CSVGenerateImpl& operator=(CSVGenerateImpl&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        virtual void GenerateFile(const String& directory) const;

    protected:
        NODISCARD String GetCSVClassName() const;
        NODISCARD String GetOldContent(const String& fileName) const;
        NODISCARD CSVFormatType GetCSVFormatType() const noexcept;
        NODISCARD CSVHead GetCSVHead() const noexcept;

        NODISCARD String GenerateCopyright() const;
        NODISCARD String GenerateHeaderGuard() const;
        NODISCARD String GenerateNameSpace() const;
        NODISCARD String GenerateHeaderGuardEndif() const;

        NODISCARD String GetKeyTypeDescribe() const;

    private:
        NODISCARD virtual String GetSuffix() const = 0;
        NODISCARD virtual String GetFilePrefix() const = 0;
        NODISCARD virtual String GetFileSuffix() const = 0;
        NODISCARD virtual String GetContent() const = 0;

    private:
        CSVHead csvHead;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_CSV_GENERATE_IMPL_H