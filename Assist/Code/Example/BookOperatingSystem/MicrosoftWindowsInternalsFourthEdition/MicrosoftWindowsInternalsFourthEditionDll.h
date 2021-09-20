///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.3 (2021/05/01 19:03)

#ifndef MICROSOFT_WINDOWS_INTERNALS_FOURTH_EDITION_DLL_H
#define MICROSOFT_WINDOWS_INTERNALS_FOURTH_EDITION_DLL_H

#include "Helper/UserMacro.h"
#include "System/Helper/ExportMacro.h"

#if defined(BUILDING_MICROSOFT_WINDOWS_INTERNALS_FOURTH_EDITION_NO_IMPORT) || defined(BUILDING_MICROSOFT_WINDOWS_INTERNALS_FOURTH_EDITION_STATIC)

    #define MICROSOFT_WINDOWS_INTERNALS_FOURTH_EDITION_DEFAULT_DECLARE
    #define MICROSOFT_WINDOWS_INTERNALS_FOURTH_EDITION_VISIBLE

    #if defined(BUILDING_MICROSOFT_WINDOWS_INTERNALS_FOURTH_EDITION_EXPORT)

        #define MICROSOFT_WINDOWS_INTERNALS_FOURTH_EDITION_HIDDEN_DECLARE

    #else  // !defined(BUILDING_MICROSOFT_WINDOWS_INTERNALS_FOURTH_EDITION_EXPORT)

        #define MICROSOFT_WINDOWS_INTERNALS_FOURTH_EDITION_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

    #endif  // BUILDING_MICROSOFT_WINDOWS_INTERNALS_FOURTH_EDITION_EXPORT

#else  // !defined(BUILDING_MICROSOFT_WINDOWS_INTERNALS_FOURTH_EDITION_NO_IMPORT) && !defined(BUILDING_MICROSOFT_WINDOWS_INTERNALS_FOURTH_EDITION_STATIC)

    #if defined(BUILDING_MICROSOFT_WINDOWS_INTERNALS_FOURTH_EDITION_EXPORT)

        #define MICROSOFT_WINDOWS_INTERNALS_FOURTH_EDITION_DEFAULT_DECLARE TCRE_SYMBOL_EXPORT
        #define MICROSOFT_WINDOWS_INTERNALS_FOURTH_EDITION_HIDDEN_DECLARE TCRE_SYMBOL_NO_EXPORT

    #else  // !defined(BUILDING_MICROSOFT_WINDOWS_INTERNALS_FOURTH_EDITION_EXPORT)

        #define MICROSOFT_WINDOWS_INTERNALS_FOURTH_EDITION_DEFAULT_DECLARE TCRE_SYMBOL_IMPORT
        #define MICROSOFT_WINDOWS_INTERNALS_FOURTH_EDITION_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

    #endif  // BUILDING_MICROSOFT_WINDOWS_INTERNALS_FOURTH_EDITION_EXPORT

    #define MICROSOFT_WINDOWS_INTERNALS_FOURTH_EDITION_VISIBLE TCRE_SYMBOL_VISIBLE

#endif  // defined(BUILDING_MICROSOFT_WINDOWS_INTERNALS_FOURTH_EDITION_NO_IMPORT) || defined(BUILDING_MICROSOFT_WINDOWS_INTERNALS_FOURTH_EDITION_STATIC)

#endif  // MICROSOFT_WINDOWS_INTERNALS_FOURTH_EDITION_DLL_H
