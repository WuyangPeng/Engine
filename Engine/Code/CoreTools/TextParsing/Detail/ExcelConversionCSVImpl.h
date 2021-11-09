///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.7.2.4 (2021/10/15 14:18)

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