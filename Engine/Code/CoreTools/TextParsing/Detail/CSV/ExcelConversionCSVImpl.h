///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.4 (2023/03/09 11:11)

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