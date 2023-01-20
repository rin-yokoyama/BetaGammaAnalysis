set(LIB_NAME BetaGammaCore)

configure_file(include/LibraryConfig.h.in ${CMAKE_BINARY_DIR}/generated/LibraryConfig.h)

include_directories(include)

add_library( ${LIB_NAME} SHARED
	source/GACalibFunctions.cpp
	source/GACalibrator.cpp
	source/GACalibManager.cpp
	source/GASlewFunctions.cpp
	source/GASlewCorrectionManager.cpp
	source/RemainTime.cpp
	source/ProgressPrinter.cpp
	source/YamlParameter.cpp
	source/YamlReader.cpp
	source/TTreeEventLoaderBase.cpp
	source/TTreeEventBuilder.cpp
	source/PIDGate.cpp
)

target_link_libraries(${LIB_NAME} yaml-cpp)

install(TARGETS ${LIB_NAME}
		LIBRARY DESTINATION lib
		)
install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include
		DESTINATION include
		FILES_MATCHING PATTERN "*.h"
		)