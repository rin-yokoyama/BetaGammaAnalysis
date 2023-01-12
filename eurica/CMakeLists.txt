set(LIB_NAME Eurica)

include_directories(include)

ROOT_GENERATE_DICTIONARY(G__Eurica
    Data_bigrips.h
    Data_eurica.h
    Data_wasabi.h
	LINKDEF include/EuricaLinkDef.h)

add_library( ${LIB_NAME} SHARED
	G__Eurica.cxx
    source/BigRIPSTSScanner.cc
    source/EuricaTSScanner.cc
    source/WasabiTSScanner.cc
)

target_link_libraries(${LIB_NAME} ${ROOT_LIBRARIES})

install(TARGETS ${LIB_NAME}
		LIBRARY DESTINATION lib
		)
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/libAPVData_rdict.pcm
		DESTINATION lib
		)
install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include
		DESTINATION include
		FILES_MATCHING PATTERN "*.h"
		)