///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.9 (2023/05/25 09:47)

#include "Database/DatabaseExport.h"

#include "RedisDatabaseFlush.h"
#include "RedisReply.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

#ifdef DATABASE_USE_REDIS

Database::RedisReply::RedisReply(RedisContext& redisContext, const std::string& command)
    : redisReply{ static_cast<::redisReply*>(::redisCommand(redisContext.GetRedisContext(), command.c_str())) }
{
    if (redisReply == nullptr)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("redis Command 失败。"))
    }
    else if (redisReply->type != REDIS_REPLY_STATUS)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("redis Command 失败。") + CoreTools::StringConversion::MultiByteConversionStandard(redisReply->str))
    }

    DATABASE_SELF_CLASS_IS_VALID_9;
}

Database::RedisReply::~RedisReply() noexcept
{
    EXCEPTION_TRY
    {
        ::freeReplyObject(redisReply);
    }
    EXCEPTION_ALL_CATCH(Database)

    DATABASE_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Database, RedisReply)

::redisReply* Database::RedisReply::GetRedisReply() noexcept
{
    DATABASE_CLASS_IS_VALID_9;

    return redisReply;
}

#endif  // DATABASE_USE_REDIS
