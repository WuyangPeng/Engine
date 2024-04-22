/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/02 22:50)

#ifndef CORE_TOOLS_TEXT_PARSING_BATCH_CONVERSION_CSV_IMPL_H
#define CORE_TOOLS_TEXT_PARSING_BATCH_CONVERSION_CSV_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE BatchConversionCSVImpl final
    {
    public:
        using ClassType = BatchConversionCSVImpl;

        using String = System::String;

    public:
        BatchConversionCSVImpl(String nativeFileName, String outputDirectory);

        CLASS_INVARIANT_DECLARE;

    private:
        void ExecutionFile() const;

        NODISCARD String GetOutputFile() const;

    private:
        String nativeFileName;
        String outputDirectory;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_BATCH_CONVERSION_CSV_IMPL_H