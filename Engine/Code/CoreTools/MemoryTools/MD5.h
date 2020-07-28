// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.1 (2020/01/20 16:41)

#ifndef CORE_TOOLS_MEMORY_TOOLS_MD5_H
#define CORE_TOOLS_MEMORY_TOOLS_MD5_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Helper/ExportMacro.h"

#include "MD5Context.h"

#include <boost/noncopyable.hpp>
#include <string>

EXPORT_NONCOPYABLE_CLASS(CORE_TOOLS);

namespace CoreTools
{
	class CORE_TOOLS_DEFAULT_DECLARE MD5 : private boost::noncopyable
	{
	public:
		using ClassType = MD5;

	public:
		MD5();

		CLASS_INVARIANT_DECLARE;

		// 必须保证digest大小为16
		void MessageDigestAlgorithm5(uint8_t const* buffer, uint32_t length, uint8_t* digest);

		const std::string MessageDigestAlgorithm5(const std::string& source);

		const std::string MessageDigestAlgorithm5(uint8_t const* buffer, uint32_t length);

		static const std::string GetHexDigestWithUppercase(const uint8_t* digest);
		static const std::string GetHexDigestWithLowercase(const uint8_t* digest);

		static int GetDigestSize() noexcept;

	private:
		static constexpr int sm_DigestSize{ 16 };

		MD5Context m_MD5Context;
	};

}
#endif // CORE_TOOLS_MEMORY_TOOLS_MD5_H
