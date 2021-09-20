///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.0.0 (2021/01/30 11:02)

#ifndef DISCRETE_MATHEMATICS_AND_ITS_APPLICATIONS_SEVENTH_EDITION_LIB_H
#define DISCRETE_MATHEMATICS_AND_ITS_APPLICATIONS_SEVENTH_EDITION_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_DISCRETE_MATHEMATICS_AND_ITS_APPLICATIONS_SEVENTH_EDITION_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "DiscreteMathematicsAndItsApplicationsSeventhEditionD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "DiscreteMathematicsAndItsApplicationsSeventhEdition.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_DISCRETE_MATHEMATICS_AND_ITS_APPLICATIONS_SEVENTH_EDITION_STATIC

        #include "DllLib.h" 

        #ifdef _DEBUG
            #pragma comment(lib, "DiscreteMathematicsAndItsApplicationsSeventhEditionStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "DiscreteMathematicsAndItsApplicationsSeventhEditionStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_DISCRETE_MATHEMATICS_AND_ITS_APPLICATIONS_SEVENTH_EDITION_STATIC

#endif  // TCRE_USE_MSVC

#endif  // DISCRETE_MATHEMATICS_AND_ITS_APPLICATIONS_SEVENTH_EDITION_LIB_H
