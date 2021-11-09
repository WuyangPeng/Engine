///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.2.5 (2021/10/18 15:32)

#include "CoreTools/CoreToolsExport.h"

#include "CSVRow.h"
#include "Detail/CSVRowImpl.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/TextParsing/Data/IntVector2.h"
#include "CoreTools/TextParsing/Data/IntVector3.h"
#include "CoreTools/TextParsing/Data/IntVector4.h"
#include "CoreTools/TextParsing/Data/Vector2.h"
#include "CoreTools/TextParsing/Data/Vector3.h"
#include "CoreTools/TextParsing/Data/Vector4.h"

using std::deque;
using std::vector;

CoreTools::CSVRow::CSVRow(const CSVHead& csvHead, const String& rowContent)
    : impl{ csvHead, rowContent }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, CSVRow)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, CSVRow, GetCount, int)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_CR(CoreTools, CSVRow, GetString, String, System::String)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_CR(CoreTools, CSVRow, GetBool, String, bool)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_CR(CoreTools, CSVRow, GetChar, String, System::TChar)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_CR(CoreTools, CSVRow, GetInt, String, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_CR(CoreTools, CSVRow, GetInt64, String, int64_t)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_CR(CoreTools, CSVRow, GetDouble, String, double)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_CR(CoreTools, CSVRow, GetEnumString, String, System::String)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_CR(CoreTools, CSVRow, GetVector2, String, CoreTools::Vector2)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_CR(CoreTools, CSVRow, GetVector3, String, CoreTools::Vector3)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_CR(CoreTools, CSVRow, GetVector4, String, CoreTools::Vector4)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_CR(CoreTools, CSVRow, GetIntVector2, String, CoreTools::IntVector2)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_CR(CoreTools, CSVRow, GetIntVector3, String, CoreTools::IntVector3)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_CR(CoreTools, CSVRow, GetIntVector4, String, CoreTools::IntVector4)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_CR(CoreTools, CSVRow, GetBoolArray, String, CoreTools::CSVRow::BoolContainer)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_CR(CoreTools, CSVRow, GetCharArray, String, CoreTools::CSVRow::CharContainer)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_CR(CoreTools, CSVRow, GetIntArray, String, CoreTools::CSVRow::IntContainer)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_CR(CoreTools, CSVRow, GetInt64Array, String, CoreTools::CSVRow::Int64Container)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_CR(CoreTools, CSVRow, GetDoubleArray, String, CoreTools::CSVRow::DoubleContainer)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_CR(CoreTools, CSVRow, GetEnumStringArray, String, CoreTools::CSVRow::StringContainer)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_CR(CoreTools, CSVRow, GetVector2Array, String, CoreTools::CSVRow::Vector2Container)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_CR(CoreTools, CSVRow, GetVector3Array, String, CoreTools::CSVRow::Vector3Container)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_CR(CoreTools, CSVRow, GetVector4Array, String, CoreTools::CSVRow::Vector4Container)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_CR(CoreTools, CSVRow, GetIntVector2Array, String, CoreTools::CSVRow::IntVector2Container)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_CR(CoreTools, CSVRow, GetIntVector3Array, String, CoreTools::CSVRow::IntVector3Container)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_CR(CoreTools, CSVRow, GetIntVector4Array, String, CoreTools::CSVRow::IntVector4Container)
