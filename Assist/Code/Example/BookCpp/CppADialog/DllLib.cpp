///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.6.0.0 (2020/12/27 18:45)

#include "Example/BookCpp/CppADialog/CppADialogExport.h"

#include "CppADialog.h" 

#ifndef BUILDING_CPP_A_DIALOG_STATIC

    #include "DllLib.h"

#else  // !BUILDING_CPP_A_DIALOG_STATIC

namespace CppADialog
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_CPP_A_DIALOG_STATIC
