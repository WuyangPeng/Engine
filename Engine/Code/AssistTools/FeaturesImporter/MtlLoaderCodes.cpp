// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/07/31 15:17)

#include "AssistTools/AssistToolsExport.h"

#include "MtlLoader.h"

const char* AssistTools::MtlLoader
	::msCodeString[System::EnumCastUnderlying(ErrorCode::EC_MAX_ERROR_CODES)] =
{
    "Loaded successfully",          // EC_SUCCESSFUL
    "Logfile open failed",          // EC_LOGFILE_OPEN_FAILED
    "File open failed",             // EC_FILE_OPEN_FAILED
    "No tokens",                    // EC_NO_TOKENS
    "Too few tokens",               // EC_TOO_FEW_TOKENS
    "Too many tokens",              // EC_TOO_MANY_TOKENS
    "Unexpected token",             // EC_UNEXPECTED_TOKEN
    "Not yet implemented",          // EC_NOT_YET_IMPLEMENTED
    "Value out of range",           // EC_VALUE_OUT_OF_RANGE
    "Missing map filename",         // EC_MISSING_MAP_FILENAME
    "Invalid option",               // EC_INVALID_OPTION
    "Too few option tokens",        // EC_TOO_FEW_OPTION_TOKENS
    "Invalid option argument"       // EC_INVALID_OPTION_ARGUMENT
};
