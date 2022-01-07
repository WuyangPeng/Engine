///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/19 20:00)

#include "CoreTools/CoreToolsExport.h"

#include "CSVHead.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/TextParsing/Detail/CSV/CSVHeadImpl.h"

CoreTools::CSVHead::CSVHead(const String& path, const FileContent& fileContent)
    : impl{ path, fileContent }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, CSVHead)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, CSVHead, GetCSVFormatType, CoreTools::CSVFormatType)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, CSVHead, GetNameSpace, System::String)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, CSVHead, GetCSVClassName, System::String)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, CSVHead, GetCompleteClassName, System::String)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, CSVHead, GetKey, System::String)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, CSVHead, GetKeyName, CoreTools::CSVHead::KeyName)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, CSVHead, GetCount, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(CoreTools, CSVHead, GetMapping, int, System::String)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, CSVHead, HasMapping, bool)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(CoreTools, CSVHead, GetScope, int, System::String)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, CSVHead, HasScope, bool)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(CoreTools, CSVHead, GetScopeExpression, int, System::String)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(CoreTools, CSVHead, GetDefaultValue, int, System::String)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(CoreTools, CSVHead, GetAnnotation, int, System::String)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(CoreTools, CSVHead, GetDataType, int, CoreTools::CSVDataType)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_CR(CoreTools, CSVHead, GetDataType, String, CoreTools::CSVDataType)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(CoreTools, CSVHead, GetActualType, int, System::String)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(CoreTools, CSVHead, GetValueType, int, System::String)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(CoreTools, CSVHead, GetActualTypeByNameSpace, int, System::String)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_CR(CoreTools, CSVHead, GetDataIndex, String, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_CR(CoreTools, CSVHead, GetDataIndex, StringView, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_CR(CoreTools, CSVHead, HasDataField, String, bool)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_CR(CoreTools, CSVHead, HasDataField, StringView, bool)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(CoreTools, CSVHead, GetEnumTypeName, int, System::String)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(CoreTools, CSVHead, GetVariableName, int, System::String)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(CoreTools, CSVHead, GetUpperVariableName, int, System::String)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(CoreTools, CSVHead, GetFunctionVariableName, int, System::String)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(CoreTools, CSVHead, GetFunctionName, int, System::String)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(CoreTools, CSVHead, HasDataType, CSVDataType, bool)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, CSVHead, HasVectorArrayDataType, bool)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, CSVHead, HasArrayDataType, bool)
