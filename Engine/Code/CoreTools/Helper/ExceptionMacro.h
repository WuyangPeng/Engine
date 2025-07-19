/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/03/28 11:04)

#ifndef CORE_TOOLS_HELPER_EXCEPTION_MACRO_H
#define CORE_TOOLS_HELPER_EXCEPTION_MACRO_H

#include "System/SystemOutput/MessageBoxSelection.h"
#include "CoreTools/Exception/Error.h"
#include "CoreTools/Exception/LastError.h"
#include "CoreTools/Helper/FunctionDescribedMacro.h"
#include "CoreTools/Helper/LogMacro.h"

#include <stdexcept>

#define THROW_EXCEPTION(error)                                                  \
    {                                                                           \
        using namespace std::literals;                                          \
        CoreTools::Error::ThrowError((CORE_TOOLS_FUNCTION_DESCRIBED), (error)); \
    }

#define THROW_WINDOWS_EXCEPTION                                                          \
    {                                                                                    \
        CoreTools::Error::ThrowError((CORE_TOOLS_FUNCTION_DESCRIBED), System::String{}); \
    }

#define THROW_LAST_ERROR_EXCEPTION(lastError, error)                                       \
    {                                                                                      \
        using namespace std::literals;                                                     \
        CoreTools::Error::ThrowError((CORE_TOOLS_FUNCTION_DESCRIBED), lastError, (error)); \
    }

#define EXCEPTION_TRY try

#define EXCEPTION_ENGINE_EXCEPTION_CATCH(filterType)                                                                \
    catch (const CoreTools::Error& error)                                                                           \
    {                                                                                                               \
        LOG_SINGLETON_ENGINE_APPENDER(Error, filterType, error, CoreTools::LogAppenderIOManageSign::TriggerAssert); \
    }

#define EXCEPTION_STD_EXCEPTION_CATCH(filterType)                                                                   \
    catch (const std::exception& error)                                                                             \
    {                                                                                                               \
        LOG_SINGLETON_ENGINE_APPENDER(Error, filterType, error, CoreTools::LogAppenderIOManageSign::TriggerAssert); \
    }

#define EXCEPTION_UNKNOWN_CATCH(filterType)                                                                                             \
    catch (...)                                                                                                                         \
    {                                                                                                                                   \
        LOG_SINGLETON_ENGINE_APPENDER(Fatal, filterType, SYSTEM_TEXT("未知错误。"), CoreTools::LogAppenderIOManageSign::TriggerAssert); \
    }

#define EXCEPTION_ALL_CATCH(filterType)          \
    EXCEPTION_ENGINE_EXCEPTION_CATCH(filterType) \
    EXCEPTION_STD_EXCEPTION_CATCH(filterType)    \
    EXCEPTION_UNKNOWN_CATCH(filterType)

#define EXCEPTION_ENTRY_POINT_CATCH                    \
    catch (const CoreTools::Error& error)              \
    {                                                  \
        CERR << error.GetError() << SYSTEM_TEXT('\n'); \
    }                                                  \
    catch (const std::runtime_error& error)            \
    {                                                  \
        std::cerr << error.what() << '\n';             \
    }                                                  \
    catch (...)                                        \
    {                                                  \
        CERR << SYSTEM_TEXT("未知错误\n");             \
    }

#define EXCEPTION_WINDOWS_ENTRY_POINT_CATCH                                                                                              \
    catch (const CoreTools::Error& error)                                                                                                \
    {                                                                                                                                    \
        MAYBE_UNUSED const auto dialogBoxCommand = System::MessageBoxSelectionWithTChar(error.GetError().c_str(), SYSTEM_TEXT("错误"));  \
    }                                                                                                                                    \
    catch (const std::runtime_error& error)                                                                                              \
    {                                                                                                                                    \
        MAYBE_UNUSED const auto dialogBoxCommand = System::MessageBoxSelectionWithChar(error.what(), "错误");                            \
    }                                                                                                                                    \
    catch (...)                                                                                                                          \
    {                                                                                                                                    \
        MAYBE_UNUSED const auto dialogBoxCommand = System::MessageBoxSelectionWithTChar(SYSTEM_TEXT("未知错误！"), SYSTEM_TEXT("错误")); \
    }

#define ASSERT_FAIL_THROW_EXCEPTION(condition, error) \
    {                                                 \
        if (!(condition))                             \
        {                                             \
            THROW_EXCEPTION(error);                   \
        }                                             \
    }

#endif  // CORE_TOOLS_HELPER_EXCEPTION_MACRO_H
