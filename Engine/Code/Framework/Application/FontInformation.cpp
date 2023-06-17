///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/13 14:50)

#include "Framework/FrameworkExport.h"

#include "FontInformation.h"
#include "Detail/FontInformationImpl.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

Framework::FontInformation::FontInformation(PlatformTypes type)
    : impl{ CoreTools::ImplCreateUseFactory::Default, type }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

Framework::FontInformation::FontInformation(WindowsHWnd hwnd)
    : impl{ CoreTools::ImplCreateUseFactory::Default, hwnd }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(Framework, FontInformation)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Framework, FontInformation, GetStringWidth, String, int);
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Framework, FontInformation, GetCharacterWidth, const TChar, int);
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Framework, FontInformation, GetFontHeight, int);
