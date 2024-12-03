#include "FlappyBird/Util/Logger.h"

#include <iostream>

int main(int argc, char** argv)
{
	FlappyBird::Logger::Init();
	FLAPPYBIRD_LOG_INFO("FlappyBirdGame");
}
