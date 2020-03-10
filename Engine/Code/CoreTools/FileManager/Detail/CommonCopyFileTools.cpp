// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/19 14:50)

#include "CoreTools/CoreToolsExport.h"

#include "CommonCopyFileTools.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

#include <boost/numeric/conversion/cast.hpp>

CoreTools::CommonCopyFileTools
	::CommonCopyFileTools(const String& inFileName, const String& outFileName)
	:ParentType{}, m_InFile{ inFileName }, m_OutFile{ outFileName }, m_Buffer(m_InFile.GetFileByteSize())
{
	m_InFile.Read(m_Buffer.size(), m_Buffer.data());
	m_OutFile.Write(m_Buffer.size(), m_Buffer.data());

	CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CoreTools::CommonCopyFileTools
	::~CommonCopyFileTools()
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, CommonCopyFileTools)




