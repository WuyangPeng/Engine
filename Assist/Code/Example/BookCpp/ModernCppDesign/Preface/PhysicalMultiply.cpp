///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.1 (2021/03/11 17:53)

#include "Example/BookCpp/ModernCppDesign/ModernCppDesignExport.h"

#include "PhysicalDetail.h"
#include "PhysicalMultiply.h"
#include "Example/BookCpp/ModernCppDesign/Helper/ModernCppDesignClassInvariantMacro.h"

BookAdvanced::ModernCppDesign::PhysicalMultiply::PhysicalMultiply() noexcept
{
    MODERN_CPP_DESIGN_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(BookAdvanced::ModernCppDesign, PhysicalMultiply)

int BookAdvanced::ModernCppDesign::PhysicalMultiply::Multiply(int lhs, int rhs) const noexcept
{
    MODERN_CPP_DESIGN_CLASS_IS_VALID_CONST_9;

    return (Physical<1, 2, 3>{ lhs } * Physical<3, 1, 2>{ rhs }).Value();
}
