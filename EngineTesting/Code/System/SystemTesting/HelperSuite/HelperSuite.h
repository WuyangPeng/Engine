/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/06 17:33)

#ifndef SYSTEM_TESTING_HELPER_SUITE_H
#define SYSTEM_TESTING_HELPER_SUITE_H

#include "ConfigMacro/CompilerConfigTesting.h"
#include "ConfigMacro/ConfigMarkTesting.h"
#include "ConfigMacro/EndianTesting.h"
#include "ConfigMacro/FixedSizeTesting.h"
#include "ConfigMacro/PlatformConfigTesting.h"
#include "ConfigMacro/StdLibConfigTesting.h"
#include "EnumCastTesting.h"
#include "EnumOperator/EnumAddableTesting.h"
#include "EnumOperator/EnumAndableTesting.h"
#include "EnumOperator/EnumDecrementableTesting.h"
#include "EnumOperator/EnumIncrementableTesting.h"
#include "EnumOperator/EnumMultiplicationTesting.h"
#include "EnumOperator/EnumNegateTesting.h"
#include "EnumOperator/EnumOrableTesting.h"
#include "EnumOperator/EnumShiftableTesting.h"
#include "EnumOperator/EnumSubtractableTesting.h"
#include "EnumOperator/EnumXorableTesting.h"
#include "ExportMacroTesting.h"
#include "GlExtensionsMacroTesting.h"
#include "NetworkMacroTesting.h"
#include "NoexceptTesting.h"
#include "OpenGL/GlPluginMacroTesting.h"
#include "OpenGL/GlUtilityMacro/GlUtilityBodyResultTesting.h"
#include "OpenGL/GlUtilityMacro/GlUtilityBodyTesting.h"
#include "OpenGL/GlUtilityMacro/GlUtilityGetFunctionTesting.h"
#include "OpenGL/GlUtilityMacro/GlUtilityMarkTesting.h"
#include "OpenGL/GlUtilityMacro/GlUtilityPreviouslyBodyResultTesting.h"
#include "OpenGL/GlUtilityMacro/GlUtilityPreviouslyBodyTesting.h"
#include "OpenGL/GlxExtensionsMacroTesting.h"
#include "OpenGL/WglExtensionsMacroTesting.h"
#include "PlatformTesting.h"
#include "PragmaMessageMacroTesting.h"
#include "PragmaWarningTesting.h"
#include "SecuritySidMacroTesting.h"
#include "StringizeMacroTesting.h"
#include "Tools/DebugTesting.h"
#include "Tools/GetArraySizeTesting.h"
#include "Tools/OperatorTesting.h"
#include "Tools/UnusedFunctionTesting.h"
#include "UnicodeUsing/CharBufferTesting.h"
#include "UnicodeUsing/FileStreamMacroTesting.h"
#include "UnicodeUsing/NullCharTesting.h"
#include "UnicodeUsing/StringMacroTesting.h"
#include "UnicodeUsing/StringStreamMacroTesting.h"
#include "UnicodeUsing/ToStringTesting.h"
#include "UserMacroTesting.h"
#include "VariableTemplateTypeTesting.h"
#include "VersionTesting.h"
#include "WindowsMacro/HResultTesting.h"
#include "WindowsMacro/MakeIntResourceTesting.h"
#include "WindowsMacro/MakeLanguageCidTesting.h"
#include "WindowsMacro/MakeLanguageIdTesting.h"
#include "WindowsMacro/MakeWordTesting.h"
#include "WindowsMacro/MarkTesting.h"
#include "WindowsMacro/PtrToIntTesting.h"

#endif  // SYSTEM_TESTING_HELPER_SUITE_H