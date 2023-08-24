///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.3 (2023/08/08 19:29)

#ifndef FRAMEWORK_MAIN_FUNCTION_HELPER_DIRECTORY_DEFAULT_NAME_H
#define FRAMEWORK_MAIN_FUNCTION_HELPER_DIRECTORY_DEFAULT_NAME_H

#include "Framework/FrameworkDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "Framework/MainFunctionHelper/MainFunctionHelperFwd.h"

namespace Framework
{
    class FRAMEWORK_HIDDEN_DECLARE DirectoryDefaultName
    {
    public:
        using ClassType = DirectoryDefaultName;

        using String = System::String;

    public:
        NODISCARD static String GetDefaultNullName();
        NODISCARD static String GetSuffix();
        NODISCARD static String GetDefaultKeyName(AnalysisDirectory analysisDirectory);
        NODISCARD static String GetDefaultName(AnalysisDirectory analysisDirectory);
    };
}

#endif  // FRAMEWORK_MAIN_FUNCTION_HELPER_DIRECTORY_DEFAULT_NAME_H