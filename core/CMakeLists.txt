set(LIB_NAME APVCore)

include_directories(include)
add_library( ${LIB_NAME} SHARED
	source/RemainTime.cpp
	source/ProgressPrinter.cpp
	source/YamlParameter.cpp
	source/YamlReader.cpp
	source/TTreeEventLoaderBase.cpp
	source/TTreeEventBuilder.cpp
)

target_link_libraries(${LIB_NAME} yaml-cpp)

install(TARGETS ${LIB_NAME}
		LIBRARY DESTINATION lib
		)
install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include
		DESTINATION include
		FILES_MATCHING PATTERN "*.h"
		)