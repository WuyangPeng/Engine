// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/18 14:59)

#ifndef CORE_TOOLS_HELPER_EXCEPTION_MACRO_H
#define CORE_TOOLS_HELPER_EXCEPTION_MACRO_H

#include "System/SystemOutput/MessageBoxSelection.h"
#include "CoreTools/Exception/Error.h"
#include "CoreTools/Exception/LastError.h"
#include "CoreTools/Helper/LogMacro.h"
#include "CoreTools/Helper/FunctionDescribedMacro.h"

#include <stdexcept>

#define THROW_EXCEPTION(error) \
		CoreTools::Error::ThrowError((CORE_TOOLS_FUNCTION_DESCRIBED),(error))

#define THROW_WINDOWS_EXCEPTION \
		CoreTools::Error::ThrowError((CORE_TOOLS_FUNCTION_DESCRIBED),System::String{}) 

#define THROW_LAST_ERROR_EXCEPTION(lastError,error) \
        CoreTools::Error::ThrowError((CORE_TOOLS_FUNCTION_DESCRIBED),lastError,(error))

#define EXCEPTION_TRY try

#define EXCEPTION_ENGINE_EXCEPTION_CATCH(filterType) \
		catch (const CoreTools::Error& error) { LOG_SINGLETON_ENGINE_APPENDER(Error, filterType) \
        << error << LOG_SINGLETON_TRIGGER_ASSERT; } 

#define EXCEPTION_STD_EXCEPTION_CATCH(filterType) \
		catch (const std::exception& error) {	LOG_SINGLETON_ENGINE_APPENDER(Error, filterType) \
        << error.what() << LOG_SINGLETON_TRIGGER_ASSERT; }

#define EXCEPTION_UNKOWN_CATCH(filterType) \
		catch (...) { LOG_SINGLETON_ENGINE_APPENDER(Fatal, filterType) << SYSTEM_TEXT("Œ¥÷™¥ÌŒÛ°£") \
		<< LOG_SINGLETON_TRIGGER_ASSERT; }

#define EXCEPTION_ALL_CATCH(filterType) \
		EXCEPTION_ENGINE_EXCEPTION_CATCH(filterType) \
        EXCEPTION_STD_EXCEPTION_CATCH(filterType) \
        EXCEPTION_UNKOWN_CATCH(filterType)

#define EXCEPTION_ENTRY_POINT_CATCH \
		catch (const CoreTools::Error& error) { \
		CERR << error.GetError() << SYSTEM_TEXT('\n'); }\
		catch (const std::runtime_error& error) { \
		std::cerr << error.what() << '\n'; } \
		catch (...) { CERR << SYSTEM_TEXT("Œ¥÷™¥ÌŒÛ\n"); }

#define EXCEPTION_WINDOWS_ENTRY_POINT_CATCH \
		catch (const CoreTools::Error& error) { \
		System::MessageBoxSelectionWithTChar(error.GetError().c_str(), SYSTEM_TEXT("¥ÌŒÛ")); }\
		catch (const std::runtime_error& error) { \
		System::MessageBoxSelectionWithChar(error.what(), "¥ÌŒÛ"); } \
		catch (...) { System::MessageBoxSelectionWithTChar(SYSTEM_TEXT("Œ¥÷™¥ÌŒÛ£°"), SYSTEM_TEXT("¥ÌŒÛ")); } 

#endif // CORE_TOOLS_HELPER_EXCEPTION_MACRO_H
