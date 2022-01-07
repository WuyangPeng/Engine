///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/19 11:48)

#ifndef CORE_TOOLS_TEXT_PARSING_BATCH_CONVERSION_CSV_IMPL_H
#define CORE_TOOLS_TEXT_PARSING_BATCH_CONVERSION_CSV_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE BatchConversionCSVImpl final
    {
    public:
        using ClassType = BatchConversionCSVImpl;
        using String = System::String;

    public:
        BatchConversionCSVImpl(const String& nativeFileName, const String& outputDirectory);

        CLASS_INVARIANT_DECLARE;

    private:
        void ExecutionFile(const String& nativeFileName, const String& outputDirectory);

        NODISCARD String GetOutputFile(const String& nativeFileName, const String& outputDirectory);
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_BATCH_CONVERSION_CSV_IMPL_H