set(LIB_NAME APVData)

include_directories(include)
ROOT_GENERATE_DICTIONARY(G__APVData
	APVSingleData.h
	APVMultiData.h
	SH13S2PlusData.h
	OutputTreeData.hpp
	TAPV8008Data.h
	TDataObject.h
	ITiming.h
	ICharge.h
	TArtemisObject.h
	LINKDEF include/APVLinkDef.h)
add_library( ${LIB_NAME} SHARED
	G__APVData.cxx
	${ARTEMIS_OEDO_PATH}/TAPV8008Data.cc
	${ARTEMIS_SRC_PATH}/cont/ITiming.cc
	${ARTEMIS_SRC_PATH}/cont/ICharge.cc
	${ARTEMIS_SRC_PATH}/core/TDataObject.cc
	${ARTEMIS_SRC_PATH}/core/TArtemisObject.cc
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