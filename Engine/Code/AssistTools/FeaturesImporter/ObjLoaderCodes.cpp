// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/07/31 15:17)

#include "AssistTools/AssistToolsExport.h"

#include "ObjLoader.h"

const char* AssistTools::ObjLoader
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
    "Failed to load materials",     // EC_FAILED_TO_LOAD_MATERIALS
    "Failed to find material",      // EC_FAILED_TO_FIND_MATERIAL
    "Invalid vertex"                // EC_INVALID_VERTEX
};
