// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/19 10:46)

#include "CoreTools/CoreToolsExport.h"

#include "ErrorFactory.h"
#include "ErrorImpl.h"
#include "NormalError.h"
#include "WindowsError.h"
#include "System/Window/Flags/PlatformErrorFlags.h"
#include "CoreTools/Exception/LastError.h"

using std::make_shared;

// static
CoreTools::ErrorFactory::ErrorImplPtr CoreTools::ErrorFactory
	::CreateError(const FunctionDescribed& functionDescribed, const LastError& lastError, const String& message)
{
	return CreateError(functionDescribed, lastError.GetLastError(), message);
}

// static
CoreTools::ErrorFactory::ErrorImplPtr CoreTools::ErrorFactory
	::CreateError(const FunctionDescribed& functionDescribed, WindowError lastError, const String& message)
{
	switch (lastError)
	{
		case WindowError::Success:
			return make_shared<NormalError>(functionDescribed, message);

		default:
			return make_shared<WindowsError>(functionDescribed, lastError, message);
	}
}
