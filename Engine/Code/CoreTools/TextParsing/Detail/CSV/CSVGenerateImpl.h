///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.5 (2023/04/03 20:03)

#ifndef CORE_TOOLS_TEXT_PARSING_CSV_GENERATE_IMPL_H
#define CORE_TOOLS_TEXT_PARSING_CSV_GENERATE_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/TextParsing/CSV/CSVHead.h"
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
        CSVGenerateImpl(const CSVGenerateImpl& rhs) noexcept = default;
        CSVGenerateImpl& operator=(const CSVGenerateImpl& rhs) noexcept = default;
        CSVGenerateImpl(CSVGenerateImpl&& rhs) noexcept = default;
        CSVGenerateImpl& operator=(CSVGenerateImpl&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        virtual void GenerateFile(const String& directory) const;

    protected: 
        NODISCARD static String GetOldContent(const String& fileName);

        NODISCARD String GetCSVClassName() const;
        NODISCARD CSVFormatType GetCSVFormatType() const noexcept;
        NODISCARD CSVHead GetCSVHead() const noexcept;

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