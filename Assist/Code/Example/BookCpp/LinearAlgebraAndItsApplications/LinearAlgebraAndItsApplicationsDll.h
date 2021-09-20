///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.0.1 (2021/02/09 14:57)

#ifndef LINEAR_ALGEBRA_AND_ITS_APPLICATIONS_DLL_H
#define LINEAR_ALGEBRA_AND_ITS_APPLICATIONS_DLL_H

#include "Helper/UserMacro.h"
#include "System/Helper/ExportMacro.h"

#if defined(BUILDING_LINEAR_ALGEBRA_AND_ITS_APPLICATIONS_NO_IMPORT) || defined(BUILDING_LINEAR_ALGEBRA_AND_ITS_APPLICATIONS_STATIC)

    #define LINEAR_ALGEBRA_AND_ITS_APPLICATIONS_DEFAULT_DECLARE
    #define LINEAR_ALGEBRA_AND_ITS_APPLICATIONS_HIDDEN_DECLARE
    #define LINEAR_ALGEBRA_AND_ITS_APPLICATIONS_VISIBLE

#else  // !defined(BUILDING_LINEAR_ALGEBRA_AND_ITS_APPLICATIONS_NO_IMPORT) && !defined(BUILDING_LINEAR_ALGEBRA_AND_ITS_APPLICATIONS_STATIC)

    #if defined(BUILDING_LINEAR_ALGEBRA_AND_ITS_APPLICATIONS_EXPORT)

        #define LINEAR_ALGEBRA_AND_ITS_APPLICATIONS_DEFAULT_DECLARE TCRE_SYMBOL_EXPORT
        #define LINEAR_ALGEBRA_AND_ITS_APPLICATIONS_HIDDEN_DECLARE TCRE_SYMBOL_NO_EXPORT

    #else  // !defined(BUILDING_LINEAR_ALGEBRA_AND_ITS_APPLICATIONS_EXPORT)

        #define LINEAR_ALGEBRA_AND_ITS_APPLICATIONS_DEFAULT_DECLARE TCRE_SYMBOL_IMPORT
        #define LINEAR_ALGEBRA_AND_ITS_APPLICATIONS_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

    #endif  // BUILDING_LINEAR_ALGEBRA_AND_ITS_APPLICATIONS_EXPORT

    #define LINEAR_ALGEBRA_AND_ITS_APPLICATIONS_VISIBLE TCRE_SYMBOL_VISIBLE

#endif  // defined(BUILDING_LINEAR_ALGEBRA_AND_ITS_APPLICATIONS_NO_IMPORT) || defined(BUILDING_LINEAR_ALGEBRA_AND_ITS_APPLICATIONS_STATIC)

#endif  // LINEAR_ALGEBRA_AND_ITS_APPLICATIONS_DLL_H
