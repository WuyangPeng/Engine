///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.4 (2023/03/09 11:11)

#ifndef CORE_TOOLS_TEXT_PARSING_EXCEL_CONVERSION_CSV_IMPL_H
#define CORE_TOOLS_TEXT_PARSING_EXCEL_CONVERSION_CSV_IMPL_H

#include "CoreTools/CoreToolsDll.h"
#include "CoreTools/TextParsing/TextParsingInternalFwd.h"

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE ExcelConversionCSVImpl
    {
    public:
        using ClassType = ExcelConversionCSVImpl;
        using FactoryType = ExcelConversionCSVFactory;

    public:
        ExcelConversionCSVImpl() noexcept;
        virtual ~ExcelConversionCSVImpl() noexcept = 0;
        ExcelConversionCSVImpl(const ExcelConversionCSVImpl& rhs) noexcept = default;
        ExcelConversionCSVImpl& operator=(const ExcelConversionCSVImpl& rhs) noexcept = default;
        ExcelConversionCSVImpl(ExcelConversionCSVImpl&& rhs) noexcept = default;
        ExcelConversionCSVImpl& operator=(ExcelConversionCSVImpl&& rhs) noexcept = default;

        CLASS_INVARIANT_PURE_VIRTUAL_DECLARE;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_EXCEL_CONVERSION_CSV_IMPL_H