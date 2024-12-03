file(GLOB_RECURSE FlappyBirdSources
	"${CMAKE_CURRENT_SOURCE_DIR}/Main.cpp"
	
	"${CMAKE_CURRENT_SOURCE_DIR}/Util/Platform.h"
	"${CMAKE_CURRENT_SOURCE_DIR}/Util/Assertion.h"
	"${CMAKE_CURRENT_SOURCE_DIR}/Util/Logger.h"
	"${CMAKE_CURRENT_SOURCE_DIR}/Util/Logger.cpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/Util/FileIO.h"
	"${CMAKE_CURRENT_SOURCE_DIR}/Util/FileIO.cpp"
)

add_definitions(-DFPDEBUG)

add_executable(${FLAPPYBIRD_TARGET_NAME} ${FlappyBirdSources})
target_include_directories(${FLAPPYBIRD_TARGET_NAME} PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/../")
target_link_libraries(${FLAPPYBIRD_TARGET_NAME} PRIVATE spdlog)
