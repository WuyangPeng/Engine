// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.2 (2020/01/22 17:40)

#ifndef CORE_TOOLS_INTERNET_CONNECTION_H
#define CORE_TOOLS_INTERNET_CONNECTION_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "System/Network/Using/WindowsInternetUsing.h"

#include <boost/noncopyable.hpp>
#include <string>

namespace CoreTools
{
	class CORE_TOOLS_HIDDEN_DECLARE InternetConnection : private boost::noncopyable
	{
	public:
		using ClassType = InternetConnection;
		using InternetHandle = System::InternetHandle;

	public:
		explicit InternetConnection(const System::String& agent);
		~InternetConnection();
 
		CLASS_INVARIANT_DECLARE;

		InternetHandle GetInternet() const;

	private:
		InternetHandle m_Internet;
	};	
}

#endif // CORE_TOOLS_INTERNET_CONNECTION_H
