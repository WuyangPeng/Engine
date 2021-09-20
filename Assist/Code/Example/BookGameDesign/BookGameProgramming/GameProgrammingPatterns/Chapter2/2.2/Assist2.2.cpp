// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
//
// ÒýÇæ¸¨Öú°æ±¾£º0.0.1.0 (2019/11/05 22:07)

#include "Assist2.2.h" 
#include "Command2.h"
#include "InputHandler3.h"

namespace GameProgrammingPatterns
{
	namespace Chapter2
	{		
		void GameActor::jump()
		{

		}

		void Test()
		{
			GameActor gameActor;
			InputHandler3 inputHandler;
			Command2* command = inputHandler.handleInput();

			if (command)
			{
				command->execute(gameActor);
			}
		}
	}
}


