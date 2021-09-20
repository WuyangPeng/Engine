///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.2 (2021/04/22 21:59)

#ifndef CLEAN_CPP_SUSTAINABLE_SOFTWARE_DEVELOPMENT_CHAPTER2_ENUM_CLASS_H
#define CLEAN_CPP_SUSTAINABLE_SOFTWARE_DEVELOPMENT_CHAPTER2_ENUM_CLASS_H

#include "Example/BookCpp/CleanCppSustainableSoftwareDevelopment/CleanCppSustainableSoftwareDevelopmentDll.h"

#include "CoreTools/Helper/ExportMacro.h"

#include <string>

namespace BookAdvanced
{
    namespace CleanCppSustainableSoftwareDevelopment
    {
        const std::string bear;
        // ... and elsewhere in the same namespace...

        enum Animal1
        {
            Dog,
            Deer,
            Cat,
            Bird,
            Bear  // bear
        };
        // error:'bear' redeclared as different kind of symbol

        enum class Animal2
        {
            Dog,
            Deer,
            Cat,
            Bird,
            bear
        };
        // Mo conflictt with the string named 'bear'
    }
}

#endif  // CLEAN_CPP_SUSTAINABLE_SOFTWARE_DEVELOPMENT_CHAPTER2_ENUM_CLASS_H
