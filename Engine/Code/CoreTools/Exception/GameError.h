// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/19 10:46)

#ifndef CORE_TOOLS_EXCEPTION_GAME_ERROR_H
#define CORE_TOOLS_EXCEPTION_GAME_ERROR_H

#include "CoreTools/CoreToolsDll.h"

#include "Error.h" 

namespace CoreTools
{
	template<typename E>
	class GameError : public Error
	{
	public:
		static_assert(std::is_enum<E>::value, "E must be an enum.");

		using ClassType = GameError<E>;
		using ParentType = Error;

	public:
		GameError(const FunctionDescribed& functionDescribed, const LastError& lastError, E errorCode, const String& message);
		GameError(const FunctionDescribed& functionDescribed, WindowError lastError, E errorCode, const String& message);
		virtual ~GameError();

		CLASS_INVARIANT_OVERRIDE_DECLARE;

		E GetErrorCode() const noexcept;

		  const String GetError() const override;

	private: 
		virtual const String GetErrorCodeDescribed() const;

	private:
		E m_ErrorCode;
	};
}

#endif // CORE_TOOLS_EXCEPTION_GAME_ERROR_H