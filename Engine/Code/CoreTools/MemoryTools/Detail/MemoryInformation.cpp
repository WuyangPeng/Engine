// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/21 13:30)

#include "CoreTools/CoreToolsExport.h"

#include "MemoryInformation.h"
#include "CoreTools/Base/UniqueIDManagerDetail.h"
#include "CoreTools/Base/Flags/UniqueIDSelectFlags.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

using std::string;

CoreTools::MemoryInformation
	::MemoryInformation(size_t bytesNumber, int dimensionsNumber, const FunctionDescribed& functionDescribed)
	:m_BytesNumber{ bytesNumber }, m_DimensionsNumber{ dimensionsNumber },
	 m_FunctionDescribed{ functionDescribed }, m_UniqueID{ UNIQUE_ID_MANAGER_SINGLETON.NextUniqueID(UniqueIDSelect::MemoryInformation) }
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
bool CoreTools::MemoryInformation
	::IsValid() const noexcept
{
	if (m_UniqueID != 0)
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT	

size_t CoreTools::MemoryInformation
	::GetBytesNumber() const noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	return m_BytesNumber;
}

int CoreTools::MemoryInformation
	::GetDimensionsNumber() const noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	return m_DimensionsNumber;
}

const CoreTools::FunctionDescribed& CoreTools::MemoryInformation
	::GetFunctionDescribed() const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	return m_FunctionDescribed;
}

uint64_t CoreTools::MemoryInformation
	::GetUniqueID() const noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	return m_UniqueID;
}

