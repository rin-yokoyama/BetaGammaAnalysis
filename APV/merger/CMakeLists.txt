include_directories(include)
include_directories(${CMAKE_SOURCE_DIR}/core/include)
include_directories(${CMAKE_SOURCE_DIR}/data/include)
include_directories(${ARTEMIS_PATH}/include)
set(LIB_NAME SH13Merger)
set(LIB_SOURCES
	source/S2PlusTSScanner.cpp
	source/SH13PIDTSScanner.cpp
)
set(EXE_NAME merger)
add_library(${LIB_NAME} SHARED ${LIB_SOURCES})
add_executable(${EXE_NAME} source/SH13MergerMain.cpp)

target_link_libraries(${LIB_NAME} ${ROOT_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT} APVData APVCore)
target_link_libraries(${EXE_NAME} ${ROOT_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT} ${LIB_NAME} APVData APVCore)

install(TARGETS ${EXE_NAME}
		RUNTIME DESTINATION bin
		)
install(TARGETS ${LIB_NAME}
		LIBRARY DESTINATION lib
		)
install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include
		DESTINATION include
		FILES_MATCHING PATTERN "*.h"
		)