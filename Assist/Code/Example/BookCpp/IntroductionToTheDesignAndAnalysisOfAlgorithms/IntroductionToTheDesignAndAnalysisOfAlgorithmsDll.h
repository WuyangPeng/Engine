///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.0.1 (2021/02/09 14:57)

#ifndef INTRODUCTION_TO_THE_DESIGN_AND_ANALYSIS_OF_ALGORITHMS_DLL_H
#define INTRODUCTION_TO_THE_DESIGN_AND_ANALYSIS_OF_ALGORITHMS_DLL_H

#include "Helper/UserMacro.h"
#include "System/Helper/ExportMacro.h"

#if defined(BUILDING_INTRODUCTION_TO_THE_DESIGN_AND_ANALYSIS_OF_ALGORITHMS_NO_IMPORT) || defined(BUILDING_INTRODUCTION_TO_THE_DESIGN_AND_ANALYSIS_OF_ALGORITHMS_STATIC)

    #define INTRODUCTION_TO_THE_DESIGN_AND_ANALYSIS_OF_ALGORITHMS_DEFAULT_DECLARE
    #define INTRODUCTION_TO_THE_DESIGN_AND_ANALYSIS_OF_ALGORITHMS_HIDDEN_DECLARE
    #define INTRODUCTION_TO_THE_DESIGN_AND_ANALYSIS_OF_ALGORITHMS_VISIBLE

#else  // !defined(BUILDING_INTRODUCTION_TO_THE_DESIGN_AND_ANALYSIS_OF_ALGORITHMS_NO_IMPORT) && !defined(BUILDING_INTRODUCTION_TO_THE_DESIGN_AND_ANALYSIS_OF_ALGORITHMS_STATIC)

    #if defined(BUILDING_INTRODUCTION_TO_THE_DESIGN_AND_ANALYSIS_OF_ALGORITHMS_EXPORT)

        #define INTRODUCTION_TO_THE_DESIGN_AND_ANALYSIS_OF_ALGORITHMS_DEFAULT_DECLARE TCRE_SYMBOL_EXPORT
        #define INTRODUCTION_TO_THE_DESIGN_AND_ANALYSIS_OF_ALGORITHMS_HIDDEN_DECLARE TCRE_SYMBOL_NO_EXPORT

    #else  // !defined(BUILDING_INTRODUCTION_TO_THE_DESIGN_AND_ANALYSIS_OF_ALGORITHMS_EXPORT)

        #define INTRODUCTION_TO_THE_DESIGN_AND_ANALYSIS_OF_ALGORITHMS_DEFAULT_DECLARE TCRE_SYMBOL_IMPORT
        #define INTRODUCTION_TO_THE_DESIGN_AND_ANALYSIS_OF_ALGORITHMS_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

    #endif  // BUILDING_INTRODUCTION_TO_THE_DESIGN_AND_ANALYSIS_OF_ALGORITHMS_EXPORT

    #define INTRODUCTION_TO_THE_DESIGN_AND_ANALYSIS_OF_ALGORITHMS_VISIBLE TCRE_SYMBOL_VISIBLE

#endif  // defined(BUILDING_INTRODUCTION_TO_THE_DESIGN_AND_ANALYSIS_OF_ALGORITHMS_NO_IMPORT) || defined(BUILDING_INTRODUCTION_TO_THE_DESIGN_AND_ANALYSIS_OF_ALGORITHMS_STATIC)

#endif  // INTRODUCTION_TO_THE_DESIGN_AND_ANALYSIS_OF_ALGORITHMS_DLL_H