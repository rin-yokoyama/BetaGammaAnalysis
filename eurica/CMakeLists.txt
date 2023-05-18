set(LIB_NAME Eurica)
set(EXE_NAME eurica_merger)

include_directories(include)

ROOT_GENERATE_DICTIONARY(G__Eurica
    Data_bigrips.h
    Data_eurica.h
    Data_wasabi.h
	EuricaMergerData.hpp
	EuricaBigRIPSPreScanSelector.h
	EuricaWasabiPreScanSelector.h
	EuricaPreScanSelector.h
	LINKDEF include/EuricaLinkDef.h)

add_library( ${LIB_NAME} SHARED
	G__Eurica.cxx
	#source/Data_bigrips.C
	#source/Data_wasabi.C
	#source/Data_eurica.C
	source/BigRIPSPreScanSelector.cc
	source/WasabiPreScanSelector.cc
	source/EuricaPreScanSelector.cc
	source/BigRIPSTSScanner.cc
	source/EuricaTSScanner.cc
	source/WasabiTSScanner.cc
	source/WasabiMergedTSScanner.cc
	#source/BetaTSScanner.cc
	#source/ImplantTSScanner.cc
	#source/BetaTreeMerger.cc
)

target_link_libraries(${LIB_NAME} ${ROOT_LIBRARIES} yaml-cpp BetaGammaCore)

install(TARGETS ${LIB_NAME}
		LIBRARY DESTINATION lib
		)
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/libEurica_rdict.pcm
		DESTINATION lib
		)
install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include
		DESTINATION include
		FILES_MATCHING PATTERN "*.h"
		)

#add_executable(${EXE_NAME} source/EuricaMergerMain.cpp)
#target_link_libraries(${EXE_NAME} ${ROOT_LIBRARIES} yaml-cpp BetaGammaCore ${LIB_NAME})
#
#install(TARGETS ${EXE_NAME}
#		RUNTIME DESTINATION bin)

add_executable(bigrips_prescan source/BigRIPSPreScanMain.cc)
target_link_libraries(bigrips_prescan ${ROOT_LIBRARIES} BetaGammaCore ${LIB_NAME})

add_executable(wasabi_prescan source/WasabiPreScanMain.cc)
target_link_libraries(wasabi_prescan ${ROOT_LIBRARIES} BetaGammaCore ${LIB_NAME})

add_executable(eurica_prescan source/EuricaPreScanMain.cc)
target_link_libraries(eurica_prescan ${ROOT_LIBRARIES} BetaGammaCore ${LIB_NAME})

add_executable(eurica_premerger source/EuricaPreMergerMain.cc)
target_link_libraries(eurica_premerger ${ROOT_LIBRARIES} BetaGammaCore ${LIB_NAME})

install(TARGETS bigrips_prescan wasabi_prescan eurica_prescan eurica_premerger
		RUNTIME DESTINATION bin)

add_subdirectory(scripts)